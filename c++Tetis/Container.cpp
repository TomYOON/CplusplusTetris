#include "Container.h"
#include <Windows.h>

Container::Container()
	:Container(5,1)
{

}

Container::Container(const int& ab_x, const int& ab_y)
:m_ab_x(ab_x),m_ab_y(ab_y)
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
