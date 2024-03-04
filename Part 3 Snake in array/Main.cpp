#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Const.h"
#include"Game.h"
#include"Snake.h"
#include"Field.h"

using std::cout;
using std::cin;
using std::endl;


void main()
{
	cout << "Direction (R/L): ";
	char direction;
	cin >> direction;
	switch (direction)
	{
	case 'R':;
	case 'r':
		direction = RIGHT;
		break;
	case 'L':;
	case 'l':
		direction = LEFT;
		break;
	}

	cout << "Press 'Enter' to start the game:";
	unsigned int start;
	start = _getch();

	system("cls"); // очистка консоли
	int X = 7; // координата первоначального положения "головы" змейки
	int indMove = 0; // индекс "хвоста" змейки
	
	if (direction == RIGHT) // Координаты змейки
	{
		for (int i = 1; i < snake_size; i++)
		{
			snake_x[i] = X - i;
		}
		indMove = 1;
	}
	else
	{
		for (int i = 1; i < snake_size; i++)
		{
			snake_x[i] = X + i;
		}
		indMove = -1;
	}

	while (game_on)
	{
		snake_x[0] = X; // координата положения "головы" змейки в процессе
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < snake_size; j++)
			{
				if (i == 0 || i == columns - 1)
				{
					field[i] = border_symbol;
				}
				else if (i == snake_x[0])
				{
					field[i] = head_symbol;
				}
				else if (i == snake_x[j])
				{
					field[i] = tail_symbol;
					break;
				}
				else
				{
					field[i] = field_symbol;
				}
			}
			cout << field[i];
		}

		Sleep(timeout);
		//ind = system("cls");
		system("cls");

		// изменение коррдинат в процессе движения:
		if (direction == RIGHT)
		{
			X++;
			for (int i = 1; i < snake_size; i++)
			{
				if (snake_x[i] < L)
				{
					snake_x[i] += indMove;
				}
				else
				{
					snake_x[i] = 1;
				}
			}
		}
		else
		{
			X--;
			for (int i = 1; i < snake_size; i++)
			{
				if (snake_x[i] > 1)
				{
					snake_x[i] += indMove;
				}
				else
				{
					snake_x[i] = L;
				}
			}
		}

		if (X == (columns - 1))
		{
			X = 1;
		}
		else if (X == 0)
		{
			X = columns - 2;
		}

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




	//cout << "Direction (R/L): ";
	//char direction;
	//cin >> direction;
	//switch (direction)
	//{
	//	case 'R':;
	//	case 'r':
	//		direction = RIGHT;
	//		break;
	//	case 'L':;
	//	case 'l':
	//		direction = LEFT;
	//		break;
	//}

	//cout << "Press 'Enter' to start the game:";
	//unsigned int start;
	//start = _getch();
	//
	//system("cls"); // очистка консоли
	//int X = 5; // координата первоначального положения "головы" змейки
	//int indTail = 0; // индекс "хвоста" змейки
	//	
	//while (game_on)
	//{
	//	if (direction == RIGHT) // Координаты змейки
	//	{
	//		for (int i = 0; i < snake_size; i++)
	//		{
	//			snake_x[i] = X - i;
	//		}
	//		indTail = X - snake_size + 1;
	//	}
	//	else
	//	{
	//		for (int i = 0; i < snake_size; i++)
	//		{
	//			snake_x[i] = X + i;
	//		}
	//		indTail = X + snake_size - 1;
	//	}

	//	for (int i = 0; i < columns; i++)
	//	{
	//		if (i == 0 || i == columns - 1)
	//		{
	//			field[i] = border_symbol;
	//		}
	//		else if (i == snake_x[0])
	//		{
	//			field[i] = head_symbol;
	//		}
	//		else if (i >= indTail && i < snake_x[0] && direction == RIGHT)
	//		{
	//			field[i] = tail_symbol;
	//		}
	//		else if (i <= indTail && i > snake_x[0] && direction == LEFT)
	//		{
	//			field[i] = tail_symbol;
	//		}
	//		else
	//		{
	//			field[i] = ' ';
	//		}
	//		cout << field[i];
	//	}
	//	Sleep(timeout);
	//	//ind = system("cls");
	//	system("cls");

	//	if (direction == RIGHT)
	//	{
	//		X++;
	//	}
	//	else
	//	{
	//		X--;
	//	}
	//	
	//	if (X == (columns - 1))
	//	{
	//		X = 1;
	//	}
	//	else if (X == 0)
	//	{
	//		X = columns - 2;
	//	}

	//	if (_kbhit()) // проверяет консоль на предмет недавнего нажатия клавиши
	//	{
	//		unsigned int endGame;
	//		endGame = _getch();
	//		if (endGame == 27)
	//		{
	//			cout << "Game over" << endl;
	//			game_on = false;
	//		}
	//	}

	//}

}