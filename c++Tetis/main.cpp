#include "LogoContainer.h"
#include "SelectLevelContainer.h"
#include "GameContainer.h"
#include "Stage.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

const unsigned int EXT_KEY = 0xffffffe0;
const int KEY_LEFT = 0x4b;
const int  KEY_RIGHT = 0x4d;
const int  KEY_UP = 0x48;
const int  KEY_DOWN = 0x50;

int main(void) {
	LogoContainer lc;
	SelectLevelContainer slc;
	GameContainer gc;
	Stage stage;

	int i;
	int is_gameover = 0;
	char keytemp;
	lc.show_logo();
	gc.init();
	while (1)
	{
		slc.show_select_level(); // 난이도 입력
		gc.set_level(slc.get_level());
		gc.show_total_block();  // 인터페이스 형성
		gc.make_cur_tetromino();// 블록 모양 생성
		gc.show_next_tetromino(); // 다음 블록 모양 출력
		gc.tetromino_start();
		gc.show_gamestat();
		for (i = 1; 1; i++)
		{
			if (_kbhit())      //키 입력이 일어나면
			{
				keytemp = _getche();      //무슨키인지 변수에 넣음
				if (keytemp == EXT_KEY)      //키 입력 범위 확인
				{
					keytemp = _getche();
					switch (keytemp)
					{
					case KEY_UP:      //회전하기

						if (gc.strike_check() == 0) //충돌이 없을 경우에만 가능하게
						{
							gc.erase_cur_tetromino(); //현재 블럭을 지우고
							gc.rotate_tetromino();//블럭의 앵글을 변경
							//블럭이랑 충돌할 경우 원상태로 x--
							if (gc.strike_check() == 1) {
								while (gc.strike_check()) gc.set_tetromino_x(gc.get_tetromino_x() - 1);
							}  
							gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //변경된 블럭 출력
						}
						break;
					case KEY_LEFT:      //왼쪽으로 이동
						if (gc.get_tetromino_x() > 1)  //벽이랑 충돌 안할 경우만
						{
							gc.erase_cur_tetromino();   //현재 블럭지우고
							gc.set_tetromino_x(gc.get_tetromino_x() - 1); // x좌표 이동
							if (gc.strike_check() == 1)  //블럭이랑 충돌할 경우 원상태로 x++
								gc.set_tetromino_x(gc.get_tetromino_x() + 1);

							gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //수정된 블럭 보여줌
						}
						break;
					case KEY_RIGHT:      //오른쪽으로 이동

						if (gc.get_tetromino_x() < 14)   //오른쪽 벽이랑 충돌 안할 경우만
						{
							gc.erase_cur_tetromino();      // 현재 블럭지움
							gc.set_tetromino_x(gc.get_tetromino_x() + 1);   // x좌표 이동
							if (gc.strike_check() == 1)   //블럭이랑 충돌시
								gc.set_tetromino_x(gc.get_tetromino_x() - 1);        //원상태
							gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //수정된 블럭 보여줌
						}
						break;
					case KEY_DOWN:      //아래로 이동
						is_gameover = gc.move_tetromino(); //game_over판단 1==over, 0==not over
						gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());  //수정된 블럭보여줌
						break;
					}
				}
				if (keytemp == 32)   //스페이스바를 눌렀을때
				{
					while (is_gameover == 0)
					{
						is_gameover = gc.move_tetromino();   //game_over 판단
					}
					gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());
				}
			}
			const Stage cur_stage = gc.get_stage_data()[gc.get_level()];
			if (i % cur_stage.get_speed() == 0)         //satge_data에 저장된level의 speed에 따라 블럭의 내려가는 속도를 조절. speed값이 클수록 느리게 떨어짐
			{
				is_gameover = gc.move_tetromino();

				gc.show_tetromino(gc.get_tetromino_x(), gc.get_tetromino_y());
			}

			if (cur_stage.get_clear_line() <= gc.get_lines())   //클리어 스테이지, 각 레벨별 라인과 부순 라인이 같으면 클리어라고 판단
			{
				gc.set_level(gc.get_level() + 1);
				gc.set_lines(0);
				gc.show_total_block(); //스테이지에 대한 출력변화를 바로 보여주기위해 추가
				gc.show_gamestat();
			}
			if (is_gameover == 1)         //게임 오버
			{
				is_gameover = 0;
				gc.show_gameover();  //게임오버 메세지 출력
				gc.setColor(GRAY);
				break;               //인게임 루프탈출
			}

			gc.gotoxy(77, 23);
			Sleep(15);         //루프의 속도를 조절하기 위해서
			gc.gotoxy(77, 23);
		}
		gc.init(); //게임오버에서 탈출시 다시 초기화
	}
	return 0;
}