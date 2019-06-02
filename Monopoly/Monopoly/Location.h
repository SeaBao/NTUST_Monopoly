#pragma once
#include <string>
using namespace std;

enum class LocType
{
	Start = 0,
	Estate = 1,
	Destiny = -1,
	Chance = -2
};


class Location
{
public:
	Location(wstring name, LocType type, int pos);
	LocType Type;
	wstring Name;
	int Position;
	
	bool operator<(const Location& loc) const;
	bool operator==(const Location& loc) const;
};

