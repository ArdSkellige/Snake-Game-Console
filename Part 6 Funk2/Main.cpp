#include"Game.h"

int main()
{
	// Game.cpp:
	bool game_onMain = 1;

	// Food.cpp:
	bool food_flagMain = false;
	int food_xMain = 0;

	// Snake.cpp:
	int snake_sizeMain = 1;
	DIRECTION directionMain = RIGHT;
	int snake_xMain[L] = { 0 };
	int indMoveMain = 0; // индекс "хвоста" змейки
	int XMain = 5; // координата первоначального положения "головы" змейки

	// Field.cpp:
	unsigned char fieldMain[columns];

	Game(food_flagMain, food_xMain, fieldMain, snake_sizeMain, directionMain, snake_xMain, indMoveMain, XMain, game_onMain);

	return 0;
}