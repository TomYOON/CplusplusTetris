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
	/*1�ܰ� �׳�
	2�ܰ� ������ǰ
	3�ܰ� �Ƿ�
	4�ܰ� ��������
	5�ܰ� ���� ������ ����
	6�ܰ� 5�ܰ� + ��ֹ�
	7�ܰ� 6�ܰ� + �ӵ���ȭ*/
	GameContainer* gcArray[] = { &g1 ,&ac,&cc,&oc, &tc,&tpc,  &sc};
	GameContainer* levelgc[1] = { &g1 };
	
	Stage stage;
	TetrisPlayer storyMode(gcArray, 3);
	TetrisPlayer levelMode(levelgc, 1);

	while (1)
	{
		lc.show_logo();
		storyMode.run();
	}
	return 0;
}