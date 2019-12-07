#pragma once

#include "TrashPlusCloudContainer.h"

class SpeedContainer :
	public TrashPlusCloudContainer
{
private:
	void change_random_speed();
public:
	void merge_tetromino();
	void show_gamestat();

};

