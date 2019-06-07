#include "Bank.h"
#include "Utility.h"
#include "Player.h"
#include "GameMap.h"
#include "Menu.h"
#include "Player.h"
#include "InfoPanel.h"
#include "Stack.h"

Bank theBank;

int Bank::AccMoney[4];
int Bank::AccDebt[4];
int Bank::AccPay[4];

void Bank::printMoney()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
	SetCursorPosistion(98, 5);
	wcout << L"債";
	SetCursorPosistion(98, 7);
	wcout << L"還";
	SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	int count = 0;
	for (auto p : TheMap.PlayerList) {
		SetCursorPosistion(100 + p.ID * 9, 3);
		wcout << "$";
		cout << theBank.AccMoney[count];
		SetCursorPosistion(100 + p.ID * 9, 5);
		wcout << "$";
		cout << theBank.AccDebt[count];
		SetCursorPosistion(100 + p.ID * 9, 7);
		wcout << " ";
		cout << theBank.AccPay[count];
		count++;
	}
}

void Bank::readAM()
{
	wifstream input;
	input.open("Banks.txt");
	vector<wstring> store;
	if (input.is_open())
	{
		wstring temp;
		while (input >> temp)
		{
			store.push_back(temp);
		}
	}
	input.close();
}

void Bank::writeAM()
{
	{
		wofstream out("Banks.txt");
		wstringstream s;
		if (out.is_open())
		{
			for (int i = 0; i < 4; i++)
			{
				s << to_wstring(theBank.AccMoney[i]);
				if (i != 3)
				{
					s << " ";
				}
			}
		}
		out << s.str();
		out.close();
	}
	{
		wofstream out("Debts.txt");
		wstringstream s;
		if (out.is_open())
		{
			for (int i = 0; i < 4; i++)
			{
				s << to_wstring(theBank.AccDebt[i]);
				if (i != 3)
				{
					s << " ";
				}
			}
		}
		out << s.str();
		out.close();
	}
	{
		wofstream out("Pays.txt");
		wstringstream s;
		if (out.is_open())
		{
			for (int i = 0; i < 4; i++)
			{
				s << to_wstring(theBank.AccPay[i]);
				if (i != 3)
				{
					s << " ";
				}
			}
		}
		out << s.str();
		out.close();
	}
}

void Bank::printATM()
{
	theMenu.printWord(0);
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	SetCursorPosistion(98, 29);
	wcout << L"1.存款";
	SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	SetCursorPosistion(98, 30);
	wcout << L"2.借款";
	SetCursorPosistion(98, 31);
	wcout << L"3.提款";
	SetCursorPosistion(98, 32);
	wcout << L"4.離開";
	pos.Y = 29;
	SetConsoleCursorPosition(hOut, pos);
	char command;
	command = _getch();
	while (command != EOF)
	{
		if (command == 80)//down
		{
			if (pos.Y != 32)
			{
				pos.Y++;
				SetCursorPosistion(98, pos.Y);
				printWord(pos.Y);
			}
		}
		else if (command == 72)//up
		{
			if (pos.Y != 29)
			{
				pos.Y--;
				SetCursorPosistion(98, pos.Y);
				printWord(pos.Y);
			}
		}
		else if (command == 13)//Enter
		{
			if (pos.Y == 29)//存款
			{
				SetCursorPosistion(105, 29);
				wcout << L"輸入金額:$";
				int money;
				cin >> money;
				while (money > TheMap.GetCurrentPlayer().Money)
				{
					SetCursorPosistion(105, 31);
					wcout << L"        !!餘額不足!!";
					SetCursorPosistion(115, 29);
					wcout << L"          ";
					SetCursorPosistion(105, 29);
					wcout << L"輸入金額:$";
					cin >> money;
				}
				TheMap.GetCurrentPlayer().Money = TheMap.GetCurrentPlayer().Money - money;
				theBank.AccMoney[TheMap.GetCurrentPlayer().ID] += money;
				printWord(0);
				PlayerPanel.PrintPanel();
				theBank.printMoney();
				break;
			}
			else if (pos.Y == 30)//借款
			{
				SetCursorPosistion(105, 29);
				wcout << L"輸入金額:$";
				int money;
				cin >> money;
				TheMap.GetCurrentPlayer().Money = TheMap.GetCurrentPlayer().Money + money;
				theBank.AccDebt[TheMap.GetCurrentPlayer().ID] += money;
				if (theBank.AccPay[TheMap.GetCurrentPlayer().ID] == 0)
				{
					theBank.AccPay[TheMap.GetCurrentPlayer().ID] = 7;
				}
				printWord(0);
				PlayerPanel.PrintPanel();
				theBank.printMoney();
				break;
			}
			else if (pos.Y == 31)//提款
			{
				SetCursorPosistion(105, 29);
				wcout << L"輸入金額:$";
				int money;
				cin >> money;
				while (money > theBank.AccMoney[TheMap.GetCurrentPlayer().ID])
				{
					SetCursorPosistion(105, 31);
					wcout << L"        !!餘額不足!!";
					SetCursorPosistion(115, 29);
					wcout << L"          ";
					SetCursorPosistion(105, 29);
					wcout << L"輸入金額:$";
					cin >> money;
				}
				TheMap.GetCurrentPlayer().Money = TheMap.GetCurrentPlayer().Money + money;
				theBank.AccMoney[TheMap.GetCurrentPlayer().ID] -= money;
				printWord(0);
				PlayerPanel.PrintPanel();
				theBank.printMoney();
				break;
			}
			else if (pos.Y == 32)//離開
			{
				printWord(0);
				break;
			}
		}
		command = _getch();
	}
}

