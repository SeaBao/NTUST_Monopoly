#include "GameMap.h"
#include "Utility.h"
#include "Chance.h"
#include "Destiny.h"
#include "Estate.h"
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
						LocationList.emplace_back(new Estate(name, pos, stoi(splitStrArr[3]), fees));
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
}

Player& GameMap::GetCurrentPlayer()
{
	return PlayerList[_CurrentPlayerID];
}

Estate& GameMap::GetEstateByID(int ID)
{
	return *static_cast<Estate*>(LocationList[ID].get());
}
