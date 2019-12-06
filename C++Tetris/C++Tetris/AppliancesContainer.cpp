#include "AppliancesContainer.h"
#include <iostream>
using namespace std;
void AppliancesContainer::show_tetromino(const int& x, const int& y)
{
	show_tetromino(m_cur_app_tetromino, x, y);
}

void AppliancesContainer::show_tetromino(AppliancesTetromino& tetromino, const int& x, const int& y)
{
	// 해당 블록에 맞는 색깔을 출력
	switch (tetromino.get_shape())
	{
	case 0: //막대모양 1
		setColor(RED);
		break;
	case 1: //네모모양 ㅁ
		setColor(BLUE);
		break;
	case 2: //'ㅓ' 모양
		setColor(SKY_BLUE);
		break;
	case 3: //'ㄱ'모양
		setColor(WHITE);
		break;
	case 4: //'ㄴ' 모양
		setColor(YELLOW);
		break;
	case 5: //'Z' 모양
		setColor(VOILET);
		break;
	case 6: //'S' 모양
		setColor(GREEN);
		break;
	}
	// 좌표 x, y 에 대하여 4X4 칸 내에 블록을 출력
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// 화면 밖을 나갈때는 출력을 생략한다.
			if ((j + y) < 0)
				continue;
			if (tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + x) * 2 + m_ab_x, j + y + m_ab_y);
				cout << "■";

			}
		}
	}
	// 다시 검정으로 바꾼후 커서 이동
	setColor(BLACK);
	gotoxy(77, 23);
}

void AppliancesContainer::make_cur_tetromino()
{
	int shape;
	shape = rand() % 7;
	m_cur_app_tetromino.set_shape(shape);
}

void AppliancesContainer::make_next_tetromino()
{
	int shape;
	shape = rand() % 7;
	m_next_app_tetromino.set_shape(shape);
	m_next_app_tetromino.set_angle(0);
	show_next_tetromino();
}

void AppliancesContainer::erase_cur_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (m_cur_app_tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + tetromino_x) * 2 + m_ab_x, j + tetromino_y + m_ab_y);
				cout << "  ";
				//break;

			}
		}
	}
}

int AppliancesContainer::move_tetromino()
{
	erase_cur_tetromino();

	tetromino_y++;   //블럭을 한칸 아래로 내림
	if (strike_check() == 1)
	{
		if (tetromino_y <= 0)   //게임오버
		{
			return 1;
		}
		(tetromino_y)--;
		cout << m_cur_app_tetromino.get_shape() << m_cur_app_tetromino.get_angle();
		merge_tetromino();
		m_cur_app_tetromino.set_shape(m_next_app_tetromino.get_shape());
		make_next_tetromino();
		//m_tetromino.set_next_shape(make_new_tetromino());

		tetromino_start();
		show_next_tetromino();
		return 2;
	}
	return 0;
}

void AppliancesContainer::rotate_tetromino()
{
	m_cur_app_tetromino.set_angle((m_cur_app_tetromino.get_angle() + 1) % 4);
}

bool AppliancesContainer::strike_check()
{
	int i, j;
	int block_dat;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			int moved_x = tetromino_x + j;
			int moved_y = tetromino_y + i;
			if ((moved_x == 0) || (moved_x == 13))
				block_dat = 1;
			else if (moved_y >= 0 && moved_y < 21 && moved_x >= 1 && moved_x < 14)
				block_dat = m_total_block[moved_y][moved_x];
			else
				block_dat = 0;


			if ((block_dat == 1) && (m_cur_app_tetromino.get_tetromino()[i][j] == 1))                                                                     //좌측벽의 좌표를 빼기위함
			{
				return 1;
			}
		}
	}
	return 0;
}

void AppliancesContainer::merge_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m_total_block[tetromino_y + i][tetromino_x + j] |= m_cur_app_tetromino.get_tetromino()[i][j];
		}
	}
	check_full_line();
	show_total_block();
}

void AppliancesContainer::show_next_tetromino()
{
	int i, j;
	// 레벨에 해당하는 색상으로 바꾼후
	setColor(1);
	for (i = 1; i < 7; i++)
	{
		// 다음 블록 출력 시작 위치로 이동후
		gotoxy(m_ab_x + 30, m_ab_y - 1 + i);
		// 박스를 출력
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}

		}
	}
	// 박스 안에 다음 블록의 모양을 출력
	/*show_cur_tetromino(15,1);*/
	show_tetromino(m_next_app_tetromino, 16, 1);
}

void AppliancesContainer::show_gamestat()
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
	cout << "가전제품 쓰레기들을 차곡차곡 정리하자!";
	//gotoxy(35, 10);
	//cout << m_score;
	gotoxy(m_ab_x + 30, m_ab_y + 17); // 35 13
	cout << stage_data[m_level].get_clear_line() - m_lines << " 회";
}
