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
			if (m_tetromino.get_tetromino()[j][i] == 1)
			{
				gotoxy((i + x) * 2 + m_ab_x, j + y + m_ab_y);
				cout << "■";

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
	setColor(GRAY);
	gotoxy(10, 2);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	gotoxy(10, 3);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 4);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 5);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 6);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 7);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 8);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 9);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 10);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 11);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 12);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 13);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 14);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 15);
	cout << "┃                                                                                             ┃";
	gotoxy(10, 16);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	Sleep(500);

	setColor(RED);
	gotoxy(22, 4);
	cout << " ■■■■";
	gotoxy(22, 5);
	cout << "   ■";
	gotoxy(22, 6);
	cout << "  ■";
	gotoxy(22, 7);
	cout << " ■";
	gotoxy(22, 8);
	cout << "■";
	Sleep(200);
	setColor(DARK_YELLOW);
	gotoxy(33, 4);
	cout << "■■■";
	gotoxy(29, 5);
	cout << "   ■";
	gotoxy(29, 6);
	cout << "  ■■■";
	gotoxy(29, 7);
	cout << " ■";
	gotoxy(29, 8);
	cout << "■■■";
	Sleep(200);
	setColor(GREEN);
	gotoxy(40, 4);
	cout << " ■■■■";
	gotoxy(40, 5);
	cout << "   ■";
	gotoxy(40, 6);
	cout << "  ■";
	gotoxy(40, 7);
	cout << " ■";
	gotoxy(40, 8);
	cout << "■";
	Sleep(200);
	setColor(SKY_BLUE);
	gotoxy(51, 4);
	cout << "■■■";
	gotoxy(47, 5);
	cout << "   ■   ■ ";
	gotoxy(47, 6);
	cout << "  ■■■ ";
	gotoxy(47, 7);
	cout << " ■   ■";
	gotoxy(47, 8);
	cout << "■    ■";
	Sleep(200);
	setColor(BLUE);
	gotoxy(57, 4);
	cout << "    ■";
	gotoxy(57, 5);
	cout << "   ■";
	gotoxy(57, 6);
	cout << "  ■";
	gotoxy(57, 7);
	cout << " ■";
	gotoxy(57, 8);
	cout << "■";
	Sleep(200);
	setColor(VOILET);
	gotoxy(65, 4);
	cout << " ■■■";
	gotoxy(64, 5);
	cout << "■";
	gotoxy(61, 6);
	cout << "    ■■  ";
	gotoxy(61, 7);
	cout << "       ■";
	gotoxy(61, 8);
	cout << " ■■■";
	Sleep(200);
	setColor(GRAY);
	gotoxy(74, 4);
	cout << " ";
	gotoxy(74, 5);
	cout << "   ■";
	gotoxy(74, 6);
	cout << "      ■■ ";
	gotoxy(74, 7);
	cout << " ■  ■  ■";
	gotoxy(74, 8);
	cout << "■  ■  ■";
	Sleep(300);
	gotoxy(87, 8);
	cout << "■";
	Sleep(300);
	gotoxy(91, 8);
	cout << "■";
	Sleep(300);
	gotoxy(95, 8);
	cout << "■";
	gotoxy(13, 9);
	setColor(DARK_GRAY);
	cout << "";
	Sleep(300);
	gotoxy(13, 10);
	cout << " ■■■■  ■■■        ■       ■■■   ■    ■  ■            ■      ■    ■  ■■";
	Sleep(100);
	gotoxy(13, 11);
	cout << "   ■     ■   ■      ■■     ■        ■    ■  ■           ■■     ■■  ■  ■  ■";
	Sleep(100);
	gotoxy(13, 12);
	cout << "  ■     ■■■      ■  ■      ■■    ■■■■  ■          ■  ■    ■  ■■  ■   ■";
	Sleep(100);
	gotoxy(13, 13);
	cout << " ■     ■   ■    ■■■■         ■  ■    ■  ■         ■■■■   ■    ■  ■   ■";
	Sleep(100);
	gotoxy(13, 14);
	cout << "■     ■    ■  ■      ■   ■■■   ■    ■  ■■■■  ■      ■  ■    ■  ■■■";
	Sleep(400);

	gotoxy(45, 18);
	setColor(GRAY);
	cout << "<Press any key to start~!>";

	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{


			for (j = 0; j < 5; j++)
			{
				gotoxy(10, 20 + j);
				cout << "                                                                         ";


			}
			for (int k = 1; k < 5; k++){
				show_random_block(10 + 6 * k, 20);
			}
		}
		if (_kbhit())
			break;
		Sleep(30);
	}

	_getche();
	system("cls");
}
