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

	void ReadMap(string path, int maxPlayer = -1);
	void WriteMap(string path);
	void PrintMap();
	void RefreshPlayerLocation();
	void RefreshEstateLabel();
	int GetMaxPlayers();
	int GetRemainingRounds();
	int ReturnTurns();
	COORD GetCoordByPos(short pos);
	Estate& GetEstateFromPos(int pos);
	Player& GetOwnerByEstate(const Estate& e);
	Player& GetOwnerByEstate(int pos);
	Player& GetCurrentPlayer();
	int GetLocationCount();
	vector<reference_wrapper<Player>> GetPlayersFromLocation(const Location& loc);
	vector<reference_wrapper<Player>> GetPlayersFromLocation(int pos);
	Location& operator[](int index);
	void TurnNextRound();

	
	vector<Player> PlayerList;
	wstring Name;
private:
	int RemainingRounds;
	int MaxPlayers;
	int _CurrentPlayerID;
	int _PlayerTurns;
	
	Estate& GetEstateByID(int ID);
	vector<unique_ptr<Location>> LocationList;
};

extern GameMap TheMap;

