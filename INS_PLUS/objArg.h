#pragma once
#include "stdafx.h"
int autoGetArgIntA(DWORD * _obj, int NeedArgN);
int autoGetArgIntB(DWORD ptNowObj, int NeedArgN);
int* autoGetPtrArgIntA(DWORD * _obj, int NeedArgN);
float autoGetArgFloatA(DWORD * _obj, int NeedArgN);
float autoGetArgFloatB(DWORD ptNowObj, int NeedArgN);
int* autoGetPtrArgIntB(DWORD ptNowObj, int NeedArgN);
float* autoGetPtrArgFloatA(DWORD * _obj, int NeedArgN);
float* autoGetPtrArgFloatB(DWORD ptNowObj, int NeedArgN);

inline int getPtrObj(DWORD * obj);//通过_obj获得ptObj
inline int* getPtrEsp(DWORD ptNowObj);//获得栈顶地址,超尾注意
inline int* getPtrArgSt(DWORD ptNowObj, int ArgCount);//获得栈顶下某数的地址
inline float getFloatArgSt(DWORD ptNowObj, int ArgCount);//获得栈顶下某数
inline int getIntArgSt(DWORD ptNowObj, int ArgCount);//获得栈顶下某数
inline void autoSubESP(DWORD ptNowObj, int Arg);//将esp减少
inline int* getValueOfESP(DWORD ptNowObj);//获取esp的地址


inline int getPtrObj(DWORD * obj)//通过_obj获得ptObj
{
	return *(_DWORD *)(obj[0x112E] + 0xC);
}

inline int* getPtrEsp(DWORD ptNowObj)//获得栈顶地址
{
	return (int*)(0x10 + *(_DWORD *)(ptNowObj + 0x100C) + ptNowObj);
}

inline int* getPtrArgSt(DWORD ptNowObj, int ArgCount)//获得栈顶下某数的地址
{
	return (int*)(0x10 + *(_DWORD *)(ptNowObj + 0x100C) + ptNowObj + 8 * ArgCount);
}

inline float getFloatArgSt(DWORD ptNowObj, int ArgCount)//获得栈顶下某数
{
	int address = (int)getPtrArgSt(ptNowObj, ArgCount);
	char flag = *(BYTE*)(address - 4);
	if (flag == 'i')
	{
		return (float)(*(int*)address);
	}
	return *(float*)address;
}

inline int getIntArgSt(DWORD ptNowObj, int ArgCount)//获得栈顶下某数
{
	int address = (int)getPtrArgSt(ptNowObj, ArgCount);
	char flag = *(BYTE*)(address - 4);
	if (flag == 'i')
	{
		return *(int*)address;
	}
	return (int)(*(float*)address);
}

inline void autoSubESP(DWORD ptNowObj, int Arg)//将esp减少
{
	*getValueOfESP(ptNowObj) -= Arg * 8;
}

inline int* getValueOfESP(DWORD ptNowObj)//获取esp的地址
{
	return (int*)(ptNowObj + 0x100C);
}