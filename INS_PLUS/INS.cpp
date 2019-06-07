#include "stdafx.h"
#include "INS.h"
#include "dmAndObj.h"
#include "ECLcaculation.h"
int testVal=0;
void INS_2333(DWORD* ptNowObj)
{
	char w[20];
	testVal++;
	testVal %= 5;
	int u=testVal;
	int flag = 0;
	sprintf_s(w, "_%d.sht", u);
	int ptw = (int)w;
	int ptthis=*(int*)0x004e9bb8;
	int ptdel=*(int*)(*(int*)0x004E9BB8+0x2c008);
	_asm
	{
		mov eax,ptdel
		push eax
		mov eax,0x004904C4
		call eax
		pop eax

		mov eax, ptw
		push eax
		mov ecx, ptthis
		mov eax,0x00455a20
		call eax
		mov flag, eax
	}
	if (!flag)
	{
		
		int poweru= *(int*)0x004E7440;
		int power = (poweru+150)%400;
		*(DWORD*)0x004E7440 = power;
		__asm
		{
			mov ecx, DWORD_PTR[0x004E9BB8]
			mov eax, 0x004567B0
			call eax
		}
		power = poweru;
		*(DWORD*)0x004E7440 = power;
		__asm
		{
			mov ecx, DWORD_PTR[0x004E9BB8]
			mov eax, 0x004567B0
			call eax
		}
	}
		return;

	return;
}

void  init()
{
	*(DWORD*)(0x00526000) = (DWORD)INS_Switch;
	*(DWORD*)(0x00526050) = (DWORD)shapes;

	{
		DWORD addr= 0x00526010;
		*(DWORD*)(0x00455A89) = addr;//修改加载位置
		*(DWORD*)(addr + 0x0) = 0x00000000;//0
		*(DWORD*)(addr + 0x4) = 0x004599C0;//1
		*(DWORD*)(addr + 0x8) = 0x00459DB0;//2
		*(DWORD*)(addr + 0xC) = 0x0045AA10;//3
		*(DWORD*)(addr + 0x10) = 0x0045AEF0;//4
		*(DWORD*)(addr + 0x14) = 0x0045B010;//5		
		*(DWORD*)(addr + 0x18) = (DWORD)playerDm_flag1;//6	
		*(DWORD*)(addr + 0x8) = (DWORD)playerDm_flag1;//2
	}//伪造虚表,flag1
	{
		DWORD addr = 0x00526030;
		*(DWORD*)(0x00455A96) = addr;//修改加载位置
		*(DWORD*)(addr + 0x0) =  0x00000000;//0
		*(DWORD*)(addr + 0x4) =  0x004599D0;//1
		*(DWORD*)(addr + 0x8) =  0x00459E10;//2
		*(DWORD*)(addr + 0xC) =  0x0045A780;//3
		*(DWORD*)(addr + 0x10) = 0x0045AA20;//4
		//*(DWORD*)(addr + 0x14) = (DWORD)playerDm_flag2;//5	
		*(DWORD*)(addr + 0x8) = (DWORD)playerDm_flag2;//2 使用
	}//伪造虚表,flag2
	{
		DWORD addr = 0x00526050;
		*(DWORD*)(0x00455AB0) = addr;//修改加载位置
		*(DWORD*)(addr + 0x0) = 0x00000000;//0
		*(DWORD*)(addr + 0x4) = 0x00459BD0;//1
		*(DWORD*)(addr + 0x8) = 0x0045A180;//2
		*(DWORD*)(addr + 0xC) = 0x0045A7A0;//3
		*(DWORD*)(addr + 0x10) = 0x0045A8E0;//4
		*(DWORD*)(addr + 0x14) = 0x0045ABB0;//5	
		*(DWORD*)(addr + 0x18) = 0x0045AD10;//6
		*(DWORD*)(addr + 0x1C) = (DWORD)playerDm_flag4;//7
	}//伪造虚表,flag4
	
}

