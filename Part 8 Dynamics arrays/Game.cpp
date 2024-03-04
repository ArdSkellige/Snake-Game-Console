#include"Game.h"


void StartDirection(DIRECTION& direction, int& indMoveRL, int& indMoveUD, int& input)
{
	cout << "Direction (W-D-S-A): ";
	char direct;
	cin >> direct;
	input = direct;
	switch (direct)
	{
	case 'D':
	case 'd':
		indMoveRL = 1;
		direction = RIGHT;
		break;
	case 'A':
	case 'a':
		indMoveRL = -1;
		direction = LEFT;
		break;
	case 'W':
	case 'w':
		indMoveUD = -1;
		direction = UP;
		break;
	case 'S':
	case 's':
		indMoveUD = 1;
		direction = DOWN;
		break;
	}
}

void SetDirection(DIRECTION& direction, int& input)
{
	input = _getch();

	if (direction == DIRECTION::UP)
	{
		switch (input)
		{
		case 'w':
			direction = DIRECTION::UP;
			break;
		case 'a':
			direction = DIRECTION::LEFT;
			break;
		case 'd':
			direction = DIRECTION::RIGHT;
			break;
		}
	}
	else if (direction == DIRECTION::DOWN)
	{
		switch (input)
		{
		case 's':
			direction = DIRECTION::DOWN;
			break;
		case 'a':
			direction = DIRECTION::LEFT;
			break;
		case 'd':
			direction = DIRECTION::RIGHT;
			break;
		}
	}
	else if (direction == DIRECTION::LEFT)
	{
		switch (input)
		{
		case 'w':
			direction = DIRECTION::UP;
			break;
		case 's':
			direction = DIRECTION::DOWN;
			break;
		case 'a':
			direction = DIRECTION::LEFT;
			break;
		}
	}
	else
	{
		switch (input)
		{
		case 'w':
			direction = DIRECTION::UP;
			break;
		case 's':
			direction = DIRECTION::DOWN;
			break;
		case 'd':
			direction = DIRECTION::RIGHT;
			break;
		}
	}	
}

void StartGame(DIRECTION& direction, int& indMoveRL, int& indMoveUD, int& input)
{
	// ����� ����������� ��������:
	StartDirection(direction, indMoveRL, indMoveUD, input);

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();
	system("cls"); // ������� �������
}

void ExitGame(bool& game_on, int& input)
{
	if (input == 27)
	{
		cout << "Game over" << endl;
		game_on = false;
	}
}

bool CheckSnake(bool& game_on, bool& damage, unsigned char** p, unsigned int* snake_hor, unsigned int* snake_vert, unsigned int snake_size)
{
	if (Crash(damage, p, snake_hor, snake_vert))
	{
		game_on = false;
	}
	else if (snake_size == 100)
	{
		game_on = false;
		cout << "You win. Enter ESC to exit." << endl;
	}
	return game_on;
}

// ������ ��������� � ����:
bool Crash(bool& damage, unsigned char** p, unsigned int* snake_x, unsigned int* snake_y)
{
	if (p[snake_y[0]][snake_x[0]] == tail_symbol)
	{
		damage = true;
		cout << "You lose. Enter ESC to exit." << endl;
	}
	return damage;
}

void Game(bool& food_flag, unsigned int& food_x, unsigned int& food_y, unsigned char** p, int fieldXSize, int fieldYSize, unsigned int& snake_size, DIRECTION& direction, unsigned int* snake_x, unsigned int* snake_y, bool& game_on, bool& damage, int& indMoveRL, int& indMoveUD)
{
	int input = 0;

	// ������������� ����:
	StartGame(direction, indMoveRL, indMoveUD, input);
	// ���������� ����� �������� ����:
	SetBorder(p, fieldXSize, fieldYSize);
	// ������������� ������:
	InitSnake(fieldXSize, fieldYSize, snake_x, snake_y, snake_size, direction, indMoveRL, indMoveUD, input);

	while (game_on)
	{
		// �������� ������ �� ������������ � ������:
		CheckSnake(game_on, damage, p, snake_x, snake_y, snake_size);

		if (_kbhit())
		{
			// ����� ����������� �������� ������:
			SetDirection(direction, input);
			// �������� ������� ������ �� ����:
			ExitGame(game_on, input);
		}

		// ���������� ��� ����������� ��������� ���������� �������� ������. ��� ���������� ������ ��������� ������,
		// �� ������������ �� ����� ����������, � �� �����, ��� ������ ��������� ������� ��� ��������� �� ����� ������� � ������� move()
		int last_segm_x = snake_x[snake_size - 1];
		int last_segm_y = snake_y[snake_size - 1];

		if (game_on)
		{
			ClearField(p, fieldXSize, fieldYSize);
			// ���������� ������ ���������:
			SnakeMove(fieldXSize, fieldYSize, direction, snake_x, snake_y, snake_size, indMoveRL, indMoveUD);
			// ��������� "���" �� ����:
			SetFood(fieldXSize, fieldYSize, food_flag, snake_size, snake_x, snake_y, food_x, food_y);
			// ��������� �������� ������ � ��� � ����� for:
			SetSnake(food_flag, snake_size, p, snake_x, snake_y, food_x, food_y);
		}

		// ������ �������� ���� �� ������� � ���� � ����� for:
		PrintField(p, fieldXSize, fieldYSize, snake_size);

		if ((snake_x[0] == food_x) && (snake_y[0] == food_y))
		{
			SnakeAteFood(food_flag, snake_x, snake_y, snake_size, last_segm_x, last_segm_y);
		}

		// ������� �������� ���� � �������� � ��������
		Sleep(timeout);
		//system("cls");
		setCursorPosition(0, 0);
	}
}
