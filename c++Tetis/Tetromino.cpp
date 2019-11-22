#include "Tetromino.h"

Tetromino::Tetromino()
	:m_shape(0),m_next_shape(0),m_angle(0)
{
}

Tetromino::~Tetromino()
{
}
 
void Tetromino::set_shape(const int& shape)
{
	m_shape = shape;
}

void Tetromino::set_angle(const int& angle)
{
	m_angle = angle;
}

int Tetromino::get_shape() const
{
	return m_shape;
}

int Tetromino::get_angle() const
{
	return m_angle;
}

void Tetromino::set_next_shape(const int& next_shape)
{
	m_next_shape = next_shape;
}

int Tetromino::get_next_shape() const
{
	return m_next_shape;
}

//char* Tetromino::get_cur_tetromino() const
//{
//	return (char*) m_tetrominos[m_shape][m_angle];
//}

const char(&Tetromino::get_cur_tetromino())[4][4]
{
	return m_tetrominos[m_shape][m_angle];
}

const char(&Tetromino::get_next_tetromino())[4][4]
{
	return m_tetrominos[m_next_shape][m_angle];
}

//char* Tetromino::get_next_tetromino() const
//{
//	return (char*) m_tetrominos[m_next_shape][m_angle];
//}
