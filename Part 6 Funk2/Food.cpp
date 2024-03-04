#include "Food.h"


void SetFood(bool& food_flag, int& food_x, int& snake_size, int* snake_x)
{
	srand(time(0));
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
}
