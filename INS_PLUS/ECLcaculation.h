#pragma once
#include "stdafx.h"
#include "objArg.h"

void inline INS_2050(DWORD ptNowObj);
void inline INS_2051(DWORD ptNowObj);
void inline INS_2052(DWORD ptNowObj);
void inline INS_2053(DWORD ptNowObj);
void inline INS_2054(DWORD ptNowObj);
void inline INS_2055(DWORD ptNowObj);
void inline INS_2056(DWORD ptNowObj);
void inline INS_2057(DWORD ptNowObj);
void inline INS_2058(DWORD ptNowObj);
void inline INS_2059(DWORD ptNowObj);
void inline INS_2060(DWORD ptNowObj);
void inline INS_2061(DWORD ptNowObj);
void inline INS_2062(DWORD ptNowObj);
void inline INS_2063(DWORD ptNowObj);
void inline INS_2064(DWORD ptNowObj);
void inline INS_2070(DWORD ptNowObj);
void inline INS_2071(DWORD ptNowObj);
void inline INS_2072(DWORD ptNowObj);
void inline INS_2073(DWORD ptNowObj);
void inline INS_2074(DWORD ptNowObj);

void inline INS_2050(DWORD ptNowObj)
{
	float a=getFloatArgSt(ptNowObj, -1);
	float b=getFloatArgSt(ptNowObj, -2);
	float c=getFloatArgSt(ptNowObj, -3);
	float d=getFloatArgSt(ptNowObj, -4);
	autoSubESP(ptNowObj, 2);
	a += c; b += d;
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = a;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = b;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2051(DWORD ptNowObj)
{
	float a = getFloatArgSt(ptNowObj, -1);
	float b = getFloatArgSt(ptNowObj, -2);
	float c = getFloatArgSt(ptNowObj, -3);
	float d = getFloatArgSt(ptNowObj, -4);
	autoSubESP(ptNowObj, 2);
	a -= c; b -= d;
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = a;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = b;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2052(DWORD ptNowObj)
{
	float a = getFloatArgSt(ptNowObj, -1);
	float b = getFloatArgSt(ptNowObj, -2);
	float c = getFloatArgSt(ptNowObj, -3);
	autoSubESP(ptNowObj, 1);
	b *= a; c *= a;
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = b;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = c;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2053(DWORD ptNowObj)
{
	float a = 1/getFloatArgSt(ptNowObj, -1);
	float b = getFloatArgSt(ptNowObj, -2);
	float c = getFloatArgSt(ptNowObj, -3);
	autoSubESP(ptNowObj, 1);
	b *= a; c *= a;
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = b;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = c;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2054(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	float y2 = getFloatArgSt(ptNowObj, -3);
	float x2 = getFloatArgSt(ptNowObj, -4);
	autoSubESP(ptNowObj, 3);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = x1 * x2 + y1 * y2;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2055(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	float y2 = getFloatArgSt(ptNowObj, -3);
	float x2 = getFloatArgSt(ptNowObj, -4);
	autoSubESP(ptNowObj, 3);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = x2 * y1 - y2 * x1;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2056(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	autoSubESP(ptNowObj, 1);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = sqrtf(x1*x1+y1*y1);
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2057(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	autoSubESP(ptNowObj, 1);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = atan2f(y1, x1);
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2058(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = -y1;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = -x1;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2059(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	float w = sqrtf(x1*x1 + y1 * y1);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = y1/w;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = x1/w;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2060(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	float y2 = getFloatArgSt(ptNowObj, -3);
	float x2 = getFloatArgSt(ptNowObj, -4);
	autoSubESP(ptNowObj, 3);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(int*)pt = (int)(fabsf(x1-x2)<=EPS && fabsf(y1-y2)<=EPS);
	*(BYTE*)(pt - 4) = 'i';
}

void inline INS_2061(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	float w = sqrtf(x1*x1 + y1 * y1);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = x1;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = y1;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2062(DWORD ptNowObj)
{
	float a = getFloatArgSt(ptNowObj, -1);
	float y1 = getFloatArgSt(ptNowObj, -2);
	float x1 = getFloatArgSt(ptNowObj, -3);
	autoSubESP(ptNowObj, 1);
	float x2 = cosf(a),y2=-sinf(a);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = x1 * y2 + x2 * y1;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = x1 * x2 - y1 * y2;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2063(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = sqrtf(x1*x1 + y1 * y1);
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = atan2f(y1, x1);
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2064(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = y1 * sinf(x1);
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = y1 * cosf(x1);
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2070(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -2);
	autoSubESP(ptNowObj, 1);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = y1;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2071(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	autoSubESP(ptNowObj, 1);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = y1;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2072(DWORD ptNowObj)
{
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = -getFloatArgSt(ptNowObj, -1);
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2073(DWORD ptNowObj)
{
	float y1 = getFloatArgSt(ptNowObj, -1);
	float x1 = getFloatArgSt(ptNowObj, -2);
	float y2 = getFloatArgSt(ptNowObj, -3);
	float x2 = getFloatArgSt(ptNowObj, -4);
	autoSubESP(ptNowObj, 2);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = x1 * y2 + x2 * y1;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = x1 * x2 - y1 * y2;
	*(BYTE*)(pt - 4) = 'f';
}

void inline INS_2074(DWORD ptNowObj)
{
	float y2 = getFloatArgSt(ptNowObj, -1);
	float x2 = getFloatArgSt(ptNowObj, -2);
	float y1 = getFloatArgSt(ptNowObj, -3);
	float x1 = getFloatArgSt(ptNowObj, -4);
	float w = x2 * x2 + y2 * y2;
	autoSubESP(ptNowObj, 2);
	int pt = (int)getPtrArgSt(ptNowObj, -1);
	*(float*)pt = (y1*x2 - x1 * y2) / w;
	*(BYTE*)(pt - 4) = 'f';
	pt -= 8;
	*(float*)pt = (x1*x2 + y1 * y2) / w;
	*(BYTE*)(pt - 4) = 'f';
}