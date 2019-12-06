#pragma once
#include "GameContainer.h"
#include "TrashTetromino.h"
class TrashContainer :
	public GameContainer
{
protected:
	TrashTetromino m_cur_trash_tetromino, m_next_trash_tetromino;
	

public:
	virtual void show_tetromino(const int& x, const int& y);
	virtual void show_tetromino(TrashTetromino& tetromino, const int& x, const int& y);
	virtual void make_cur_tetromino();

	virtual void make_next_tetromino();
	virtual void erase_cur_tetromino();
	virtual int move_tetromino();
	virtual void rotate_tetromino();
	virtual bool strike_check();
	virtual void merge_tetromino();
	virtual void show_next_tetromino();
	virtual void show_gamestat();
};

