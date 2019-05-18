#include "OperatingPlayers.h"



OperatingPlayers::OperatingPlayers()
{


}

void OperatingPlayers::GameStart()
{
	GameMap temp;

	cout << "現在輪到 "<< (turn % 4 )+1 <<"玩家擲骰子，請按任意鍵擲骰子";
	while (command != EOF)
	{
		cout << "擲出的點數為 " << (rand() % 6) + 1 << " 點";
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
