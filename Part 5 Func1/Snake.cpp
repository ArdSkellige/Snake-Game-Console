#include "Snake.h"

int snake_size = 5;
DIRECTION direction = RIGHT;
int snake_x[L] = { 0 };

// глобальные данные для определения координат змейки:
int indMove = 0; // индекс "хвоста" змейки
int X = 5; // координата первоначального положения "головы" змейки

// определение координат змейки перед началом игры:
void InitSnake()
{
	if (direction == RIGHT)
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
}

// изменение координат змейки в процессе игры:
void MoveSnake()
{
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
	{
		X = 1;
	}
	else if (X == 0)
	{
		X = columns - 2;
	}
}

void SnakeAteFood()
{
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
}