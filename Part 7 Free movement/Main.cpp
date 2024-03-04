#include"Game.h"

// Отображение змейки в двумерном встроенном массиве

int main()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl, FOREGROUND_GREEN);

	// Game.cpp:
	bool game_onMain = 1;

	// Food.cpp:
	bool food_flagMain = false;
	unsigned int food_X_Main = 0; // Координата еды по горизонтали
	unsigned int food_Y_Main = 0; // Координата еды по вертикали

	// Snake.cpp:
	unsigned int snake_sizeMain = 7;
	unsigned int snake_X_Main[L] = { 0 }; // Массив координат змейки по горизонтали
	unsigned int snake_Y_Main[L] = { 0 }; // Массив координат змейки по вертикали
	DIRECTION directionMain = RIGHT;

	// Field.cpp:
	unsigned char fieldMain[rows][columns] = { 0 };

	bool damageMain = false;
	int indMoveRL = 0; // индекс движения горизонтально
	int indMoveUD = 0; // индекс движения вертикально

	Game(food_flagMain, food_X_Main, food_Y_Main, fieldMain, snake_sizeMain, directionMain, snake_X_Main, snake_Y_Main, game_onMain, damageMain, indMoveRL, indMoveUD);

	return 0;
}