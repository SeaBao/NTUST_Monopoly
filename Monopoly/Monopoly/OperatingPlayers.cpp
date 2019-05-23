#include "OperatingPlayers.h"
#include<time.h>

OperatingPlayers::OperatingPlayers()
{


}

void OperatingPlayers::GameStart()
{
	
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 15;
	Position.Y = 10;
	SetConsoleCursorPosition(hOut, Position);

	wcout << L"現在輪到 "<< (turn % TheMap.GetMaxPlayers())+1 <<L"玩家擲骰子，請按任意鍵擲骰子";
	command = _getch();
	while (command != EOF)
	{
		
		srand(static_cast<int>(time(NULL)));
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"擲出的點數為 " << (rand() % 6) + 1 << L" 點";
		if ((turn % TheMap.GetMaxPlayers()) + 1 == 1)
		{

		}
		else if ((turn % TheMap.GetMaxPlayers()) + 1 == 2)
		{

		}
		else if ((turn % TheMap.GetMaxPlayers()) + 1 == 3)
		{

		}
		else if ((turn % TheMap.GetMaxPlayers()) + 1 == 4)
		{

		}
		turn++;
		Position.X = 15;
		Position.Y = 10;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"現在輪到 " << (turn % TheMap.GetMaxPlayers()) + 1 << L"玩家擲骰子，請按任意鍵擲骰子";
		command = _getch();
	}
}


OperatingPlayers::~OperatingPlayers()
{
}
