#include "OddTetromino.h"

OddTetromino::OddTetromino()
	:Tetromino()
{
}

const char(&OddTetromino::get_tetromino())[4][4]
{
	return m_tetrominos[get_shape()][get_angle()];
}
