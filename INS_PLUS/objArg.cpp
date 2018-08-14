#include "stdafx.h"
#include "objArg.h"

int autoGetArgIntA(DWORD * _obj, int NeedArgN)
{
	int ptNowObj = *(_DWORD *)(_obj[0x112E] + 0xC);
	return autoGetArgIntB(ptNowObj, NeedArgN);
}

int autoGetArgIntB(DWORD ptNowObj, int NeedArgN)
{
	int off_INS; // edx@1
	int SUBnum; // ecx@2
	int ptINS; // edi@3
	signed int ArgValue; // edx@6
	int off_Stack; // eax@10
	off_INS = *(_DWORD *)(ptNowObj + 8);
	if (off_INS == -1 || (SUBnum = *(_DWORD *)(ptNowObj + 4), SUBnum == -1))
		return 0;//抛出错误.jpg
	else
		ptINS = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ptNowObj + 0x1018) + 0x11F8) + 0x8C) + 8 * SUBnum + 4)
		+ off_INS
		+ 0x10;
	if (*(_WORD *)(ptINS + 8) & (1 << NeedArgN))// 如果需要的值不是const
	{
		ArgValue = *(_DWORD *)(ptINS + 4 * NeedArgN + 16);
		if (ArgValue < 0)                         // 如果是堆栈值或者全局变量
		{
			if (ArgValue < -100)   // 如果是全局变量,前半句if似乎没用
			{
				//以防万一这里也用thiscall
				int ptCALL = *(int*)(**(_DWORD **)(ptNowObj + 0x1018) + 4);
				int res;
				__asm
				{
					mov ecx, ptNowObj
					mov ecx, [ecx + 0x00001018]
					push ArgValue
					call ptCALL
					mov res, eax
				}
				return res;
			}
			else {                                         // 如果是堆栈
				off_Stack = 8 * ArgValue + 4 + *(_DWORD *)(ptNowObj + 0x100C);
				if (*(_BYTE *)(off_Stack + ptNowObj + 8) == 'f')
					return (signed int)ffloor(*(float *)(off_Stack + ptNowObj + 0xC));
				return *(_DWORD *)(off_Stack + ptNowObj + 0xC);
			}
		}
		else {                                           // 如果是变量
			return *(_DWORD *)(ArgValue + *(_DWORD *)(ptNowObj + 0x1010) + ptNowObj + 0xC);
		}
	}
	return *(_DWORD *)(ptINS + 4 * NeedArgN + 16);
}

float autoGetArgFloatA(DWORD * _obj, int NeedArgN)
{
	int ptNowObj = *(_DWORD *)(_obj[0x112E] + 0xC);
	return autoGetArgFloatB(ptNowObj, NeedArgN);
}

float autoGetArgFloatB(DWORD ptNowObj, int NeedArgN)
{
	int off_Stack;
	int off_INS = *(_DWORD *)(ptNowObj + 8);
	int SUBnum, ptINS;
	float ArgValue;
	if (off_INS == -1 || (SUBnum = *(_DWORD *)(ptNowObj + 4), SUBnum == -1))
		return 0;//抛出错误.jpg
	ptINS = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ptNowObj + 0x1018) + 0x11F8) + 0x8C) + 8 * SUBnum + 4)
		+ off_INS
		+ 0x10;//获得ins指针
	if (*(_WORD *)(ptINS + 8) & (1 << NeedArgN))//如果是变量
	{
		ArgValue = *(float *)(ptINS + 4 * NeedArgN + 0x10);
		if (ArgValue < 0)//如果是堆栈,全局变量等
		{
			if (ArgValue < -100.0) {//全局变量
									//这里要保存ecx,所以用asm
				int ptCALL = *(int*)(**(_DWORD **)(ptNowObj + 0x1018) + 0xC);
				//(*(int(__stdcall **)(signed int))(**(_DWORD **)(plNowObj + 0x1018) + 4))(ArgValue);
				int IArgValue = (int)ArgValue;
				float res;
				__asm
				{
					push IArgValue
					mov ecx, ptNowObj
					mov ecx, [ecx + 0x00001018]
					call ptCALL
					fstp res
				}
				return res;
			}
			else {//堆栈
				off_Stack = 8 * (int)ArgValue + 4 + *(_DWORD *)(ptNowObj + 0x100C);
				if (*(_BYTE *)(off_Stack + ptNowObj + 8) == 'f')
					return *(float *)(off_Stack + ptNowObj + 0xC);
				return (float)(*(_DWORD *)(off_Stack + ptNowObj + 0xC));
			}
		}
		else {//变量
			return *(float *)((int)ArgValue + *(_DWORD *)(ptNowObj + 0x1010) + ptNowObj + 0xC);
		}
	}
	else {//常量
		return *(float *)(ptINS + 4 * NeedArgN + 0x10);
	}
	return 0;
}

