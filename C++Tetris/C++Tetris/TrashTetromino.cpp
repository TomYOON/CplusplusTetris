#include "TrashTetromino.h"

TrashTetromino::TrashTetromino()
	:Tetromino()
{
}

const char(&TrashTetromino::get_tetromino())[4][4]
{
	return m_tetrominos[get_shape()][get_angle()];
}
