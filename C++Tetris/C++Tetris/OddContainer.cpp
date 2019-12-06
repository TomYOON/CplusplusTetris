#include "OddContainer.h"
#include <iostream>
#include <string>
using namespace std;

void OddContainer::show_tetromino(const int& x, const int& y)
{
	show_tetromino(m_cur_oddtetromino, x, y);
}

void OddContainer::show_tetromino(OddTetromino& tetromino, const int& x, const int& y)
{
	// 해당 블록에 맞는 색깔을 출력
	switch (tetromino.get_shape())
	{
	case 0: 
	case 1:
	case 2:
	case 3:
		setColor(RED); // odd tetromino
		break;
	case 4: //네모모양 ㅁ
		setColor(BLUE);
		break;
	case 5: //'ㅓ' 모양
		setColor(SKY_BLUE);
		break;
	case 6: //'ㄱ'모양
		setColor(WHITE);
		break;
	case 7: //'ㄴ' 모양
		setColor(YELLOW);
		break;
	case 8: //'Z' 모양
		setColor(VOILET);
		break;
	case 9: //'S' 모양
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

void OddContainer::make_cur_tetromino()
{
	int i;
	i = rand() % 100;
	int shape;
	if (i <= odd_per) {      //oddTetromino가 나올 확률
		shape = rand() % 3;
	}
	else {
		shape = rand() % 7 + 3;
	}
	m_cur_oddtetromino.set_shape(shape);
}

void OddContainer::make_next_tetromino()
{
	int i;
	i = rand() % 100;
	int shape;
	if (i <= odd_per) {      //oddTetromino가 나올 확률
		shape = rand() % 3;
	}
	else {
		shape = rand() % 7 + 3;
	}
	m_next_oddtetromino.set_shape(shape);
	m_next_oddtetromino.set_angle(0);
	show_next_tetromino();

	shape = (rand() % 6) + 1;      //shape에는 1~6의 값이 들어감
}

void OddContainer::erase_cur_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (m_cur_oddtetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + tetromino_x) * 2 + m_ab_x, j + tetromino_y + m_ab_y);
				cout << "  ";
				//break;

			}
		}
	}
}

int OddContainer::move_tetromino()
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
		cout << m_cur_oddtetromino.get_shape() << m_cur_oddtetromino.get_angle();
		merge_tetromino();
		m_cur_oddtetromino.set_shape(m_next_oddtetromino.get_shape());
		make_next_tetromino();
		//m_tetromino.set_next_shape(make_new_tetromino());

		tetromino_start();
		show_next_tetromino();
		return 2;
	}
	return 0;
}

void OddContainer::rotate_tetromino()
{
	m_cur_oddtetromino.set_angle((m_cur_oddtetromino.get_angle() + 1) % 4);
}

bool OddContainer::strike_check()
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


			if ((block_dat == 1) && (m_cur_oddtetromino.get_tetromino()[i][j] == 1))                                                                     //좌측벽의 좌표를 빼기위함
			{
				return 1;
			}
		}
	}
	return 0;
}

void OddContainer::merge_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m_total_block[tetromino_y + i][tetromino_x + j] |= m_cur_oddtetromino.get_tetromino()[i][j];
		}
	}
	check_full_line();
	show_total_block();
}

void OddContainer::show_next_tetromino()
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
	show_tetromino(m_next_oddtetromino, 16, 1);
}

void OddContainer::show_gamestat()
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