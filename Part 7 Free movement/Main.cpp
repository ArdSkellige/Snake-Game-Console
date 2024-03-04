#include"Game.h"

// ����������� ������ � ��������� ���������� �������

int main()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl, FOREGROUND_GREEN);

	// Game.cpp:
	bool game_onMain = 1;

	// Food.cpp:
	bool food_flagMain = false;
	unsigned int food_X_Main = 0; // ���������� ��� �� �����������
	unsigned int food_Y_Main = 0; // ���������� ��� �� ���������

	// Snake.cpp:
	unsigned int snake_sizeMain = 7;
	unsigned int snake_X_Main[L] = { 0 }; // ������ ��������� ������ �� �����������
	unsigned int snake_Y_Main[L] = { 0 }; // ������ ��������� ������ �� ���������
	DIRECTION directionMain = RIGHT;

	// Field.cpp:
	unsigned char fieldMain[rows][columns] = { 0 };

	bool damageMain = false;
	int indMoveRL = 0; // ������ �������� �������������
	int indMoveUD = 0; // ������ �������� �����������

	Game(food_flagMain, food_X_Main, food_Y_Main, fieldMain, snake_sizeMain, directionMain, snake_X_Main, snake_Y_Main, game_onMain, damageMain, indMoveRL, indMoveUD);

	return 0;
}