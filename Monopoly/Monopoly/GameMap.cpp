#include "GameMap.h"
#include "Utility.h"
#include "Chance.h"
#include "Destiny.h"
#include "Estate.h"
#include <iostream>
#include <fstream>

GameMap TheMap;

GameMap::GameMap()
{
	Name = L"";
	RemainingRounds = 0;
	MaxPlayers = 0;
	_CurrentPlayerID = -1;
}

void GameMap::ReadMap(string path)
{
	wifstream file;
	file.imbue(locale("zh_TW.UTF-8"));
	file.open(path);

	if (file.is_open()) {
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
				MaxPlayers = stoi(splitStrArr[2]);
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
					Player player;
					player.ID = stoi(splitStrArr[0]);
					player.Position = stoi(splitStrArr[1]);
					player.Money = stoi(splitStrArr[2]);
					player.Stop = RemainingRounds;

					if (splitStrArr.size() > 3) {
						for (size_t i = 3; i < splitStrArr.size(); i += 2) {
							Property property;
							property.Estate = GetEstateByID(stoi(splitStrArr[i]));
							property.Level = stoi(splitStrArr[i + 1]);

							player.OwnedProperties.push_back(property);
						}
					}

					PlayerList.push_back(player);
				}
			}
		}
		_PlayerTurns = MaxPlayers;
		file.close();
	}
}

void GameMap::WriteMap(string path)
{
	ofstream file;
	file.open(path);

	if (file.is_open()) {
		file.close();
	}
}

void GameMap::PrintMap()
{
	auto cuurentPos = GetCursorPosition();
	ShowConsoleCursor(false);

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
	for (Player p : PlayerList) {
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
	else {
		GetCurrentPlayer().Stop = RemainingRounds;
	}

	int index = -1;
	for (int i = 0; i < PlayerList.size(); i++) {
		if (PlayerList[i].ID == _CurrentPlayerID) index = i;
	}

	if (index == -1) throw exception("Wrong Player ID");

	bool isFound = false;
	for (int i = index + 1; i < PlayerList.size(); i++) {
		if (PlayerList[i].Stop != -1) {
			_CurrentPlayerID = PlayerList[i].ID;
			isFound = true;
			break;
		}
	}

	if (!isFound) {
		for (int i = 0; i < index; i++) {
			if (PlayerList[i].Stop != -1) {
				_CurrentPlayerID = PlayerList[i].ID;
				isFound = true;
				break;
			}
		}
	}

	_PlayerTurns--;
	if (_PlayerTurns == 0) {
		RemainingRounds--;

		int temp = 0;
		for (auto p : PlayerList) {
			if (p.Stop == -1) temp++;
		}
		_PlayerTurns = temp;
	}
}

Player& GameMap::GetCurrentPlayer()
{
	return PlayerList[_CurrentPlayerID];
}

Estate& GameMap::GetEstateByID(int ID)
{
	return *static_cast<Estate*>(LocationList[ID].get());
}
