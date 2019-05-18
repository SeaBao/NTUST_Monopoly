#include "Estate.h"

Estate::Estate() : Location(L"", LocType::Estate, -1) {

}

Estate::Estate(wstring name, int pos, int price, array<int, 4> fees) : Location(name, LocType::Estate, pos)
{
	InitialPrice = price;
	Fees = fees;
}