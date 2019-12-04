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
using namespace std;

const int LEVEL_MODE = 1;
const int STORY_MODE = 2;

int main(void) {
	LogoContainer lc;
	SelectLevelContainer slc;
	GameContainer g1;
	OddContainer O1;
	RandomFieldContainer r1;
	SelectModeContainer smc;
	GameContainer* gcArray[1] = {&r1,};
	GameContainer* levelgc[1] = { &g1 };
	Stage stage;
	TetrisPlayer storyMode(gcArray);
	TetrisPlayer levelMode(levelgc);

	while (1)
	{
		lc.show_logo();
		smc.show_select_mode();
		while (true){
			if (smc.get_mode() == LEVEL_MODE) levelMode.run();
			else if (smc.get_mode() == STORY_MODE) storyMode.run();
			else continue;
			break;
		}
	}
	return 0;
}