#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include "Const.h"
#include "Snake.h"
#include "Food.h"
#include "Field.h"
#include "winconsole.h"
using std::cout;
using std::cin;
using std::endl;


void StartDirection(DIRECTION& direction, int& indMoveRL, int& indMoveUD, int& input);
void SetDirection(DIRECTION& direction, int& input);
void StartGame(DIRECTION& direction, int& indMoveRL, int& indMoveUD, int& input);
void ExitGame(bool& game_on, int& input);
bool CheckSnake(bool& game_on, bool& damage, unsigned char(*field)[columns], unsigned int* snake_hor, unsigned int* snake_vert, unsigned int snake_size);
bool Crash(bool& damage, unsigned char(*field)[columns], unsigned int* snake_x, unsigned int* snake_y);
void Game(bool& food_flag, unsigned int& food_x, unsigned int& food_y, unsigned char(*field)[columns], unsigned int& snake_size, DIRECTION& direction, unsigned int* snake_x, unsigned int* snake_y, bool& game_on, bool& damage, int& indMoveRL, int& indMoveUD);

