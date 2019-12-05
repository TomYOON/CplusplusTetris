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
	m_storyCnt = 0;
}

void TetrisPlayer::getKeyUp(GameContainer* cur_mode)
{
	if (cur_mode->strike_check() == 0) //충돌이 없을 경우에만 가능하게
	{
		cur_mode->erase_cur_tetromino(); //현재 블럭을 지우고
		cur_mode->rotate_tetromino();//블럭의 앵글을 변경
		//블럭이랑 충돌할 경우 원상태로 x--
		if (cur_mode->strike_check() == 1) {
			while (cur_mode->strike_check()) cur_mode->set_tetromino_x(cur_mode->get_tetromino_x() - 1);
		}
		cur_mode->show_tetromino(cur_mode->get_tetromino_x(), cur_mode->get_tetromino_y());  //변경된 블럭 출력
	}
}

void TetrisPlayer::getKeyDown(GameContainer* cur_mode)
{
	m_is_gameOver = cur_mode->move_tetromino(); //game_over판단 1==over, 0==not over
	cur_mode->show_tetromino(cur_mode->get_tetromino_x(), cur_mode->get_tetromino_y());  //수정된 블럭보여줌
}

void TetrisPlayer::getKeyLeft(GameContainer* cur_mode)
{
	if (cur_mode->get_tetromino_x() > 1)  //벽이랑 충돌 안할 경우만
	{
		cur_mode->erase_cur_tetromino();   //현재 블럭지우고
		cur_mode->set_tetromino_x(cur_mode->get_tetromino_x() - 1); // x좌표 이동
		if (cur_mode->strike_check() == 1)  //블럭이랑 충돌할 경우 원상태로 x++
			cur_mode->set_tetromino_x(cur_mode->get_tetromino_x() + 1);

		cur_mode->show_tetromino(cur_mode->get_tetromino_x(), cur_mode->get_tetromino_y());  //수정된 블럭 보여줌
	}
}

void TetrisPlayer::getKeyRight(GameContainer* cur_mode)
{
	if (cur_mode->get_tetromino_x() < 14)   //오른쪽 벽이랑 충돌 안할 경우만
	{
		cur_mode->erase_cur_tetromino();      // 현재 블럭지움
		cur_mode->set_tetromino_x(cur_mode->get_tetromino_x() + 1);   // x좌표 이동
		if (cur_mode->strike_check() == 1)   //블럭이랑 충돌시
			cur_mode->set_tetromino_x(cur_mode->get_tetromino_x() - 1);        //원상태
		cur_mode->show_tetromino(cur_mode->get_tetromino_x(), cur_mode->get_tetromino_y());  //수정된 블럭 보여줌
	}
}

void TetrisPlayer::getKeySpace(GameContainer* cur_mode)
{
	while (m_is_gameOver == 0)
	{
		m_is_gameOver = cur_mode->move_tetromino();   //game_over 판단
	}
	cur_mode->show_tetromino(cur_mode->get_tetromino_x(), cur_mode->get_tetromino_y());
}

void TetrisPlayer::showScreen(GameContainer* cur_mode, int speed)
{
	if (m_frame % speed == 0)         //satge_data에 저장된level의 speed에 따라 블럭의 내려가는 속도를 조절. speed값이 클수록 느리게 떨어짐
	{
		m_is_gameOver = cur_mode->move_tetromino();

		cur_mode->show_tetromino(cur_mode->get_tetromino_x(), cur_mode->get_tetromino_y());
	}
}

void TetrisPlayer::setSpeed(int s)
{
	m_speed = s;
}

void TetrisPlayer::showStageUp(GameContainer* cur_mode)
{
	m_storyCnt++;
	system("cls");
	if (typeid(cur_mode) != typeid(GameContainer&)) {
		sc.startStory(m_storyCnt);
		system("cls");
	}
	cur_mode->set_level(cur_mode->get_level() + 1);
	cur_mode->set_lines(0);
	cur_mode->show_total_block(); //스테이지에 대한 출력변화를 바로 보여주기위해 추가
	cur_mode->show_gamestat();
}

