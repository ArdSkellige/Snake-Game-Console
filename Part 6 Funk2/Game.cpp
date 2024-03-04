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
	// выбор направлени€ движени€:
	direction = SetDirection(direction);

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();
	system("cls"); // очистка консоли
}

void ExitGame(bool& game_on)
{
	if (_kbhit()) // провер€ет консоль на предмет недавнего нажати€ клавиши
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
	// »нициализаци€ игры:
	StartGame(direction);

	// »нициализаци€ змейки:
	InitSnake(snake_size, direction, snake_x, indMove, X);

	while (game_on)
	{
		// прорисовка верхней границы:
		PrintUpBorder();

		// установка "еды" на поле:
		SetFood(food_flag, food_x, snake_size, snake_x);

		// ѕечать игрового пол€ со змейкой и едой в блоке for:
		PrintField(food_x, field, snake_size, snake_x, X);

		// прорисовка нижней границы:
		PrintLowBorder();

		// очистка игрового пол€ и задержка в тайминге
		Sleep(timeout);
		system("cls");

		// координата "головы" совпадает с координатой "еды":
		SnakeAteFood(food_flag, food_x, snake_size, direction, snake_x, X);

		// координаты змейки смещаютс€:
		MoveSnake(snake_size, direction, snake_x, indMove, X);

		// змейка достигла своего максимально возможного размера
		SnakeMaxSizeCheck(snake_size, game_on);

		// ожидание команды выхода из игры:
		ExitGame(game_on);
	}
}