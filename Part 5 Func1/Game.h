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

extern int timeout;
extern bool game_on;

DIRECTION SetDirection();
void StartGame();
void ExitGame();
void SnakeMaxSizeCheck();
void Game();