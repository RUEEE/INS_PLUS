#include "stdafx.h"
#include "test.h"
#include"tlhelp32.h"

int _fastcall stageDM()
{
	DWORD ptrdm;
	_asm {
		mov ptrdm, ecx
	}//弹幕指针
	float px,py;
	px = *(float*)(*(DWORD*)(0x004E9BB8) + 0x618);
	py = *(float*)(*(DWORD*)(0x004E9BB8) + 0x61C);
	float x, y, d;
	x = *(float*)(ptrdm + 0xC38);
	y = *(float*)(ptrdm + 0xC3C);
	d = (x - px) * (x - px) + (y - py) * (y - py);
	d += 0.01f;
	float vx, vy;
	vx=*(float*)(ptrdm + 0xC44) += 14.0f*(px-x)/d;
	vy=*(float*)(ptrdm + 0xC48) += 14.0f * (py - y) / d;
	*(float*)(ptrdm + 0xC50) = sqrt(vx*vx+vy*vy);
	*(float*)(ptrdm + 0xC54) = atan2(vy,vx);

	return 0;
}





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
	DWORD  v2 = *(_DWORD*)(*(_DWORD*)((*(DWORD*)0x004E9BB8) + 0x2C008) + 4 * (*(_DWORD*)(ptDm + 0xAC) >> 8) + 0xE0)
		+ 0x58 * (unsigned __int8)(*(_DWORD*)(ptDm + 0xAC));
	
	float* ptr_angle_1 = (float*)(v2 + 20);//魔理沙的激光的角度
	const float posX = ((float) * ((signed int*)(*(DWORD*)0x004E9BB8) + 0x39 * *(_BYTE*)(v2 + 0x20) + 0x178))/128.0f;
	const float posY = ((float) * ((signed int*)(*(DWORD*)0x004E9BB8) + 0x39 * *(_BYTE*)(v2 + 0x20) + 0x179)) / 128.0f;
	float eX = 0, eY = 0, dis = 100000000;
	int pt = 0x004E9A80;
	pt = *(int*)(*(int*)pt + 0x180);
	int ptr;
	float tx = 0, ty = 0;
	float angle;
	int i = 0;
	float pre = *ptr_angle_1;
	while (*(int*)(pt + 4) != 0)
	{
		pt = *(int*)(pt + 4);
		ptr = *(int*)pt;
		DWORD flag = *(DWORD*)(ptr + 0x526c);
		if (flag & 0x21 || flag & 0xc0000000)continue;
		float x, y;
		x = *(float*)(ptr + 0x1250);
		y = *(float*)(ptr + 0x1254);//获得敌人x,y
		if (x <= -200.0f || y <= 0.0f || x>=200.0f || y>=450.0f)continue;//防maple enemy
		float mx = x - posX, my = y - posY;
		if (dis > mx * mx + my * my)//按距离判定
		{
			eX = mx; eY = my;
			dis = mx * mx + my * my;
			i++;
			//break;加上这句:优先集火一个enemy,不加入:优先打最近敌人
		}
		/*
		if (dis > fabsf(atan2(my,mx)- pre))//按角度判定
		{
			eX = mx; eY = my;
			dis = fabsf(atan2(my, mx) - pre);
			i++;
		}*/
	}
	
	if (i == 0)
	{angle = -1.5708f; 
	}else{
		angle =atan2f(eY, eX);
	}
	float uangle;
	if (fabsf(angle - pre) > 3.1415926f)
	{
		uangle = 6.28318f + (angle - pre);
	}else
	{
		uangle = (angle - pre);
	}
	angle = pre + uangle*0.4f;//缓冲器
	*ptr_angle_1 = angle;
	int txl= *(DWORD*)(ptDm +0xB0)-1;
	if (txl >= 256 || txl < 0)
	{
		txl = 0;
	}
	
	*(float*)((char*)(*(DWORD*)0x004E9BB8) + (txl*0x94 + 0xCD98)) = angle;
	*(float*)((char*)(*(DWORD*)0x004E9BB8) +(*(DWORD*)((*(DWORD*)0x004E9BB8)+0xcd88))*0x94 + 0xCD98) = angle;
	//函数0x4571d0内部为初始化角度
	_asm
	{
		pushad
		mov ecx,ptDm
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

