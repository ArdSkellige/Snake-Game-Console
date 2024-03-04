#include "Field.h"

char field[columns];

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

// печать игрового поля, символов змейки и "еды"
void PrintField()
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