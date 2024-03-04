#include"Game.h"

// ����������� ������ � ��������� ������������ �������

int main()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl, FOREGROUND_GREEN);

	int columnsX; // M - ����� �������� ���� �� �����������
	int rowsY; // N - ����� �������� ���� �� ���������
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

	bool game_onMain = 1; // ������� ����������� ����
	bool food_flagMain = false; // �������, ��� ��� �����������
	unsigned int food_X_Main = 0; // ���������� ��� �� �����������
	unsigned int food_Y_Main = 0; // ���������� ��� �� ���������
	unsigned int snake_sizeMain = 7; // ������� ������ ������
	unsigned int snake_X_Main[100] = { 0 }; // ������ ��������� ������ �� �����������
	unsigned int snake_Y_Main[100] = { 0 }; // ������ ��������� ������ �� ���������
	DIRECTION directionMain = RIGHT; // ����������� �������� ������
	//unsigned char fieldMain[rows][columns] = { 0 };
	bool damageMain = false;
	int indMoveRL = 0; // ������ �������� �������������
	int indMoveUD = 0; // ������ �������� �����������

	Game(food_flagMain, food_X_Main, food_Y_Main, pch2, columnsX, rowsY, snake_sizeMain, directionMain, snake_X_Main, snake_Y_Main, game_onMain, damageMain, indMoveRL, indMoveUD);

	delete[] pch;
	delete[] pch2;

	return 0;
}