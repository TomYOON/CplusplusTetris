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
using namespace std;

int main(void) {
	LogoContainer lc;
	SelectLevelContainer slc;
	GameContainer g1;
	OddContainer O1;
	RandomFieldContainer r1;
	RandomFieldContainer gcArray[1] = {r1,};
	Stage stage;
	TetrisPlayer tp(gcArray);
	while (1)
	{
		system("cls");
		Sleep(150);
		lc.show_logo();
		tp.run();
	}
	return 0;
}