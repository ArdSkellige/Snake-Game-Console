#include"Game.h"

int timeout = 300;
bool game_on = 1;

// ����������� ����������� �������� ������ ����� ������� ����:
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
	// ����� ����������� ��������:
	direction = SetDirection();

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();
	system("cls"); // ������� �������
}

void ExitGame()
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
	// ������������� ����:
	StartGame();

	// ������������� ������:
	InitSnake();

	while (game_on)
	{
		// ���������� ������� �������:
		PrintUpBorder();

		// ��������� "���" �� ����:
		SetFood();

		// ������ �������� ���� �� ������� � ���� � ����� for:
		PrintField();

		// ���������� ������ �������:
		PrintLowBorder();

		// ������� �������� ���� � �������� � ��������
		Sleep(timeout);
		system("cls");

		// ���������� ������ ���������:
		MoveSnake();

		// ���������� "������" ��������� � ����������� "���":
		SnakeAteFood();

		// ������ �������� ������ ����������� ���������� �������
		SnakeMaxSizeCheck();

		// �������� ������� ������ �� ����:
		ExitGame();
	}
}