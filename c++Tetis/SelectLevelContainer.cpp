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
	printf("����������<GAME KEY>������������������������������");
	Sleep(10);
	gotoxy(10, 8);
	printf("�� UP   : Rotate Block        ��");
	Sleep(10);
	gotoxy(10, 9);
	printf("�� DOWN : Move One-Step Down  ��");
	Sleep(10);
	gotoxy(10, 10);
	printf("�� SPACE: Move Bottom Down    ��");
	Sleep(10);
	gotoxy(10, 11);
	printf("�� LEFT : Move Left           ��");
	Sleep(10);
	gotoxy(10, 12);
	printf("�� RIGHT: Move Right          ��");
	Sleep(10);
	gotoxy(10, 13);
	printf("������������������������������������������������������������");


	while (i < 1 || i > 10)
	{
		gotoxy(10, 3);
		printf("Select Start level[1-10]:       \b\b\b\b\b\b\b");
		scanf_s("%d", &i);
	}


	m_level = i - 1;
	system("cls");
}

int SelectLevelContainer::get_level()
{
	return m_level;
}
