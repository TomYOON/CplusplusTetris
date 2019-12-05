#include "TetrisPlayer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

void TetrisPlayer::init()
{
	m_frame = 0;
	m_keytemp = 0; 
	m_is_gameOver = 0;
	m_speed = 0;
	m_modeCnt = 0;
}

void TetrisPlayer::getKeyUp(GameContainer& cur_mode)
{
	if (cur_mode.strike_check() == 0) //�浹�� ���� ��쿡�� �����ϰ�
	{
		cur_mode.erase_cur_tetromino(); //���� ���� �����
		cur_mode.rotate_tetromino();//���� �ޱ��� ����
		//���̶� �浹�� ��� �����·� x--
		if (cur_mode.strike_check() == 1) {
			while (cur_mode.strike_check()) cur_mode.set_tetromino_x(cur_mode.get_tetromino_x() - 1);
		}
		cur_mode.show_tetromino(cur_mode.get_tetromino_x(), cur_mode.get_tetromino_y());  //����� �� ���
	}
}

void TetrisPlayer::getKeyDown(GameContainer& cur_mode)
{
	m_is_gameOver = cur_mode.move_tetromino(); //game_over�Ǵ� 1==over, 0==not over
	cur_mode.show_tetromino(cur_mode.get_tetromino_x(), cur_mode.get_tetromino_y());  //������ ��������
}

void TetrisPlayer::getKeyLeft(GameContainer& cur_mode)
{
	if (cur_mode.get_tetromino_x() > 1)  //���̶� �浹 ���� ��츸
	{
		cur_mode.erase_cur_tetromino();   //���� �������
		cur_mode.set_tetromino_x(cur_mode.get_tetromino_x() - 1); // x��ǥ �̵�
		if (cur_mode.strike_check() == 1)  //���̶� �浹�� ��� �����·� x++
			cur_mode.set_tetromino_x(cur_mode.get_tetromino_x() + 1);

		cur_mode.show_tetromino(cur_mode.get_tetromino_x(), cur_mode.get_tetromino_y());  //������ �� ������
	}
}

void TetrisPlayer::getKeyRight(GameContainer& cur_mode)
{
	if (cur_mode.get_tetromino_x() < 14)   //������ ���̶� �浹 ���� ��츸
	{
		cur_mode.erase_cur_tetromino();      // ���� ������
		cur_mode.set_tetromino_x(cur_mode.get_tetromino_x() + 1);   // x��ǥ �̵�
		if (cur_mode.strike_check() == 1)   //���̶� �浹��
			cur_mode.set_tetromino_x(cur_mode.get_tetromino_x() - 1);        //������
		cur_mode.show_tetromino(cur_mode.get_tetromino_x(), cur_mode.get_tetromino_y());  //������ �� ������
	}
}

void TetrisPlayer::getKeySpace(GameContainer& cur_mode)
{
	while (m_is_gameOver == 0)
	{
		m_is_gameOver = cur_mode.move_tetromino();   //game_over �Ǵ�
	}
	cur_mode.show_tetromino(cur_mode.get_tetromino_x(), cur_mode.get_tetromino_y());
}

void TetrisPlayer::showScreen(GameContainer& cur_mode, int speed)
{
	if (m_frame % speed == 0)         //satge_data�� �����level�� speed�� ���� ���� �������� �ӵ��� ����. speed���� Ŭ���� ������ ������
	{
		m_is_gameOver = cur_mode.move_tetromino();

		cur_mode.show_tetromino(cur_mode.get_tetromino_x(), cur_mode.get_tetromino_y());
	}
}

void TetrisPlayer::setSpeed(int s)
{
	m_speed = s;
}

void TetrisPlayer::showStageUp(GameContainer& cur_mode)
{
	cur_mode.set_level(cur_mode.get_level() + 1);
	cur_mode.set_lines(0);
	cur_mode.show_total_block(); //���������� ���� ��º�ȭ�� �ٷ� �����ֱ����� �߰�
	cur_mode.show_gamestat();
}

