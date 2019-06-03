#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
using namespace std;

class Stack
{
public:
	void printTheScreen();

	int getPlayerAccount();

	void readStackFile(string path);
	void writeStackFile();

	void rateChange(string path);
	void colorChange(int rate);

	void buyStacks();

private:
	int playerMoney;
	COORD pos;
	HANDLE hOut;
};

static wstring stackInfo[8][6];
extern Stack theStack;
