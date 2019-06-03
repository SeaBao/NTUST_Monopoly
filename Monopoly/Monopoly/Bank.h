#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
using namespace std;

class Bank
{
public:
	static int AccMoney[4];
	static int AccDebt[4];
	static int AccPay[4];
	void printATM();
	void printWord(int y);
	void printMoney();
	int readAM(int pID);
	void writeAM();
	void payDebt();
	
private:
	COORD pos;
	HANDLE hOut;
};

extern Bank theBank;