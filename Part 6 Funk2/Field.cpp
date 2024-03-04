#include "Field.h"


void PrintUpBorder()
{
	for (int i = 0; i < columns; i++)
	{
		cout << '*';
	}
	cout << endl;
}

void PrintLowBorder()
{
	cout << endl;
	for (int i = 0; i < columns; i++)
	{
		cout << '*';
	}
}

void PrintField(int& food_x, unsigned char* field, int& snake_size, int* snake_x, int& X)
{
	snake_x[0] = X; // координата положения "головы" змейки в процессе
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < snake_size; j++)
		{
			if (i == 0 || i == columns - 1)
			{
				field[i] = border_symbol;
			}
			else if (i == snake_x[0])
			{
				field[i] = head_symbol;
			}
			else if (i == snake_x[j])
			{
				field[i] = tail_symbol;
				break;
			}
			else if (i == food_x)
			{
				field[i] = food_symbol;
			}
			else
			{
				field[i] = field_symbol;
			}
		}
		cout << field[i];
	}
}