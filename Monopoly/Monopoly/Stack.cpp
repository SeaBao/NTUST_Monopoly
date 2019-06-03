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
	wcout << L"        �x ������x ���^�x P 1�x P 2�x P 3�x P 4�x";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�g���Ȧ�x       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�����Ţx       �x     �x    �x    �x    �x    �x";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�Ȯa���΢x       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"½��q�T�x       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�����s�Ģx       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�곽�s���x       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�����ȹC�x       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�q�w�w�w�w�t";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�λ����~�x       �x     �x    �x    �x    �x    �x";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�r�w�w�w�w�w�r�w�w�w�w�r�w�w�w�w�r�w�w�w�w�r�w�w�w�w�}";
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
	wcout << L"�п�ܪѲ�";
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
			wcout << L"�ʶR";
			SetCursorPosistion(119, 31);
			wcout << L"�X��";
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
			if (buy) //����ʶR
			{
				SetCursorPosistion(111, 33);
				wcout << L"�п�J�ʶR�i��:";
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
					wcout << L"!!�b��l�B����!!";
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
			else //��ܥX��
			{
				SetCursorPosistion(111, 33);
				wcout << L"�п�J�X��i��:";
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
					wcout << L"!!�Ѳ��i�Ƥ���!!";
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