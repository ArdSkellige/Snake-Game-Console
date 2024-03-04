#pragma once
#include "Const.h"
#include"Game.h"


void SetBorder(unsigned char(*field)[columns]);
void SetSnake(bool food_flag, unsigned int snake_size, unsigned char(*field)[columns], unsigned int* snake_x, unsigned int* snake_y, int food_x, int food_y);
void PrintField(unsigned char(*field)[columns], unsigned int snake_size);
void ClearField(unsigned char(*field)[columns]);


