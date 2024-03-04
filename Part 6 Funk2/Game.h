#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include "Const.h"
#include "Snake.h"
#include "Food.h"
#include "Field.h"
using std::cout;
using std::cin;
using std::endl;


DIRECTION SetDirection(DIRECTION& direction);
void StartGame(DIRECTION& direction);
void ExitGame(bool& game_on);
void SnakeMaxSizeCheck(int snake_size, bool& game_on);
void Game(bool& food_flag, int& food_x, unsigned char* field, int& snake_size, DIRECTION& direction, int* snake_x, int& indMove, int& X, bool& game_on);