#include"Game.h"

// ����������� ������ � ��������� ������������ �������. ���������

int main()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl, FOREGROUND_GREEN);

	Food food;
	Snake snake;
	Field field;
	Game game;

	InitFieldSize(field);
	CreateField(field);
	GameStruct(food, snake, field, game);
	DeleteField(field);

	return 0;
}