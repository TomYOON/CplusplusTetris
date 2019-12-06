#pragma once
#include "GameContainer.h"

class SpeedContainer :
	public GameContainer
{
private:
	void change_random_speed();
public:
	void merge_tetromino();
	void show_gamestat();
};

