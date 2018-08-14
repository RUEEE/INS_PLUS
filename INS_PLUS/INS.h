#pragma once
#include "stdafx.h"
#include "test.h"
#include "objArg.h"


const float one = 1.0;
void init();
int _stdcall INS_Switch(int code, int ptINS, DWORD ptObj, DWORD* _obj);
inline int fastPow(int a, int b);
inline void INS_2333(DWORD* obj);
inline void INS_2311(DWORD ptNowObj);
inline void INS_2310(DWORD ptNowObj);
inline void INS_2309(DWORD ptNowObj);
inline void INS_2308(DWORD ptNowObj);
inline void INS_2307(DWORD ptNowObj);
inline void INS_2034(DWORD ptNowObj);
inline void INS_2000(DWORD ptNowObj, DWORD ptINS);
inline void INS_2001(DWORD ptNowObj, DWORD ptINS);
inline void INS_2002(DWORD ptNowObj, DWORD ptINS);
inline void INS_2003(DWORD ptNowObj, DWORD ptINS);
inline void INS_2109(DWORD ptNowObj, DWORD ptINS);
inline void INS_2110(DWORD ptNowObj);
inline void INS_2111(DWORD ptNowObj);
inline void INS_2112(DWORD ptNowObj);
inline void INS_2004(DWORD ptNowObj);
inline void INS_2005(DWORD ptNowObj);
inline void INS_2006(DWORD ptNowObj);
inline void INS_2114(DWORD ptNowObj);
inline void INS_2113(DWORD ptNowObj);
inline void INS_2400(DWORD* obj);
inline void INS_2150(DWORD ptINS, DWORD ptNowObj);
inline void INS_2151(DWORD* obj, DWORD ptNowObj);
inline void INS_STACK_CALC_FLOAT_RET_FLOAT(int code, DWORD ptNowObj);
inline void INS_STACK_CALC_VOID_RET_FLOAT(int code, DWORD ptNowObj);
inline void INS_STACK_CALC_VOID_RET_INT(int code, DWORD ptNowObj);
inline void INS_STACK_CALC_INT_RET_INT(int code, DWORD ptNowObj);
inline void INS_2102(DWORD ptINS, DWORD ptNowObj);
inline void INS_2103(DWORD ptINS, DWORD ptNowObj);
inline void INS_2104(DWORD ptINS, DWORD ptNowObj);

inline int fastPow(int a, int b) {
	int r = 1, base = a;
	while (b) {
		if (b & 1) r *= base;
		base *= base;
		b >>= 1;
	}
	return r;
}

inline void INS_2311(DWORD ptNowObj)
{
	int power = autoGetArgIntB(ptNowObj, 0);
	*(DWORD*)0x004E7440 = power;
	__asm
	{
		mov ecx, DWORD_PTR[0x004E9BB8]
		mov eax, 0x004567B0
		call eax
	}
}

inline void INS_2310(DWORD ptNowObj)
{
	int bomb = autoGetArgIntB(ptNowObj, 0);
	if (bomb > 8)bomb = 8;
	if (bomb < 0)bomb = 0;
	*(DWORD*)0x004E745C = bomb;
	__asm
	{
		push DWORD_PTR[0x004E7460]
		push bomb
		mov ecx, DWORD_PTR[0x004E9A8C]
		mov eax, 0x0043A960
		call eax
	}
}

inline void INS_2309(DWORD ptNowObj)
{
	int life = autoGetArgIntB(ptNowObj, 0);
	if (life > 8)life = 8;
	if (life < 0)life = 0;
	*(DWORD*)0x004E7450 = life;
	__asm
	{
		push DWORD_PTR[0x004E7454]
		push life
		mov ecx, DWORD_PTR[0x004E9A8C]
		mov eax, 0x0043A850
		call eax
	}
}

inline void INS_2308(DWORD ptNowObj)
{
	int inv = autoGetArgIntB(ptNowObj, 0);
	if (inv < 0)inv = 0;
	*(DWORD*)(*(DWORD*)0x004E9BB8 + 0x16284) = inv;
	*(float*)(*(DWORD*)0x004E9BB8 + 0x16288) = (float)inv;
}

