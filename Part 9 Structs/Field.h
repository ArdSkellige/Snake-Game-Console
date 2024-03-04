#pragma once
//#include "Const.h"
//#include "Food.h"
//#include "Snake.h"
//#include"Game.h"

#include "const.h"
struct Snake;
struct Food;

struct Field
{
	int columnsX; // M - Длина игрового поля по горизонтали
	int rowsY; // N - Длина игрового поля по вертикали
	unsigned char* pch = nullptr; // = new unsigned char[rowsY * columnsX];
	unsigned char** pch2 = nullptr; // = new unsigned char* [rowsY];
};

void InitFieldSize(Field& field);
void CreateField(Field& field);
void SetBorder(Field& field);
void SetSnake(Food& food, Snake& snake, Field& field);
void PrintField(Snake& snake, Field& field);
void ClearField(Field& field);
void DeleteField(Field& field);
