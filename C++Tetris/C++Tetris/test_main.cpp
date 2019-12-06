#include "LogoContainer.h"
#include "SelectLevelContainer.h"
#include "GameContainer.h"
#include "Stage.h"
#include "TetrisPlayer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "OddContainer.h"
#include "RandomFieldContainer.h"
#include "SelectModeContainer.h"
#include "SpeedContainer.h"
#include "ClothContainer.h"
#include "TrashContainer.h"
#include "AppliancesContainer.h"
#include "TrashPlusCloudContainer.h"
using namespace std;

const int LEVEL_MODE = 1;
const int STORY_MODE = 2;

int main(void) {
	LogoContainer lc;
	SelectLevelContainer slc;
	GameContainer g1;
	OddContainer oc;
	RandomFieldContainer r1;
	SpeedContainer sc;
	SelectModeContainer smc;
	ClothContainer cc;
	TrashContainer tc;
	AppliancesContainer ac;
	TrashPlusCloudContainer tpc;
	/*1단계 그냥
	2단계 가전제품
	3단계 의류
	4단계 건축자재
	5단계 우주 쓰레기 파편
	6단계 5단계 + 장애물
	7단계 6단계 + 속도변화*/
	GameContainer* gcArray[] = { &g1 ,&ac,&cc,&oc, &tc,&tpc,  &sc};
	
	Stage stage;
	TetrisPlayer storyMode(gcArray, 7);

	while (1)
	{
		lc.show_logo();
		storyMode.run();
	}
	return 0;
}