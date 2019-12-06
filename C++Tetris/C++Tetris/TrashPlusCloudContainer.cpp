#include "TrashPlusCloudContainer.h"
#include <iostream>
using namespace std;
void TrashPlusCloudContainer::init()
{
	int count = 0;
	int k = 0;
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
			
			if (i < 19 && i > 6 && (j % 2 == 0) && (i%3==0)) {
				
		
				m_total_block[i][j] = 1;
				
				
			}

		}
		
		
	}
	//화면의 제일 밑의 줄은 1로 채운다.
	for (int j = 0; j < 14; j++)
		m_total_block[20][j] = 1;
}

void TrashPlusCloudContainer::show_gamestat()
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
	cout << "장애물들의 방해를 피해 쓰레기를 처리하자!";
	//gotoxy(35, 10);
	//cout << m_score;
	gotoxy(m_ab_x + 30, m_ab_y + 17); // 35 13
	cout << stage_data[m_level].get_clear_line() - m_lines << " KG";
}

