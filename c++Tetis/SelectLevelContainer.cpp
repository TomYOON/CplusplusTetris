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
	cout << "����������<GAME KEY>������������������������������";
	Sleep(10);
	gotoxy(10, 8);
	cout << "�� UP   : Rotate Block        ��";
	Sleep(10);
	gotoxy(10, 9);
	cout << "�� DOWN : Move One-Step Down  ��";
	Sleep(10);
	gotoxy(10, 10);
	cout << "�� SPACE: Move Bottom Down    ��";
	Sleep(10);
	gotoxy(10, 11);
	cout << "�� LEFT : Move Left           ��";
	Sleep(10);
	gotoxy(10, 12);
	cout << "�� RIGHT: Move Right          ��";
	Sleep(10);
	gotoxy(10, 13);
	cout << "������������������������������������������������������������";


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
