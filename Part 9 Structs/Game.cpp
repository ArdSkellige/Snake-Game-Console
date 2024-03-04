#include"Game.h"


void StartDirection(Snake& snake, Game& game, int& input)
{
	cout << "Direction (W-D-S-A): ";
	char direct;
	cin >> direct;
	input = direct;
	switch (direct)
	{
	case 'D':
	case 'd':
		game.indMoveRL = 1;
		snake.direction = RIGHT;
		break;
	case 'A':
	case 'a':
		game.indMoveRL = -1;
		snake.direction = LEFT;
		break;
	case 'W':
	case 'w':
		game.indMoveUD = -1;
		snake.direction = UP;
		break;
	case 'S':
	case 's':
		game.indMoveUD = 1;
		snake.direction = DOWN;
		break;
	}
}

void SetDirection(Snake& snake, int& input)
{
	input = _getch();

	if (snake.direction == DIRECTION::UP)
	{
		switch (input)
		{
		case 'w':
			snake.direction = DIRECTION::UP;
			break;
		case 'a':
			snake.direction = DIRECTION::LEFT;
			break;
		case 'd':
			snake.direction = DIRECTION::RIGHT;
			break;
		}
	}
	else if (snake.direction == DIRECTION::DOWN)
	{
		switch (input)
		{
		case 's':
			snake.direction = DIRECTION::DOWN;
			break;
		case 'a':
			snake.direction = DIRECTION::LEFT;
			break;
		case 'd':
			snake.direction = DIRECTION::RIGHT;
			break;
		}
	}
	else if (snake.direction == DIRECTION::LEFT)
	{
		switch (input)
		{
		case 'w':
			snake.direction = DIRECTION::UP;
			break;
		case 's':
			snake.direction = DIRECTION::DOWN;
			break;
		case 'a':
			snake.direction = DIRECTION::LEFT;
			break;
		}
	}
	else
	{
		switch (input)
		{
		case 'w':
			snake.direction = DIRECTION::UP;
			break;
		case 's':
			snake.direction = DIRECTION::DOWN;
			break;
		case 'd':
			snake.direction = DIRECTION::RIGHT;
			break;
		}
	}
}

// ������ ��������� � ����:
bool Crash(Snake& snake, Field& field, Game& game)
{
	if (field.pch2[snake.snake_Y[0]][snake.snake_X[0]] == tail_symbol)
	{
		game.damage = true;
		cout << "You lose. Enter ESC to exit." << endl;
	}
	return game.damage;
}

bool CheckSnake(Snake& snake, Field& field, Game& game)
{
	if (Crash(snake, field, game))
	{
		game.game_on = false;
	}
	else if (snake.snake_size == 100)
	{
		game.game_on = false;
		cout << "You win. Enter ESC to exit." << endl;
	}
	return game.game_on;
}

void StartGame(Snake& snake, Game& game, int& input)
{
	// ����� ����������� ��������:
	StartDirection(snake, game, input);

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();
	system("cls"); // ������� �������
}

void ExitGame(Game& game, int& input)
{
	if (input == 27)
	{
		cout << "Game over" << endl;
		game.game_on = false;
	}
}

void GameStruct(Food& food, Snake& snake, Field& field, Game& game)
{
	int input = 0;

	// ������������� ����:
	StartGame(snake, game, input);
	// ���������� ����� �������� ����:
	SetBorder(field);
	// ������������� ������:
	InitSnake(field, snake, game, input);

	while (game.game_on)
	{
		// �������� ������ �� ������������ � ������:
		CheckSnake(snake, field, game);

		if (_kbhit())
		{
			// ����� ����������� �������� ������:
			SetDirection(snake, input);
			// �������� ������� ������ �� ����:
			ExitGame(game, input);
		}

		// ���������� ��� ����������� ��������� ���������� �������� ������. ��� ���������� ������ ��������� ������,
		// �� ������������ �� ����� ����������, � �� �����, ��� ������ ��������� ������� ��� ��������� �� ����� ������� � ������� move()
		int last_segm_x = snake.snake_X[snake.snake_size - 1];
		int last_segm_y = snake.snake_Y[snake.snake_size - 1];

		if (game.game_on)
		{
			ClearField(field);
			// ���������� ������ ���������:
			SnakeMove(field, snake, game);
			// ��������� "���" �� ����:
			SetFood(food, snake, field);
			// ��������� �������� ������ � ��� � ����� for:
			SetSnake(food, snake, field);
		}

		// ������ �������� ���� �� ������� � ���� � ����� for:
		PrintField(snake, field);

		if ((snake.snake_X[0] == food.food_X) && (snake.snake_Y[0] == food.food_Y))
		{
			SnakeAteFood(food, snake, last_segm_x, last_segm_y);
		}

		// ������� �������� ���� � �������� � ��������
		Sleep(timeout);
		//system("cls");
		setCursorPosition(0, 0);
	}
}

