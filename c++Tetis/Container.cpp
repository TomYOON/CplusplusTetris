#include "Container.h"
#include <Windows.h>

Container::Container(const int& ab_x, const int& ab_y)
:m_ab_x(ab_x),m_ab_y(ab_y)
/*�⺻ ������*/
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
	case 0: //������ 1
		setColor(RED);
		break;
	case 1: //�׸��� ��
		setColor(BLUE);
		break;
	case 2: //'��' ���
		setColor(SKY_BLUE);
		break;
	case 3: //'��'���
		setColor(WHITE);
		break;
	case 4: //'��' ���
		setColor(YELLOW);
		break;
	case 5: //'Z' ���
		setColor(VOILET);
		break;
	case 6: //'S' ���
		setColor(GREEN);
		break;
	}
}
