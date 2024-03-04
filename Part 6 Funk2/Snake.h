#pragma once
#include "Const.h"
#include"Game.h"

void InitSnake(int& snake_size, DIRECTION direction, int* snake_x, int& indMove, int& X);
void MoveSnake(int& snake_size, DIRECTION direction, int* snake_x, int& indMove, int& X);
void SnakeAteFood(bool& food_flag, int& food_x, int& snake_size, DIRECTION direction, int* snake_x, int& X);