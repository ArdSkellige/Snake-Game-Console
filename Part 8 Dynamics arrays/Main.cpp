#include"Game.h"

// Отображение змейки в двумерном динамическом массиве

int main()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl, FOREGROUND_GREEN);

	int columnsX; // M - Длина игрового поля по горизонтали
	int rowsY; // N - Длина игрового поля по вертикали
	cout << "Input field widgh: ";
	cin >> columnsX;
	cout << "Input field high: ";
	cin >> rowsY;
	//int L = (columnsX - 2) * ((rowsY - 2) - 2);
	unsigned char* pch = new unsigned char[rowsY * columnsX];
	unsigned char** pch2 = new unsigned char*[rowsY];
	for (int i = 0; i < rowsY; i++)
	{
		pch2[i] = pch + i * columnsX;
	}

	bool game_onMain = 1; // Признак продолжения игры
	bool food_flagMain = false; // Признак, что еда установлена
	unsigned int food_X_Main = 0; // Координата еды по горизонтали
	unsigned int food_Y_Main = 0; // Координата еды по вертикали
	unsigned int snake_sizeMain = 7; // Текущий размер змейки
	unsigned int snake_X_Main[100] = { 0 }; // Массив координат змейки по горизонтали
	unsigned int snake_Y_Main[100] = { 0 }; // Массив координат змейки по вертикали
	DIRECTION directionMain = RIGHT; // Направление движения змейки
	//unsigned char fieldMain[rows][columns] = { 0 };
	bool damageMain = false;
	int indMoveRL = 0; // индекс движения горизонтально
	int indMoveUD = 0; // индекс движения вертикально

	Game(food_flagMain, food_X_Main, food_Y_Main, pch2, columnsX, rowsY, snake_sizeMain, directionMain, snake_X_Main, snake_Y_Main, game_onMain, damageMain, indMoveRL, indMoveUD);

	delete[] pch;
	delete[] pch2;

	return 0;
}