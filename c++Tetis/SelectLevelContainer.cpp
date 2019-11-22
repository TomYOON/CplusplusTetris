#include "SelectLevelContainer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

SelectLevelContainer::SelectLevelContainer()
	:Container(), m_level(1)
{
}

SelectLevelContainer::~SelectLevelContainer()
{
}

SelectLevelContainer::SelectLevelContainer(const int& ab_x, const int& ab_y)
	:Container(ab_x, ab_y), m_level(1)
{
}

void SelectLevelContainer::show_select_level()
{
	int i = 0;
	setColor(GRAY);
	gotoxy(10, 7);
	cout << "旨收收收收<GAME KEY>收收收收收收收收收收收收收收旬";
	Sleep(10);
	gotoxy(10, 8);
	cout << "早 UP   : Rotate Block        早";
	Sleep(10);
	gotoxy(10, 9);
	cout << "早 DOWN : Move One-Step Down  早";
	Sleep(10);
	gotoxy(10, 10);
	cout << "早 SPACE: Move Bottom Down    早";
	Sleep(10);
	gotoxy(10, 11);
	cout << "早 LEFT : Move Left           早";
	Sleep(10);
	gotoxy(10, 12);
	cout << "早 RIGHT: Move Right          早";
	Sleep(10);
	gotoxy(10, 13);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	while (i < 1 || i > 10)
	{
		gotoxy(10, 3);
		cout << "Select Start level[1-10]:       \b\b\b\b\b\b\b";
		cin >> i;
	}


	m_level = i - 1;
	system("cls");
}

int SelectLevelContainer::get_level()
{
	return m_level;
}
