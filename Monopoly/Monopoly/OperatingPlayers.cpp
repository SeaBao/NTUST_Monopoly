#include "OperatingPlayers.h"
#include<time.h>

bool isEstateOwned(int pos) {
	for (auto p : TheMap.PlayerList) {
		for (auto estate : p.OwnedProperties) {
			if (estate.Estate.Position == pos) return true;
		}
	}
	return false;
}


OperatingPlayers::OperatingPlayers()
{


}

int OperatingPlayers::PurchaseLand(int ID, int pos)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 15;
	Position.Y = 20;
	SetConsoleCursorPosition(hOut, Position);
	wcout << ID+1 << L"�ثe�b "<< TheMap[pos].Name <<L" ��m";
	return 1;
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
			TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position = TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position % 28;
			cout << TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position;
			//�R�B
			if (TheMap[TheMap.GetCurrentPlayer().Position].Type == LocType::Destiny)
			{

			}
			//���|
			else if (TheMap[TheMap.GetCurrentPlayer().Position].Type == LocType::Chance)
			{


			}
			else
			{
				
				
				//�g�a���S���H�ʶR
				if (TheMap.GetOwnerByEstate(TheMap.GetCurrentPlayer().Position).OwnedProperties.size() != 0)
				{
					//�p�G�O�ۤv���a 
					if (TheMap.GetOwnerByEstate(TheMap.GetCurrentPlayer().Position).ID == TheMap.GetCurrentPlayer().ID)
					{
						int pos = 0;
						for (int i = 0; i < TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties.size(); i++)
						{
							if (TheMap.GetEstateFromPos(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position) == TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties[i].Estate)
							{
								pos = i;
							}
						}
						//�p�G�ɯŦ����٨S�W�L3��
						if (TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties[pos].Level != 3)
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
					
					if (PurchaseLand(TheMap.GetCurrentPlayer().ID, TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position))
					{

					}
					else
					{

					}
				}
			}
			
		
		
	
		wcout << L"      �Ы����N���~��...";
		TheMap.RefreshPlayerLocation();
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
