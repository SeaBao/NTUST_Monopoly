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

	wcout << L"�{�b���� " << TheMap.GetCurrentPlayer().ID + 1 << L"���a�Y��l�A�Ы����N���Y��l";
	command = _getch();
	while (command != EOF)
	{
		if (isFirst != 0)
		{	
			Position.X = 15;
			Position.Y = 10;
			SetConsoleCursorPosition(hOut, Position);
			wcout << L"�{�b���� " << TheMap.GetCurrentPlayer().ID + 1 << L"���a�Y��l�A�Ы����N���Y��l";
			command = _getch();
			
		}
		srand(static_cast<int>(time(NULL)));
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		int DicePoint = (rand() % 6) + 1;
		wcout << L"�Y�X���I�Ƭ� " << DicePoint << L" �I";
		
			TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position = TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position + DicePoint;
			//�g�a���S���H�ʶR
			if (TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties.size() != 0)
			{
				if (TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).ID == TheMap.GetCurrentPlayer().ID)
				{
					int pos = 0;
					for (int i = 0; i < TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties.size(); i++)
					{
						if (TheMap.GetEstateFromPos(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position) == TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties[i].Estate)
						{
							pos = i;
						}
					}
					if (TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties[pos].Level!= 3)
					{

						//��X�O�_�ɯ�
						/*if(YES)
						{
							TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties[pos].Level++;
						}
						else
						{

						}*/
					}
				}
				else
				{
					//�x���g�a��	
					
				}
			}
			else
			{
				//��X�O�_�n�ʶR������
			}
		
		
		cout << TheMap.GetCurrentPlayer().ID  +1 <<TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position;
		wcout << L"      �Ы����N���~��...";
		TheMap.TurnNextRound();
		command = _getch();
	
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                               ";
		isFirst = 1;
	}
}


OperatingPlayers::~OperatingPlayers()
{
}
