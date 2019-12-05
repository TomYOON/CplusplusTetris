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
	// 각 gameContainer 가 출력할 스테이지 개수
	int m_maxStage = 2; 
	int m_level;
	int m_score;
	int m_lines;
	Stage stage_data[10]
		= { Stage(40,20,1), Stage(38,18,1), Stage(35,18,1), Stage(30,17,1), Stage(25,16,1),
	Stage(20,14,20), Stage(15,14,20), Stage(10,13,20), Stage(6,12,20), Stage(4,11,99999) };
private:


	Tetromino m_cur_tetromino, m_next_tetromino;

public:
	GameContainer();
	~GameContainer();
	GameContainer(const int& ab_x, const int& ab_y);
	int get_tetromino_x() const;
	int get_tetromino_y() const;
	int get_level() const;
	int get_lines() const;
	int get_tetromino_shape() const;
	virtual int get_max_stage() const;
	void set_level(const int& level);
	void set_lines(const int& lines);
	void set_tetromino_x(const int& x);
	void set_tetromino_y(const int& y);
	virtual void init();
	virtual void show_tetromino(const int& x, const int& y);
	virtual void show_tetromino(Tetromino& tetromino, const int& x, const int& y);
	virtual void show_total_block();
	virtual void show_next_tetromino();
	void show_gameover();
	virtual void show_gamestat();
	virtual void make_cur_tetromino();
	virtual void make_next_tetromino();
	virtual void erase_cur_tetromino();
	virtual bool strike_check();
	virtual void merge_tetromino();
	void tetromino_start();
	virtual int move_tetromino();
	virtual void rotate_tetromino();
	void check_full_line();
	const Stage(&get_stage_data())[10];
};

