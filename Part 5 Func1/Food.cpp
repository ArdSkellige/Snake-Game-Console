#include "Food.h"

bool food_flag = false;
// Координата еды в поле игры (по горизонтали):
int food_x = 0;

// установка "еды" на поле:
void SetFood()
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
