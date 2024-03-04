//#include "Field.h"
#include "Game.h"


void InitFieldSize(Field& field)
{
	cout << "Enter sizes of the playing field width(X) and height(Y): ";
	while ((field.rowsY < 10) && (field.columnsX < 10))
	{
		cin >> field.rowsY;
		cin >> field.columnsX;
		if ((field.rowsY < 10) && (field.columnsX < 10))
		{
			cout << "Invalid values, try again!";
		}
	}
}

void CreateField(Field& field)
{
	field.pch = new unsigned char[field.rowsY * field.columnsX];
	field.pch2 = new unsigned char* [field.rowsY];

	for (size_t i = 0; i < field.rowsY; i++)
	{
		field.pch2[i] = &(field.pch[i * field.columnsX]);
	}
}

void SetBorder(Field& field)
{
	for (int i = 0; i < field.rowsY; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < field.columnsX; j++)
			{
				field.pch2[i][j] = '*';
			}
		}
		else if (i == field.rowsY - 1)
		{
			for (int j = 0; j < field.columnsX; j++)
			{
				field.pch2[i][j] = '*';
			}
		}
		field.pch2[i][0] = border_symbol;
		field.pch2[i][field.columnsX - 1] = border_symbol;
	}
}

void SetSnake(Food& food, Snake& snake, Field& field)
{
	if (food.food_flag)
	{
		field.pch2[food.food_Y][food.food_X] = food_symbol;
	}

	for (int i = 0; i < snake.snake_size; i++)
	{
		if (i == 0)
		{
			field.pch2[snake.snake_Y[i]][snake.snake_X[i]] = head_symbol;
		}
		else
		{
			field.pch2[snake.snake_Y[i]][snake.snake_X[i]] = tail_symbol;
		}
	}
}

void PrintField(Snake& snake, Field& field)
{
	for (int i = 0; i < field.rowsY; i++)
	{
		for (int j = 0; j < field.columnsX; j++)
		{
			std::cout << field.pch2[i][j];
		}
		cout << endl;
	}
}

void ClearField(Field& field)
{
	for (int i = 1; i < field.rowsY - 1; i++)
	{
		for (int j = 1; j < field.columnsX - 1; j++)
		{
			field.pch2[i][j] = field_symbol;
		}
	}
}

void DeleteField(Field& field)
{
	delete[] field.pch;
	delete[] field.pch2;
}
