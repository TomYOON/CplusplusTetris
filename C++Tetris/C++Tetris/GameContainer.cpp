#include "GameContainer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

GameContainer::GameContainer()
	:GameContainer(5,1)
{
}

GameContainer::~GameContainer()
{
}

GameContainer::GameContainer(const int& ab_x, const int& ab_y)
	:Container(ab_x, ab_y), m_level(0), m_lines(0), m_score(0), m_cur_tetromino(), m_next_tetromino(),
	tetromino_x(5), tetromino_y(-3)
{
}

int GameContainer::get_tetromino_x() const
{
	return tetromino_x;
}

int GameContainer::get_tetromino_y() const
{
	return tetromino_y;
}

int GameContainer::get_level() const
{
	return m_level;
}

int GameContainer::get_lines() const
{
	return m_lines;
}

int GameContainer::get_tetromino_shape() const
{
	return m_cur_tetromino.get_shape();
}

int GameContainer::get_max_stage() const
{
	return m_maxStage;
}

void GameContainer::set_level(const int& level)
{
	m_level = level;
}

void GameContainer::set_lines(const int& lines)
{
	m_lines = lines;
}

void GameContainer::set_tetromino_x(const int& x)
{
	tetromino_x = x;
}

void GameContainer::set_tetromino_y(const int& y)
{
	tetromino_y = y;
}

void GameContainer::init()
{
	int i, j;

	srand((unsigned)time(NULL));

	// 화면 초기화
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				m_total_block[i][j] = 1;
			}
			else {
				m_total_block[i][j] = 0;
			}
		}
	}

	//화면의 제일 밑의 줄은 1로 채운다.
	for (j = 0; j < 14; j++)
		m_total_block[20][j] = 1;

	
	m_level = 0;
	m_lines = 0;
	m_ab_x = 5;
	m_ab_y = 1;
	m_score = 0;
}

void GameContainer::show_tetromino(const int& x, const int& y)
{
	show_tetromino(m_cur_tetromino, x, y);
}

void GameContainer::show_tetromino(Tetromino& tetromino, const int& x, const int& y)
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

void GameContainer::erase_cur_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (m_cur_tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + tetromino_x) * 2 + m_ab_x, j + tetromino_y + m_ab_y);
				cout << "  ";
				//break;

			}
		}
	}
}

void GameContainer::show_total_block()
{
	int i, j;
	setColor(DARK_GRAY);
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			//레벨에 따라 외벽 색을 변경한다.
			if (j == 0 || j == 13 || i == 20)
			{
				setColor((m_level % 6) + 1);

			}
			else { // 바닥에 앉은 블록은 회색으로 출력
				setColor(DARK_GRAY);
			}
			gotoxy((j * 2) + m_ab_x, i + m_ab_y);
			// 블록이 앉은 자리는 출력을 한다.
			if (m_total_block[i][j] == 1)
			{
				cout << "■";
			}
			else {
				cout << "  ";
			}

		}
	}
	// 검은색으로 바꾼후 종료
	setColor(BLACK);
	gotoxy(77, 23);
}

void GameContainer::show_next_tetromino()
{
	int i, j;
	// 레벨에 해당하는 색상으로 바꾼후
	setColor((m_level + 1) % 6 + 1);
	for (i = 1; i < 7; i++)
	{
		// 다음 블록 출력 시작 위치로 이동후
		gotoxy(33, i);
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
	show_tetromino(m_next_tetromino, 15, 1);
}

void GameContainer::make_cur_tetromino()
{
	int i;
	i = rand() % 100;
	if (i <= stage_data[m_level].get_stick_rate()) {      //막대기 나올확률 계산
		m_cur_tetromino.set_shape(0);
		return;                     //막대기 모양으로 리턴
	}
	m_cur_tetromino.set_shape((rand() % 6) + 1);
}

void GameContainer::make_next_tetromino()
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[m_level].get_stick_rate()) {      //막대기 나올확률 계산
		m_next_tetromino.set_shape(0);
		return;                     //막대기 모양으로 리턴
	}
	m_next_tetromino.set_shape((rand() % 6) + 1);
	m_next_tetromino.set_angle(0);
	show_next_tetromino();

	shape = (rand() % 6) + 1;      //shape에는 1~6의 값이 들어감
}

bool GameContainer::strike_check()
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


			if ((block_dat == 1) && (m_cur_tetromino.get_tetromino()[i][j] == 1))                                                                     //좌측벽의 좌표를 빼기위함
			{
				return 1;
			}
		}
	}
	return 0;
}

void GameContainer::merge_tetromino()
{
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

void GameContainer::tetromino_start()
{
	tetromino_x = 5;
	tetromino_y = -3;
	m_cur_tetromino.set_angle(0);
}

int GameContainer::move_tetromino()
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
		cout << m_cur_tetromino.get_shape() << m_cur_tetromino.get_angle();
		merge_tetromino();
		m_cur_tetromino.set_shape(m_next_tetromino.get_shape());
		make_next_tetromino();
		//m_tetromino.set_next_shape(make_new_tetromino());

		tetromino_start();
		show_next_tetromino();
		return 2;
	}
	return 0;
}

void GameContainer::rotate_tetromino()
{
	m_cur_tetromino.set_angle((m_cur_tetromino.get_angle() + 1) % 4);
}

void GameContainer::show_gameover()
{
	setColor(RED);
	gotoxy(15, 8);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(15, 9);
	cout << "┃ **************************┃";
	gotoxy(15, 10);
	cout << "┃ *        GAME OVER       *┃";
	gotoxy(15, 11);
	cout << "┃ **************************┃";
	gotoxy(15, 12);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	fflush(stdin);
	Sleep(1000);

	_getche();
	system("cls");
}

void GameContainer::show_gamestat()
{
	static int printed_text = 0;
	setColor(GRAY);
	if (printed_text == 0)
	{
		gotoxy(35, 7);
		cout << "STAGE";

		gotoxy(35, 9);
		cout << "SCORE";

		gotoxy(35, 12);
		cout << "LINES";


	}
	gotoxy(41, 7);
	cout << m_level + 1;
	gotoxy(35, 10);
	cout << m_score;
	gotoxy(35, 13);
	cout << stage_data[m_level].get_clear_line() - m_lines;
}

void GameContainer::check_full_line()
{
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (m_total_block[i][j] == 0)
				break;
		}
		if (j == 13)   //한줄이 다 채워졌음
		{
			m_lines++;
			show_total_block();
			setColor(BLUE);
			gotoxy(1 * 2 + m_ab_x, i + m_ab_y);
			for (j = 1; j < 13; j++)
			{
				cout << "□";
				Sleep(10);
			}
			gotoxy(1 * 2 + m_ab_x, i + m_ab_y);
			for (j = 1; j < 13; j++)
			{
				cout << "  ";
				Sleep(10);
			}

			for (k = i; k > 0; k--)
			{
				for (j = 1; j < 13; j++)
					m_total_block[k][j] = m_total_block[k - 1][j];
			}
			for (j = 1; j < 13; j++)
				m_total_block[0][j] = 0;
			m_score += 100 + (m_level * 10) + (rand() % 10);
			show_gamestat();
		}
	}
}

const Stage(&GameContainer::get_stage_data())[10]
{
	return stage_data;
}
