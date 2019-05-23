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

	wcout << L"現在輪到 " << TheMap.GetCurrentPlayer().ID + 1 << L"玩家擲骰子，請按任意鍵擲骰子";
	command = _getch();
	while (command != EOF)
	{
		if (isFirst != 0)
		{	
			Position.X = 15;
			Position.Y = 10;
			SetConsoleCursorPosition(hOut, Position);
			wcout << L"現在輪到 " << TheMap.GetCurrentPlayer().ID + 1 << L"玩家擲骰子，請按任意鍵擲骰子";
			command = _getch();
			
		}
		srand(static_cast<int>(time(NULL)));
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		int DicePoint = (rand() % 6) + 1;
		wcout << L"擲出的點數為 " << DicePoint << L" 點";
		
			TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position = TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position + DicePoint;
			//土地有沒有人購買
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

						//輸出是否升級
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
					//徵收土地錢	
					
				}
			}
			else
			{
				//輸出是否要購買的視窗
			}
		
		
		cout << TheMap.GetCurrentPlayer().ID  +1 <<TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position;
		wcout << L"      請按任意鍵繼續...";
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
