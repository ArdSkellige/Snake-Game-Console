#pragma once

/*
Food:
void SetFood(...); // ��������� "���" �� ����
Field:
void SetBorder(unsigned char(...); // ��������� ������ �������� ���� (������� ���������� �������)
void SetSnake(...); // ��������� ��������� ������ �� ����
void PrintField(...); // ������ �������� ����, �������� ������ � "���"
void ClearField(...); // "�������" �������� ���� - ���������� ��������� ���� - (' ')
Snake:
void InitSnake(...); // ����������� ��������� ������ ����� ������� ����
void MoveSnake(...); // ��������� ��������� ������ � �������� ����
Game:
DIRECTION StartDirection(...); // ����������� ����������� �������� ������ ����� ������� ����
void SetDirection(...); // ����� ����������� �������� ������
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