inline void INS_2307(DWORD ptNowObj)
{
	float x = autoGetArgFloatB(ptNowObj, 0), y = autoGetArgFloatB(ptNowObj, 1);
	DWORD ptPla = *(DWORD*)0x004E9BB8;
	*(float*)(ptPla + 0x618) = x;
	*(float*)(ptPla + 0x61C) = y;
	float sz = *(float*)0x004CFDAC;
	sz = 1 / sz;
	x *= sz; y *= sz;
	*(int*)(ptPla + 0x624) = (int)x;
	*(int*)(ptPla + 0x628) = (int)y;
}

inline void INS_2034(DWORD ptNowObj)
{
	float* res = autoGetPtrArgFloatB(ptNowObj, 0);
	float x = autoGetArgFloatB(ptNowObj, 1);
	int tpe = autoGetArgIntB(ptNowObj, 2);
	float progress = autoGetArgFloatB(ptNowObj, 3);
	float result;
	__asm
	{
		mov ecx, tpe
		movss xmm1, progress
		movss xmm2, one
		mov eax, 0x00404500
		call eax
		movss result, xmm0
	}
	*res = result * x;
	return;
}

inline void INS_2000(DWORD ptNowObj, DWORD ptINS)
{
	int pt;
	if (*(BYTE*)(ptINS + 11) == 0) {
		pt = (int)getPtrArgSt(ptNowObj, -1);
	}
	else {
		pt = (int)getPtrArgSt(ptNowObj, -autoGetArgIntB(ptNowObj, 0));
	}
	if (*(BYTE*)(pt - 4) == 'f' || *(BYTE*)(pt - 4) == 'g')
	{
		*(int*)pt = (int)*(float*)pt;
		*(BYTE*)(pt - 4) = 'i';
	}

}

inline void INS_2001(DWORD ptNowObj, DWORD ptINS)
{
	int pt;
	if (*(BYTE*)(ptINS + 11) == 0) {
		pt = (int)getPtrArgSt(ptNowObj, -1);
	}
	else {
		pt = (int)getPtrArgSt(ptNowObj, -autoGetArgIntB(ptNowObj, 0));
	}
	if (*(BYTE*)(pt - 4) == 'i')
	{
		*(float*)pt = (float)*(int*)pt;
		*(BYTE*)(pt - 4) = 'f';
	}
}

inline void INS_2002(DWORD ptNowObj, DWORD ptINS)
{
	int pt;
	if (*(BYTE*)(ptINS + 11) == 0) {
		pt = (int)getPtrArgSt(ptNowObj, -1);
	}
	else {
		pt = (int)getPtrArgSt(ptNowObj, -autoGetArgIntB(ptNowObj, 0));
	}
	*(BYTE*)(pt - 4) = 'i';
}

inline void INS_2003(DWORD ptNowObj, DWORD ptINS)
{
	int pt;
	if (*(BYTE*)(ptINS + 11) == 0) {
		pt = (int)getPtrArgSt(ptNowObj, -1);
	}
	else {
		pt = (int)getPtrArgSt(ptNowObj, -autoGetArgIntB(ptNowObj, 0));
	}
	*(BYTE*)(pt - 4) = 'f';
}

inline void INS_2004(DWORD ptNowObj)
{
	int pt = (int)getPtrEsp(ptNowObj);
	*(int*)pt = *getValueOfESP(ptNowObj);
	*(BYTE*)(pt - 4) = 'i';
	autoSubESP(ptNowObj, -1);
}

inline void INS_2005(DWORD ptNowObj)
{
	int pt1 = (int)getPtrArgSt(ptNowObj, -autoGetArgIntB(ptNowObj, 0));
	int pt2 = (int)getPtrEsp(ptNowObj);
	*(int*)pt2 = *(int*)pt1;
	*(BYTE*)(pt2 - 4) = *(BYTE*)(pt1 - 4);
	autoSubESP(ptNowObj, -1);
}

inline void INS_2006(DWORD ptNowObj)
{
	int pt1 = (int)getPtrArgSt(ptNowObj, -autoGetArgIntB(ptNowObj, 0));
	int pt2 = (int)getPtrArgSt(ptNowObj, -1);
	if (*(BYTE*)(pt1 - 4) == 'f')
	{
		if (*(BYTE*)(pt2 - 4) == 'i')
			*(float*)pt1 = (float) *(int*)pt2;
		else
			*(float*)pt1 = *(float*)pt2;
	}
	else {
		if (*(BYTE*)(pt2 - 4) == 'f')
			*(int*)pt1 = (int) *(float*)pt2;
		else
			*(int*)pt1 = *(int*)pt2;
	}
	autoSubESP(ptNowObj, 1);
}

