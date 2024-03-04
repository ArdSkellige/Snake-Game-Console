#include "Food.h"


void SetFood(bool& food_flag, unsigned int snake_size, unsigned int* snake_x, unsigned int* snake_y, unsigned int& food_x, unsigned int& food_y)
{
	while (!food_flag && snake_size < L)
	{
		food_x = rand() % (columns - 2) + 1;
		food_y = rand() % (rows - 2) + 1;
		food_flag = true;

		for (size_t i = 0; i < snake_size; i++)
		{
			if ((food_x == snake_x[i]) && (food_y == snake_y[i]))
			{
				food_flag = false;
				break;
			}
		}
	}
}
