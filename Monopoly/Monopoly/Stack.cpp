#include "Stack.h"
#include "Utility.h"

Stack theStack;


void Stack::printTheScreen()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 98;
	pos.Y = 11;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"        │ 成交價│ 漲跌│ P 1│ P 2│ P 3│ P 4│";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"土豪銀行│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"原民航空│       │     │    │    │    │    │";
	pos.Y ++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"客家集團│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"翻牆通訊│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"維尼製藥│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"國魚廣播│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"高雄旅遊│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┼───────┼─────┼────┼────┼────┼────┤";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"佳豪企業│       │     │    │    │    │    │";
	pos.Y++;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"────────┴───────┴─────┴────┴────┴────┴────┘";
}

void Stack::readStackFile(string path)
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	wifstream file;
	file.open(path);

	if (file.is_open())
	{
		int row = 0;
		wstring line;
		while (getline(file, line))
		{
			row++;
			vector<wstring> store;
			Split(line, store, ' ');
			pos.X = 108;
			pos.Y = 10 + 2 * row + 1;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[0] << endl;
			pos.X = 116;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[1] << endl;
			pos.X = 122;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[2] << endl;
			pos.X = 127;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[3] << endl;
			pos.X = 132;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[4] << endl;
			pos.X = 137;
			SetConsoleCursorPosition(hOut, pos);
			wcout << store[5] << endl;
		}
	}
	file.close();
}

void Stack::writeStackFile()
{
	wstringstream s;
	wofstream outStream("Stacks.txt");
	if (outStream.is_open())
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				wstring temp = stackInfo[i][j];
				s << temp;
				if (i == 7 and j == 5) break;
				s << (j == 5 ? "\n" : " ");
			}
		}
	}
	outStream << s.str();
	outStream.close();
}

void Stack::rateChange(string path)
{
	wifstream file;
	file.imbue(locale("zh_TW.UTF-8"));
	file.open(path);
	if (file.is_open())
	{
		int row = 0;
		wstring line;
		vector<wstring> store;
		int count = 0;
		while (!file.eof())
		{
			getline(file, line);
			Split(line, store, ' ');

			for (int j = 0; j < 6; j++)
			{
				stackInfo[count][j] = store[j];
			}
			count++;
		}
		for (int i = 0; i <= 7; i++)
		{
			int up = 0 + rand() % 10;
			int down = 0 + rand() % 10;
			int rate = up - down;
			int temp = stoi(stackInfo[i][0]);
			temp += rate;
			stackInfo[i][0] = to_wstring(temp);
		}
		Stack temp;
		temp.writeStackFile();
		temp.readStackFile("Stacks.txt");
	}
	file.close();
}