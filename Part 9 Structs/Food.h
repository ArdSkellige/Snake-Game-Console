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
	unsigned int food_X; // ���������� ��� �� ����������� X
	unsigned int food_Y = 0; // ���������� ��� �� ��������� Y
	bool food_flag = false; // �������, ��� ��� �����������
};

void SetFood(Food& food, Snake& snake, Field& field);
