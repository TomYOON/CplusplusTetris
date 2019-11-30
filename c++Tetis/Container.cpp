#include "Container.h"
#include <Windows.h>

Container::Container(const int& ab_x, const int& ab_y)
:m_ab_x(ab_x),m_ab_y(ab_y)
/*기본 생성자*/
{
}

void Container::setColor(const int& color)
{
	static HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}

void Container::gotoxy(const int& x, const int& y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
}

void Container::get_tetromino_color(const int& shape)
{
	switch (shape)
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
}
