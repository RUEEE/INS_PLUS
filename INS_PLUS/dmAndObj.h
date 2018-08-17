#pragma once
#include "stdafx.h"
#include <functional>
#include "objArg.h"
#include "dmShape.h"
#include <list>
#define MAX_MSG_SIZE 200
struct ECLMsg
{
	int hwndObj,parentObj;
	int id;
	int a, b, c;
	float x, y, z;
	ECLMsg(int h,int p,int idf,int ia,int ib,int ic,float ix,float iy,float iz):hwndObj(h),parentObj(p),id(idf),a(ia),b(ib),c(ic),x(ix),y(iy),z(iz)
	{
		return;
	}
};
extern std::list<ECLMsg> msg;

void inline forEachDm(std::function<void(DWORD)> F)
{
	DWORD bspt = *(DWORD*)(0x004e9a6c);
	bspt+=0x6C;
	bspt = *(DWORD*)bspt;
	while (bspt)
	{
		F(*(DWORD*)bspt);
		bspt = *(DWORD*)(bspt+4);
	}
}
void inline INS_2410(DWORD ptNowObj);
void inline INS_2411(DWORD ptNowObj);
void inline INS_2412(DWORD ptNowObj, DWORD ptINS);
void inline INS_2413(DWORD ptNowObj);
void inline INS_2414(DWORD ptNowObj);
void inline INS_2415(DWORD ptNowObj);
void inline INS_2416(DWORD ptNowObj);
void inline INS_2417(DWORD ptNowObj);

void inline INS_2530(DWORD ptNowObj);
void inline INS_2531(DWORD ptNowObj);
void inline INS_2532(DWORD ptNowObj);
void inline INS_2533(DWORD ptNowObj);
void inline INS_2534(DWORD ptNowObj);
void inline INS_2535(DWORD ptNowObj);
void inline INS_2536(DWORD ptNowObj);
void inline INS_2537(DWORD ptNowObj);
void inline INS_2538(DWORD ptNowObj);
void inline INS_2539(DWORD ptNowObj);

void inline INS_2530(DWORD ptNowObj){
	int b=autoGetArgIntB(ptNowObj,0), n= autoGetArgIntB(ptNowObj, 1), t= autoGetArgIntB(ptNowObj, 2),w = autoGetArgIntB(ptNowObj, 3);
	std::function<void(DWORD)> F = [b,n,t,w](int ptDm)
	{
		int p = *(int*)(ptDm + 0xC9C);
		if (*(int*)(ptDm + 0xCB8) == n && p<w && p!=t && masks[b].isInsideA(*(float*)(ptDm + 0xC38), *(float*)(ptDm + 0xC3C)))
		{
			*(int*)(ptDm + 0xC9C) = t;
		}
	};
	forEachDm(F);
}

void inline INS_2531(DWORD ptNowObj){
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int t = autoGetArgIntB(ptNowObj, 2);
	int A = autoGetArgIntB(ptNowObj, 3);
	int mode= autoGetArgIntB(ptNowObj, 4);
	int a = autoGetArgIntB(ptNowObj, 5);
	int b = autoGetArgIntB(ptNowObj, 6);
	float r = autoGetArgFloatB(ptNowObj, 7);
	float s = autoGetArgFloatB(ptNowObj, 8);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(*(float*)(ptDm + 0xC38), *(float*)(ptDm + 0xC3C)))
		{
			DWORD w = ptDm + (t * 0x2C) + 0xCA4;
			*(float*)w = r; w += 4;
			*(float*)w = s; w += 0xC;
			*(int*)w = a; w += 4;
			*(int*)w = b; w += 0xC;
			*(int*)w = mode; w += 4;
			*(int*)w = A; w += 4;
		}
	};
	forEachDm(F);
}