float* autoGetPtrArgFloatA(DWORD* _obj, int NeedArgN)
{
	int ptNowObj = *(_DWORD *)(_obj[0x112E] + 0xC);
	return autoGetPtrArgFloatB(ptNowObj, NeedArgN);
}

float* autoGetPtrArgFloatB(DWORD ptNowObj, int NeedArgN)
{
	int off_INS; // edx@1
	int subNum; // ecx@2
	int ptINS; // edi@3
	off_INS = *(_DWORD *)(ptNowObj + 8);
	if (off_INS == -1 || (subNum = *(_DWORD *)(ptNowObj + 4), subNum == -1))
		return nullptr;
	ptINS = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ptNowObj + 0x1018) + 0x11F8) + 0x8C) + 8 * subNum + 4)
		+ off_INS
		+ 0x10;
	if (*(_WORD *)(ptINS + 8) & (1 << NeedArgN))
	{
		float argValue = *(float*)(ptINS + NeedArgN * 4 + 0x10);
		if (argValue < 0)//不允许使用堆栈,所以一定是全局
		{
			//以防万一这里也用thiscall
			int ptCALL = *(int*)(**(DWORD**)(ptNowObj + 0x1018) + 0x10);

			int IArgValue = (int)argValue;
			float* res;
			__asm
			{
				push IArgValue
				mov ecx, ptNowObj
				mov ecx, [ecx + 0x00001018]
				call ptCALL
				mov res, eax
			}
			return res;
		}//局部
		return (float *)((int)(argValue)+*(_DWORD *)(ptNowObj + 0x1010) + ptNowObj + 0xC);
	}
	return 0;
}

int* autoGetPtrArgIntA(DWORD* _obj, int NeedArgN)
{
	int ptNowObj = *(_DWORD *)(_obj[0x112E] + 0xC);
	return autoGetPtrArgIntB(ptNowObj, NeedArgN);
}

int* autoGetPtrArgIntB(DWORD ptNowObj, int NeedArgN)
{
	int off_INS; // esi@1
	int subNum; // edx@2
	int ptINS; // eax@3
	int argValue; // edx@6
	off_INS = *(_DWORD *)(ptNowObj + 8);
	if (off_INS == -1 || (subNum = *(_DWORD *)(ptNowObj + 4), subNum == -1))
		return nullptr;
	ptINS = off_INS
		+ *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(ptNowObj + 0x1018) + 0x11F8) + 0x8C) + 8 * subNum + 4)
		+ 0x10;
	if (*(_WORD *)(ptINS + 8) & (1 << NeedArgN))
	{
		argValue = *(_DWORD *)(ptINS + 0x10 + NeedArgN * 4);
		if (argValue < 0)
		{
			//以防万一这里也用thiscall
			int ptCALL = *(int*)(**(DWORD**)(ptNowObj + 0x1018) + 0x8);
			int* res;
			__asm
			{
				push argValue
				mov ecx, ptNowObj
				mov ecx, [ecx + 0x00001018]
				call ptCALL
				mov res, eax
			}
			return res;
		}
		return (int *)(argValue + *(_DWORD *)(ptNowObj + 0x1010) + ptNowObj + 0xC);
	}
	return 0;
}
