#include "OperatingPlayers.h"



OperatingPlayers::OperatingPlayers()
{


}

void OperatingPlayers::GameStart()
{
	GameMap temp;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 15;
	Position.Y = 10;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"現在輪到 "<< (turn % 4 )+1 <<L"玩家擲骰子，請按任意鍵擲骰子";
	while (command != EOF)
	{
		wcout << L"擲出的點數為 " << (rand() % 6) + 1 << L" 點";
		if ((turn % 4) + 1 == 1)
		{

		}
		else if ((turn % 4) + 1 == 2)
		{

		}
		else if ((turn % 4) + 1 == 3)
		{

		}
		else if ((turn % 4) + 1 == 4)
		{

		}
		turn++;
		command = _getch();
	}
}


OperatingPlayers::~OperatingPlayers()
{
}
