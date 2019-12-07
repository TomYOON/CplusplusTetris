#pragma once
#include "Stage.h"
#include "GameContainer.h"
#include "StoryContainer.h"

class TetrisPlayer
{
private:
	static constexpr unsigned int m_EXT_KEY = 0xffffffe0;
	static constexpr int m_KEY_LEFT = 0x4b;
	static constexpr int  m_KEY_RIGHT = 0x4d;
	static constexpr int  m_KEY_UP = 0x48;
	static constexpr int  m_KEY_DOWN = 0x50;
	int m_MODE_LEN = 7;
	static const int m_CHEAT_KEY = 93; //"]" ��ư ������ ������������
	GameContainer** m_gcArray;
	StoryContainer sc;
	int m_frame;
	char m_keytemp;
	int m_is_gameOver;
	int m_speed;
	int m_modeCnt;
	int m_storyCnt;
	GameContainer* cur_mode;
	BgmPlayer bp;
	void init();
	void getKeyUp(GameContainer* cur_mode);
	void getKeyDown(GameContainer* cur_mode);
	void getKeyLeft(GameContainer* cur_mode);
	void getKeyRight(GameContainer* cur_mode);
	void getKeySpace(GameContainer* cur_mode);
	void showScreen(GameContainer* cur_mode, int speed);
	void setSpeed(int s);
	void showStageUp(GameContainer* cur_mode);
	void showModeUp();
	void showGameOver(GameContainer* cur_mode);
	bool isStoryEnd();
	bool isStageClear(Stage& cs, GameContainer* cm);
	bool isGameOver();


public:
	TetrisPlayer();
	TetrisPlayer(GameContainer** gc, int mode_len);
	~TetrisPlayer();
	void run();

};

