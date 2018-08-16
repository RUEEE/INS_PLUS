#include "stdafx.h"
#include "dmShape.h"
Shape shapes[16];
Mask masks[16];

float Asmp(float xl, float xr, std::function<float(float)> F)
{
	float res = 0;
	std::queue<std::pair<std::pair<float, float>, float>> pt;
	pt.push(std::make_pair(std::make_pair(xl, xr), smp(xl, xr, (xl + xr) / 2, F)));
	float x0, x1, x2, T, L, R;
	int i = 500;
	while (!pt.empty() && i>0)
	{
		x0 = pt.front().first.first;
		x1 = pt.front().first.second;
		T = pt.front().second;
		pt.pop();
		x2 = (x0 + x1) / 2;
		L = smp(x0, x2, (x0 + x2) / 2, F);
		R = smp(x2, x1, (x1 + x2) / 2, F);
		if (fabs(L + R - T) <= 50 * EPS)
		{
			res += L + R + (L + R - T) / 50;
		}
		else {
			pt.push(std::make_pair(std::make_pair(x0, x2), L));
			pt.push(std::make_pair(std::make_pair(x2, x1), R));
		}
		i--;
	}
	return res;
}

int dcmp(float x)
{
	if (fabs(x) <= EPS){return 0;}
	else if (x < 0){return -1;}
	return 1;
}

bool Shape::isInside(float a, float b)
{

	float x, y;
	x = a * ixN + b * jxN;
	y = a * iyN + b * jyN;//求出(a,b)的逆
	if (type == 0)//椭圆
	{
		return x * x + y * y <= sx * sx;
	}
	if (type == 1)//平行四边形
	{
		return fabsf(x) <= sx && fabsf(y) <= sy;
	}
	if (type == 2)//路径图形
	{
		int wd = 0, n = pts.size();
		if (n < 3)
		{
			//报错
			MessageBox(NULL, _T("错误:路径至少需要3个点"), _T("来自INS_PLUS.dll"), MB_OK);
		}
		if (x>sx || y>sy || x<mx || y<my)//在包围体外部
		{
			return 0;
		}
		for (int i = 0,j=0; i < n; i++)
		{
			float x1 = pts[i].first,y1=pts[i].second;
			j = i + 1; if (j == n)j = 0;
			float x2 = pts[j].first, y2 = pts[j].second;//(x1,y1)(x2,y2)为两个测试点
			if (fabsf((y-y1)*(x2-x) - (x-x1)*(y2-y)) <= EPS)//边界判断
			{
				return 1;//边界上=内部
			}
			int k=dcmp((x2 - x1)*(y - y1) - (y2 - y1)*(x - x1));
			int d1 = dcmp(y1 - y),d2=dcmp(y2-y);
			if (k > 0 && d1 <= 0 && d2 > 0)wd++;
			else if (k < 0 && d2 <= 0 && d1 > 0)wd--;
		}
		if (wd != 0)return 1;
		return 0;
	}
	if (type == 3)//贝塞尔曲线
	{
		if (isTransed == 0)
		{
			this->transBz();
		}
		if (x>sx || y>sy || x<mx || y<my)//在包围体外部
		{
			return 0;
		}
		float a, b, c, d, m, n, o, p;
		//贝塞尔曲线的角度的微分
		int N = funcsBz.size();
		float w=0;//绕数
		for (int i = 0; i < N; i++)
		{
			a = std::get<0>(funcsBz[i]);
			b = std::get<1>(funcsBz[i]);
			c = std::get<2>(funcsBz[i]);
			d = std::get<3>(funcsBz[i]);
			m = std::get<4>(funcsBz[i]);
			n = std::get<5>(funcsBz[i]);
			o = std::get<6>(funcsBz[i]);
			p = std::get<7>(funcsBz[i]);
			std::function<float(float)> F = [a, b, c, d, m, n, o, p, x, y](float t)
			{
				float xt = a * t * t * t + b * t * t + c * t + d;
				float xt_ = 3 * a * t * t + 2 * b * t + c;
				float yt = m * t * t * t + n * t * t + o * t + p;
				float yt_ = 3 * m * t * t + 2 * n * t + o;
				return ((xt-x) * yt_ - (yt-y)*xt_) / ((xt-x) * (xt - x) + (yt-y) * (yt - y));
			};
			w += Asmp(0, 1, F)/6.28318531f;
		}
		if (fabs(w) <= 0.15)//为0
		{
			return 0;
		}
		return 1;
	}
	return 0;
}

