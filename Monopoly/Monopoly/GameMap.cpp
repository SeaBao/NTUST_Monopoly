#include "GameMap.h"
#include "Utility.h"
#include "Chance.h"
#include "Destiny.h"
#include "Estate.h"
#include <iostream>
#include <fstream>
#include <sstream>

GameMap TheMap;

GameMap::GameMap()
{
	Name = L"";
	RemainingRounds = 0;
	MaxPlayers = 0;
	_CurrentPlayerID = -1;
}

void GameMap::ReadMap(string path, int maxPlayer)
{
	wifstream file;
	file.imbue(locale("zh_TW.UTF-8"));
	file.open(path);

	if (file.is_open()) {
		PlayerList.clear();
		LocationList.clear();

		int rows = 0;
		bool isFinishLoadingLocation = false;
		wstring line;
		while (getline(file, line)) {
			vector<wstring> splitStrArr;
			rows++;

			Split(line, splitStrArr, ' ');
			if (rows == 1) {
				Name = splitStrArr[0];
				RemainingRounds = stoi(splitStrArr[1]);
				MaxPlayers = maxPlayer != -1 ? maxPlayer : stoi(splitStrArr[2]);
			}
			else if (rows != 1 && splitStrArr[0] == L"playerstate") {
				isFinishLoadingLocation = true;
				_CurrentPlayerID = stoi(splitStrArr[1]);
			}
			else {
				if (!isFinishLoadingLocation) {
					int pos = stoi(splitStrArr[0]);
					wstring name = splitStrArr[1];

					switch (stoi(splitStrArr[2]))
					{
					case 0:
					{
						LocationList.emplace_back(new Location(name, LocType::Start, pos));
						break;
					}
					case 1:
					{
						array<int, 4> fees{ stoi(splitStrArr[4]), stoi(splitStrArr[5]), stoi(splitStrArr[6]), stoi(splitStrArr[7]) };
						Estate* estate = new Estate(name, pos, stoi(splitStrArr[3]), fees);

						if (splitStrArr[splitStrArr.size() - 1] == L"B") {
							estate->HasBarrier = 1;
						}

						LocationList.emplace_back(estate); 
						break;
					}
					case -1:
					{
						LocationList.emplace_back(new Destiny(name, pos));
						break;
					}
					case -2:
					{
						LocationList.emplace_back(new Chance(name, pos));
						break;
					}
					default:
						throw exception("Unknown Object Type.");
					}
				}
				else {
					if (PlayerList.size() >= MaxPlayers) {
						break;
					}

					Player player;
					player.ID = stoi(splitStrArr[0]);
					player.Position = stoi(splitStrArr[1]);
					player.Money = stoi(splitStrArr[2]);
					player.Stop = 0;
					player.BarrierAmount = 1;
					player.DiceAmount = 1;

					if (splitStrArr.size() > 3) {
						for (size_t i = 3; i < splitStrArr.size(); i += 2) {
							if (splitStrArr[i] == L"S") {
								player.Stop = stoi(splitStrArr[i + 1]);
							}
							else if (splitStrArr[i] == L"B") {
								player.BarrierAmount = stoi(splitStrArr[i + 1]);
							}
							else if (splitStrArr[i] == L"D") {
								player.DiceAmount = stoi(splitStrArr[i + 1]);
							}
							else {
								Property property;
								property.Estate = GetEstateByID(stoi(splitStrArr[i]));
								property.Level = stoi(splitStrArr[i + 1]);
								player.OwnedProperties.push_back(property);
							}
							
						}
					}
					PlayerList.push_back(player);
				}
			}
		}
		
		int temp = 0;
		for (auto p : TheMap.PlayerList) {
			if (p.Stop == 0) temp++;
		}
		TheMap._PlayerTurns = temp;
		file.close();
	}
}

