// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "INS.h"
#include "D3D9N.h"

HMODULE g_d3d9Module = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		TCHAR DLLPath[MAX_PATH];
    case DLL_PROCESS_ATTACH:

		//借用xfgryujkDalao的一段代码
		/*
		GetEnvironmentVariable(_T("windir"), DLLPath, MAX_PATH);
		_tcscat_s(DLLPath, _T("\\System32\\d3d9.dll"));
		g_d3d9Module = LoadLibrary(DLLPath);
		RealDirect3DCreate9 = (Direct3DCreate9Type)GetProcAddress(g_d3d9Module, "Direct3DCreate9");
		if (RealDirect3DCreate9 == NULL)
		{
			MessageBox(NULL, _T("获取Direct3DCreate9地址失败"), DLLPath, MB_OK);
			return FALSE;
		}*/
		MessageBox(NULL, _T("注入成功"), _T("来自INS_PLUS(d3d9.dll)2"), MB_OK);
		init();

		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

