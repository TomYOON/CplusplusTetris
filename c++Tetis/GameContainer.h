#pragma once
#include "Container.h"
#include "Tetromino.h"
#include "Stage.h"
class GameContainer :
	public Container
{
private:
	int m_level;
	int m_score;
	int m_lines;
	char m_total_block[21][14];
	int tetromino_x;
	int tetromino_y;
	Tetromino m_tetromino;
	Stage stage_data[10];
public:
	void show_cur_tetromino(const Tetromino& tetromino, const int& x, const int& y);
	void erase_cur_block(const Tetromino& tetromino, const int& x, const int& y);
	void show_total_block();
	void show_next_block(const Tetromino& tetromino);
	void make_new_block(const Tetromino& tetromino);
	void strike_check(const Tetromino& tetromino, const int& x, const int& y);
	void merge_block(const Tetromino& tetromino, const int& x, const int& y);
	void block_start(const Tetromino& tetromino, const int& x, const int& y);
	void move_block(const Tetromino& tetromino, const int& x, const int& y);
	void rotate_block(const Tetromino& tetromino, const int& x, const int& y);
	void show_gameover();
	void show_gamestat();
	void check_full_line();

	/*
	+ erase_cur_block(int shape, int angle, int x, int y): type
	+ show_total_block(): type
	+ show_next_block(int shape): type
	+ make_new_block(): int
	+ strike_check(int shape, int angle, int x, int y): type
	+ merge_block(int shape, int angle, int x, int y): type
	+ block_start(int shape, int* angle, int* x, int* y): type
	+ move_block(int* shape, int* angle, int* x, int* y, int* next_shape): type
	+ rotate_block(int shape, int* angle, int* x, int* y): type
	+ show_gameover(): type
	+ show_gamestat(): type
	+ check_full_line(): type
	*/
};

