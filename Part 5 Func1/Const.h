#pragma once

/*
Food:
void SetFood(); // ��������� "���" �� ����
Field:
void PrintField(); // ������ �������� ����, �������� ������ � "���"
Snake:
void InitSnake(); // ����������� ��������� ������ ����� ������� ����
void MoveSnake(); // ��������� ��������� ������ � �������� ����
Game:
DIRECTION SetDirection(); // ����������� ����������� �������� ������ ����� ������� ����
*/

const int columns = 18;
const char tail_symbol = '=';
const char head_symbol = '0';
const char field_symbol = ' ';
const char border_symbol = '|';
const int L = columns - 2;
const char food_symbol = 'x';

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