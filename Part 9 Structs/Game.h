#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Const.h"
#include "Food.h"
#include "Snake.h"
#include "Field.h"
#include "winconsole.h"

using std::cout;
using std::cin;
using std::endl;

struct Game
{
	bool game_on; // = 1; // Признак продолжения игры
	bool damage = false;
	int indMoveRL = 0; // индекс движения горизонтально
	int indMoveUD = 0; // индекс движения вертикально
};


void StartDirection(Snake& snake, Game& game, int& input);
void SetDirection(Snake& snake, int& input);
bool Crash(Snake& snake, Field& field, Game& game);
bool CheckSnake(Snake& snake, Field& field, Game& game);
void StartGame(Snake& snake, Game& game, int& input);
void ExitGame(Game& game, int& input);
void GameStruct(Food& food, Snake& snake, Field& field, Game& game);
