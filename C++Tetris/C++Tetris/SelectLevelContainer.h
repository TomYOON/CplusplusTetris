#pragma once
#include "Container.h"
class SelectLevelContainer :
	public Container
{
private:
	int m_level;
public:
	SelectLevelContainer();
	~SelectLevelContainer();
	SelectLevelContainer(const int& ab_x, const int& ab_y);
	void show_select_level();
	int get_level();
};

