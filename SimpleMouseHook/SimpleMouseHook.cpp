// SimpleMouseHook.cpp : Defines the entry point for the console application.
//

#include "main.h"
#include "MouseHook.h"
#include <thread>

void MouseHookFunc();

int main()
{
	cout << "hello" << endl;

	thread mouseThread(MouseHookFunc);

	getchar();

    return 0;
}

void MouseHookFunc()
{
	MouseHook myHook;
	myHook.Init();
	myHook.Messages();
}