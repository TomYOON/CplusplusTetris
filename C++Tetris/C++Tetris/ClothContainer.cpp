#include "ClothContainer.h"
#include <iostream>
using namespace std;

void ClothContainer::show_tetromino(const int& x, const int& y)
{
	show_tetromino(m_cur_cloth_tetromino, x, y);
}

void ClothContainer::show_tetromino(ClothTetromino& tetromino, const int& x, const int& y)
{
	// �ش� ��Ͽ� �´� ������ ���
	switch (tetromino.get_shape())
	{
	case 0: //������ 1
		setColor(RED);
		break;
	case 1: //�׸��� ��
		setColor(BLUE);
		break;
	case 2: //'��' ���
		setColor(SKY_BLUE);
		break;
	case 3: //'��'���
		setColor(WHITE);
		break;
	case 4: //'��' ���
		setColor(YELLOW);
		break;
	case 5: //'Z' ���
		setColor(VOILET);
		break;
	case 6: //'S' ���
		setColor(GREEN);
		break;
	}
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
				cout << "��";

			}
		}
	}
	// �ٽ� �������� �ٲ��� Ŀ�� �̵�
	setColor(BLACK);
	gotoxy(77, 23);
}

void ClothContainer::make_cur_tetromino()
{
	int shape;
	shape = rand() % 7;
	m_cur_cloth_tetromino.set_shape(shape);
}

void ClothContainer::make_next_tetromino()
{
	int shape;
	shape = rand() % 7;
	m_next_cloth_tetromino.set_shape(shape);
	m_next_cloth_tetromino.set_angle(0);
	show_next_tetromino();
}

void ClothContainer::erase_cur_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (m_cur_cloth_tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + tetromino_x) * 2 + m_ab_x, j + tetromino_y + m_ab_y);
				cout << "  ";
				//break;

			}
		}
	}
}

int ClothContainer::move_tetromino()
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
		cout << m_cur_cloth_tetromino.get_shape() << m_cur_cloth_tetromino.get_angle();
		merge_tetromino();
		m_cur_cloth_tetromino.set_shape(m_next_cloth_tetromino.get_shape());
		make_next_tetromino();
		//m_tetromino.set_next_shape(make_new_tetromino());

		tetromino_start();
		show_next_tetromino();
		return 2;
	}
	return 0;
}

void ClothContainer::rotate_tetromino()
{
	m_cur_cloth_tetromino.set_angle((m_cur_cloth_tetromino.get_angle() + 1) % 4);
}

bool ClothContainer::strike_check()
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


			if ((block_dat == 1) && (m_cur_cloth_tetromino.get_tetromino()[i][j] == 1))                                                                     //�������� ��ǥ�� ��������
			{
				return 1;
			}
		}
	}
	return 0;
}

void ClothContainer::merge_tetromino()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m_total_block[tetromino_y + i][tetromino_x + j] |= m_cur_cloth_tetromino.get_tetromino()[i][j];
		}
	}
	check_full_line();
	show_total_block();
}

void ClothContainer::show_next_tetromino()
{
	int i, j;
	// ������ �ش��ϴ� �������� �ٲ���
	setColor(1);
	for (i = 1; i < 7; i++)
	{
		// ���� ��� ��� ���� ��ġ�� �̵���
		gotoxy(33, i);
		// �ڽ��� ���
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				cout << "��";
			}
			else {
				cout << "  ";
			}

		}
	}
	// �ڽ� �ȿ� ���� ����� ����� ���
	/*show_cur_tetromino(15,1);*/
	show_tetromino(m_next_cloth_tetromino, 15, 1);
}

void ClothContainer::show_gamestat()
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