int _stdcall INS_Switch(int code, int ptINS, DWORD ptObj,DWORD* _obj)
{
	switch (code)
	{
	case 2000:
		INS_2000(ptObj + 0x10,ptINS);return 1;
	case 2001:
		INS_2001(ptObj + 0x10,ptINS);return 1;
	case 2002:
		INS_2002(ptObj + 0x10, ptINS);return 1;
	case 2003:
		INS_2003(ptObj + 0x10, ptINS);return 1;
	case 2004:
		INS_2004(ptObj + 0x10);return 1;
	case 2005:
		INS_2005(ptObj + 0x10);return 1;
	case 2006:
		INS_2006(ptObj + 0x10);return 1;
	case 2007:
		autoSubESP(ptObj + 0x10, autoGetArgIntB(ptObj + 0x10, 0));return 1;
	case 2013:
	case 2014:
	case 2015:
	case 2016:
	case 2017:
	case 2020:
	case 2021:
	case 2022:
	case 2023:
	case 2024:
	case 2031:
	case 2033:
	case 2036:
	case 2039:
		INS_STACK_CALC_FLOAT_RET_FLOAT(code,ptObj+0x10);return 1;//浮点符号
	case 2018:
	case 2019:
	case 2026:
	case 2027:
	case 2028:
	case 2032:
	case 2035:
	case 2037:
	case 2038:
		INS_STACK_CALC_INT_RET_INT(code, ptObj + 0x10);return 1;//整数符号
	case 2029:
	case 2030:
	case 2105:
	case 2106:
	case 2107:
	case 2300:
		INS_STACK_CALC_VOID_RET_INT(code, ptObj + 0x10); return 1;//int push
	case 2025:
	case 2108:
		INS_STACK_CALC_VOID_RET_FLOAT(code, ptObj + 0x10); return 1;//float push
	case 2034:
		INS_2034(ptObj + 0x10);return 1;
	case 2050://vector的开始
		INS_2050(ptObj + 0x10); return 1;
	case 2051:
		INS_2051(ptObj + 0x10); return 1;
	case 2052:
		INS_2052(ptObj + 0x10); return 1;
	case 2053:
		INS_2053(ptObj + 0x10); return 1;
	case 2054:
		INS_2054(ptObj + 0x10); return 1;
	case 2055:
		INS_2055(ptObj + 0x10); return 1;
	case 2056:
		INS_2056(ptObj + 0x10); return 1;
	case 2057:
		INS_2057(ptObj + 0x10); return 1;
	case 2058:
		INS_2058(ptObj + 0x10); return 1;
	case 2059:
		INS_2059(ptObj + 0x10); return 1;
	case 2060:
		INS_2060(ptObj + 0x10); return 1;
	case 2061:
		INS_2061(ptObj + 0x10); return 1;
	case 2062:
		INS_2062(ptObj + 0x10); return 1;
	case 2063:
		INS_2063(ptObj + 0x10); return 1;
	case 2064:
		INS_2064(ptObj + 0x10); return 1;
	case 2070:
		INS_2070(ptObj + 0x10); return 1;
	case 2071:
		INS_2071(ptObj + 0x10); return 1;
	case 2072:
		INS_2072(ptObj + 0x10); return 1;
	case 2073:
		INS_2073(ptObj + 0x10); return 1;
	case 2074:
		INS_2074(ptObj + 0x10); return 1;
	case 2100:
		if(*(BYTE*)(ptINS+11)==0){//没有变量
			int* pt=getPtrArgSt(ptObj + 0x10,-1);
			*pt = *(int*)(*pt);
		}else{
			int* pt = getPtrEsp(ptObj + 0x10); *(char*)(pt - 1) = 'i';
			*pt=*(int*)autoGetArgIntB(ptObj + 0x10, 0);
			autoSubESP(ptObj + 0x10, -1);
		}return 1;
	case 2101:
		if (*(BYTE*)(ptINS + 11) == 0) {//没有变量
			int* pt = getPtrArgSt(ptObj + 0x10, -1);
			*pt = *(int*)(*pt);
		}else {
			int* pt = getPtrEsp(ptObj + 0x10); *(char*)(pt - 1) = 'f';
			*(float*)pt = *(float*)autoGetArgIntB(ptObj + 0x10, 0);
			autoSubESP(ptObj + 0x10, -1);
		}return 1;
	case 2102:
		INS_2102(ptINS, ptObj + 0x10); return 1;
	case 2103:
		INS_2103(ptINS, ptObj + 0x10); return 1;
	case 2104:
		INS_2104(ptINS, ptObj + 0x10); return 1;
	case 2109:
		INS_2109(ptObj + 0x10,ptINS); return 1;
	case 2110:
		INS_2110(ptObj + 0x10); return 1;
	case 2111:
		INS_2111(ptObj + 0x10); return 1;
	case 2112:
		INS_2112(ptObj + 0x10); return 1;
	case 2113:
		INS_2113(ptObj + 0x10); return 1;
	case 2114:
		INS_2114(ptObj + 0x10); return 1;
	case 2150:
		INS_2150(ptINS, ptObj + 0x10); return 1;
	case 2151:
		INS_2151(_obj, ptObj + 0x10); return 1;
	case 2306:
		*(DWORD*)((DWORD)*(DWORD *)0x004E9BB8 + 0x16220) = 4;return 1;
	case 2307:
		INS_2307(ptObj + 0x10);return 1;
	case 2308:
		INS_2308(ptObj + 0x10);return 1;
	case 2309:
		INS_2309(ptObj + 0x10);return 1;
	case 2310:
		INS_2310(ptObj + 0x10);return 1;
	case 2311:
		INS_2311(ptObj + 0x10);return 1;
	case 2400:
		INS_2400(_obj); return 1;
	case 2410:
		INS_2410(ptObj + 0x10); return 1;
	case 2411:
		INS_2411(ptObj + 0x10); return 1;
	case 2412:
		INS_2412(ptObj + 0x10,ptINS); return 1;
	case 2413:
		INS_2413(ptObj + 0x10); return 1;
	case 2414:
		INS_2414(ptObj + 0x10); return 1;
	case 2415:
		INS_2415(ptObj + 0x10); return 1;
	case 2416:
		INS_2416(ptObj + 0x10); return 1;
	case 2417:
		INS_2417(ptObj + 0x10); return 1;
	case 2418:
		INS_2418(ptObj + 0x10); return 1;
	case 2333:
		INS_2333(_obj);
		/*MessageBox(nullptr, _T("2333"), _T("来自INS_PLUS.dll"), MB_OK);*/
		return 1;
	case 2500:
		INS_2500(ptObj + 0x10); return 1;
	case 2501:
		INS_2501(ptObj + 0x10); return 1;
	case 2502:
		INS_2502(ptObj + 0x10); return 1;
	case 2503:
		INS_2503(ptObj + 0x10); return 1;
	case 2504:
		INS_2504(ptObj + 0x10); return 1;
	case 2505:
		INS_2505(ptObj + 0x10); return 1;
	case 2506:
		INS_2506(ptObj + 0x10); return 1;
	case 2507:
		INS_2507(ptObj + 0x10); return 1;
	case 2508:
		INS_2508(ptObj + 0x10); return 1;
	case 2509:
		INS_2509(ptObj + 0x10); return 1;
	case 2510:
		INS_2510(ptObj + 0x10); return 1;
	case 2511:
		INS_2511(ptObj + 0x10); return 1;
	case 2512:
		INS_2512(ptObj + 0x10); return 1;
	case 2513:
		INS_2513(ptObj + 0x10); return 1;
	case 2514:
		INS_2514(ptObj + 0x10); return 1;
	case 2515:
		INS_2515(ptObj + 0x10); return 1;
	case 2516:
		INS_2516(ptObj + 0x10); return 1;
	case 2517:
		INS_2517(ptObj + 0x10); return 1;
	case 2518:
		INS_2518(ptObj + 0x10); return 1;
	case 2519:
		INS_2519(ptObj + 0x10); return 1;
	case 2520:
		INS_2520(ptObj + 0x10); return 1; 
	case 2521:
		INS_2521(ptObj + 0x10); return 1;
	case 2522:
		INS_2522(ptObj + 0x10); return 1;
	case 2523:
		INS_2523(ptObj + 0x10); return 1;
	case 2524:
		INS_2524(ptObj + 0x10); return 1;
	case 2525:
		INS_2525(ptObj + 0x10); return 1;
	case 2530:
		INS_2530(ptObj + 0x10); return 1;
	case 2531:
		INS_2531(ptObj + 0x10); return 1;
	case 2532:
		INS_2532(ptObj + 0x10); return 1;
	case 2533:
		INS_2533(ptObj + 0x10); return 1;
	case 2534:
		INS_2534(ptObj + 0x10); return 1;
	case 2535:
		INS_2535(ptObj + 0x10); return 1;
	case 2536:
		INS_2536(ptObj + 0x10); return 1;
	case 2537:
		INS_2537(ptObj + 0x10); return 1;
	case 2538:
		INS_2538(ptObj + 0x10); return 1;
	case 2539:
		INS_2539(ptObj + 0x10); return 1;
	case 2540:
		INS_2540(ptObj + 0x10); return 1;
	case 2541:
		INS_2541(ptObj + 0x10); return 1;
	case 2542:
		INS_2542(ptObj + 0x10); return 1;
	case 2543:
		INS_2543(ptObj + 0x10); return 1;
	case 2544:
		INS_2544(ptObj + 0x10); return 1;
	case 2545:
		INS_2545(ptObj + 0x10); return 1;
	case 2546:
		INS_2546(ptObj + 0x10); return 1;
	default:
		return 0;
	}
	return 0;
}



