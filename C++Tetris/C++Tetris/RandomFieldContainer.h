#pragma once
#include "GameContainer.h"
class RandomFieldContainer :
	public GameContainer
{
private:
	void awlfield_init(); //�۰��ʵ�
	void stairsfield_init(); // ��� �ʵ�
	void sewerfield_init();  // �ϼ��� �ʵ�
	void cloudfield_init();
public:
	void init();
	void show_gamestat();
	

};

