#pragma once

#include "main.h"
#include <Windows.h>

class MouseHook
{
public:

	MSG msg;
	MouseHook();
	~MouseHook();

	void Init();
	int Messages();

};

LRESULT WINAPI MouseCallBack(int nCode, WPARAM wParam, LPARAM lParam);