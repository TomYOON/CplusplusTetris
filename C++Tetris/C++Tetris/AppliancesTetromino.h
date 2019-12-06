#pragma once
#include "Tetromino.h"
class AppliancesTetromino:
	public Tetromino
{
private:
	const char m_tetrominos[7][4][4][4] = {
		//��
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		//�׸��� ��
		1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
		//3*3 ��
		0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,	0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,	0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,	0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,
		//����
		0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,	0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,	0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,	0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,
		//���� ����
		0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,	0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,	0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,	0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,
		//4*4 ��
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		//�� 
		1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,

	};
public:
	AppliancesTetromino();
	const char(&get_tetromino())[4][4];

};
