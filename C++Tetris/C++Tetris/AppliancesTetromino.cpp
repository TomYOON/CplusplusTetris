#include "AppliancesTetromino.h"

AppliancesTetromino::AppliancesTetromino()
	:Tetromino()
{
}

const char(&AppliancesTetromino::get_tetromino())[4][4]
{
	return m_tetrominos[get_shape()][get_angle()];
}
