#include "RandomFieldContainer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;
void RandomFieldContainer::init()
{
	int i, j;

	srand((unsigned)time(NULL));
	int what_field = rand() % 3;
	switch (what_field)
	{
	case 0:
		awlfield_init();
		break;
	case 1:
		stairsfield_init();
		break;
	case 2:
		sewerfield_init();
	}

	// ȭ�� �ʱ�ȭ
	//awlfield_init();
	//stairsfield_init();
	//sewerfield_init();
		
	//ȭ���� ���� ���� ���� 1�� ä���.
	for (j = 0; j < 14; j++)
		m_total_block[20][j] = 1;


	/*m_level = 0;
	m_lines = 0;*/
	m_ab_x = 5;
	m_ab_y = 1;
}

void RandomFieldContainer::show_gamestat()
{
	static int printed_text = 0;
	setColor(GRAY);
	if (printed_text == 0)
	{
		gotoxy(m_ab_x + 30, m_ab_y + 8); // 35 7
		cout << "��ǥ:";

		//gotoxy(35, 9);
		//cout << "SCORE";

		gotoxy(m_ab_x + 30, m_ab_y + 15);  // 35 12
		cout << "���� ������ ��";


	}
	gotoxy(m_ab_x + 30, m_ab_y + 10); // 41 7
	cout << "�и����Ÿ� ����.";
	//gotoxy(35, 10);
	//cout << m_score;
	gotoxy(m_ab_x + 30, m_ab_y + 17); // 35 13
	cout << stage_data[m_level].get_clear_line() - m_lines << " KG";
}

void RandomFieldContainer::awlfield_init()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				m_total_block[i][j] = 1;
			}
			else {
				m_total_block[i][j] = 0;
			}

			if (j% 2 && i > 15) {
				m_total_block[i][j] = 1;
			}

		}

	}
}

void RandomFieldContainer::stairsfield_init()
{
	int floor = 0;
	for (int i = 20; i > 0; i--)
	{
		for (int j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				m_total_block[i][j] = 1;
			}
			else {
				m_total_block[i][j] = 0;
			}

			if (j > floor ) {
				m_total_block[i][j] = 1;
			}

		}
		floor++;
	}
}

void RandomFieldContainer::sewerfield_init()
{
	for (int i = 20; i > 0; i--)
	{
		for (int j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				m_total_block[i][j] = 1;
			}
			else {
				m_total_block[i][j] = 0;
			}

			if (i == 17 && j % 2) {
				m_total_block[i][j] = 1;
			}

		}
	}
}

void RandomFieldContainer::cloudfield_init()
{
	for (int i = 20; i > 0; i--)
	{
		for (int j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				m_total_block[i][j] = 1;
			}
			else {
				m_total_block[i][j] = 0;
			}

			if (i > 17 && i < 6 && j % 2) {
				int k = rand() % 14;
				m_total_block[i][k] = 1;
			}

		}
	}
}