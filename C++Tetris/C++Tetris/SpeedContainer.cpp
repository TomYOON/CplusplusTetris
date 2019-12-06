#include "SpeedContainer.h"
#include <iostream>
#include <ctime>
using namespace std;

void SpeedContainer::change_random_speed()
{
	srand((unsigned int)time(NULL));
	int speed[4]{ 1,20,30,40 };
	for (int i = 0; i < 1; i++){
		stage_data[i].set_speed(speed[rand() % 3]);
	}
}

void SpeedContainer::merge_tetromino()
{
	change_random_speed();
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m_total_block[tetromino_y + i][tetromino_x + j] |= m_cur_tetromino.get_tetromino()[i][j];
		}
	}
	check_full_line();
	show_total_block();
}

void SpeedContainer::show_gamestat()
{
	static int printed_text = 0;
	setColor(GRAY);
	if (printed_text == 0)
	{
		gotoxy(m_ab_x + 30, m_ab_y + 8); // 35 7
		cout << "목표:";

		//gotoxy(35, 9);
		//cout << "SCORE";

		gotoxy(m_ab_x + 30, m_ab_y + 15);  // 35 12
		cout << "남은 쓰레기 양";


	}
	gotoxy(m_ab_x + 30, m_ab_y + 10); // 41 7
	cout << "분리수거를 하자.";
	//gotoxy(35, 10);
	//cout << m_score;
	gotoxy(m_ab_x + 30, m_ab_y + 17); // 35 13
	cout << stage_data[m_level].get_clear_line() - m_lines << " KG";
}
