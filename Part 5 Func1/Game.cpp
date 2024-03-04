#include"Game.h"

int timeout = 300;
bool game_on = 1;

// определение направления движения змейки перед началом игры:
DIRECTION SetDirection()
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

void StartGame()
{
	// выбор направления движения:
	direction = SetDirection();

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();
	system("cls"); // очистка консоли
}

void ExitGame()
{
	if (_kbhit()) // проверяет консоль на предмет недавнего нажатия клавиши
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

void SnakeMaxSizeCheck()
{
	if (snake_size == L)
	{
		cout << "You win" << endl;
		game_on = false;
	}
}

void Game()
{
	// Инициализация игры:
	StartGame();

	// Инициализация змейки:
	InitSnake();

	while (game_on)
	{
		// прорисовка верхней границы:
		PrintUpBorder();

		// установка "еды" на поле:
		SetFood();

		// Печать игрового поля со змейкой и едой в блоке for:
		PrintField();

		// прорисовка нижней границы:
		PrintLowBorder();

		// очистка игрового поля и задержка в тайминге
		Sleep(timeout);
		system("cls");

		// координаты змейки смещаются:
		MoveSnake();

		// координата "головы" совпадает с координатой "еды":
		SnakeAteFood();

		// змейка достигла своего максимально возможного размера
		SnakeMaxSizeCheck();

		// ожидание команды выхода из игры:
		ExitGame();
	}
}