#include "LogoContainer.h"
#include "SelectLevelContainer.h"
#include "GameContainer.h"
#include "Stage.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "OddContainer.h"
#include "OddTetromino.h"
#include "TestContainer.h"
using namespace std;

const unsigned int EXT_KEY = 0xffffffe0;
const int KEY_LEFT = 0x4b;
const int  KEY_RIGHT = 0x4d;
const int  KEY_UP = 0x48;
const int  KEY_DOWN = 0x50;

int main(void) {
	LogoContainer lc;
	SelectLevelContainer slc;
	TestContainer gc;
	Stage stage;

	int i;
	int is_gameover = 0;
	char keytemp;
	lc.show_logo();
	gc.init();
	while (1)
	{
		slc.show_select_level(); // ���̵� �Է�
		gc.set_level(slc.get_level());
		gc.show_total_block();  // �������̽� ����
		gc.make_cur_tetromino();// ��� ��� ����
		gc.show_next_tetromino(); // ���� ��� ��� ���
		gc.tetromino_start();
		gc.show_gamestat();
		for (i = 1; 1; i++)
		{
			if (_kbhit())      //Ű �Է��� �Ͼ��
			{
				keytemp = _getche();      //����Ű���� ������ ����
				if (keytemp == EXT_KEY)      //Ű �Է� ���� Ȯ��
				{
					keytemp = _getche();
					switch (keytemp)
					{
					case KEY_UP:      //ȸ���ϱ�

						if (gc.strike_check() == 0) //�浹�� ���� ��쿡�� �����ϰ�
						{
							gc.erase_cur_tetromino(); //���� ���� �����
							gc.rotate_tetromino();//���� �ޱ��� ����
							//���̶� �浹�� ��� �����·� x--
							if (gc.strike_check() == 1) {
								while (gc.strike_check()) gc.set_tetromino_x(gc.get_tetromino_x() - 1);
							}  
							gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //����� �� ���
						}
						break;
					case KEY_LEFT:      //�������� �̵�
						if (gc.get_tetromino_x() > 1)  //���̶� �浹 ���� ��츸
						{
							gc.erase_cur_tetromino();   //���� �������
							gc.set_tetromino_x(gc.get_tetromino_x() - 1); // x��ǥ �̵�
							if (gc.strike_check() == 1)  //���̶� �浹�� ��� �����·� x++
								gc.set_tetromino_x(gc.get_tetromino_x() + 1);

							gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //������ �� ������
						}
						break;
					case KEY_RIGHT:      //���������� �̵�

						if (gc.get_tetromino_x() < 14)   //������ ���̶� �浹 ���� ��츸
						{
							gc.erase_cur_tetromino();      // ���� ������
							gc.set_tetromino_x(gc.get_tetromino_x() + 1);   // x��ǥ �̵�
							if (gc.strike_check() == 1)   //���̶� �浹��
								gc.set_tetromino_x(gc.get_tetromino_x() - 1);        //������
							gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //������ �� ������
						}
						break;
					case KEY_DOWN:      //�Ʒ��� �̵�
						is_gameover = gc.move_tetromino(); //game_over�Ǵ� 1==over, 0==not over
						gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //������ ��������
						break;
					}
				}
				if (keytemp == 32)   //�����̽��ٸ� ��������
				{
					while (is_gameover == 0)
					{
						is_gameover = gc.move_tetromino();   //game_over �Ǵ�
					}
					gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());
				}
			}
			const Stage cur_stage = gc.get_stage_data()[gc.get_level()];
			if (i % cur_stage.get_speed() == 0)         //satge_data�� �����level�� speed�� ���� ���� �������� �ӵ��� ����. speed���� Ŭ���� ������ ������
			{
				is_gameover = gc.move_tetromino();

				gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());
			}

			if (cur_stage.get_clear_line() <= gc.get_lines())   //Ŭ���� ��������, �� ������ ���ΰ� �μ� ������ ������ Ŭ������ �Ǵ�
			{
				gc.set_level(gc.get_level() + 1);
				gc.set_lines(0);
				gc.show_total_block(); //���������� ���� ��º�ȭ�� �ٷ� �����ֱ����� �߰�
				gc.show_gamestat();
			}
			if (is_gameover == 1)         //���� ����
			{
				is_gameover = 0;
				gc.show_gameover();  //���ӿ��� �޼��� ���
				gc.setColor(GRAY);
				break;               //�ΰ��� ����Ż��
			}

			gc.gotoxy(77, 23);
			Sleep(15);         //������ �ӵ��� �����ϱ� ���ؼ�
			gc.gotoxy(77, 23);
		}
		gc.init(); //���ӿ������� Ż��� �ٽ� �ʱ�ȭ
	}
	return 0;
}