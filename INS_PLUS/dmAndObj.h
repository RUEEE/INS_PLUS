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
void inline INS_2540(DWORD ptNowObj);
void inline INS_2541(DWORD ptNowObj);
void inline INS_2542(DWORD ptNowObj);
void inline INS_2543(DWORD ptNowObj);
void inline INS_2544(DWORD ptNowObj);
void inline INS_2545(DWORD ptNowObj);
void inline INS_2546(DWORD ptNowObj);

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
				reflectDm(B, x, y, vx, vy, (float*)(ptDm + 0xC44), (float*)(ptDm + 0xC48), (float*)(ptDm + 0xC54));
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;
			}
		}
	};
	forEachDm(F);
}

void inline INS_2540(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 3)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}

	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y;
		if (*(int*)(ptDm + 0xCB8) == N && !shapes[B].isInsideA(x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C)))
		{
			float vx, vy;
			vx = *(float*)(ptDm + 0xC44);
			vy = *(float*)(ptDm + 0xC48);
			if (shapes[B].isInsideA(x + vx, y + vy))
			{
				reflectDm(B, x, y, vx, vy, (float*)(ptDm + 0xC44), (float*)(ptDm + 0xC48), (float*)(ptDm + 0xC54));
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;

			}

		}
	};
	forEachDm(F);
}

void inline INS_2541(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 2)//如果是纯反弹不用考虑内外问题
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}

	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y,vx,vy;
		if (reflectDm(B, x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C),
			vx = *(float*)(ptDm + 0xC44), vy =*(float*)(ptDm + 0xC48),
			(float*)(ptDm + 0xC44), (float*)(ptDm + 0xC48), (float*)(ptDm + 0xC54)))
		{
			if (M != -1)
				*(int*)(ptDm + 0xCB8) = M;
			if (R != -1)
				*(int*)(ptDm + 0xC9C) = R;
		}
	};
	forEachDm(F);
}

void inline INS_2542(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 2)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}
	float x, y, vx, vy, nx, ny, r;
	x = autoGetArgFloatB(ptNowObj, 1);
	y = autoGetArgFloatB(ptNowObj, 2);
	vx = autoGetArgFloatB(ptNowObj, 3);
	vy = autoGetArgFloatB(ptNowObj, 4);
	autoSubESP(ptNowObj, -3);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	if (!reflectDm(B, x, y, vx, vy, &nx, &ny, &r))
	{
		nx = ny = r = 0.0f;
	}
	*(float*)pt = r;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = ny;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = nx;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2543(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	float nw = autoGetArgFloatB(ptNowObj, 4)/ autoGetArgFloatB(ptNowObj, 5);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 3)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y;
		if (*(int*)(ptDm + 0xCB8) == N && shapes[B].isInsideA(x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C)))
		{
			float vx, vy;
			vx = *(float*)(ptDm + 0xC44);
			vy = *(float*)(ptDm + 0xC48);
			if (!shapes[B].isInsideA(x + vx, y + vy))
			{
				refractDm(B, x, y, vx, vy, *(float*)(ptDm + 0xCA4)*nw/(*(float*)(ptDm + 0xCA8)), (float*)(ptDm + 0xC44), (float*)(ptDm + 0xC48), (float*)(ptDm + 0xC54));
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;
			}
		}
	};
	forEachDm(F);
}

void inline INS_2544(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	float nw = autoGetArgFloatB(ptNowObj, 5) / autoGetArgFloatB(ptNowObj, 4);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 3)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y;
		if (*(int*)(ptDm + 0xCB8) == N && !shapes[B].isInsideA(x = *(float*)(ptDm + 0xC38), y = *(float*)(ptDm + 0xC3C)))
		{
			float vx, vy;
			vx = *(float*)(ptDm + 0xC44);
			vy = *(float*)(ptDm + 0xC48);
			if (shapes[B].isInsideA(x + vx, y + vy))
			{
				refractDm(B, x, y, vx, vy, *(float*)(ptDm + 0xCA8)*nw / (*(float*)(ptDm + 0xCA4)), (float*)(ptDm + 0xC44), (float*)(ptDm + 0xC48), (float*)(ptDm + 0xC54));
				if (M != -1)
					*(int*)(ptDm + 0xCB8) = M;
				if (R != -1)
					*(int*)(ptDm + 0xC9C) = R;
			}
		}
	};
	forEachDm(F);
}


