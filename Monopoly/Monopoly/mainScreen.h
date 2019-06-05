#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;

class mainScreen
{
public:
	void printMainScreen();
	void printWord(int y);
	int selectPeople();

	void pressStart();
	void pressRead();
	void pressExp();
private:
	COORD pos;
	HANDLE hOut;
};

extern mainScreen theScreen;