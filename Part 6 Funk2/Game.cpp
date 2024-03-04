#include"Game.h"


DIRECTION SetDirection(DIRECTION& direction)
{
	cout << "Direction (R/L): ";
	char direct;
	cin >> direct;
	switch (direct)
	{
	case 'R':;
	case 'r':
		return DIRECTION::RIGHT;
		break;
	case 'L':;
	case 'l':
		return DIRECTION::LEFT;
		break;
	}
}

void StartGame(DIRECTION& direction)
{
	// ����� ����������� ��������:
	direction = SetDirection(direction);

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();
	system("cls"); // ������� �������
}

void ExitGame(bool& game_on)
{
	if (_kbhit()) // ��������� ������� �� ������� ��������� ������� �������
	{
		unsigned int endGame;
		endGame = _getch();
		if (endGame == 27)
		{
			cout << "Game over" << endl;
			game_on = false;
		}
	}
}

void SnakeMaxSizeCheck(int snake_size, bool& game_on)
{
	if (snake_size == L)
	{
		cout << "You win" << endl;
		game_on = false;
	}
}

void Game(bool& food_flag, int& food_x, unsigned char* field, int& snake_size, DIRECTION& direction, int* snake_x, int& indMove, int& X, bool& game_on)
{
	// ������������� ����:
	StartGame(direction);

	// ������������� ������:
	InitSnake(snake_size, direction, snake_x, indMove, X);

	while (game_on)
	{
		// ���������� ������� �������:
		PrintUpBorder();

		// ��������� "���" �� ����:
		SetFood(food_flag, food_x, snake_size, snake_x);

		// ������ �������� ���� �� ������� � ���� � ����� for:
		PrintField(food_x, field, snake_size, snake_x, X);

		// ���������� ������ �������:
		PrintLowBorder();

		// ������� �������� ���� � �������� � ��������
		Sleep(timeout);
		system("cls");

		// ���������� "������" ��������� � ����������� "���":
		SnakeAteFood(food_flag, food_x, snake_size, direction, snake_x, X);

		// ���������� ������ ���������:
		MoveSnake(snake_size, direction, snake_x, indMove, X);

		// ������ �������� ������ ����������� ���������� �������
		SnakeMaxSizeCheck(snake_size, game_on);

		// �������� ������� ������ �� ����:
		ExitGame(game_on);
	}
}