void GameMap::WriteMap(string path)
{
	wofstream file;
	file.imbue(locale("zh_TW.UTF-8"));
	file.open(path);
	
	if (file.is_open()) {
		wstringstream ss;
		ss << TheMap.Name << " " << TheMap.RemainingRounds << " " << TheMap.MaxPlayers << endl;

		for (int i = 0; i < TheMap.LocationList.size(); i++) {
			ss << (TheMap[i].Position < 10 ? L'0' + to_wstring(TheMap[i].Position) : to_wstring(TheMap[i].Position)) << " " << TheMap[i].Name;
			ss << " " << (int)TheMap[i].Type;

			if (TheMap[i].Type == LocType::Estate) {
				Estate* temp = static_cast<Estate*>(&TheMap[i]);
				ss << " " << temp->InitialPrice;
				for (int item : temp->Fees) {
					ss << " " << item;
				}

				if (temp->HasBarrier == 1) ss << " B";
			}

			ss << endl;
		}

		ss << "playerstate " << TheMap._CurrentPlayerID << endl;

		for (Player p : TheMap.PlayerList) {
			ss << p.ID << " " << (p.Position < 10 ? L'0' + to_wstring(p.Position) : to_wstring(p.Position)) << " " << p.Money;

			for (auto theProperty : p.OwnedProperties) {
				ss << " " << theProperty.Estate.Position << " " << theProperty.Level;
			}

			ss << " S " << p.Stop;

			if (p.BarrierAmount > 0) {
				ss << " B " << p.BarrierAmount;
			}

			if (p.DiceAmount > 0) {
				ss << " D " << p.DiceAmount;
			}

			ss << endl;
		}

		file << ss.rdbuf();
		file.close();
	}
}

void GameMap::PrintMap()
{
	auto cuurentPos = GetCursorPosition();
	ShowConsoleCursor(false);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	int maxWidth = 88 + 8, maxHeight = 34;

	for (int y = 0; y <= maxHeight; y++) {
		for (int x = 0; x <= maxWidth; x+=2) {
			SetCursorPosistion(x, y);

			if (y == 0) {
				if (x == 0) {
					wcout << L"╔ ";
				}
				else if (x == maxWidth) {
					wcout << L"╗ ";
				}
				else {
					wcout << L"═ ";
				}
				
			}
			else if (y == maxHeight) {
				if (x == 0) {
					wcout << L"╚ ";
				}
				else if (x == maxWidth) {
					wcout << L"╝ ";
				}
				else {
					wcout << L"═ ";
				}
			}
			else {
				if (x == 0 || x == maxWidth) {
					wcout << L"║ ";
				}
			}
		}
	}

	int startY = 1;
	for (int y = startY, row = 1; y < startY + 4 * 9; y+=4, row++) {
		for (int x = 2; x <= maxWidth - 2; x++) {
			SetCursorPosistion(x, y);

			if (row == 1 || row == 9) {
				if (x % 12 == 0) {
					wcout << (row == 1 ? L"┬" : L"┴");
				}
				else {
					wcout << L"─";
				}
				
			}
			else {
				if (x == 12) {
					wcout << L"┤";
				}
				else if (x == maxWidth - 2 - 10) {
					wcout << L"├";
				}
				else if (x < 12 || x > maxWidth - 2 - 10 || row == 2 || row == 8) {
					wcout << L"─";
				}
			}
			
		}
	}

	for (int x = 2 + 10, col= 1; x <= maxWidth - 12; x += 12, col++) {
		for (int y = startY + 1; y < startY + 4 * 8; y++) {
			SetCursorPosistion(x, y);
			if (col == 1 || col == 7) {
				wcout << L"│";
			}
			else {
				if ((y - startY + 2) / 6 >= 1 && (y - startY + 1) / 6 <= 4) {

				}
				else {
					wcout << L"│";
				}
				
			}
		}
	}

	sort(LocationList.begin(), LocationList.end(), [](const unique_ptr<Location> & a, const unique_ptr<Location> & b) { return a->Position < b->Position; });
	
	RefreshEstateLabel();
	RefreshPlayerLocation();
	ShowConsoleCursor(true);
	SetCursorPosistion(cuurentPos.X, cuurentPos.Y);
}