void Bank::printWord(int y)
{
	if (y == 29)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		SetCursorPosistion(98, 29);
		wcout << L"1.存款";
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		SetCursorPosistion(98, 30);
		wcout << L"2.借款";
		SetCursorPosistion(98, 31);
		wcout << L"3.提款";
		SetCursorPosistion(98, 32);
		wcout << L"4.離開";
		SetCursorPosistion(98, 29);
		
	}
	else if (y == 30)
	{
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		SetCursorPosistion(98, 29);
		wcout << L"1.存款";
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		SetCursorPosistion(98, 30);
		wcout << L"2.借款";
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		SetCursorPosistion(98, 31);
		wcout << L"3.提款";
		SetCursorPosistion(98, 32);
		wcout << L"4.離開";
		SetCursorPosistion(98, 30);
	}
	else if (y == 31)
	{
		SetCursorPosistion(98, 29);
		wcout << L"1.存款";
		SetCursorPosistion(98, 30);
		wcout << L"2.借款";
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		SetCursorPosistion(98, 31);
		wcout << L"3.提款";
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		SetCursorPosistion(98, 32);
		wcout << L"4.離開";
		SetCursorPosistion(98, 31);
	}
	else if (y == 32)
	{
		SetCursorPosistion(98, 29);
		wcout << L"1.存款";
		SetCursorPosistion(98, 30);
		wcout << L"2.借款";
		SetCursorPosistion(98, 31);
		wcout << L"3.提款";
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		SetCursorPosistion(98, 32);
		wcout << L"4.離開";
		SetCursorPosistion(98, 32);
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if (y == 0)
	{
		SetConsoleTextAttribute(hOut, 0 | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		SetCursorPosistion(98, 29);
		wcout << L"                                  ";
		SetCursorPosistion(98, 30);
		wcout << L"                                  ";
		SetCursorPosistion(98, 31);
		wcout << L"                                  ";
		SetCursorPosistion(98, 32);
		wcout << L"                                  ";
		SetCursorPosistion(98, 33);
		wcout << L"                                  ";
		SetCursorPosistion(98, 29);
	}
}

void Bank::payDebt()
{
	for (int i = 0; i < 4; i++)
	{
		if (theBank.AccPay[i] == 0)
		{
			int debt = theBank.AccDebt[i];
			theBank.AccDebt[i] = 0;
			if (debt > theBank.AccMoney[i])
			{
				theBank.AccMoney[i] = 0;
				TheMap.PlayerList[i].Money = TheMap.PlayerList[i].Money - (debt - theBank.AccMoney[i]);
			}
			else
			{
				theBank.AccMoney[i] -= debt;
			}
		}
		else
		{
			theBank.AccPay[i]--;
		}
	}
}

void Bank::restore()
{
	for (int i = 0; i < 4; i++)
	{
		AccMoney[i] = 10000;
		AccDebt[i] = 0;
		AccPay[i] = 0;
	}
	wstring temp;
	int n = 0;
	temp = to_wstring(n);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			stackInfo[i][j] = temp;
		}
	}
	n = 90;
	temp = to_wstring(n);
	for (int i = 0; i < 8; i++)
	{
		stackInfo[i][0] = temp;
	}
	theStack.readStackFile("StacksR.txt");
	theStack.writeStackFile("Stacks.txt");
	writeAM();
}