#include "GameMap.h"
#include "Utility.h"
#include "Chance.h"
#include "Destiny.h"
#include "Estate.h"
#include <iostream>
#include <fstream>

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
		int rows = 0, currentPlayerID;
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

					if (splitStrArr.size() > 3) {
						for (int i = 3; i < splitStrArr.size(); i += 2) {
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

	int maxWidth = 88, maxHeight = 34;

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
				if (x % 11 == 0) {
					wcout << (row == 1 ? L"┬" : L"┴");
				}
				else {
					wcout << L"─";
				}
				
			}
			else {
				if (x == 11) {
					wcout << L"┤";
				}
				else if (x == maxWidth - 2 - 9) {
					wcout << L"├";
				}
				else if (x < 12 || x > maxWidth - 2 - 10 || row == 2 || row == 8) {
					wcout << L"─";
				}
			}
			
		}
	}

	for (int x = 11, col= 1; x <= maxWidth - 11; x += 11, col++) {
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
	
	for (size_t i = 0; i < LocationList.size(); i++) {
		auto coord = GetCoordByPos(LocationList[i].get()->Position);
		SetCursorPosistion(coord.X + 4 - LocationList[i].get()->Name.length(), coord.Y);
		wcout << LocationList[i].get()->Name;
		
		SetCursorPosistion(coord.X, coord.Y + 1);
		wcout << L" : :: :";
	}
	ShowConsoleCursor(true);
	SetCursorPosistion(cuurentPos.X, cuurentPos.Y);
}

COORD GameMap::GetCoordByPos(short pos)
{
	if (pos <= 7) {
		return { 2 ,2 + pos * 4 };
	}
	else if (pos > 7 && pos <= 14) {
		return { 2 + (pos - 7) * 11 , 2 + 7 * 4};
	}
	else if (pos > 14 && pos <= 21) {
		return { 2 + 7 * 11 , 2 + (7 - pos + 14) * 4 };
	}
	else if (pos <= 27) {
		return { 2 + (7 - pos + 21) * 11, 2 };
	}
	else {
		throw exception("Invalid Coordinate.");
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
