#include "stdafx.h"
#include "test.h"

int _fastcall playerDm(DWORD ptDm)//这个是每帧都会执行的(
{
	int pt = 0x004E9A80;
	pt = *(int*)(*(int*)pt + 0x180);
	int ptr;
	float nx = *(float*)(ptDm + 0x48);
	float ny = *(float*)(ptDm + 0x4C);
	float tx = 0, ty = 0;
	while (*(int*)(pt + 4) != 0)
	{
		pt = *(int*)(pt + 4);
		ptr = *(int*)pt;
		float x, y;
		x = *(float*)(ptr + 0x1250);
		y = *(float*)(ptr + 0x1254);//获得敌人x,y
		float mx = x - nx, my = y - ny;
		float m = mx * mx + my * my;
		tx += mx / m * 3;
		ty += my / m * 3;
	}
	tx += *(float*)(ptDm + 0x60)*cosf(*(float*)(ptDm + 0x64));
	ty += *(float*)(ptDm + 0x60)*sinf(*(float*)(ptDm + 0x64));
	*(float*)(ptDm + 0x60) = sqrtf(tx*tx + ty * ty);
	*(float*)(ptDm + 0x64) = atan2f(ty, tx);
	return 0;
}

int _fastcall playerDm2(DWORD ptDm)
{
	/*int* d = (int*)(ptDm + 0xAC);
	*(int*)(ptDm + 0x9C) = 100;
	*d = 0;
	float w;
	__asm
	{
	mov ecx, [0x004E9A48]
	mov eax, 0x00403840
	call eax
	fstp w
	}
	w *= 3.1415927f;
	*(float*)(ptDm + 0x64) = w;*/
	return 0;
}