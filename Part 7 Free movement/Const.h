#pragma once

/*
Food:
void SetFood(...); // установка "еды" на поле
Field:
void SetBorder(unsigned char(...); // установка границ игрового поля (крайние координаты массива)
void SetSnake(...); // установка координат змейки на поле
void PrintField(...); // печать игрового поля, символов змейки и "еды"
void ClearField(...); // "очистка" игрового поля - заполнение символами поля - (' ')
Snake:
void InitSnake(...); // определение координат змейки перед началом игры
void MoveSnake(...); // изменение координат змейки в процессе игры
Game:
DIRECTION StartDirection(...); // определение направления движения змейки перед началом игры
void SetDirection(...); // смена направления движения змейки
*/

const int columns = 18; // X
const int rows = 18; // Y
const char tail_symbol = '=';
const char head_symbol = '0';
const char field_symbol = ' ';
const char border_symbol = '*';
const int L = (columns - 2) * ((rows - 2) - 2);
const char food_symbol = 'x';
const int timeout = 400;

enum KEYS // From Part 1
{
	goUP = 72,
	goDOWN = 80,
	goRIGHT = 77,
	goLEFT = 75
};

enum DIRECTION
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};