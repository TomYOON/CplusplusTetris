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
		gotoxy(35, 7);
		cout << "STAGE";



		gotoxy(35, 12);
		cout << "LINES";


	}
	gotoxy(41, 7);
	cout << m_level + 1;
	gotoxy(35, 13);
	cout << stage_data[m_level].get_clear_line() - m_lines;
}
