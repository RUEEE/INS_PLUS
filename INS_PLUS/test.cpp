#include "stdafx.h"
#include "test.h"
#include"tlhelp32.h"

void _fastcall curve_laser_update1(DWORD ptr_this)
{

	int n = *(DWORD*)(ptr_this + 0x5F4);
	float time = (float)(*(DWORD*)(ptr_this + 0x44));
	DWORD ptr_s;
	float omiga = 6.28318f / n;
	for (int i = n-1; i >=0; i--)
	{
		ptr_s = *(DWORD*)(ptr_this + 0x153C) + i * 0x20;
		float x, y,t;
		t = i*omiga;
		x = (1.5+0.05*cos(0.1*time))*50*cos(t); y = (1.5 + 0.05 * sin(0.1 * time)) * 50 * sin(t);
		y = y + 224;
		*(float*)ptr_s = x;
		*(float*)(ptr_s+4) = y;
		*(float*)(ptr_s + 0x18) = t + 1.57079f;/*贴图角度*/
		float d;
		d= sqrt(
			(x - *(float*)(ptr_s + 0x20)) * (x - *(float*)(ptr_s + 0x20)) +
			(y - *(float*)(ptr_s + 0x24)) * (y - *(float*)(ptr_s + 0x24))
		);
		*(float*)(ptr_s + 0x1C) = d;
		/*判定*/
	}
	return;
}


void _fastcall curve_laser_update(DWORD ptr_this)
{
	int n = *(DWORD*)(ptr_this + 0x5F4);
	int nm = n - 1;
	float *vx = (float*)(ptr_this + 0x1558);
	float *vy = (float*)(ptr_this + 0x155C);
	float time = (float)(*(DWORD*)(ptr_this + 0x44));
	if (time == 0)
	{
		*vx*= *(float*)(ptr_this + 0x1574);
		*vy*= *(float*)(ptr_this + 0x1574);
	}
	DWORD ptr_s;
	for (int i = n-1; i >0; i--)
	{
		ptr_s = *(DWORD*)(ptr_this + 0x153C) + i * 0x20;
		*(float*)(ptr_s) = *(float*)(ptr_s - 0x20);
		*(float*)(ptr_s+0x4) = *(float*)(ptr_s - 0x1C);//x,y
	}
	ptr_s = *(DWORD*)(ptr_this + 0x153C);
	*(float*)(ptr_s) += *vx;
	*(float*)(ptr_s + 0x4) += *vy;

	for (int i = n - 1; i >= 0; i--)
	{
		ptr_s = *(DWORD*)(ptr_this + 0x153C) + i * 0x20;
		float d;
		float x1, x2, y1, y2;
		x1 = *(float*)(ptr_s);
		x2 = *(float*)(ptr_s + 0x20);
		y1 = *(float*)(ptr_s + 0x4);
		y2 = *(float*)(ptr_s + 0x24);
		d = sqrt((x1 - x2)* (x1 - x2)+(y1-y2)* (y1 - y2));
		*(float*)(ptr_s + 0x1C) = d;
		*(float*)(ptr_s + 0x18) = atan2f(y2-y1,x2-x1);
	}/*判定,角度*/
	float px, py, lsx, lsy;
	px = *(float*)(*(DWORD*)(0x004E9BB8) + 0x618);
	py = *(float*)(*(DWORD*)(0x004E9BB8) + 0x61C);
	ptr_s = *(DWORD*)(ptr_this + 0x153C);
	lsx = *(float*)(ptr_s);
	lsy = *(float*)(ptr_s + 0x4);
	float d = sqrt((px - lsx)* (px - lsx) + (py - lsy)* (py - lsy))+0.01f;
	*vx += 0.8f * (px - lsx) / d;
	*vy += 0.8f * (py - lsy) / d;
	return;
}



void curve_laser_update_init()
{
	BYTE *curve_laser_update_h = new BYTE[23]{ 
	0x60, 0xB8,
	0x01, 0x00, 0x00, 0x00,
	0x8B, 0xCE, 0xFF, 0xD0, 0x61, 0x83,0xBE, 0xA4, 0x05, 0x00, 0x00, 0x00, 0xE9,
	0x98, 0x84, 0x3A, 0xF0 };
	DWORD oldP;
	DWORD jmp_addr=(DWORD)(&(curve_laser_update_h[0]))-0x004484A8-5;
	*(BYTE*)(0x004484A8) = 0xE9;
	*(DWORD*)(0x004484A9) = jmp_addr;
	*(BYTE*)(0x004484AD) = 0x90; *(BYTE*)(0x004484AE) = 0x90;
	*(DWORD*)(&(curve_laser_update_h[19]))=0x004484AF- ((DWORD)&(curve_laser_update_h[19]))-5;
	*(DWORD*)(&(curve_laser_update_h[2])) = (DWORD)curve_laser_update;
	VirtualProtect(curve_laser_update_h, sizeof(curve_laser_update_h), PAGE_EXECUTE_READWRITE, &oldP);
	//004483A4:0F8EFE000000->E9FF00000090
	//0044840e : E9
	*(BYTE*)(0x004483A4) = 0xE9;
	*(BYTE*)(0x004483A5) = 0xFF;
	*(BYTE*)(0x004483A6) = 0x00;
	*(BYTE*)(0x004483A7) = 0x00;
	*(BYTE*)(0x004483A8) = 0x00;
	*(BYTE*)(0x004483A9) = 0x90;
	*(BYTE*)(0x0044840E) = 0xE9;
}

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

void test_init()
{
	{
		DWORD addr = 0x00526010;
		*(DWORD*)(0x00455A89) = addr;//修改加载位置
		*(DWORD*)(addr + 0x0) = 0x00000000;//0
		*(DWORD*)(addr + 0x4) = 0x004599C0;//1
		*(DWORD*)(addr + 0x8) = 0x00459DB0;//2
		*(DWORD*)(addr + 0xC) = 0x0045AA10;//3
		*(DWORD*)(addr + 0x10) = 0x0045AEF0;//4
		*(DWORD*)(addr + 0x14) = 0x0045B010;//5		
		//*(DWORD*)(addr + 0x18) = (DWORD)playerDm_flag1;//6	
	}//伪造虚表,flag1
	{
		DWORD addr = 0x00526030;
		*(DWORD*)(0x00455A96) = addr;//修改加载位置
		*(DWORD*)(addr + 0x0) = 0x00000000;//0
		*(DWORD*)(addr + 0x4) = 0x004599D0;//1
		*(DWORD*)(addr + 0x8) = 0x00459E10;//2
		*(DWORD*)(addr + 0xC) = 0x0045A780;//3
		*(DWORD*)(addr + 0x10) = 0x0045AA20;//4
		//*(DWORD*)(addr + 0x14) = (DWORD)playerDm_flag2;//5	
		//*(DWORD*)(addr + 0x8) = (DWORD)playerDm_flag2;//2 使用
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
		//*(DWORD*)(addr + 0x1C) = (DWORD)playerDm_flag4;//7
	}//伪造虚表,flag4
	{
		BYTE opcode[] = {
			0x55, 0x8B, 0xEC, 0x60, 0xB8,
			0x11, 0x11, 0xFF, 0x0F,
			0xFF,0xD0, 0x61, 0xEB, 0x03, 0xEB, 0xF0, 0x90
		};
		int j = 0;
		for (DWORD i = 0x00419382; i <= 0x00419392; i++, j++)
		{
			*(BYTE*)i = opcode[j];
		}
		*(DWORD*)(0x00419387) = (DWORD)stageDM;
	}//修改弹幕帧更新语句
	curve_laser_update_init();
}