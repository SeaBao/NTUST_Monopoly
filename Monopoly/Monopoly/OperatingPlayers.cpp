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

	wcout << L"�{�b���� "<< (turn % TheMap.GetMaxPlayers())+1 <<L"���a�Y��l�A�Ы����N���Y��l";
	
	while (command != EOF)
	{
		if (turn != 0)
		{
			
			Position.X = 15;
			Position.Y = 10;
			SetConsoleCursorPosition(hOut, Position);
			wcout << L"�{�b���� " << (turn % TheMap.GetMaxPlayers()) + 1 << L"���a�Y��l�A�Ы����N���Y��l";
			command = _getch();
		}
		srand(static_cast<int>(time(NULL)));
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"�Y�X���I�Ƭ� " << (rand() % 6) + 1 << L" �I";
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
		wcout << L"      �Ы����N���~��...";
		command = _getch();
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		wcout << "                                                      ";
	
	}
}


OperatingPlayers::~OperatingPlayers()
{
}
