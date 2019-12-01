#pragma once
#include "Container.h"
class SelectModeContainer :
	public Container
{
private:
	int m_mode;
public:
	SelectModeContainer();
	~SelectModeContainer();
	SelectModeContainer(const int& ab_x, const int& ab_y);
	void show_select_mode();
	int get_mode();
};