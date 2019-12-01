#include "LogoContainer.h"
#include "SelectLevelContainer.h"
#include "GameContainer.h"
#include "Stage.h"
#include "TetrisPlayer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

int main(void) {
	LogoContainer lc;
	SelectLevelContainer slc;
	GameContainer g1;
	GameContainer gcArray[1] = {g1,};
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