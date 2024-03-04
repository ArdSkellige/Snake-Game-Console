#pragma once

const int columns = 18;
const char tail_symbol = '=';
const char head_symbol = '0';

// New datas
const char field_symbol = ' ';
const char border_symbol = '|';
const int L = columns - 2;

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
	LEFT
};