#pragma once
#include<stdio.h>
#include <conio.h>
#include <iostream>
#include"Player.h"
#include"GameMap.h"
using namespace std;
class OperatingPlayers
{
private:
	
	
public:
	OperatingPlayers();
	int  PurchaseLand(int ID, int pos, COORD Position);
	void GameStart();
	~OperatingPlayers();
};

