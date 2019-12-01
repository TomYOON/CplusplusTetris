#pragma once
#include "GameContainer.h"
class RandomFieldContainer :
	public GameContainer
{
private:
	void awlfield_init(); //송곳필드
	void stairsfield_init(); // 계단 필드
	void sewerfield_init();  // 하수구 필드
public:
	void init();
	

};

