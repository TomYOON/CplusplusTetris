#include "LogoContainer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

void LogoContainer::show_random_block(const int& x, const int& y)
{
	m_tetromino.set_shape(rand() % 7);
	m_tetromino.set_angle(rand() % 4);

	// �ش� ��Ͽ� �´� ������ ���
	get_tetromino_color(m_tetromino.get_shape());
	// ��ǥ x, y �� ���Ͽ� 4X4 ĭ ���� ����� ���
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// ȭ�� ���� �������� ����� �����Ѵ�.
			if ((j + y) < 0)
				continue;
			if (m_tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + x) * 2 + m_ab_x, j + y + m_ab_y);
				cout << "��";

			}
		}
	}
	// �ٽ� �������� �ٲ��� Ŀ�� �̵�
	setColor(BLACK);
	gotoxy(77, 23);
}

LogoContainer::LogoContainer()
:Container()
{
}

LogoContainer::LogoContainer(const int& ab_x, const int& ab_y)
	:Container(ab_x, ab_y)
{
}

LogoContainer::~LogoContainer()
{
}

void LogoContainer::show_logo()
{
	int i, j;
	gotoxy(13, 3);
	cout << "������������������������������������������������������������������������������������������������";
	Sleep(100);
	gotoxy(13, 4);
	cout << "���ߡߡ�  �ߡߡ�  �ߡߡ�   �ߡ�     ��   ��  �� ��";
	Sleep(100);
	gotoxy(13, 5);
	cout << "��  ��    ��        ��     �� ��    ��    �ߡ�  ��";
	Sleep(100);
	gotoxy(13, 6);
	cout << "��  ��    �ߡߡ�    ��     �ߡ�     ��     ��   ��";
	Sleep(100);
	gotoxy(13, 7);
	cout << "��  ��    ��        ��     �� ��    ��    �ߡ�  ��";
	Sleep(100);
	gotoxy(13, 8);
	cout << "��  ��    �ߡߡ�    ��     ��  ��   ��   ��  �� ��";
	Sleep(100);
	gotoxy(13, 9);
	cout << "������������������������������������������������������������������������������������������������";

	gotoxy(28, 20);
	cout << "Please Press Any Key~!";

	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{


			for (j = 0; j < 5; j++)
			{
				gotoxy(0, 14 + j);
				cout << "                                                                    ";


			}
			for (int k = 1; k < 5; k++){
				show_random_block(6 * k, 14);
			}
		}
		if (_kbhit())
			break;
		Sleep(30);
	}

	_getche();
	system("cls");
}