void inline INS_2532(DWORD ptNowObj) {
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int t = autoGetArgIntB(ptNowObj, 2);
	int A = autoGetArgIntB(ptNowObj, 3);
	int mode = autoGetArgIntB(ptNowObj, 4);
	int a = autoGetArgIntB(ptNowObj, 5);
	int b = autoGetArgIntB(ptNowObj, 6);
	int c = autoGetArgIntB(ptNowObj, 7);
	int d = autoGetArgIntB(ptNowObj, 8);
	float r = autoGetArgFloatB(ptNowObj, 9);
	float s = autoGetArgFloatB(ptNowObj, 10);
	float m = autoGetArgFloatB(ptNowObj, 11);
	float n = autoGetArgFloatB(ptNowObj, 12);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(*(float*)(ptDm + 0xC38), *(float*)(ptDm + 0xC3C)))
		{
			DWORD w = ptDm + (t * 0x2C) + 0xCA4;
			*(float*)w = r; w += 4;
			*(float*)w = s; w += 4;
			*(float*)w = m; w += 4;
			*(float*)w = n; w += 4;
			*(int*)w = a; w += 4;
			*(int*)w = b; w += 4;
			*(int*)w = c; w += 4;
			*(int*)w = d; w += 4;
			*(int*)w = mode; w += 4;
			*(int*)w = A; w += 4;
		}
	};
	forEachDm(F);
}

void inline INS_2533(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	float t = autoGetArgFloatB(ptNowObj, 2);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x = *(float*)(ptDm + 0xC38);
		float y = *(float*)(ptDm + 0xC3C);
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(x,y))
		{
			float v = *(float*)(ptDm + 0xC50);
			float ns = atan2f(y - masks[B].n, x - masks[B].m) + t;
			*(float*)(ptDm + 0xC54) = ns;
			*(float*)(ptDm + 0xC44) = v * cosf(ns);
			*(float*)(ptDm + 0xC48) = v * sinf(ns);
		}
	};
	forEachDm(F);
}

void inline INS_2534(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(*(float*)(ptDm + 0xC38), *(float*)(ptDm + 0xC3C)))
		{
			*(float*)(ptDm + 0xC38)+=masks[B].m;
			*(float*)(ptDm + 0xC3C)+=masks[B].n;
		}
	};
	forEachDm(F);
}


void inline INS_2535(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	float Fg = autoGetArgFloatB(ptNowObj, 2);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x = *(float*)(ptDm + 0xC38);
		float y = *(float*)(ptDm + 0xC3C);
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(x, y))
		{
			float nx = x - masks[B].m, ny = y - masks[B].n;
			float S = (nx * nx + ny * ny);
			float f = Fg / S;
			*(float*)(ptDm + 0xC44);
			S = 1/sqrt(S);
			float ax, ay;
			ax = nx * S*f;
			ay = ny * S*f;
			*(float*)(ptDm + 0xC44) += ax;
			*(float*)(ptDm + 0xC48) += ay;
			ax = *(float*)(ptDm + 0xC44);
			ay = *(float*)(ptDm + 0xC48);
			*(float*)(ptDm + 0xC50) = sqrt(ax*ax + ay * ay);
			*(float*)(ptDm + 0xC54) = atan2f(ay,ax);
		}
	};
	forEachDm(F);
}

void inline INS_2536(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(*(float*)(ptDm + 0xC38), *(float*)(ptDm + 0xC3C)))
		{
			*(int*)(ptDm + 0xCB8) = M;
		}
	};
	forEachDm(F);
}

void inline INS_2410(DWORD ptNowObj)
{
	for (;msg.size()>=200;)
	{
		msg.pop_front();
	}//超过200数据自动删除到199个
	msg.push_back(ECLMsg(autoGetArgIntB(ptNowObj,0),*(int*)(ptNowObj+0x5730),
		autoGetArgIntB(ptNowObj, 1), autoGetArgIntB(ptNowObj, 2),
		autoGetArgIntB(ptNowObj, 3), autoGetArgIntB(ptNowObj, 4),
		autoGetArgFloatB(ptNowObj,5), autoGetArgFloatB(ptNowObj, 6), 
		autoGetArgFloatB(ptNowObj, 7)));
}

void inline INS_2411(DWORD ptNowObj)
{
	int thisObj = *(int*)(ptNowObj + 0x5730);
	std::list<ECLMsg>::iterator iter,end=msg.end();
	for (iter = msg.begin(); iter != end; ++iter)
	{
		if (iter->hwndObj == thisObj)
		{
			*autoGetPtrArgIntB(ptNowObj, 0) = iter->id;
			int* w;
			w = autoGetPtrArgIntB(ptNowObj, 1);
			if (w != 0)
				 *w= iter->a;
			w = autoGetPtrArgIntB(ptNowObj, 2);
			if (w != 0)
				*w = iter->b;
			w = autoGetPtrArgIntB(ptNowObj, 3);
			if (w != 0)
				*w = iter->c;
			float * w2;
			w2 = autoGetPtrArgFloatB(ptNowObj, 4);
			if (w2 != 0)
				*w2 = iter->x;
			w2 = autoGetPtrArgFloatB(ptNowObj, 5);
			if (w2 != 0)
				*w2 = iter->y;
			w2 = autoGetPtrArgFloatB(ptNowObj, 6);
			if (w2 != 0)
				*w2 = iter->z;
			msg.erase(iter);
			return;
		}
	}
	*autoGetPtrArgIntB(ptNowObj, 0) = 0;//调取失败
}