inline void INS_STACK_CALC_FLOAT_RET_FLOAT(int code, DWORD ptNowObj)
{
	float arg = getFloatArgSt(ptNowObj, -1);
	switch (code)
	{
	case 2013:
		arg = arg * 57.295780f;
		break;
	case 2014:
		arg = arg / 57.295780f;
		break;
	case 2015:
		arg = logf(arg);
		break;
	case 2016:
		arg = log2f(arg);
		break;
	case 2017:
		arg = powf(getFloatArgSt(ptNowObj, -2), arg);
		autoSubESP(ptNowObj, 1);
		break;
	case 2020:
		if (arg > EPS) arg = 1.0f;
		else if (arg < -EPS) arg = -1.0f;
		else arg = 0.0f;
		break;
	case 2021:
		arg = tanf(arg);
		break;
	case 2022:
		arg = asinf(arg);
		break;
	case 2023:
		arg = acosf(arg);
		break;
	case 2024:
		arg = atanf(arg);
		break;
	case 2031:
		arg = fmodf(getFloatArgSt(ptNowObj, -2), arg);
		autoSubESP(ptNowObj, 1);
		break;
	case 2033:
		arg = fabsf(arg);
		break;
	case 2036:
		if (autoGetArgIntB(ptNowObj, 0) >= 0)//保留较大数
		{
			arg = max(arg, getFloatArgSt(ptNowObj, -2));
		}
		else {
			arg = min(arg, getFloatArgSt(ptNowObj, -2));
		}
		autoSubESP(ptNowObj, 1);
		break;
	case 2039://虽然应该放在i ret f里面,反正是bool
		if (arg == 0.000000f)arg = autoGetArgFloatB(ptNowObj, 0);
		else arg = autoGetArgFloatB(ptNowObj, 1);
		break;
	}
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = arg;
	*(BYTE*)(pt - 4) = 'f';
}

inline void INS_STACK_CALC_INT_RET_INT(int code, DWORD ptNowObj)
{
	int arg = getIntArgSt(ptNowObj, -1);
	switch (code)
	{
	case 2018:
		arg = fastPow(getIntArgSt(ptNowObj, -2), arg);
		autoSubESP(ptNowObj, 1);
		break;
	case 2019:
		if (arg > 0)arg = 1;
		else if (arg < 0)arg = -1;
		break;
	case 2026:
		arg >>= getIntArgSt(ptNowObj, -2);
		autoSubESP(ptNowObj, 1);
		break;
	case 2027:
		arg = (unsigned int)arg >> (unsigned int)getIntArgSt(ptNowObj, -2);
		autoSubESP(ptNowObj, 1);
		break;
	case 2028:
		arg <<= getIntArgSt(ptNowObj, -2);
		autoSubESP(ptNowObj, 1);
		break;
	case 2032:
		arg = abs(arg);
		break;
	case 2035:
		if (autoGetArgIntB(ptNowObj, 0) >= 0)//保留较大数
		{
			arg = max(arg, getIntArgSt(ptNowObj, -2));
		}
		else {
			arg = min(arg, getIntArgSt(ptNowObj, -2));
		}
		autoSubESP(ptNowObj, 1);
		break;
	case 2037:
		if (arg == 0)arg = -1;
		else arg = 1;
		break;
	case 2038:
		if (arg == 0)arg = autoGetArgIntB(ptNowObj, 0);
		else arg = autoGetArgIntB(ptNowObj, 1);
		break;
	}
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(int*)pt = arg;
	*(BYTE*)(pt - 4) = 'i';
}

