#include "mainScreen.h"
#include "Utility.h"

mainScreen theScreen;

void mainScreen::printMainScreen()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	for (int i = 0; i < 37; i++)
	{
		pos.Y = i;
		pos.X = 0;
		SetConsoleCursorPosition(hOut, pos);
		for (int j = 0; j <= 142; j++)
		{
			cout << " ";
		}
	}
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
		pos.X = 76, pos.Y = 0;
		SetConsoleCursorPosition(hOut, pos);
		cout << "    \n";
		pos.X = 72, pos.Y = 1;
		SetConsoleCursorPosition(hOut, pos);
		cout << "           \n";
		pos.X = 68, pos.Y = 2;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                 \n";
		pos.X = 67, pos.Y = 3;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                  \n";
		pos.X = 66, pos.Y = 4;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                 \n";
		pos.X = 65, pos.Y = 5;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                 \n";
		pos.X = 63, pos.Y = 6;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                    \n";
		pos.X = 62, pos.Y = 7;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                     \n";
		pos.X = 60, pos.Y = 8;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                      \n";
		pos.X = 59, pos.Y = 9;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                       \n";
		pos.X = 58, pos.Y = 10;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                       \n";
		pos.X = 57, pos.Y = 11;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                       \n";
		pos.X = 56, pos.Y = 12;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                       \n";
		pos.X = 55, pos.Y = 13;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                        \n";
		pos.X = 54, pos.Y = 14;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                         \n";
		pos.X = 53, pos.Y = 15;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                         \n";
		pos.X = 52, pos.Y = 16;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                          \n";
		pos.X = 52, pos.Y = 17;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                         \n";
		pos.X = 52, pos.Y = 18;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                         \n";
		pos.X = 52, pos.Y = 19;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                         \n";
		pos.X = 51, pos.Y = 20;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                         \n";
		pos.X = 51, pos.Y = 21;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                        \n";
		pos.X = 51, pos.Y = 22;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                       \n";
		pos.X = 53, pos.Y = 23;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                    \n";
		pos.X = 53, pos.Y = 24;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                   \n";
		pos.X = 54, pos.Y = 25;
		SetConsoleCursorPosition(hOut, pos);
		cout << "                 \n";
		pos.X = 55, pos.Y = 26;
		SetConsoleCursorPosition(hOut, pos);
		cout << "              \n";
		pos.X = 55, pos.Y = 27;
		SetConsoleCursorPosition(hOut, pos);
		cout << "             \n";
		pos.X = 59, pos.Y = 28;
		SetConsoleCursorPosition(hOut, pos);
		cout << "        \n";
		pos.X = 61, pos.Y = 29;
		SetConsoleCursorPosition(hOut, pos);
		cout << "      \n";
		pos.X = 62, pos.Y = 30;
		SetConsoleCursorPosition(hOut, pos);
		cout << "     \n";
		pos.X = 62, pos.Y = 31;
		SetConsoleCursorPosition(hOut, pos);
		cout << "     \n";
		pos.X = 62, pos.Y = 32;
		SetConsoleCursorPosition(hOut, pos);
		cout << "    \n";
	}

	{ {
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			pos.X = 3;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ◢███████◣\n";
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ██   ██   ██\n";
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ██   ██   ██\n";
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ██   ██   ██\n";
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ██   ██   ██\n";
			pos.Y = 12;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ██   ██   ██\n";
			pos.Y = 13;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ██   ██   ██\n";
			pos.Y = 14;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"     ◥█   ██   █◤\n";

			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			pos.X = 27;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢█████◣\n";
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 12;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 13;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 14;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◥█████◤\n";

			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			pos.X = 42;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢█\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██████◣\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◥█      █◤\n\n";

			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			pos.X = 57;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN);
			pos.X = 59;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"█████◣\n";
			pos.X = 57;
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 12;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 13;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 14;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◥█████◤\n";

			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
			pos.X = 72;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢████";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			wcout << L"◣\n";
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
			wcout << L"██    ██\n";
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██    ██\n";
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██    ██\n";
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"█████";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			wcout << L"◤\n";
			pos.Y = 12;
			SetConsoleCursorPosition(hOut, pos);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
			wcout << L"██\n";
			pos.Y = 13;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██\n";
			pos.Y = 14;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██◣\n";

			SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			pos.X = 85;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢█████◣\n";
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 12;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 13;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██      ██\n";
			pos.Y = 14;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◥█████◤\n";

			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			pos.X = 100;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢█\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██        ▄\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"███████\n";

			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_INTENSITY);
			pos.X = 115;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢█    █◣\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██    ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██████\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"        ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◢█    ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██    ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"██    ██\n";
			pos.Y++;
			SetConsoleCursorPosition(hOut, pos);
			wcout << L"◥████◤\n";
		}}


	{
		pos.Y = 25;
		pos.X = 114;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		wcout << L"新 的 遊 戲";

		pos.Y = 27;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"規 則 說 明";

		pos.Y = 29;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"讀 取 地 圖";

		pos.Y = 31;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"離 開 遊 戲";

	}

	char command;
	command = _getch();
	pos.Y = 25;
	SetConsoleCursorPosition(hOut, pos);
	while (command != EOF)
	{
		if (command == 80)//down
		{
			if (pos.Y != 31)
			{
				pos.Y += 2;
				printWord(pos.Y);
			}
		}
		if (command == 72)//up
		{
			if (pos.Y != 25)
			{
				pos.Y -= 2;
				printWord(pos.Y);
			}

		}
		if (command == 13)//enter
		{
			if (pos.Y == 25)
			{
				pressStart();
			}
			else if (pos.Y == 27)
			{

			}
			else if (pos.Y == 29)
			{
				pressRead();
			}
			else if (pos.Y == 31)
			{
				exit(1);
			}
		}
		command = _getch();
	}
}

