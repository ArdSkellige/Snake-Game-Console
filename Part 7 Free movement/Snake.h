#pragma once
#include "Const.h"
#include"Game.h"


void InitSnake(unsigned char(*field)[columns], unsigned int* snake_x, unsigned int* snake_y, unsigned int snake_size, DIRECTION& direction, int& indMoveRL, int& indMoveUD, int& input);
void SnakeMove(const DIRECTION direction, unsigned int* snake_x, unsigned int* snake_y, unsigned int snake_size, int moveRL, int moveUD);
void SnakeAteFood(bool& food_flag, unsigned int* snake_x, unsigned int* snake_y, unsigned int& snake_size, int last_segm_bud_hor, int last_segm_bud_vert);