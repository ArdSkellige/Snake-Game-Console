#pragma once
#include "Const.h"
#include"Game.h"


void SetBorder(unsigned char** p, int fieldXSize, int fieldYSize);
void SetSnake(bool food_flag, unsigned int snake_size, unsigned char** p, unsigned int* snake_x, unsigned int* snake_y, int food_x, int food_y);
void PrintField(unsigned char** p, int fieldXSize, int fieldYSize, unsigned int snake_size);
void ClearField(unsigned char** p, int fieldXSize, int fieldYSize);


