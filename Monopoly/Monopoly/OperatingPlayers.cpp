#include "OperatingPlayers.h"



OperatingPlayers::OperatingPlayers()
{


}

void OperatingPlayers::GameStart()
{
	GameMap temp;

	cout << "�{�b���� "<< (turn % 4 )+1 <<"���a�Y��l�A�Ы����N���Y��l";
	while (command != EOF)
	{
		cout << "�Y�X���I�Ƭ� " << (rand() % 6) + 1 << " �I";
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
