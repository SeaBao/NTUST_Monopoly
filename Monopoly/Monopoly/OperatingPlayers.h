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
	char command;
	
public:
	OperatingPlayers();
	void GameStart();
	~OperatingPlayers();
};

