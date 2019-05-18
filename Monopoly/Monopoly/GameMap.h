#pragma once
#include "Location.h"
#include "Player.h"
#include <memory>
#include <vector>
#include <string>
using namespace std;

class GameMap
{
public:
	GameMap();

	void ReadMap(string path);
	void WriteMap(string path);
	void PrintMap();

	wstring Name;
private:
	int RemainingRounds;
	int MaxPlayers;
	int _CurrentPlayerID;

	Player& GetCurrentPlayer();
	Estate& GetEstateByID(int ID);
	vector<unique_ptr<Location>> LocationList;
	vector<Player> PlayerList;
};

