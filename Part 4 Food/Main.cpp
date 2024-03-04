#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Const.h"
#include"Game.h"
#include"Snake.h"
#include"Field.h"
#include"Food.h"

using std::cout;
using std::cin;
using std::endl;


void main()
{
	srand(time(0));
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
	int X = 5; // координата первоначального положения "головы" змейки
	int indMove = 0; // индекс "хвоста" змейки

	if (direction == RIGHT) // Координаты змейки перед началом игры:
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
		// прорисовка верхней границы:
		for (int i = 0; i < columns; i++)
		{
			cout << '*';
		}
		cout << endl;

		snake_x[0] = X; // координата положения "головы" змейки в процессе

		// установка "еды" на поле:
		while (food_flag == false)
		{
			food_x = rand() % L + 1; // L = columns - 2;
			food_flag = true;

			for (int i = 0; i < snake_size; i++)
			{
				if (food_x == snake_x[i])
				{
					food_flag = false;
					break;
				}
			}
		}

		// Печать игрового поля со змейкой и едой в блоке for:
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
				else if (i == food_x)
				{
					field[i] = food_symbol;
				}
				else
				{
					field[i] = field_symbol;
				}
			}
			cout << field[i];
		}

		// прорисовка нижней границы:
		cout << endl;
		for (int i = 0; i < columns; i++)
		{
			cout << '*';
		}

		// очистка игрового поля и задержка в тайминге
		Sleep(timeout);
		system("cls");

		// координаты змейки смещаются:
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
		
		// координата "головы" совпадает с координатой конца игрового поля:
		if (X == (columns - 1))
		{ X = 1; }
		else if (X == 0)
		{ X = columns - 2; }

		// координата "головы" совпадает с координатой "еды":
		if (X == food_x)
		{
			food_flag = false;			
			if (direction == RIGHT)
			{
				snake_x[snake_size] = snake_x[snake_size - 1] - 1;
			}
			else
			{
				snake_x[snake_size] = snake_x[snake_size - 1] + 1;
			}
			snake_size++;
		}

		// змейка достигла своего максимально возможного размера
		if (snake_size == L)
		{
			cout << "You win" << endl;
			game_on = false;
		}
		
		// ожидание команды выхода из игры:
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

}