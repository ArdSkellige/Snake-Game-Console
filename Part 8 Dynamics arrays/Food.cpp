#include "Food.h"


void SetFood(int fieldXSize, int fieldYSize, bool& food_flag, unsigned int snake_size, unsigned int* snake_x, unsigned int* snake_y, unsigned int& food_x, unsigned int& food_y)
{
	while (!food_flag && snake_size < 100)
	{
		food_x = rand() % (fieldXSize - 2) + 1;
		food_y = rand() % (fieldYSize - 2) + 1;
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
