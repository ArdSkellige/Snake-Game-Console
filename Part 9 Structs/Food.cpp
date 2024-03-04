//#include "Food.h"
#include "Game.h"

void SetFood(Food& food, Snake& snake, Field& field)
{
	while (!food.food_flag && snake.snake_size < 100)
	{
		food.food_X = rand() % (field.columnsX - 2) + 1;
		food.food_Y = rand() % (field.rowsY - 2) + 1;
		food.food_flag = true;

		for (size_t i = 0; i < snake.snake_size; i++)
		{
			if ((food.food_X == snake.snake_X[i]) && (food.food_Y == snake.snake_Y[i]))
			{
				food.food_flag = false;
				break;
			}
		}
	}
}