void Shape::transBz()
{
	if (type != 3)
	{
		MessageBox(NULL, _T("错误:给非贝塞尔曲线的图形转换"), _T("来自INS_PLUS.dll"), MB_OK);
	}
	int n = ptsBz.size();
	if (n < 1)
	{
		MessageBox(NULL, _T("错误:贝塞尔曲线数据太少"), _T("来自INS_PLUS.dll"), MB_OK);
	}
	std::pair<float, float> pt0, pt1, pt2,pt3;
	float xa, xb, xc, xd, ya, yb, yc, yd, del, m1, m2, a, b;
	for (int i = 0; i < n; i++)
	{
		int j = i + 1; if (j == n)j = 0;
		pt0 = std::get<0>(ptsBz[i]);
		pt1 = std::get<2>(ptsBz[i]);
		pt2 = std::get<1>(ptsBz[j]);
		pt3 = std::get<0>(ptsBz[j]);
		xd = pt0.first;
		xc = 3 * (pt1.first - xd);
		xb = 3 * (pt2.first - pt1.first) - xc;
		xa = pt3.first - pt0.first - xc - xb;
		yd = pt0.second;
		yc = 3 * (pt1.second - yd);
		yb = 3 * (pt2.second - pt1.second) - yc;
		ya = pt3.second - pt0.second - yc - yb;
		funcsBz.push_back(std::make_tuple(xa, xb, xc, xd, ya, yb, yc, yd));
		//x=f(n)=xa t^3+xb t^2+xc t+xd
		//y=g(n)=ya t^3+yb t^2+yc t+yd
		//t in [0,1]
		//f'(n)=(3*xa)t^2+(2*xb)t+xc
		//g'(n)=(3*ya)t^2+(2*yb)t+yc
		a = 6 * xa; b = 2 * xb;
		del = b * b - 2 * a*xc;//delta=b^2-4ac
		if (del >= 0)//delta>0,不使用精度EPS
		{
			del = sqrtf(del);
			m1 = (-b + del) / a;
			m2 = (-b - del) / a;
			//获得取得最值的t
			if (m1 >= 0 && m1 <= 1)
			{
				m1 = xa * m1*m1*m1 + xb * m1*m1 + xc * m1 + xd;
				if (m1 < mx)
					mx = m1;
				else if (m1 > sx)
					sx = m1;
			}
			if (m2 >= 0 && m2 <= 1)
			{
				m2 = xa * m2*m2*m2 + xb * m2*m2 + xc * m2 + xd;
				if (m2 < mx)
					mx = m2;
				else if (m2 > sx)
					sx = m2;
			}
			//获得并输入两个最值
		}
		m1 = xa + xb + xc + xd;//t=1时
		m2 = xd;//t=0时
		if (m2 < mx)
			mx = m2;
		else if (m2 > sx)
			sx = m2;
		if (m1 < mx)
			mx = m1;
		else if (m1 > sx)
			sx = m1;
		//然后是y的判定>>>>>>>>>>>>>>>>>>>
		a = 6 * ya; b = 2 * yb;
		del = b * b - 2 * a*yc;
		if (del >= 0)
		{
			del = sqrtf(del);
			m1 = (-b + del) / a;
			m2 = (-b - del) / a;
			if (m1 >= 0 && m1 <= 1)
			{
				m1 = ya * m1*m1*m1 + yb * m1*m1 + yc * m1 + yd;
				if (m1 < my)
					my = m1;
				else if (m1 > sy)
					sy = m1;
			}
			if (m2 >= 0 && m2 <= 1)
			{
				m2 = ya * m2*m2*m2 + yb * m2*m2 + yc * m2 +yd;
				if (m2 < my)
					my = m2;
				else if (m2 > sy)
					sy = m2;
			}
		}
		m1 = ya + yb + yc + yd;
		m2 = yd;
		if (m2 < my)
			my = m2;
		else if (m2 > sy)
			my = m2;
		if (m1 < my)
			my = m1;
		else if (m1 > sy)
			sy = m1;
	}
	isTransed = 1;
}

