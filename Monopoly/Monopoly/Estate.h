#pragma once
#include "Location.h"
#include <array>
using namespace std;

class Estate : public Location
{
public:
	Estate();
	Estate(wstring name, int pos, int price, array<int,4> fees);
	int HasBarrier;
	int InitialPrice;
	array<int, 4> Fees;
};