void TetrisPlayer::showModeUp()
{
	m_storyCnt++;
	system("cls");
	if (typeid(cur_mode) != typeid(GameContainer&)) {
		sc.startStory(m_storyCnt);
		system("cls");
	}
	cur_mode = m_gcArray[m_modeCnt];
	cur_mode->init();
	cur_mode->set_lines(0);
	cur_mode->show_total_block(); //스테이지에 대한 출력변화를 바로 보여주기위해 추가
	cur_mode->show_gamestat();
}

void TetrisPlayer::showGameOver(GameContainer* cur_mode)
{
	if (typeid(cur_mode) == typeid(GameContainer&)) {
		cur_mode->show_gameover();
	}
	else {
		system("cls");
		sc.failedStory(m_modeCnt);
		
	}
	system("cls");
	;  //게임오버 메세지 출력
	
	cur_mode->setColor(GRAY);
}

bool TetrisPlayer::isStoryEnd()
{
	return m_modeCnt >= m_MODE_LEN;
}

bool TetrisPlayer::isStageClear(Stage& cs, GameContainer* cm)
{
	return cs.get_clear_line() <= cm->get_lines();
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
	: m_gcArray{ _gc }, m_frame{ 0 }, m_keytemp{ 0 }, m_is_gameOver{ 0 },
	m_speed{ 0 }, m_modeCnt{ 0 }, m_MODE_LEN{ mode_len }, cur_mode{ _gc[0] }
	, m_storyCnt{0}
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
		//GameContainer&* cur_mode = *m_gcArray[m_modeCnt];
		cur_mode->init();

		if (typeid(cur_mode) != typeid(GameContainer&)) {
			sc.startStory(m_storyCnt);
			system("cls");
		}
		

		cur_mode->show_total_block();  // 인터페이스 형성
		cur_mode->make_cur_tetromino();// 블록 모양 생성
		cur_mode->show_next_tetromino(); // 다음 블록 모양 출력
		
		cur_mode->tetromino_start();
		cur_mode->show_gamestat();
		
		for (m_frame = 1; 1; m_frame++)
		{
			if (_kbhit())      //키 입력이 일어나면
			{
				m_keytemp = _getche();      //무슨키인지 변수에 넣음
				if (m_keytemp == m_EXT_KEY)      //키 입력 범위 확인
				{
					m_keytemp = _getche();
					switch (m_keytemp)
					{
					case m_KEY_UP:      //회전하기
						getKeyUp(cur_mode);
						break;
					case m_KEY_LEFT:      //왼쪽으로 이동
						getKeyLeft(cur_mode);
						break;
					case m_KEY_RIGHT:      //오른쪽으로 이동
						getKeyRight(cur_mode);
						break;
					case m_KEY_DOWN:      //아래로 이동
						getKeyDown(cur_mode);
						break;
					}
				}
				if (m_keytemp == 32)   getKeySpace(cur_mode);//스페이스바를 눌렀을때
				if (m_keytemp == m_CHEAT_KEY) showStageUp(cur_mode);
			}
			Stage cur_stage = cur_mode->get_stage_data()[cur_mode->get_level()];
			showScreen(cur_mode, cur_stage.get_speed());
			if (isStageClear(cur_stage, cur_mode) || m_keytemp == m_CHEAT_KEY) {
				if (m_keytemp == m_CHEAT_KEY) m_keytemp = 'a';
				if (cur_mode->get_level() + 1 < cur_mode->get_max_stage()) showStageUp(cur_mode);
				else {
					m_modeCnt++;
					if (isStoryEnd()) {
						system("cls");
						sc.showStory8();
						system("cls");
						return;
					}
					showModeUp();
					cur_mode->init();
				}
				cur_mode->gotoxy(77, 23);
				Sleep(15);         //루프의 속도를 조절하기 위해서
				cur_mode->gotoxy(77, 23);
				//m_keytemp = 'a'; // 버퍼비워주기
			}
			else if (isGameOver()) {
				showGameOver(cur_mode);
				m_is_gameOver = 0;
				cur_mode->setColor(GRAY);
				cur_mode->init();//게임오버에서 탈출시 다시 초기화
				return;
			}

			cur_mode->gotoxy(77, 23);
			Sleep(15);         //루프의 속도를 조절하기 위해서
			cur_mode->gotoxy(77, 23);
		}
	}
}