void inline INS_2412(DWORD ptNowObj,DWORD ptINS)
{
	int thisObj = *(int*)(ptNowObj + 0x5730);
	std::list<ECLMsg>::iterator iter, end = msg.end();
	for (iter = msg.begin(); iter != end; ++iter)
	{
		if (iter->hwndObj == thisObj)
		{
			*autoGetPtrArgIntB(ptNowObj, 0) = iter->id;
			int* w;
			w = autoGetPtrArgIntB(ptNowObj, 1);
			if (w != 0)
				*w = iter->a;
			w = autoGetPtrArgIntB(ptNowObj, 2);
			if (w != 0)
				*w = iter->b;
			w = autoGetPtrArgIntB(ptNowObj, 3);
			if (w != 0)
				*w = iter->c;
			float * w2;
			w2 = autoGetPtrArgFloatB(ptNowObj, 4);
			if (w2 != 0)
				*w2 = iter->x;
			w2 = autoGetPtrArgFloatB(ptNowObj, 5);
			if (w2 != 0)
				*w2 = iter->y;
			w2 = autoGetPtrArgFloatB(ptNowObj, 6);
			if (w2 != 0)
				*w2 = iter->z;
			msg.erase(iter);
			return;
		}
	}
	//调取失败
	*(DWORD*)(ptNowObj + 8) -= *(WORD*)(ptINS+6);
	*(float*)(ptNowObj) -= 1.0f;
}

void inline INS_2413(DWORD ptNowObj)
{
	ECLMsg* iter;
	if (msg.size() != 0)
	{
		iter = &msg.front();
		*autoGetPtrArgIntB(ptNowObj, 0) = iter->id;
		int* w;
		w = autoGetPtrArgIntB(ptNowObj, 1);
		if (w != 0)
			*w = iter->a;
		w = autoGetPtrArgIntB(ptNowObj, 2);
		if (w != 0)
			*w = iter->b;
		w = autoGetPtrArgIntB(ptNowObj, 3);
		if (w != 0)
			*w = iter->c;
		float * w2;
		w2 = autoGetPtrArgFloatB(ptNowObj, 4);
		if (w2 != 0)
			*w2 = iter->x;
		w2 = autoGetPtrArgFloatB(ptNowObj, 5);
		if (w2 != 0)
			*w2 = iter->y;
		w2 = autoGetPtrArgFloatB(ptNowObj, 6);
		if (w2 != 0)
			*w2 = iter->z;
		msg.pop_front();
		return;
	}
	*autoGetPtrArgIntB(ptNowObj, 0) = 0;
}

void inline INS_2414(DWORD ptNowObj)
{
	ECLMsg* iter;
	if (msg.size() != 0)
	{
		iter = &msg.back();
		*autoGetPtrArgIntB(ptNowObj, 0) = iter->id;
		int* w;
		w = autoGetPtrArgIntB(ptNowObj, 1);
		if (w != 0)
			*w = iter->a;
		w = autoGetPtrArgIntB(ptNowObj, 2);
		if (w != 0)
			*w = iter->b;
		w = autoGetPtrArgIntB(ptNowObj, 3);
		if (w != 0)
			*w = iter->c;
		float * w2;
		w2 = autoGetPtrArgFloatB(ptNowObj, 4);
		if (w2 != 0)
			*w2 = iter->x;
		w2 = autoGetPtrArgFloatB(ptNowObj, 5);
		if (w2 != 0)
			*w2 = iter->y;
		w2 = autoGetPtrArgFloatB(ptNowObj, 6);
		if (w2 != 0)
			*w2 = iter->z;
		msg.pop_back();
		return;
	}
	*autoGetPtrArgIntB(ptNowObj, 0) = 0;
}

