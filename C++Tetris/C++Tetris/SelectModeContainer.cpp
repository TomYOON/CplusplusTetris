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
	cout << "���������� < Keys / Game Mode >����������";
	Sleep(10);
	gotoxy(10, 8);
	cout << "��                             ��";
	Sleep(10);
	gotoxy(10, 9);
	cout << "��   UP   : Rotate Block       ��";
	Sleep(10);
	gotoxy(10, 10);
	cout << "��   DOWN : Move One-Step Down ��";
	Sleep(10);
	gotoxy(10, 11);
	cout << "��   SPACE: Move Bottom Down   ��";
	Sleep(10);
	gotoxy(10, 12);
	cout << "��   LEFT : Move Left          ��";
	Sleep(10);
	gotoxy(10, 13);
	cout << "��   RIGHT: Move Right         ��";
	Sleep(10);
	gotoxy(10, 14);
	cout << "��                             ��";
	Sleep(10);
	gotoxy(10, 15);
	cout << "��������������������������������������������������������������";
	Sleep(10);
	gotoxy(10, 16);
	cout << "��                             ��";
	Sleep(10);
	gotoxy(10, 17);
	cout << "��        1. Level Mode        ��";
	Sleep(10);
	gotoxy(10, 18);
	cout << "��                             ��";
	Sleep(10);
	gotoxy(10, 19);
	cout << "��        2. Story Mode        ��";
	Sleep(10);
	gotoxy(10, 20);
	cout << "��                             ��";
	Sleep(10);
	gotoxy(10, 21);
	cout << "��������������������������������������������������������������";


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
