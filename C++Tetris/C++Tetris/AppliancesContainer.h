#pragma once
#include "GameContainer.h"
#include "AppliancesTetromino.h"
class AppliancesContainer :
	public GameContainer
{
private:
	AppliancesTetromino m_cur_app_tetromino, m_next_app_tetromino;


public:
	void show_tetromino(const int& x, const int& y);
	void show_tetromino(AppliancesTetromino& tetromino, const int& x, const int& y);
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

