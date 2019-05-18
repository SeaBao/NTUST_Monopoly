#pragma once
#include<stdio.h>
#include <conio.h>
#include <iostream>
#include"GameMap.h"
using namespace std;
class OperatingPlayers
{
private:
	char command;
	int turn;
public:
	OperatingPlayers();
	void GameStart();
	~OperatingPlayers();
};

