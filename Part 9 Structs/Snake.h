#pragma once
//#include "Const.h"
//#include "Food.h"
//#include "Field.h"
//#include "Game.h"

#include "const.h"
struct Game;
struct Field;
struct Food;

struct Snake
{
	unsigned int snake_size = 7; // ������� ������ ������
	unsigned int snake_X[100] = { 0 }; // ������ ��������� ������ �� �����������
	unsigned int snake_Y[100] = { 0 }; // ������ ��������� ������ �� ���������
	DIRECTION direction = RIGHT; // ����������� �������� ������
};

void InitSnake(Field& field, Snake& snake, Game& game, int& input);
void SnakeMove(Field& field, Snake& snake, Game& game);
void SnakeAteFood(Food& food, Snake& snake, int last_segm_bud_hor, int last_segm_bud_vert);
