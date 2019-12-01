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
	// �ش� ��Ͽ� �´� ������ ���
	switch (tetromino.get_shape())
	{
	case 0: 
	case 1:
	case 2:
	case 3:
		setColor(RED); // odd tetromino
		break;
	case 4: //�׸��� ��
		setColor(BLUE);
		break;
	case 5: //'��' ���
		setColor(SKY_BLUE);
		break;
	case 6: //'��'���
		setColor(WHITE);
		break;
	case 7: //'��' ���
		setColor(YELLOW);
		break;
	case 8: //'Z' ���
		setColor(VOILET);
		break;
	case 9: //'S' ���
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

void OddContainer::make_cur_tetromino()
{
	int i;
	i = rand() % 100;
	int shape;
	if (i <= odd_per) {      //oddTetromino�� ���� Ȯ��
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
	if (i <= odd_per) {      //oddTetromino�� ���� Ȯ��
		shape = rand() % 3;
	}
	else {
		shape = rand() % 7 + 3;
	}
	m_next_oddtetromino.set_shape(shape);
	m_next_oddtetromino.set_angle(0);
	show_next_tetromino();

	shape = (rand() % 6) + 1;      //shape���� 1~6�� ���� ��
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

	tetromino_y++;   //���� ��ĭ �Ʒ��� ����
	if (strike_check() == 1)
	{
		if (tetromino_y <= 0)   //���ӿ���
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


			if ((block_dat == 1) && (m_cur_oddtetromino.get_tetromino()[i][j] == 1))                                                                     //�������� ��ǥ�� ��������
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
	show_tetromino(m_next_oddtetromino, 15, 1);
}
