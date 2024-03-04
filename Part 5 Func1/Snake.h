#pragma once
#include "Const.h"
#include"Game.h"

extern int snake_size;
extern DIRECTION direction;
extern int snake_x[];

extern int indMove;
extern int X;

void InitSnake();
void MoveSnake();
void SnakeAteFood();