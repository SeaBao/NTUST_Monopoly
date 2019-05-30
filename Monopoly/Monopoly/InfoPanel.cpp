#include "InfoPanel.h"
#include "Utility.h"
#include "GameMap.h"
#include <iostream>

InfoPanel PlayerPanel;

InfoPanel::InfoPanel()
{

}

void InfoPanel::PrintPanel()
{
	auto cuurentPos = GetCursorPosition();
	ShowConsoleCursor(false);

	int maxWidth = 40, maxHeight = 10;
	const int whiteText = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	const int clrSelection[4] = { BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,
								  BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY };

	for (int y = 0; y <= maxHeight; y++) {
		for (int x = 98; x <= 98 + maxWidth; x += 2) {
			SetCursorPosistion(x, y);
			if (y == 0 || y == 10) {
				wcout << L"שש ";
			}
			else if (y == 1 && x != 98) {
				for (int i = 0; i < 4; i++) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clrSelection[i] | whiteText);
					wcout << '1' + i - '0';
					wcout << L"        ";
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), whiteText);
				break;
			}
			else {
				wcout << L"  ";
			}
		}
	}

	for (auto p : TheMap.PlayerList) {
		SetCursorPosistion(100 + p.ID * 9, 2);
		wcout << "$" << p.Money;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), whiteText);
	ShowConsoleCursor(true);
	SetCursorPosistion(cuurentPos.X, cuurentPos.Y);
}

