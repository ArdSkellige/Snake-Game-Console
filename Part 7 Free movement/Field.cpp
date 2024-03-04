#include "Field.h"

// установка границ игрового поля (крайние координаты массива):
void SetBorder(unsigned char(*field)[columns])
{
	for (int i = 0; i < rows; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < columns; j++)
			{
				field[i][j] = '*';
			}
		}
		else if (i == rows - 1)
		{
			for (int j = 0; j < columns; j++)
			{
				field[i][j] = '*';
			}
		}
		field[i][0] = border_symbol;
		field[i][columns - 1] = border_symbol;
	}
}

// установка координат змейки на поле:
void SetSnake(bool food_flag, unsigned int snake_size, unsigned char(*field)[columns], unsigned int* snake_x, unsigned int* snake_y, int food_x, int food_y)
{
	if (food_flag)
	{
		field[food_y][food_x] = food_symbol;
	}

	for (int i = 0; i < snake_size; i++)
	{
		if (i == 0)
		{
			field[snake_y[i]][snake_x[i]] = head_symbol;
		}
		else
		{
			field[snake_y[i]][snake_x[i]] = tail_symbol;
		}
	}
}

// печать игрового поля, символов змейки и "еды":
void PrintField(unsigned char(*field)[columns], unsigned int snake_size)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << field[i][j];
		}
		cout << endl;
	}
}

// "очистка" игрового поля - заполнение символами поля - (' ')
void ClearField(unsigned char(*field)[columns])
{
	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < columns - 1; j++)
		{
			field[i][j] = field_symbol;
		}
	}
}