void mainScreen::pressStart()
{

	/*pos.Y = 25;
	pos.X = 126;
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
	wcout << L"請輸入人數:";
	pos.Y = 26;
	pos.X = 126;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"(1~4)";
	pos.Y = 25;
	pos.X = 137;
	SetConsoleCursorPosition(hOut, pos);
	int players;
	cin >> players;*/
	selectPeople();
}

void mainScreen::pressRead()
{
	pos.Y = 25;
	pos.X = 126;
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	wcout << L"台灣地圖";
	pos.Y = 27;
	pos.X = 126;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"其他地圖";
	pos.Y = 25;
	SetConsoleCursorPosition(hOut, pos);
	char command;
	command = _getch();
	while (command != EOF)
	{
		if (command == 80)//down
		{
			if (pos.Y == 25)
			{
				pos.Y += 2;
				SetCursorPosistion(126, pos.Y);
			}
		}
		else if (command == 72)//up
		{
			if (pos.Y == 27)
			{
				pos.Y -= 2;
				SetCursorPosistion(126, pos.Y);
			}
		}
		else if (command == 13)//Enter
		{
			if (pos.Y == 25) //Taiwan
			{
				selectPeople();
			}
			else if (pos.Y == 27) //輸入檔名
			{
				pos.Y = 29;
				pos.X = 126;
				SetConsoleCursorPosition(hOut, pos);
				SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				wcout << L"              ";
				pos.Y = 29;
				pos.X = 126;
				SetConsoleCursorPosition(hOut, pos);
				string fileName;
				cin >> fileName;
				selectPeople();
			}
		}
		command = _getch();
	}
	
}

void mainScreen::pressExp()
{

}

void mainScreen::printWord(int y)
{
	COORD pos;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (y == 27)
	{
		pos.Y = 25;
		pos.X = 114;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"新 的 遊 戲";

		pos.Y = 27;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		wcout << L"規 則 說 明";

		pos.Y = 29;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"讀 取 地 圖";

		pos.Y = 31;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"離 開 遊 戲";
	}
	else if (y == 29)
	{
		pos.Y = 25;
		pos.X = 114;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"新 的 遊 戲";

		pos.Y = 27;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"規 則 說 明";

		pos.Y = 29;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		wcout << L"讀 取 地 圖";

		pos.Y = 31;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"離 開 遊 戲";
	}
	else if (y == 25)
	{
		pos.Y = 25;
		pos.X = 114;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		wcout << L"新 的 遊 戲";

		pos.Y = 27;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"規 則 說 明";

		pos.Y = 29;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"讀 取 地 圖";

		pos.Y = 31;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"離 開 遊 戲";
	}
	else if (y == 31)
	{
		pos.Y = 25;
		pos.X = 114;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"新 的 遊 戲";

		pos.Y = 27;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"規 則 說 明";

		pos.Y = 29;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		wcout << L"讀 取 地 圖";

		pos.Y = 31;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		wcout << L"離 開 遊 戲";
	}
}

void mainScreen::selectPeople()
{
	pos.Y = 29;
	pos.X = 126;
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	wcout << L"選擇人數";
	SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	wcout << "        ";
	pos.Y = 30;
	pos.X = 127;
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, 0 | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	wcout << L"1 2 3 4";
	pos.X = 127;
	SetConsoleCursorPosition(hOut, pos);
	char command;
	command = _getch();
	while (command != EOF)
	{
		if (command == 75)//left
		{
			if (pos.X != 127)
			{
				pos.X -= 2;
				SetConsoleCursorPosition(hOut, pos);
			}
		}
		else if (command == 77)//right
		{
			if (pos.X != 133)
			{
				pos.X += 2;
				SetConsoleCursorPosition(hOut, pos);
			}
		}
		else if (command == 13)//Enter
		{
			if (pos.X == 127) //1人
			{

			}
			else if (pos.X == 129) //2人
			{

			}
			else if (pos.X == 131) //3人
			{

			}
			else if (pos.X == 133) //4人
			{

			}
		}
		command = _getch();
	}

}