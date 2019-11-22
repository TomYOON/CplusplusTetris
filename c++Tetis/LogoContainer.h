#pragma once
#include "Container.h"
#include "Tetromino.h"
class LogoContainer :
	public Container
{
private:
	Tetromino m_tetromino;
	void show_random_block(const int& x, const int& y);
public:
	LogoContainer();
	LogoContainer(const int& ab_x, const int& ab_y);
	~LogoContainer();
	void show_logo();
};

