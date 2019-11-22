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
	char m_total_block[21][14] = {0,};
	int tetromino_x;
	int tetromino_y;
	Tetromino m_tetromino;
	Stage stage_data[10]
		= { Stage(40,20,20), Stage(38,18,20), Stage(35,18,20), Stage(30,17,20), Stage(25,16,20),
	Stage(20,14,20), Stage(15,14,20), Stage(10,13,20), Stage(6,12,20), Stage(4,11,99999) };
public:
	GameContainer();
	~GameContainer();
	GameContainer(const int& ab_x, const int& ab_y);
	int get_tetromino_x() const;
	int get_tetromino_y() const;
	int get_level() const;
	int get_lines() const;
	int get_tetromino_shape() const;
	void set_level(const int& level);
	void set_lines(const int& lines);
	void set_tetromino_x(const int& x);
	void set_tetromino_y(const int& y);
	void init();
	void show_cur_tetromino(const int& x, const int& y);
	void erase_cur_tetromino();
	void show_total_block();
	void show_next_tetromino();
	void make_cur_tetromino();
	void make_next_tetromino();
	bool strike_check();
	void merge_tetromino();
	void tetromino_start();
	int move_tetromino();
	void rotate_tetromino();
	void show_gameover();
	void show_gamestat();
	void check_full_line();
	const Stage(&get_stage_data())[10];
	/*void show_cur_tetromino(const Tetromino& tetromino, const int& x, const int& y);
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
	void check_full_line();*/

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

