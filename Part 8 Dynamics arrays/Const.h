#pragma once

const char tail_symbol = '=';
const char head_symbol = '0';
const char field_symbol = ' ';
const char border_symbol = '*';
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