void TetrisPlayer::showModeUp(GameContainer& cur_mode)
{
	GameContainer& next_mode = *m_gcArray[m_modeCnt];
	next_mode.set_lines(0);
	next_mode.show_total_block(); //���������� ���� ��º�ȭ�� �ٷ� �����ֱ����� �߰�
	next_mode.show_gamestat();
}

void TetrisPlayer::showGameOver(GameContainer& cur_mode)
{
	cur_mode.show_gameover();  //���ӿ��� �޼��� ���
	cur_mode.setColor(GRAY);
}

bool TetrisPlayer::isStoryEnd()
{
	return m_modeCnt >= m_MODE_LEN;
}

bool TetrisPlayer::isStageClear(Stage& cs, GameContainer& cm)
{
	return cs.get_clear_line() <= cm.get_lines();
}

bool TetrisPlayer::isGameOver()
{
	return m_is_gameOver == 1;
}

TetrisPlayer::TetrisPlayer()
	:TetrisPlayer(nullptr, 0)
{
}

TetrisPlayer::TetrisPlayer(GameContainer** _gc , int mode_len)
	:m_gcArray{ _gc }, m_frame{ 0 }, m_keytemp{ 0 }, m_is_gameOver{0},
	m_speed{ 0 }, m_modeCnt{ 0 }, m_MODE_LEN{mode_len}
{
}
TetrisPlayer::~TetrisPlayer()
{
}

void TetrisPlayer::run()
{
	init();
	while (1)
	{
		GameContainer& cur_mode = *m_gcArray[m_modeCnt];
		cur_mode.init();
		cur_mode.show_total_block();  // �������̽� ����
		cur_mode.make_cur_tetromino();// ��� ��� ����
		cur_mode.show_next_tetromino(); // ���� ��� ��� ���
		cur_mode.tetromino_start();
		cur_mode.show_gamestat();
		for (m_frame = 1; 1; m_frame++)
		{
			if (_kbhit())      //Ű �Է��� �Ͼ��
			{
				m_keytemp = _getche();      //����Ű���� ������ ����
				if (m_keytemp == m_EXT_KEY)      //Ű �Է� ���� Ȯ��
				{
					m_keytemp = _getche();
					switch (m_keytemp)
					{
					case m_KEY_UP:      //ȸ���ϱ�
						getKeyUp(cur_mode);
						break;
					case m_KEY_LEFT:      //�������� �̵�
						getKeyLeft(cur_mode);
						break;
					case m_KEY_RIGHT:      //���������� �̵�
						getKeyRight(cur_mode);
						break;
					case m_KEY_DOWN:      //�Ʒ��� �̵�
						getKeyDown(cur_mode);
						break;
					}
				}
				if (m_keytemp == 32)   getKeySpace(cur_mode);//�����̽��ٸ� ��������
				
			}
			Stage cur_stage = cur_mode.get_stage_data()[cur_mode.get_level()];
			showScreen(cur_mode, cur_stage.get_speed());
			if (isStageClear(cur_stage, cur_mode) || m_keytemp == m_CHEAT_KEY) {
				if (cur_mode.get_level() < cur_mode.get_max_stage()) showStageUp(cur_mode);
				else {
					m_modeCnt++;
					if (isStoryEnd()) {
						system("cls");
						return;
					}
					showModeUp(cur_mode);
					cur_mode.init();
				}
				cur_mode.gotoxy(77, 23);
				Sleep(15);         //������ �ӵ��� �����ϱ� ���ؼ�
				cur_mode.gotoxy(77, 23);
				//m_keytemp = 'a'; // ���ۺ���ֱ�
			}
			else if (isGameOver()) {
				showGameOver(cur_mode);
				m_is_gameOver = 0;
				cur_mode.setColor(GRAY);
				cur_mode.init();//���ӿ������� Ż��� �ٽ� �ʱ�ȭ
				return;
			}

			cur_mode.gotoxy(77, 23);
			Sleep(15);         //������ �ӵ��� �����ϱ� ���ؼ�
			cur_mode.gotoxy(77, 23);
		}
	}
}
