#pragma once
#include "Stage.h"

class TetrisPlayer
{
private:
	const unsigned int m_EXT_KEY = 0xffffffe0;
	const int m_KEY_LEFT = 0x4b;
	const int  m_KEY_RIGHT = 0x4d;
	const int  m_KEY_UP = 0x48;
	const int  m_KEY_DOWN = 0x50;
	Stage m_stage;
	GameContainer* [] m_gcArray;
	int m_frame;
	char m_keytemp;
	int m_is_gameOver;
	int m_speed;
	void init();
	int getKeyUp();
	int getKeyDown();
	int getKeyLeft();
	int getKeyRight();
	int getKeySpace();
	int showScreen(int speed);
	void setSpeed(int s);
	bool isClear(int l);
	bool isGameOver(int igo);

public:
	TetrisPlayer();
	~TetrisPlayer();
	void run();

};

