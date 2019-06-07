#include "stdafx.h"
#include "test.h"


int _fastcall playerDm_flag1(DWORD ptDm)//按射击时执行
{
	_asm
	{
		mov ecx, ptDm
		pushad
		mov eax, 0x00459DB0
		call eax
		popad
	}
	return 0;
}
int _fastcall playerDm_flag2(DWORD ptDm)//这个是每帧都会执行的(
{
	DWORD  v2 = *(_DWORD*)(*((_DWORD*)(*(DWORD*)0x004E9BB8) + 45058) + 4 * (*(_DWORD*)(ptDm + 0xAC) >> 8) + 224)
		+ 88 * (unsigned __int8) * (_DWORD*)(ptDm + 0xAC);
	float* ptr_angle_1 = (float*)(v2 + 20);//魔理沙的激光的角度
	float posX = (float) * ((signed int*)(*(DWORD*)0x004E9BB8) + 0x39 * *(_BYTE*)(v2 + 0x20) + 0x178);
	float posY = (float) * ((signed int*)(*(DWORD*)0x004E9BB8) + 0x39 * *(_BYTE*)(v2 + 0x20) + 0x179);
	
	posX /= 128.0f;
	posY /= 128.0f;//激光生成点坐标
	
	float eX = 0, eY = 0, dis = 100000000;
	float hitx = 0, hity = 0;//被弹大小
	int pt = 0x004E9A80;
	pt = *(int*)(*(int*)pt + 0x180);
	int ptr;
	float tx = 0, ty = 0;
	float angle;
	int i = 0;
	while (*(int*)(pt + 4) != 0)
	{
		pt = *(int*)(pt + 4);
		ptr = *(int*)pt;
		float x, y;
		x = *(float*)(ptr + 0x1250);
		y = *(float*)(ptr + 0x1254);//获得敌人x,y
		if (x == 0.0f && y == 0.0f)continue;//防maple enemy
		float mx = x - posX, my = y - posY;
		if (dis > mx * mx + my * my)
		{
			eX = mx; eY = my;
			hitx = *(float*)(ptr + 0x1324);
			hity = *(float*)(ptr + 0x1328);
			dis = mx * mx + my * my;
			i++;
			break;//加上这句:优先集火一个enemy,不加入:优先打最近敌人
		}
	}

	if (i == 0)
	{angle = -1.5708f; 
	}else{
		angle =atan2f(eY, eX);
		angle = (*ptr_angle_1 *2.5f + angle * 1.0f) / 3.5f;//缓冲器
	}
	*ptr_angle_1 = angle;
	for (int i = 0; i <= 256; i++)//不知道要改哪个子机弹幕就把所有的都改一遍.jpg
	{
		*(float*)((char*)(*(DWORD*)0x004E9BB8) + i* 0x94 + 0xCD98) = angle;
	}
	//*(float*)((char*)(*(DWORD*)0x004E9BB8) +(*(DWORD*)((*(DWORD*)0x004E9BB8)+0xcd88))*0x94 + 0xCD98) = angle;
	//函数0x4571d0内部为初始化角度
	_asm
	{
		mov ecx,ptDm
		pushad
		mov eax,0x00459E10
		call eax
		popad
	}
	*(float*)(ptDm + 0x64) = angle;
	return 0;

}

int _fastcall playerDm_flag4(int ptr_char_a1, int float_a2, int a3, int a4, int float_a5)//击中时执行
{
	char* a1 = *(char**)(&ptr_char_a1);
	float a2 = *(float*)(&float_a2);
	float a5 = *(float*)(&float_a5);
	DWORD ret_flag2;
	_asm
	{
		pushad
		mov ecx, ptr_char_a1
		mov edx, float_a2
		push float_a5
		push a4
		push a3
		mov eax, 0x0045A180
		call eax
		mov ret_flag2,eax
		popad
	}
	return *(int*)(&ret_flag2);
}

