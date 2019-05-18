#pragma once
#include "Estate.h"
#include <vector>
using namespace std;

struct Property
{
	Estate Estate;
	int Level = 0;
};

class Player
{
public:
	Player();

	int ID;
	int Money;
	int Position;
	
	vector<Property> OwnedProperties;
};