void inline INS_2415(DWORD ptNowObj)
{
	int pObj = autoGetArgIntB(ptNowObj,0);
	std::list<ECLMsg>::iterator iter, end = msg.end();
	for (iter = msg.begin(); iter != end; ++iter)
	{
		if (iter->parentObj == pObj)
		{
			*autoGetPtrArgIntB(ptNowObj, 1) = iter->id;
			int* w;
			w = autoGetPtrArgIntB(ptNowObj, 2);
			if (w != 0)
				*w = iter->a;
			w = autoGetPtrArgIntB(ptNowObj, 3);
			if (w != 0)
				*w = iter->b;
			w = autoGetPtrArgIntB(ptNowObj, 4);
			if (w != 0)
				*w = iter->c;
			float * w2;
			w2 = autoGetPtrArgFloatB(ptNowObj, 5);
			if (w2 != 0)
				*w2 = iter->x;
			w2 = autoGetPtrArgFloatB(ptNowObj, 6);
			if (w2 != 0)
				*w2 = iter->y;
			w2 = autoGetPtrArgFloatB(ptNowObj, 7);
			if (w2 != 0)
				*w2 = iter->z;
			msg.erase(iter);
			return;
		}
	}
	*autoGetPtrArgIntB(ptNowObj, 0) = 0;//调取失败
}

void inline INS_2416(DWORD ptNowObj)
{
	msg.clear();
}

void inline INS_2417(DWORD ptNowObj)
{
	int Obj = autoGetArgIntB(ptNowObj, 0);
	std::list<ECLMsg>::iterator iter, end = msg.end();
	for (iter = msg.begin(); iter != end;)
	{
		if (iter->hwndObj == Obj)
		{
			msg.erase(iter++);
		}else{
			++iter;
		}
	}
}

void inline INS_2418(DWORD ptNowObj)
{
	int pt = (int)getPtrEsp(ptNowObj);
	*(int*)pt = msg.size();
	*(BYTE*)(pt - 4) = 'i';
	autoSubESP(ptNowObj, -1);
}

void inline INS_2537(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x,y;
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C) ))
		{
			x += *(float*)(ptDm + 0xC44);
			y += *(float*)(ptDm + 0xC48);
			if (!masks[B].isInsideA(x, y))
			{
				if(M!=-1)
					*(int*)(ptDm + 0xCB8) = M;
				if(R!=-1)
					*(int*)(ptDm + 0xC9C) = R;
			}
			
		}
	};
	forEachDm(F);
}

void inline INS_2538(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y;
		if (*(int*)(ptDm + 0xCB8) == N && masks[B].isInsideA(x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C)))
		{
			x += *(float*)(ptDm + 0xC44);
			y += *(float*)(ptDm + 0xC48);
			if (!masks[B].isInsideA(x, y))
			{
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;
			}
		}else{
			x += *(float*)(ptDm + 0xC44);
			y += *(float*)(ptDm + 0xC48);
			if (masks[B].isInsideA(x, y))
			{
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;
			}
		}
	};
	forEachDm(F);
}

