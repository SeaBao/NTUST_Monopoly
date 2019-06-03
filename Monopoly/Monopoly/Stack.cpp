#include "Stack.h"
#include "Utility.h"
#include "Menu.h"
#include "Bank.h"
#include "InfoPanel.h"
#include "GameMap.h"

Stack theStack;


void Stack::printTheScreen()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 98;
	pos.Y = 11;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"        │ 成交價│ 漲跌│ P 1│ P 2│ P 3│ P 4│";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"土豪銀行│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"原民航空│       │     │    │    │    │    │";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"客家集團│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"翻牆通訊│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"維尼製藥│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"國魚廣播│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"高雄旅遊│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"佳豪企業│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┴───────┴─────┴────┴────┴────┴────┘";
}

void Stack::readStackFile(string path)
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	wifstream file;
	file.open(path);

	Stack Stemp;

	if (file.is_open())
	{
		int row = 0;
		wstring line;
		while (getline(file, line))
		{
			row++;
			vector<wstring> store;
			Split(line, store, ' ');

			wstring rate = store[1];
			int temp = stoi(rate);


			Stemp.colorChange(temp);

			pos.X = 108;
			pos.Y = 10 + 2 * row + 1;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[0] << endl;
			pos.X = 116;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[1] << endl;

			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			pos.X = 122;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[2] << endl;
			pos.X = 127;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[3] << endl;
			pos.X = 132;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[4] << endl;
			pos.X = 137;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[5] << endl;
		}
	}
	file.close();
}

void Stack::writeStackFile()
{
	wstringstream s;
	wofstream outStream("Stacks.txt");
	if (outStream.is_open())
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				wstring temp = stackInfo[i][j];
				s << temp;
				if (i == 7 and j == 5) break;
				s << (j == 5 ? "\n" : " ");
			}
		}
	}
	outStream << s.str();
	outStream.close();
}

void Stack::rateChange(string path)
{
	wifstream file;
	file.imbue(locale("zh_TW.UTF-8"));
	file.open(path);
	if (file.is_open())
	{
		int row = 0;
		wstring line;
		vector<wstring> store;
		vector<wstring> upsAndDowns;
		int count = 0;
		while (!file.eof())
		{
			getline(file, line);
			Split(line, store, ' ');

			for (int j = 0; j < 6; j++)
			{
				stackInfo[count][j] = store[j];
			}
			count++;
		}
		for (int i = 0; i <= 7; i++)
		{
			int up = 0 + rand() % 10;
			int down = 0 + rand() % 10;
			int rate = up - down;
			int temp = stoi(stackInfo[i][0]);
			temp += rate;
			stackInfo[i][0] = to_wstring(temp);
			wstring tempw = to_wstring(rate);
			if (rate >= 0)
			{
				tempw.insert(0, L"+");
			}
			upsAndDowns.push_back(tempw);
		}
		for (int i = 0; i < upsAndDowns.size(); i++)
		{
			stackInfo[i][1] = upsAndDowns[i];
		}
		Stack temp;
		temp.writeStackFile();
		temp.printTheScreen();
		temp.readStackFile("Stacks.txt");

	}
	file.close();
}

void Stack::colorChange(int rate)
{
	if (rate >= 0)
	{
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	}
	else
	{
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	}
}

void Stack::buyStacks()
{
	SetCursorPosistion(111, 29);
	wcout << L"請選擇股票";
	char command;
	pos.Y = 13;
	pos.X = 98;
	SetCursorPosistion(pos.X, pos.Y);
	command = _getch();
	while (command != EOF)
	{
		if (command == 80)//down
		{
			if (pos.Y != 27)
			{
				pos.Y += 2;
				SetCursorPosistion(pos.X, pos.Y);
			}
		}
		else if (command == 72)//up
		{
			if (pos.Y !=13)
			{
				pos.Y -= 2;
				SetCursorPosistion(pos.X, pos.Y);
			}
		}
		else if (command == 13)//Enter
		{
			int temp = pos.Y - 12;
			SetCursorPosistion(111, 31);
			wcout << L"購買";
			SetCursorPosistion(119, 31);
			wcout << L"出售";
			pos.X = 111;
			pos.Y = 31;
			SetCursorPosistion(pos.X, pos.Y);
			command = _getch();
			bool buy = true;
			while (command != EOF)
			{
				if (command == 75) //left
				{
					if (pos.X == 119)
					{
						pos.X = 111;
						SetCursorPosistion(pos.X, pos.Y);
					}
				}
				else if (command == 77)
				{
					if (pos.X == 111) //right
					{
						pos.X = 119;
						SetCursorPosistion(pos.X, pos.Y);
					}
				}
				else if (command == 13) //Enter
				{
					if (pos.X == 111)
					{
						buy = true;
						break;
					}
					else
					{
						buy = false;
						break;
					}
				}
				command = _getch();
			}
			if (buy) //選擇購買
			{
				SetCursorPosistion(111, 33);
				wcout << L"請輸入購買張數:";
				int amount;
				cin >> amount;
				int count;
				for (int i = 0, j = 1;; i++)
				{
					if (j == temp)
					{
						count = i;
						break;
					}
					j += 2;
				}
				if (amount * stoi(stackInfo[count][0]) > theBank.AccMoney[TheMap.GetCurrentPlayer().ID])
				{
					SetCursorPosistion(111, 33);
					wcout << "                       ";
					SetCursorPosistion(111, 33);
					wcout << L"!!帳戶餘額不足!!";
					Sleep(500);
					theBank.printWord(0);
					break;
				}
				else
				{
					theBank.AccMoney[TheMap.GetCurrentPlayer().ID] -= amount * stoi(stackInfo[count][0]);
					theBank.printWord(0);
					PlayerPanel.PrintPanel();
					theBank.printMoney();
					stackInfo[count][TheMap.GetCurrentPlayer().ID + 2] = to_wstring(amount + stoi(stackInfo[count][TheMap.GetCurrentPlayer().ID + 2]));
					Stack temp;
					temp.writeStackFile();
					temp.printTheScreen();
					temp.readStackFile("Stacks.txt");
					break;
				}
			}
			else //選擇出售
			{
				SetCursorPosistion(111, 33);
				wcout << L"請輸入出售張數:";
				int amount;
				cin >> amount;
				int count;
				for (int i = 0, j = 1;; i++)
				{
					if (j == temp)
					{
						count = i;
						break;
					}
					j += 2;
				}
				if (amount > stoi(stackInfo[count][TheMap.GetCurrentPlayer().ID + 2]))
				{
					SetCursorPosistion(111, 33);
					wcout << "                       ";
					SetCursorPosistion(111, 33);
					wcout << L"!!股票張數不足!!";
					Sleep(500);
					theBank.printWord(0);
					break;
				}
				else
				{
					theBank.AccMoney[TheMap.GetCurrentPlayer().ID] += amount * stoi(stackInfo[count][0]);
					theBank.printWord(0);
					PlayerPanel.PrintPanel();
					theBank.printMoney();
					stackInfo[count][TheMap.GetCurrentPlayer().ID + 2] = to_wstring(stoi(stackInfo[count][TheMap.GetCurrentPlayer().ID + 2]) - amount);
					Stack temp;
					temp.writeStackFile();
					temp.printTheScreen();
					temp.readStackFile("Stacks.txt");
					break;
				}
			}
		}

		command = _getch();
	}


}