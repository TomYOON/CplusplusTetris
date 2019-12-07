#pragma once
#include "Tetromino.h"
class TrashTetromino :
	public Tetromino
{
	const char m_tetrominos[7][4][4][4] = {
		// ㄱ
		1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,	1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,	0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,	0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,
		//ㅁ ㅁㅁ
		1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,	1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,
		//ㅁ
		//    ㅁ
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,	1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,	0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,	1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		//ㅁ ㅁ
		//ㅁ
		0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,	0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,	0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,	0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,
		//ㅗ
		0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,	0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,	1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,	1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,
		//ㅣ ㅣ
		0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,	0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,	1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,	1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
		//ㅡ (난이도를 위해 하나 넣어줌)
		1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
	};
public:
	TrashTetromino();
	const char(&get_tetromino())[4][4];
};

