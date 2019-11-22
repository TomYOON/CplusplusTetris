#include "LogoContainer.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

void LogoContainer::show_random_block(const int& x, const int& y)
{
	m_tetromino.set_shape(rand() % 7);
	m_tetromino.set_angle(rand() % 4);

	// 해당 블록에 맞는 색깔을 출력
	switch (m_tetromino.get_shape())
	{
	case 0: //막대모양 1
		setColor(RED);
		break;
	case 1: //네모모양 ㅁ
		setColor(BLUE);
		break;
	case 2: //'ㅓ' 모양
		setColor(SKY_BLUE);
		break;
	case 3: //'ㄱ'모양
		setColor(WHITE);
		break;
	case 4: //'ㄴ' 모양
		setColor(YELLOW);
		break;
	case 5: //'Z' 모양
		setColor(VOILET);
		break;
	case 6: //'S' 모양
		setColor(GREEN);
		break;
	}
	// 좌표 x, y 에 대하여 4X4 칸 내에 블록을 출력
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// 화면 밖을 나갈때는 출력을 생략한다.
			if ((j + y) < 0)
				continue;
			if (m_tetromino.get_cur_tetromino()[j][i] == 1)
			{
				gotoxy((i + x) * 2 + m_ab_x, j + y + m_ab_y);
				printf("■");

			}
		}
	}
	// 다시 검정으로 바꾼후 커서 이동
	setColor(BLACK);
	gotoxy(77, 23);
}

LogoContainer::LogoContainer()
:Container()
{
}

LogoContainer::LogoContainer(const int& ab_x, const int& ab_y)
	:Container(ab_x, ab_y)
{
}

LogoContainer::~LogoContainer()
{
}

void LogoContainer::show_logo()
{
	int i, j;
	gotoxy(13, 3);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	Sleep(100);
	gotoxy(13, 4);
	printf("┃◆◆◆  ◆◆◆  ◆◆◆   ◆◆     ◆   ◆  ◆ ┃");
	Sleep(100);
	gotoxy(13, 5);
	printf("┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃");
	Sleep(100);
	gotoxy(13, 6);
	printf("┃  ◆    ◆◆◆    ◆     ◆◆     ◆     ◆   ┃");
	Sleep(100);
	gotoxy(13, 7);
	printf("┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃");
	Sleep(100);
	gotoxy(13, 8);
	printf("┃  ◆    ◆◆◆    ◆     ◆  ◆   ◆   ◆  ◆ ┃");
	Sleep(100);
	gotoxy(13, 9);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

	gotoxy(28, 20);
	printf("Please Press Any Key~!");

	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{


			for (j = 0; j < 5; j++)
			{
				gotoxy(0, 14 + j);
				printf("                                                                    ");


			}
			for (int k = 1; k < 5; k++){
				show_random_block(6 * k, 14);
			}
		}
		if (_kbhit())
			break;
		Sleep(30);
	}

	_getche();
	system("cls");
}
