#include "AppliancesTetromino.h"

const char(&AppliancesTetromino::get_tetromino())[4][4]
{
	return m_tetrominos[get_shape()][get_angle()];
}
