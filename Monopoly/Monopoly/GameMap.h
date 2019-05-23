#pragma once
#include "Location.h"
#include "Player.h"
#include <Windows.h>
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
	void RefreshPlayerLocation();
	int GetMaxPlayers();
	int GetRemainingRounds();

	COORD GetCoordByPos(short pos);
	Estate& GetEstateFromPos(int pos);
	Player& GetOwnerByEstate(const Estate& e);
	Player& GetCurrentPlayer();
	int GetLocationCount();
	vector<reference_wrapper<Player>> GetPlayersFromLocation(const Location& loc);
	vector<reference_wrapper<Player>> GetPlayersFromLocation(int pos);

	void TurnNextRound();

	vector<Player> PlayerList;
	wstring Name;
private:
	int RemainingRounds;
	int MaxPlayers;
	int _CurrentPlayerID;
	
	Estate& GetEstateByID(int ID);
	vector<unique_ptr<Location>> LocationList;
	
};

extern GameMap TheMap;

