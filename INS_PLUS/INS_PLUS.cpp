// INS_PLUS.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

extern "C"
{
	void API _fastcall dtest(int dm)
	{
		*(float*)(dm + 0x84) =2.0f;
	}
}

extern "C"
{
	void API test()
	{
		/*Sleep(10);*/
		/*int a, b, c, d, e, f, g, h;
		_asm
		{
			mov a, eax
			mov b, ebx
			mov c, ecx
			mov d, edx
			mov e, edi
			mov f, esi
			mov g, esp
			mov h, ebp
		}
		WCHAR w[233];
		wsprintf(w, _T("现在处于API test内\n当前:\neax=0x%x\nebx=0x%x\necx=0x%x\nedx=0x%x\nedi=0x%x\nesi=0x%x\nesp=0x%x\nebp=0x%x\n"), a, b, c, d, e, f, g, h);
		MessageBox(NULL,w, _T("这里是ins_Plus.dll"), MB_OK);
		Sleep(1000);
		return;*/
	}
}