void inline INS_2545(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	int N = autoGetArgIntB(ptNowObj, 1);
	int M = autoGetArgIntB(ptNowObj, 2);
	int R = autoGetArgIntB(ptNowObj, 3);
	float nw = autoGetArgFloatB(ptNowObj, 4) / autoGetArgFloatB(ptNowObj, 5);
	float mw = autoGetArgFloatB(ptNowObj, 5) / autoGetArgFloatB(ptNowObj, 4);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 3)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}
	std::function<void(DWORD)> F = [=](int ptDm)
	{
		float x, y, vx, vy,ew;
		int ret;
		x = *(float*)(ptDm + 0xC38);
		y = *(float*)(ptDm + 0xC3C);
		vx = *(float*)(ptDm + 0xC44);
		vy = *(float*)(ptDm + 0xC48);
		if (shapes[B].isInsideA(x, y))
		{
			ew = *(float*)(ptDm + 0xCA4)*nw/(*(float*)(ptDm + 0xCA8));
		}
		else
		{
			ew = *(float*)(ptDm + 0xCA8)*mw / (*(float*)(ptDm + 0xCA4));
		}
		if (ret=refractDm(B, x, y, vx, vy, ew, (float*)(ptDm + 0xC44), (float*)(ptDm + 0xC48), (float*)(ptDm + 0xC54)))
		{
			if (M != -1)
				*(int*)(ptDm + 0xCB8) = M;
			if (R != -1)
				*(int*)(ptDm + 0xC9C) = R;
			if (ret == 1)
			{
				*(float*)(ptDm + 0xC38) += vx;
				*(float*)(ptDm + 0xC3C) += vy;//让它折射后不再次折射
			}
		}
	};
	forEachDm(F);
}

void inline INS_2546(DWORD ptNowObj)
{
	int B = autoGetArgIntB(ptNowObj, 0);
	if (shapes[B].type == 2 && shapes[B].pts.size() < 3)
	{
		MessageBox(NULL, _T("错误:点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	else if (shapes[B].type == 3 && shapes[B].ptsBz.size() < 2)
	{
		MessageBox(NULL, _T("错误:贝塞尔点太少"), _T("来自INS_PLUS.dll"), MB_OK);
		//报错
	}
	if (shapes[B].type == 3 && shapes[B].isTransed == 0) {
		shapes[B].transBz();//事先转换
	}
	float x, y, vx, vy, nx, ny, r,ew,t,R;
	x = autoGetArgFloatB(ptNowObj, 1);
	y = autoGetArgFloatB(ptNowObj, 2);
	vx = autoGetArgFloatB(ptNowObj, 3);
	vy = autoGetArgFloatB(ptNowObj, 4);
	float nw = autoGetArgFloatB(ptNowObj, 5) / autoGetArgFloatB(ptNowObj, 6);
	float mw = autoGetArgFloatB(ptNowObj, 6) / autoGetArgFloatB(ptNowObj, 5);
	t = autoGetArgFloatB(ptNowObj, 7);
	R = autoGetArgFloatB(ptNowObj, 8);
	nw= t * nw / R;
	mw= R * mw / t;
	autoSubESP(ptNowObj, -3);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	if (shapes[B].isInsideA(x, y))
	{
		ew = nw;
	}
	else
	{
		ew = mw;
	}
	if (!refractDm(B, x, y, vx, vy,ew, &nx, &ny, &r))
	{
		nx = ny = r = 0.0f;
	}
	*(float*)pt = r;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = ny;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = nx;
	*(BYTE*)(pt - 4) = 'f';
}
