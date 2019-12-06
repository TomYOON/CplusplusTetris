#include "ClothTetromino.h"

ClothTetromino::ClothTetromino()
	:Tetromino()
{

}

const char(&ClothTetromino::get_tetromino())[4][4]
{
	return m_tetrominos[get_shape()][get_angle()];
}
