#pragma once
#include <cstdlib>
#include <ctime>
//#include "Snake.h"
//#include "Field.h"
//#include "Game.h"

#include "const.h"
struct Field;
struct Snake;

struct Food
{
	unsigned int food_X; // Координата еды по горизонтали X
	unsigned int food_Y = 0; // Координата еды по вертикали Y
	bool food_flag = false; // Признак, что еда установлена
};

void SetFood(Food& food, Snake& snake, Field& field);