void inline INS_2539(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 3)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed==0){
		shapes[B].transBz();//事先转换
	}

	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y;
		if (*(int*)(ptDm + 0xCB8) == N && shapes[B].isInsideA(x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C)))
		{
			float vx, vy;
			vx=*(float*)(ptDm + 0xC44);
			vy=*(float*)(ptDm + 0xC48);
			if (!shapes[B].isInsideA(x+vx, y+vy))
			{
				float dx,dy,sx,sy,rtx,bx,by;
				bx = vx; by = vy;
				sx = shapes[B].x; sy = shapes[B].y;
				auto p = shapes[B].transOthPtN(x-sx, y-sy);
				x = p.first; y = p.second;
				p = shapes[B].transOthPtN(vx, vy);
				vx = p.first; vy = p.second;
				//将线段置换入坐标轴
				switch (shapes[B].type)
				{
				case 0://圆
					{
						auto root = getRoot3(0,vx*vx+vy*vy,2*vx*x+2*y*vy,x*x+y*y-shapes[B].sx*shapes[B].sx);
						//求解圆与直线的交点
						switch (std::get<0>(root))
						{
						case 2:
							//如果x1不合法或x2合法且比x1合适
							if (std::get<1>(root) < -EPS || (std::get<2>(root)>=-EPS && std::get<2>(root)-1<=EPS && std::get<2>(root) < std::get<1>(root)) )
								rtx = std::get<2>(root);
							else
								rtx = std::get<1>(root);
							break;
						case 1:
							rtx = std::get<1>(root);
							break;
						default:
							//报错
							return;
						}
						dx = rtx * vy + y; dy = -rtx * vx + x;//获得斜率的向量
					}
					break;
				case 1://方
					{
						float re=2, esi, edi;
						esi = shapes[B].sx; edi = shapes[B].sy;
						std::tuple<int,float,float> root;

						root= getLineCrossOverPoint(x, y, vx, vy, -esi, -edi, 2 * esi, 0);//上
						if (std::get<0>(root) == 1 && re > std::get<1>(root))
						{
							re = std::get<1>(root); dx = 1; dy = 0;
						}
						root = getLineCrossOverPoint(x, y, vx, vy, -esi, edi, 2 * esi, 0);//下
						if (std::get<0>(root) == 1 && re > std::get<1>(root))
						{
							re = std::get<1>(root); dx = 1; dy = 0;
						}
						root = getLineCrossOverPoint(x, y, vx, vy, -esi, -edi, 0, 2* edi);//左
						if (std::get<0>(root) == 1 && re > std::get<1>(root))
						{
							re = std::get<1>(root); dx = 0;  dy = 1;
						}
						root = getLineCrossOverPoint(x, y, vx, vy, esi, -edi, 0, 2* edi);//右
						if (std::get<0>(root) == 1 && re > std::get<1>(root))
						{
							re = std::get<1>(root); dx = 0; dy = 1;
						}
					}
					break;
				case 2://多个线段
					{
						int n = shapes[B].pts.size(),tn=-1,sn=-1;
						float rt=2;
						float lx, ly, lvx, lvy;
						std::tuple<int, float, float> root;
						int i,j;
						for (i = 0,j=1; i < n; ++i,++j)
						{
							if (j == n)
								j = 0;
							lx = shapes[B].pts[i].first;
							ly = shapes[B].pts[i].second;
							lvx = shapes[B].pts[j].first - lx;
							lvy = shapes[B].pts[j].second - ly;
							root = getLineCrossOverPoint(x, y, vx, vy, lx, ly, lvx, lvy);
							if (std::get<0>(root) ==1 && rt > std::get<1>(root))
							{
								rt = std::get<1>(root);
								tn = i;
								sn = j;
							}
						}
						if (tn == -1)
							return;
						dx = shapes[B].pts[sn].first - shapes[B].pts[tn].first;
						dy = shapes[B].pts[sn].second - shapes[B].pts[tn].second;
					}
					break;
				case 3://贝塞尔曲线
					{
						int n = shapes[B].funcsBz.size(),tn=-1;
						float w=0.0,t,lnd=999999.0f,ld;
						float Ax, Bx, Cx, Dx, Ay, By, Cy, Dy;
						float xa,ya;
						for(int i=0;i<n;i++)
						{
							std::tie(Ax, Bx, Cx, Dx, Ay, By, Cy, Dy) = shapes[B].funcsBz[i];
							auto root = getRootBzLine(x, y, vx, vy, Ax, Bx, Cx, Dx, Ay, By, Cy, Dy);
							if (root.first != 0)
							{
								t = root.second;
								xa = Ax * t*t*t + Bx * t*t + Cx * t + Dx - x;
								ya = Ay * t*t*t + By * t*t + Cy * t + Dy - y;
								ld = ya * ya + xa * xa;//判断哪个距离最近
								if (ld<lnd)
								{
									tn = i;
									w = t;
									lnd = ld;
								}
							}
						}
						//遍历完,有可能没有交点(因为bz的边界判定)
						if (tn == -1)
							tn = 1;
						std::tie(Ax, Bx, Cx, Dx, Ay, By, Cy, Dy) = shapes[B].funcsBz[tn];
						//求导
						dx = 3 * Ax*t*t + 2 * Bx*t + Cx;
						dy = 3 * Ay*t*t + 2 * By*t + Cy;
					}
					break;
				default:
					dx = dy = 1;
					return;
				}
				p = shapes[B].transOthPt(dx, dy);//让dx,dy变回原来的
				dx = p.first; dy = p.second;
				p = reflectLine(dx, dy, bx, by);
				*(float*)(ptDm + 0xC44) = p.first;
				*(float*)(ptDm + 0xC48) = p.second;
				*(float*)(ptDm + 0xC54) = atan2f(p.second, p.first);
				//和2537一样
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;
			}

		}
	};
	forEachDm(F);
}
