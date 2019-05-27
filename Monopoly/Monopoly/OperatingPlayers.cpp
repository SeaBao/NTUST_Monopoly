#include "OperatingPlayers.h"
#include<time.h>
#include <Windows.h>
char command;
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
			TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position = TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position % 28;
			TheMap.RefreshPlayerLocation();
			//命運
			if (TheMap[TheMap.GetCurrentPlayer().Position].Type == LocType::Destiny)
			{

			}
			//機會
			else if (TheMap[TheMap.GetCurrentPlayer().Position].Type == LocType::Chance)
			{


			}
			else
			{
				
				
				//土地有沒有人購買
				if (isEstateOwned(TheMap.GetCurrentPlayer().Position))
				{
					//如果是自己的地 
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
						//如果升級次數還沒超過3次
						if (TheMap.GetOwnerByEstate(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position).OwnedProperties[pos].Level != 3)
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
					
					
					if (PurchaseLand(TheMap.GetCurrentPlayer().ID, TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position, Position))
					{
						hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleCursorPosition(hOut, Position);
					}
					else
					{
						hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleCursorPosition(hOut, Position);
					}
				}
			}
			
		
		
		
		
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

int OperatingPlayers::PurchaseLand(int ID, int pos , COORD Position)
{//75left 77right 13 enter 
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	Position.X = 15;
	Position.Y = 20;
	SetConsoleCursorPosition(hOut, Position);
	wcout << ID + 1 << L"目前在 " << TheMap[pos].Name << L" 位置";
	Position.X = 15;
	Position.Y = 22;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" 這片土地目前沒有人購買 是否要購買?";
	Position.X = 15;
	Position.Y = 26;
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"yes";
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x60);
	wcout << L" no";


	int rightOrLeft = 0;
	while (command != 13)
	{

		if (rightOrLeft == 0)
		{
			if (command == 77)
			{
				Position.X = 15;
				Position.Y = 26;
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x90);
				SetConsoleCursorPosition(hOut, Position);
				wcout << L"yes";
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
				wcout << L" no";
				rightOrLeft = 1;
			}

		}
		else if (rightOrLeft == 1)
		{
			if (command == 75)
			{
				Position.X = 15;
				Position.Y = 26;
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
				SetConsoleCursorPosition(hOut, Position);
				wcout << L"yes";
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x90);
				wcout << L" no";
				rightOrLeft = 0;
			}

		}
		command = _getch();
	}
	if (rightOrLeft == 0)
	{
		
		Position.X = 15;
		Position.Y = 26;
		SetConsoleCursorPosition(hOut, Position);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | 0x00);
		wcout << L"                                               ";
		Position.X = 15;
		Position.Y = 20;
		SetConsoleCursorPosition(hOut, Position);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | 0x00);
		wcout << L"                                               ";
		Position.X = 15;
		Position.Y = 22;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | 0x00);
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                               ";
		return 1;
	}
	else if (rightOrLeft == 1)
	{
	
		Position.X = 15;
		Position.Y = 26;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | 0x00);
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                               ";
		Position.X = 15;
		Position.Y = 20;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | 0x00);
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                               ";
		Position.X = 15;
		Position.Y = 22;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | 0x00);
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                               ";
		return 0;
	}


}
