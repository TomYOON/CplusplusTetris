#pragma once
#include "GameContainer.h"
#include "OddTetromino.h"
#include "ClothTetromino.h"
class OddContainer :
	public GameContainer
{
private:
	OddTetromino m_cur_oddtetromino, m_next_oddtetromino;
	//int odd_per = 100; // 이상한 블럭 나올 확률
	//int index;
public:

	void show_tetromino(const int& x, const int& y);
	void show_tetromino(OddTetromino& tetromino, const int& x, const int& y);
	void make_cur_tetromino();
	void make_next_tetromino();
	void erase_cur_tetromino();
	int move_tetromino();
	void rotate_tetromino();
	bool strike_check();
	void merge_tetromino();
	void show_next_tetromino();
	void show_gamestat();

};

