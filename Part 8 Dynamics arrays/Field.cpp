#include "Field.h"


void SetBorder(unsigned char** p, int fieldXSize, int fieldYSize)
{
	for (int i = 0; i < fieldYSize; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < fieldXSize; j++)
			{
				p[i][j] = '*';
			}
		}
		else if (i == fieldYSize - 1)
		{
			for (int j = 0; j < fieldXSize; j++)
			{
				p[i][j] = '*';
			}
		}
		p[i][0] = border_symbol;
		p[i][fieldXSize - 1] = border_symbol;
	}
}

void SetSnake(bool food_flag, unsigned int snake_size, unsigned char** p, unsigned int* snake_x, unsigned int* snake_y, int food_x, int food_y)
{
	if (food_flag)
	{
		p[food_y][food_x] = food_symbol;
	}

	for (int i = 0; i < snake_size; i++)
	{
		if (i == 0)
		{
			p[snake_y[i]][snake_x[i]] = head_symbol;
		}
		else
		{
			p[snake_y[i]][snake_x[i]] = tail_symbol;
		}
	}
}

void PrintField(unsigned char** p, int fieldXSize, int fieldYSize, unsigned int snake_size)
{
	for (int i = 0; i < fieldYSize; i++)
	{
		for (int j = 0; j < fieldXSize; j++)
		{
			std::cout << p[i][j];
		}
		cout << endl;
	}
}

void ClearField(unsigned char** p, int fieldXSize, int fieldYSize)
{
	for (int i = 1; i < fieldYSize - 1; i++)
	{
		for (int j = 1; j < fieldXSize - 1; j++)
		{
			p[i][j] = field_symbol;
		}
	}
}