#include <Windows.h>
#include <iostream>
#include "Utility.h"
using namespace std;

int main() {
	int WindowHeight = 35, WindowWidth = 100;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND consoleWindow = GetConsoleWindow();

	setlocale(LC_ALL, "zh_TW.UTF-8");
	SetConsoleTitle("NTUST Monopoly");
	SetWindow(WindowWidth + 2, WindowHeight + 1);
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	ShowScrollBar(consoleWindow, SB_BOTH, FALSE);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOut, FALSE, &cfi);
	return 0;
}