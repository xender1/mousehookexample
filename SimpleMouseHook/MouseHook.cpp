#include "MouseHook.h"

HHOOK m_mouseHook;

MouseHook::MouseHook() 
{
	m_mouseHook = NULL;
}

MouseHook::~MouseHook()
{
	UnhookWindowsHookEx(m_mouseHook);
	m_mouseHook = NULL;
}

void MouseHook::Init()
{
	m_mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseCallBack, NULL, 0);
}

int MouseHook::Messages()
{

	while (msg.message != WM_QUIT) { //while we do not close our application
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1);
	}
	return (int)msg.wParam; //return the messages
}

LRESULT WINAPI MouseCallBack(int nCode, WPARAM wParam, LPARAM lParam)
{
	MSLLHOOKSTRUCT * pMouseStruct = (MSLLHOOKSTRUCT *)lParam;

	if (nCode == 0) { // we have information in wParam/lParam ? If yes, let's check it:
		if (pMouseStruct != NULL) { // Mouse struct contain information?			
			printf_s("Mouse Coordinates: x = %i | y = %i \n", pMouseStruct->pt.x, pMouseStruct->pt.y);
		}

		switch (wParam) {

		case WM_LBUTTONUP: {
			printf_s("LEFT CLICK UP\n");
		//	SetCursorPos(500, 500);
		}break;
		case WM_LBUTTONDOWN: {
			printf_s("LEFT CLICK DOWN\n");
		}break;

		}

	}

	return CallNextHookEx(m_mouseHook, nCode, wParam, lParam);
}