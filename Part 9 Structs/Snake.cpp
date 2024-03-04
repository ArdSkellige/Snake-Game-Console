#include "Game.h"


void InitSnake(Field& field, Snake& snake, Game& game, int& input)
{
	if (snake.direction == DIRECTION::RIGHT)
	{
		snake.snake_X[0] = snake.snake_size;
		snake.snake_Y[0] = field.rowsY / 2;

		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_X[i] = snake.snake_X[i - 1] - game.indMoveRL;
		}
		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_Y[i] = field.rowsY / 2;
		}
	}
	else if (snake.direction == DIRECTION::UP)
	{
		snake.snake_Y[0] = (field.rowsY - 2) - snake.snake_size + 1;
		snake.snake_X[0] = field.columnsX / 2;

		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_Y[i] = snake.snake_Y[i - 1] - game.indMoveUD;
		}
		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_X[i] = field.columnsX / 2;
		}
	}
	else if (snake.direction == DIRECTION::LEFT)
	{
		// Координаты змейки. snake[0] - координата головы на старте.
		snake.snake_X[0] = (field.columnsX - 2) - snake.snake_size + 1;
		snake.snake_Y[0] = field.rowsY / 2;

		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_X[i] = snake.snake_X[i - 1] - game.indMoveRL;
		}
		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_Y[i] = field.rowsY / 2;
		}
	}
	else
	{
		snake.snake_Y[0] = snake.snake_size;
		snake.snake_X[0] = field.columnsX / 2;

		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_Y[i] = snake.snake_Y[i - 1] - game.indMoveUD;
		}
		for (size_t i = 1; i < snake.snake_size; i++)
		{
			snake.snake_X[i] = field.columnsX / 2;
		}
	}
}

void SnakeMove(Field& field, Snake& snake, Game& game)
{
	for (size_t i = snake.snake_size - 1; i > 0; i--)
	{
		snake.snake_X[i] = snake.snake_X[i - 1];
		snake.snake_Y[i] = snake.snake_Y[i - 1];
	}

	if (snake.direction == DIRECTION::RIGHT)
	{
		game.indMoveRL = 1;
		if (snake.snake_X[0] < field.columnsX - 2)
		{
			snake.snake_X[0] += game.indMoveRL;
		}
		else
		{
			snake.snake_X[0] = 1;
		}
	}
	else if (snake.direction == DIRECTION::LEFT)
	{
		game.indMoveRL = -1;
		if (snake.snake_X[0] > 1)
		{
			snake.snake_X[0] += game.indMoveRL;
		}
		else
		{
			snake.snake_X[0] = field.columnsX - 2;
		}
	}
	else if (snake.direction == DIRECTION::UP)
	{
		game.indMoveUD = -1;
		if (snake.snake_Y[0] > 1)
		{
			snake.snake_Y[0] += game.indMoveUD;
		}
		else
		{
			snake.snake_Y[0] = field.rowsY - 2;
		}
	}
	else if (snake.direction == DIRECTION::DOWN)
	{
		game.indMoveUD = 1;
		if (snake.snake_Y[0] < field.rowsY - 2)
		{
			snake.snake_Y[0] += game.indMoveUD;
		}
		else
		{
			snake.snake_Y[0] = 1;
		}
	}
}

void SnakeAteFood(Food& food, Snake& snake, int last_segm_bud_hor, int last_segm_bud_vert)
{
	food.food_flag = false;

	snake.snake_Y[snake.snake_size] = last_segm_bud_hor;
	snake.snake_X[snake.snake_size] = last_segm_bud_vert;
	++snake.snake_size;
}
