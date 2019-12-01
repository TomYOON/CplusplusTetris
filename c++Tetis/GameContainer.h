#pragma once
#include "Container.h"
#include "Tetromino.h"
#include "Stage.h"
class GameContainer :
	public Container
{
protected:
	char m_total_block[21][14] = { 0, };
	int tetromino_x;
	int tetromino_y;
private:
	int m_level;
	int m_score;
	int m_lines;
	Tetromino m_cur_tetromino, m_next_tetromino;
	Stage stage_data[10]
		= { Stage(40,20,1), Stage(38,18,20), Stage(35,18,20), Stage(30,17,20), Stage(25,16,20),
	Stage(20,14,20), Stage(15,14,20), Stage(10,13,20), Stage(6,12,20), Stage(4,11,99999) };
public:
	GameContainer();
	~GameContainer();
	GameContainer(const int& ab_x, const int& ab_y);
	int get_tetromino_x() const;
	int get_tetromino_y() const;
	int get_level() const;
	int get_lines() const;
	virtual int get_tetromino_shape() const;
	void set_level(const int& level);
	void set_lines(const int& lines);
	void set_tetromino_x(const int& x);
	void set_tetromino_y(const int& y);
	void init();
	virtual void show_tetromino(const int& x, const int& y);
	virtual void show_tetromino(Tetromino& tetromino, const int& x, const int& y);
	void show_total_block();
	virtual void show_next_tetromino();
	void show_gameover();
	void show_gamestat();
	virtual void make_cur_tetromino();
	virtual void make_next_tetromino();
	virtual void erase_cur_tetromino();
	bool strike_check();
	virtual void merge_tetromino();
	void tetromino_start();
	virtual int move_tetromino();
	virtual void rotate_tetromino();
	virtual void check_full_line();
	const Stage(&get_stage_data())[10];
};

