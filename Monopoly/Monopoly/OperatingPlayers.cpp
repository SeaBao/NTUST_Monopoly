#include "OperatingPlayers.h"
#include<time.h>

OperatingPlayers::OperatingPlayers()
{


}

void OperatingPlayers::GameStart()
{
	int isFirst = 0;
	
	
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 15;
	Position.Y = 10;
	SetConsoleCursorPosition(hOut, Position);

	wcout << L"�{�b���� "<< TheMap.GetCurrentPlayer().ID <<L"���a�Y��l�A�Ы����N���Y��l";
	command = _getch();
	while (command != EOF)
	{
		if (isFirst != 0)
		{
			isFirst = 1;
			Position.X = 15;
			Position.Y = 10;
			SetConsoleCursorPosition(hOut, Position);
			wcout << L"�{�b���� " << TheMap.GetCurrentPlayer().ID << L"���a�Y��l�A�Ы����N���Y��l";
			command = _getch();
			
		}
		srand(static_cast<int>(time(NULL)));
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		int DicePoint = (rand() % 6) + 1;
		wcout << L"�Y�X���I�Ƭ� " << DicePoint << L" �I";
		if ((TheMap.GetRemainingRounds() % TheMap.GetMaxPlayers()) + 1 == 1)
		{

		}
		else if ((TheMap.GetRemainingRounds() % TheMap.GetMaxPlayers()) + 1 == 2)
		{

		}
		else if ((TheMap.GetRemainingRounds() % TheMap.GetMaxPlayers()) + 1 == 3)
		{

		}
		else if ((TheMap.GetRemainingRounds() % TheMap.GetMaxPlayers()) + 1 == 4)
		{

		}
		
		wcout << L"      �Ы����N���~��...";
		command = _getch();
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		wcout << "                                                      ";
		TheMap.TurnNextRound();
	}
}


OperatingPlayers::~OperatingPlayers()
{
}
