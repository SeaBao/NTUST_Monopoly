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
	wcout << L"�{�b���� "<< (turn % 4 )+1 <<L"���a�Y��l�A�Ы����N���Y��l";
	while (command != EOF)
	{
		wcout << L"�Y�X���I�Ƭ� " << (rand() % 6) + 1 << L" �I";
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
