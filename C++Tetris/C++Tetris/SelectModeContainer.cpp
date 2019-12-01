#include "SelectModeContainer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

SelectModeContainer::SelectModeContainer()
	:Container()
{
}

SelectModeContainer::~SelectModeContainer()
{
}

SelectModeContainer::SelectModeContainer(const int& ab_x, const int& ab_y)
	:Container(ab_x, ab_y)
{
}

void SelectModeContainer::show_select_mode()
{
	int i = 0;
	setColor(GRAY);
	gotoxy(10, 7);
	cout << "旨收收收收 < Keys / Game Mode >收收收收旬";
	Sleep(10);
	gotoxy(10, 8);
	cout << "早                             早";
	Sleep(10);
	gotoxy(10, 9);
	cout << "早   UP   : Rotate Block       早";
	Sleep(10);
	gotoxy(10, 10);
	cout << "早   DOWN : Move One-Step Down 早";
	Sleep(10);
	gotoxy(10, 11);
	cout << "早   SPACE: Move Bottom Down   早";
	Sleep(10);
	gotoxy(10, 12);
	cout << "早   LEFT : Move Left          早";
	Sleep(10);
	gotoxy(10, 13);
	cout << "早   RIGHT: Move Right         早";
	Sleep(10);
	gotoxy(10, 14);
	cout << "早                             早";
	Sleep(10);
	gotoxy(10, 15);
	cout << "早收收收收收收收收收收收收收收收收收收收收收收收收收收收收收早";
	Sleep(10);
	gotoxy(10, 16);
	cout << "早                             早";
	Sleep(10);
	gotoxy(10, 17);
	cout << "早        1. Level Mode        早";
	Sleep(10);
	gotoxy(10, 18);
	cout << "早                             早";
	Sleep(10);
	gotoxy(10, 19);
	cout << "早        2. Story Mode        早";
	Sleep(10);
	gotoxy(10, 20);
	cout << "早                             早";
	Sleep(10);
	gotoxy(10, 21);
	cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";


	while (i < 1 || i > 2)
	{
		gotoxy(12, 3);
		cout << "Select Game Mode [1 or 2] :       \b\b\b\b\b\b";
		cin >> i;
	}


	m_mode = i;
	system("cls");
}

int SelectModeContainer::get_mode()
{
	return m_mode;
}
