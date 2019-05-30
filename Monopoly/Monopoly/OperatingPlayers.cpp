#include "OperatingPlayers.h"
#include<time.h>
#include "InfoPanel.h"
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
				srand(static_cast<int>(time(NULL)));
				int DestinyCase = (rand() % 3 ) + 1;
				switch (DestinyCase)
				{
					case 1:
						Position.X = 15;
						Position.Y = 20;
						SetConsoleCursorPosition(hOut, Position);
						wcout << L"遇到韓國魚游行，停止行動2回合";
						TheMap.GetCurrentPlayer().Stop = TheMap.GetCurrentPlayer().Stop + 2;
						break;
					case 2:
						Position.X = 15;
						Position.Y = 20;
						SetConsoleCursorPosition(hOut, Position);
						wcout << L"不小心走進高雄市，獲得發財金200元";
						TheMap.GetCurrentPlayer().Money = TheMap.GetCurrentPlayer().Money + 200;
						break;
					case 3:
						Position.X = 15;
						Position.Y = 20;
						SetConsoleCursorPosition(hOut, Position);
						wcout << L"在路上撿到炒房秘笈，自身所有土地產升級一級(除了已最高級)";
						for (int i = 0; i < TheMap.GetCurrentPlayer().OwnedProperties.size(); i++)
						{
							if (TheMap.GetCurrentPlayer().OwnedProperties[i].Level < 3)
							{
								TheMap.GetCurrentPlayer().OwnedProperties[i].Level++;
							}
						
						}
						
						break;
				}
					

			}
			//機會
			else if (TheMap[TheMap.GetCurrentPlayer().Position].Type == LocType::Chance)
			{
				srand(static_cast<int>(time(NULL)));
				int ChanceCase = (rand() % 3) + 1;
				switch (ChanceCase)
				{
				case 1:
					Position.X = 15;
					Position.Y = 20;
					SetConsoleCursorPosition(hOut, Position);
					wcout << L"不小心出了車禍...";
					TheMap.GetCurrentPlayer().Stop = -1;
					break;
				case 2:
					Position.X = 15;
					Position.Y = 20;
					SetConsoleCursorPosition(hOut, Position);
					wcout << L"被查出吸食毒品，罰金500";
					TheMap.GetCurrentPlayer().Money = TheMap.GetCurrentPlayer().Money - 200;
					break;
				case 3:
					Position.X = 15;
					Position.Y = 20;
					SetConsoleCursorPosition(hOut, Position);
					wcout << L"遠雄幫你蓋的房子被發現偷工減料，所有房地產減少一級(一級以上才執行)";
					for (int i = 0; i < TheMap.GetCurrentPlayer().OwnedProperties.size(); i++)
					{
						if (TheMap.GetCurrentPlayer().OwnedProperties[i].Level > 1 )
						{
							TheMap.GetCurrentPlayer().OwnedProperties[i].Level--;
						}

					}

					break;
				}

			}
			else
			{
				
				
				//土地有沒有人購買
				if (isEstateOwned(TheMap.GetCurrentPlayer().Position))
				{
					int tempposid = TheMap.GetOwnerByEstate(TheMap.GetCurrentPlayer().Position).ID;
					int tempcurid = TheMap.GetCurrentPlayer().ID;
					//如果是自己的地 
					if (tempposid == tempcurid)
					{
						cout << TheMap.GetCurrentPlayer().OwnedProperties.size();
					
						int pos = 0;
						for (int i = 0; i < TheMap.GetCurrentPlayer().OwnedProperties.size(); i++)
						{
							if (TheMap.GetEstateFromPos(TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position) == TheMap.GetCurrentPlayer().OwnedProperties[i].Estate)
							{
								pos = i;
							}
						}
						//如果升級次數還沒超過3次
						if (TheMap.GetCurrentPlayer().OwnedProperties[pos].Level != 3)
						{
						
							if(UpdateLand(TheMap.GetCurrentPlayer().ID, TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position, Position, pos))
							{
								TheMap.GetCurrentPlayer().OwnedProperties[pos].Level++;
							}
							else
							{

							}
						}
						else
						{
							
						}
					}
					else if((TheMap.GetOwnerByEstate(TheMap.GetCurrentPlayer().Position).ID) != (TheMap.GetCurrentPlayer().ID))
					{
						
						//徵收土地錢	

					}
				}
				else
				{
					
					//購買
					if (PurchaseLand(TheMap.GetCurrentPlayer().ID, TheMap.PlayerList[TheMap.GetCurrentPlayer().ID].Position, Position))
					{
						hOut = GetStdHandle(STD_OUTPUT_HANDLE); 

						SetConsoleCursorPosition(hOut, Position);
						//購買成功
					
						if (TheMap.GetCurrentPlayer().Money - static_cast<Estate*>(&TheMap[TheMap.GetCurrentPlayer().Position])->InitialPrice > 0)
						{
							TheMap.GetCurrentPlayer().Money = TheMap.GetCurrentPlayer().Money - static_cast<Estate*>(&TheMap[TheMap.GetCurrentPlayer().Position])->InitialPrice;
							Property temp;
							temp.Estate = *static_cast<Estate*>(&TheMap[TheMap.GetCurrentPlayer().Position]);
							temp.Level = 0;
							TheMap.GetCurrentPlayer().OwnedProperties.push_back(temp);
						
							TheMap.RefreshEstateLabel();
						}
						else
						{
							
						}
					
						
						
					}
					else
					{
						hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleCursorPosition(hOut, Position);
					}
				}
			}
			
		
		
		
		
		TheMap.TurnNextRound();
		PlayerPanel.PrintPanel();
		command = _getch();
	
		Position.X = 15;
		Position.Y = 12;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                                        ";
		Position.X = 15;
		Position.Y = 20;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"                                                         ";
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

int OperatingPlayers::UpdateLand(int ID, int pos, COORD Position, int index)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 15;
	Position.Y = 20;
	SetConsoleCursorPosition(hOut, Position);
	wcout << ID + 1 << L"目前在 " << TheMap[pos].Name << L" 位置";
	Position.X = 15;
	Position.Y = 22;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" 這片土地已升級 "<< TheMap.GetCurrentPlayer().OwnedProperties[index].Level <<L" 次 是否要進行升級?";
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
