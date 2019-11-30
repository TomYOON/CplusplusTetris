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

	// ȭ�� �ʱ�ȭ
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

	//ȭ���� ���� ���� ���� 1�� ä���.
	for (j = 0; j < 14; j++)
		m_total_block[20][j] = 1;

	//�������� �ʱ�ȭ
	m_level = 0;
	m_lines = 0;
	m_ab_x = 5;
	m_ab_y = 1;
}

void GameContainer::show_tetromino(const int& x, const int& y)
{
	show_tetromino(m_cur_tetromino, x, y);
}

void GameContainer::show_tetromino(Tetromino& tetromino, const int& x, const int& y)
{
	// �ش� ��Ͽ� �´� ������ ���
	get_tetromino_color(tetromino.get_shape());
	// ��ǥ x, y �� ���Ͽ� 4X4 ĭ ���� ����� ���
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// ȭ�� ���� �������� ����� �����Ѵ�.
			if ((j + y) < 0)
				continue;
			if (tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + x) * 2 + m_ab_x, j + y + m_ab_y);
				printf("��");

			}
		}
	}
	// �ٽ� �������� �ٲ��� Ŀ�� �̵�
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
				printf("  ");
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
			//������ ���� �ܺ� ���� �����Ѵ�.
			if (j == 0 || j == 13 || i == 20)
			{
				setColor((m_level % 6) + 1);

			}
			else { // �ٴڿ� ���� ����� ȸ������ ���
				setColor(DARK_GRAY);
			}
			gotoxy((j * 2) + m_ab_x, i + m_ab_y);
			// ����� ���� �ڸ��� ����� �Ѵ�.
			if (m_total_block[i][j] == 1)
			{
				printf("��");
			}
			else {
				printf("  ");
			}

		}
	}
	// ���������� �ٲ��� ����
	setColor(BLACK);
	gotoxy(77, 23);
}

void GameContainer::show_next_tetromino()
{
	int i, j;
	// ������ �ش��ϴ� �������� �ٲ���
	setColor((m_level + 1) % 6 + 1);
	for (i = 1; i < 7; i++)
	{
		// ���� ��� ��� ���� ��ġ�� �̵���
		gotoxy(33, i);
		// �ڽ��� ���
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				printf("��");
			}
			else {
				printf("  ");
			}

		}
	}
	// �ڽ� �ȿ� ���� ����� ����� ���
	/*show_cur_tetromino(15,1);*/
	show_tetromino(m_next_tetromino, 15, 1);
}

void GameContainer::make_cur_tetromino()
{
	int i;
	i = rand() % 100;
	if (i <= stage_data[m_level].get_stick_rate()) {      //����� ����Ȯ�� ���
		m_cur_tetromino.set_shape(0);
		return;                     //����� ������� ����
	}
	m_cur_tetromino.set_shape((rand() % 6) + 1);
}

void GameContainer::make_next_tetromino()
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[m_level].get_stick_rate()) {      //����� ����Ȯ�� ���
		m_next_tetromino.set_shape(0);
		return;                     //����� ������� ����
	}
	m_next_tetromino.set_shape((rand() % 6) + 1);
	m_next_tetromino.set_angle(0);
	show_next_tetromino();

	shape = (rand() % 6) + 1;      //shape���� 1~6�� ���� ��
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


			if ((block_dat == 1) && (m_cur_tetromino.get_tetromino()[i][j] == 1))                                                                     //�������� ��ǥ�� ��������
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

	tetromino_y++;   //���� ��ĭ �Ʒ��� ����
	if (strike_check() == 1)
	{
		if (tetromino_y <= 0)   //���ӿ���
		{
			return 1;
		}
		(tetromino_y)--;
		printf("%d, %d", m_cur_tetromino.get_shape(), m_cur_tetromino.get_angle());
		merge_tetromino();
		m_cur_tetromino.set_shape(m_next_tetromino.get_shape());   //next -> cur
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
	printf("����������������������������������������������������������");
	gotoxy(15, 9);
	printf("�� **************************��");
	gotoxy(15, 10);
	printf("�� *        GAME OVER       *��");
	gotoxy(15, 11);
	printf("�� **************************��");
	gotoxy(15, 12);
	printf("����������������������������������������������������������");
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
		printf("STAGE");

		gotoxy(35, 9);
		printf("SCORE");

		gotoxy(35, 12);
		printf("LINES");


	}
	gotoxy(41, 7);
	printf("%d", m_level + 1);
	gotoxy(35, 10);
	printf("%10d", m_score);
	gotoxy(35, 13);
	printf("%10d", stage_data[m_level].get_clear_line() - m_lines);
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
		if (j == 13)   //������ �� ä������
		{
			m_lines++;
			show_total_block();
			setColor(BLUE);
			gotoxy(1 * 2 + m_ab_x, i + m_ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("��");
				Sleep(10);
			}
			gotoxy(1 * 2 + m_ab_x, i + m_ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("  ");
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