inline void INS_STACK_CALC_VOID_RET_INT(int code, DWORD ptNowObj)
{
	int ret;
	switch (code)
	{
	case 2029:
		ret = autoGetArgIntB(ptNowObj, 0);
		ret <<= 16;
		ret = (unsigned int)ret >> 16;
		break;
	case 2030:
		ret = autoGetArgIntB(ptNowObj, 0);
		ret = (unsigned int)ret >> 16;
		break;
		//以下为21xx>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	case 2105:
		ret = (int)autoGetPtrArgIntB(ptNowObj, 0);
		break;
	case 2106:
		ret = (int)getPtrArgSt(ptNowObj, autoGetArgIntB(ptNowObj, 0));
		break;
	case 2107:
		ret = *(int*)(autoGetArgIntB(ptNowObj, 0) + autoGetArgIntB(ptNowObj, 1)*autoGetArgIntB(ptNowObj, 2));
		break;
	case 2300:
		ret = *(DWORD*)0x004E6F28;
		break;
	}
	int pt = (int)getPtrEsp(ptNowObj);
	*(int*)pt = ret;
	*(BYTE*)(pt - 4) = 'i';
	autoSubESP(ptNowObj, -1);
}

inline void INS_STACK_CALC_VOID_RET_FLOAT(int code, DWORD ptNowObj)
{
	float ret;
	switch (code)
	{
	case 2025:
		ret = atan2f(autoGetArgFloatB(ptNowObj, 1), autoGetArgFloatB(ptNowObj, 0));
		break;
		//以下为21xx>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	case 2108:
		ret = *(float*)(autoGetArgIntB(ptNowObj, 0) + autoGetArgIntB(ptNowObj, 1)*autoGetArgIntB(ptNowObj, 2));
		break;
	}
	int pt = (int)getPtrEsp(ptNowObj);
	*(float*)pt = ret;
	*(BYTE*)(pt - 4) = 'f';
	autoSubESP(ptNowObj, -1);
}

inline void INS_2150(DWORD ptINS, DWORD ptNowObj)
{
	int ptStr1 = ptINS + 0x10;
	int len1 = *(int*)ptStr1;
	ptStr1 += 4;
	int ptStr2 = ptStr1 + len1 + 4;
	HMODULE hm = GetModuleHandleA((LPCSTR)ptStr1);
	FARPROC ret = GetProcAddress(hm, (LPCSTR)ptStr2);
	int pt = (int)getPtrEsp(ptNowObj);
	*(int*)pt = (int)ret;
	*(BYTE*)(pt - 4) = 'i';
	autoSubESP(ptNowObj, -1);
}

inline void INS_2151(DWORD* obj, DWORD ptNowObj)
{
	int pt = autoGetArgIntB(ptNowObj, 0);
	ptNowObj -= 0x10;
	__asm {
		mov ecx, obj
		mov edx, ptNowObj
		call pt
	}
}

inline void INS_2109(DWORD ptNowObj, DWORD ptINS)
{
	int* pt_p = (int*)autoGetArgIntB(ptNowObj, 0);
	int n = autoGetArgIntB(ptNowObj, 1);
	DWORD type = autoGetArgIntB(ptNowObj, 2);
	int pt = (int)getPtrEsp(ptNowObj);
	autoSubESP(ptNowObj, -n);
	for (int i = 1; i <= n; i++, pt_p++, pt += 8)
	{
		*(int*)pt = *pt_p;
		if (type & 1 << (i - 1)) {//为float
			*(BYTE*)(pt - 4) = 'f';
		}
		else {
			*(BYTE*)(pt - 4) = 'i';
		}
	}
	if (autoGetPtrArgIntB(ptNowObj, 3) && (*(int*)(ptINS + 8) & 1))
	{
		*autoGetPtrArgIntB(ptNowObj, 0) += n * 4;
	}
}

inline void INS_2110(DWORD ptNowObj)
{
	int n = autoGetArgIntB(ptNowObj, 1);
	int* pt_p = (int*)autoGetArgIntB(ptNowObj, 0) + n-1;
	DWORD type = autoGetArgIntB(ptNowObj, 2);
	int pt = (int)getPtrEsp(ptNowObj)-8;
	autoSubESP(ptNowObj, n);
	int one = 1 << n;
	for (int i = 1; i <= n; i++, pt_p--, pt -= 8)
	{
		if (type & one>>i) {//为float
			if (*(BYTE*)(pt - 4) == 'f')//也是float
			{
				*(float*)(pt_p) = *(float*)pt;
			}
			else
			{
				*(float*)(pt_p) = (float)*(int*)pt;
			}
		}else {
			if (*(BYTE*)(pt - 4) == 'i')
			{
				*(int*)(pt_p) = *(int*)pt;
			}
			else
			{
				*(int*)(pt_p) = (int)*(float*)pt;
			}
		}
	}
}

