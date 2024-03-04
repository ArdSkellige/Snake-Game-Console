#include "Snake.h"


void InitSnake(int fieldXSize, int fieldYSize, unsigned int* snake_x, unsigned int* snake_y, unsigned int snake_size, DIRECTION& direction, int& indMoveRL, int& indMoveUD, int& input)
{
	if (direction == DIRECTION::RIGHT)
	{
		snake_x[0] = snake_size;
		snake_y[0] = fieldYSize / 2;

		for (size_t i = 1; i < snake_size; i++)
		{
			snake_x[i] = snake_x[i - 1] - indMoveRL;
		}
		for (size_t i = 1; i < snake_size; i++)
		{
			snake_y[i] = fieldYSize / 2;
		}
	}
	else if (direction == DIRECTION::UP)
	{
		snake_y[0] = (fieldYSize - 2) - snake_size + 1;
		snake_x[0] = fieldXSize / 2;

		for (size_t i = 1; i < snake_size; i++)
		{
			snake_y[i] = snake_y[i - 1] - indMoveUD;
		}
		for (size_t i = 1; i < snake_size; i++)
		{
			snake_x[i] = fieldXSize / 2;
		}
	}
	else if (direction == DIRECTION::LEFT)
	{
		// Координаты змейки. snake[0] - координата головы на старте.
		snake_x[0] = (fieldXSize - 2) - snake_size + 1;
		snake_y[0] = fieldYSize / 2;

		for (size_t i = 1; i < snake_size; i++)
		{
			snake_x[i] = snake_x[i - 1] - indMoveRL;
		}
		for (size_t i = 1; i < snake_size; i++)
		{
			snake_y[i] = fieldYSize / 2;
		}
	}
	else
	{
		snake_y[0] = snake_size;
		snake_x[0] = fieldXSize / 2;

		for (size_t i = 1; i < snake_size; i++)
		{
			snake_y[i] = snake_y[i - 1] - indMoveUD; 
		}
		for (size_t i = 1; i < snake_size; i++)
		{
			snake_x[i] = fieldXSize / 2;
		}
	}
}

void SnakeMove(int fieldXSize, int fieldYSize, const DIRECTION direction, unsigned int* snake_x, unsigned int* snake_y, unsigned int snake_size, int moveRL, int moveUD)
{
	for (size_t i = snake_size - 1; i > 0; i--)
	{
		snake_x[i] = snake_x[i - 1];
		snake_y[i] = snake_y[i - 1];
	}

	if (direction == DIRECTION::RIGHT)
	{
		moveRL = 1;
		if (snake_x[0] < fieldXSize - 2)
		{
			snake_x[0] += moveRL;
		}
		else
		{
			snake_x[0] = 1;
		}
	}
	else if (direction == DIRECTION::LEFT)
	{
		moveRL = -1;
		if (snake_x[0] > 1)
		{
			snake_x[0] += moveRL;
		}
		else
		{
			snake_x[0] = fieldXSize - 2;
		}
	}
	else if (direction == DIRECTION::UP)
	{
		moveUD = -1;
		if (snake_y[0] > 1)
		{
			snake_y[0] += moveUD;
		}
		else
		{
			snake_y[0] = fieldYSize - 2;
		}
	}
	else if (direction == DIRECTION::DOWN)
	{
		moveUD = 1;
		if (snake_y[0] < fieldYSize - 2)
		{
			snake_y[0] += moveUD;
		}
		else
		{
			snake_y[0] = 1;
		}
	}
}

void SnakeAteFood(bool& food_flag, unsigned int* snake_x, unsigned int* snake_y, unsigned int& snake_size, int last_segm_x, int last_segm_y)
{
	food_flag = false;

	snake_y[snake_size] = last_segm_x;
	snake_x[snake_size] = last_segm_y;
	++snake_size;
}