void GameMap::RefreshPlayerLocation() {
	TheMap.WriteMap("debug.txt");
	const int clrSelection[4] = { FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY };
	for (int i = 0; i < LocationList.size(); i++) {
		auto loc = LocationList[i].get();
		auto coord = GetCoordByPos(loc->Position);
		vector<Player> tempList;

		SetCursorPosistion(coord.X + 1, coord.Y + 1);
		wcout << L" : :: : ";

		for (Player player : PlayerList) {
			if (player.Position == loc->Position) {
				SetCursorPosistion(1 + coord.X + 2 * player.ID + (player.ID > 1 ? 1 : 0), coord.Y + 1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clrSelection[player.ID]);
				wcout << to_wstring(player.ID + 1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
		}
	}
}

void GameMap::RefreshEstateLabel()
{
	auto cuurentPos = GetCursorPosition();
	ShowConsoleCursor(false);
	const int whiteText = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	const int clrSelection[4] = { BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY };

	for (size_t i = 0; i < LocationList.size(); i++) {
		auto coord = GetCoordByPos(LocationList[i].get()->Position);

		bool isPropertyOwned = false;
		int playerID = -1;
		for (auto p : PlayerList) {
			for (auto item : p.OwnedProperties) {
				if (item.Estate.Position == LocationList[i].get()->Position) {
					isPropertyOwned = true;
					playerID = p.ID;
					break;
				}
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (isPropertyOwned ? clrSelection[playerID] : 0) | whiteText);
		SetCursorPosistion(coord.X + 5 - LocationList[i].get()->Name.length(), coord.Y);
		wcout << LocationList[i].get()->Name;

		if (TheMap[i].Type == LocType::Estate) {
			Estate* myEstate = static_cast<Estate*>(&TheMap[i]);
			SetCursorPosistion(coord.X + 2, coord.Y + 2);
			if (myEstate->HasBarrier == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
				wcout << L"<路障>";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), whiteText);				
				wcout << L"      ";
			}
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), whiteText);
	ShowConsoleCursor(true);
	SetCursorPosistion(cuurentPos.X, cuurentPos.Y);
}

int GameMap::GetMaxPlayers()
{
	return MaxPlayers;
}

int GameMap::GetRemainingRounds()
{
	return RemainingRounds;
}

int GameMap::ReturnTurns()
{
	return _PlayerTurns;
}

COORD GameMap::GetCoordByPos(short pos)
{
	if (pos <= 7) {
		return { 2 ,2 + pos * 4 };
	}
	else if (pos > 7 && pos <= 14) {
		return { 2 + (pos - 7) * 12 , 2 + 7 * 4};
	}
	else if (pos > 14 && pos <= 21) {
		return { 2 + 7 * 12 , 2 + (7 - pos + 14) * 4 };
	}
	else if (pos <= 27) {
		return { 2 + (7 - pos + 21) * 12, 2 };
	}
	else {
		throw exception("Invalid Coordinate.");
	}
}

Estate& GameMap::GetEstateFromPos(int pos)
{
	for (int i = 0; i < LocationList.size(); i++) {
		if (LocationList[i].get()->Position == pos) return *static_cast<Estate*>(LocationList[i].get());
	}
}


Player& GameMap::GetOwnerByEstate(const Estate& e)
{
	for (Player& p : PlayerList) {
		for (auto item : p.OwnedProperties) {
			if (e.Name == item.Estate.Name) {
				return p;
			}
		}
	}
}

Player& GameMap::GetOwnerByEstate(int pos)
{
	return GetOwnerByEstate(GetEstateByID(pos));
}

int GameMap::GetLocationCount()
{
	return LocationList.size();
}

vector<reference_wrapper<Player>> GameMap::GetPlayersFromLocation(const Location& loc)
{
	return GetPlayersFromLocation(loc.Position);
}

vector<reference_wrapper<Player>> GameMap::GetPlayersFromLocation(int pos)
{
	vector<reference_wrapper<Player>> result;

	for (int i = 0; i < PlayerList.size(); i++) {
		if (PlayerList[i].Position == pos) result.push_back(PlayerList[i]);
	}

	return result;
}

Location& GameMap::operator[](int index)
{
	return *LocationList[index].get();
}

void GameMap::TurnNextRound()
{
	if (RemainingRounds == 0) return;

	if (GetCurrentPlayer().Money < 0) {
		GetCurrentPlayer().Stop = -1;
	}

	int index = -1;
	for (int i = 0; i < PlayerList.size(); i++) {
		if (PlayerList[i].ID == _CurrentPlayerID) index = i;
	}

	if (index == -1) throw exception("Wrong Player ID");

	bool isFound = false;
	int tempIndex = _CurrentPlayerID + 1;
	do
	{
		if (tempIndex >= MaxPlayers) {
			tempIndex = 0;
			RemainingRounds--;
		}

		if (PlayerList[tempIndex].Money < 0) {
			PlayerList[tempIndex].Stop = -1;
		}

		if (PlayerList[tempIndex].Stop > 0) {
			if (PlayerList[tempIndex].StopTurn != RemainingRounds) {
				PlayerList[tempIndex].Stop -= 1;
			}
		}
		else if (PlayerList[tempIndex].Stop == 0) {
			_CurrentPlayerID = tempIndex;
			isFound = true;
		}

		tempIndex++;
	} while (!isFound);
}

Player& GameMap::GetCurrentPlayer()
{
	return PlayerList[_CurrentPlayerID];
}

Estate& GameMap::GetEstateByID(int ID)
{
	return *static_cast<Estate*>(LocationList[ID].get());
}
