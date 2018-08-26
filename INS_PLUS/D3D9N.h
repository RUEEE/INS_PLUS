#pragma once
#include "WINDOWS.h"
typedef void* (WINAPI* Direct3DCreate9Type)(UINT SDKVersion);
extern Direct3DCreate9Type RealDirect3DCreate9;