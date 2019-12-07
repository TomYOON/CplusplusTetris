#include "SpeedContainer.h"
#include <iostream>
#include <ctime>
using namespace std;

void SpeedContainer::change_random_speed()
{
	srand((unsigned int)time(NULL));
	int speed[4]{ 7,20,30,40 };
	for (int i = 0; i < 1; i++){
		stage_data[i].set_speed(speed[rand() % 3]);
	}
}
void SpeedContainer::merge_tetromino()
{

	change_random_speed();
	TrashPlusCloudContainer::merge_tetromino();
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
		cout << "남은 수거 횟수";


	}
	gotoxy(m_ab_x + 30, m_ab_y + 10); // 41 7
	cout << "중력권에 들어가 속도가 변하는 쓰레기들을 처리하자!";
	//gotoxy(35, 10);
	//cout << m_score;
	gotoxy(m_ab_x + 30, m_ab_y + 17); // 35 13
	cout << stage_data[m_level].get_clear_line() - m_lines << " 회";
}