inline void INS_2111(DWORD ptNowObj)
{
	int* pt_p = (int*)autoGetPtrArgIntB(ptNowObj, 0);
	int n = autoGetArgIntB(ptNowObj, 1);
	DWORD type = autoGetArgIntB(ptNowObj, 2);
	int pt = (int)getPtrEsp(ptNowObj);
	autoSubESP(ptNowObj, -n);
	for (int i = 1; i <= n; i++, pt_p++, pt += 8)
	{
		*(int*)pt = *pt_p;
		if (type & 1 << (i - 1)) {//为float
			*(BYTE*)(pt - 4) = 'f';
		}
		else {
			*(BYTE*)(pt - 4) = 'i';
		}
	}
}

inline void INS_2112(DWORD ptNowObj)
{
	int n = autoGetArgIntB(ptNowObj, 1);
	int* pt_p = (int*)autoGetPtrArgIntB(ptNowObj, 0) + n-1;
	DWORD type = autoGetArgIntB(ptNowObj, 2);
	int pt = (int)getPtrEsp(ptNowObj)-8;
	autoSubESP(ptNowObj, n);
	int one = 1 << n;
	for (int i = 1; i <= n; i++, pt_p--, pt -= 8)
	{
		if (type & one>>i) {//为float
			if (*(BYTE*)(pt - 4) == 'f')//也是float
			{
				*(float*)(pt_p) = *(float*)pt;
			}
			else
			{
				*(float*)(pt_p) = (float)*(int*)pt;
			}
		}else {
			if (*(BYTE*)(pt - 4) == 'i')
			{
				*(int*)(pt_p) = *(int*)pt;
			}
			else
			{
				*(int*)(pt_p) = (int)*(float*)pt;
			}
		}
	}
}

inline void INS_2400(DWORD* obj)
{
	*(int*)((int)obj + 0x4518) = autoGetArgIntA(obj, 0);
	*(int*)((int)obj + 0x451C) = 0;
}

inline void INS_2102(DWORD ptINS, DWORD ptNowObj)
{
	if (*(BYTE*)(ptINS + 11) == 0)//没有变量
	{
		**(int**)getPtrArgSt(ptNowObj, -2) = getIntArgSt(ptNowObj, -1);
		autoSubESP(ptNowObj, 2);
	}
	else {
		*(int*)autoGetArgIntB(ptNowObj, 0) = getIntArgSt(ptNowObj, -1);
		autoSubESP(ptNowObj, 1);
	}
}

inline void INS_2103(DWORD ptINS, DWORD ptNowObj)
{
	if (*(BYTE*)(ptINS + 11) == 0)//没有变量
	{
		**(float**)getPtrArgSt(ptNowObj, -2) = getFloatArgSt(ptNowObj, -1);
		autoSubESP(ptNowObj, 2);
	}
	else {
		*(float*)autoGetArgIntB(ptNowObj, 0) = getFloatArgSt(ptNowObj, -1);
		autoSubESP(ptNowObj, 1);
	}
}

inline void INS_2104(DWORD ptINS, DWORD ptNowObj)
{
	if (*(BYTE*)(ptINS + 11) == 0)//没有变量
	{
		**(int**)getPtrArgSt(ptNowObj, -2) = *(int*)getPtrArgSt(ptNowObj, -1);
		autoSubESP(ptNowObj, 2);
	}
	else {
		*(int*)autoGetArgIntB(ptNowObj, 0) = *(int*)getPtrArgSt(ptNowObj, -1);
		autoSubESP(ptNowObj, 1);
	}
}

inline void INS_2333(DWORD* ptNowObj)
{
	return;
}

inline void INS_2113(DWORD ptNowObj)
{
	*(int*)(autoGetArgIntB(ptNowObj, 0)+ autoGetArgIntB(ptNowObj, 1)*autoGetArgIntB(ptNowObj, 2))=getIntArgSt(ptNowObj,-1);
	autoSubESP(ptNowObj, 1);
}

inline void INS_2114(DWORD ptNowObj)
{
	*(float*)(autoGetArgIntB(ptNowObj, 0) + autoGetArgIntB(ptNowObj, 1)*autoGetArgIntB(ptNowObj, 2)) = getFloatArgSt(ptNowObj, -1);
	autoSubESP(ptNowObj, 1);
}