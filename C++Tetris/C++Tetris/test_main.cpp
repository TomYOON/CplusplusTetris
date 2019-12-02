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
	OddContainer gcArray[1] = {O1,};
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