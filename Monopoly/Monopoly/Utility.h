#pragma once
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

size_t Split(const std::wstring& txt, std::vector<std::wstring>& strs, wchar_t ch);
void SetCursorPosistion(int x, int y);
void SetWindow(int Width, int Height);
void ShowConsoleCursor(bool showFlag);
COORD GetCursorPosition();