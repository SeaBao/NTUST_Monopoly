#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Menu
{
public:
	void printMenu();
	void printWord(int y);
private:
	COORD pos;
	HANDLE hOut;
};

extern Menu theMenu;