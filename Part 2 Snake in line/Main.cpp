#include<iostream>
#include<windows.h>
#include"Const.h"
#include"Game.h"
#include"Snake.h"

using namespace std;


void main()
{
	char cStep = ' ';
	int temp = 0;
	int size;

	for (int i = 0; i < columns; i++)
	{
		int tempX = 5;
		if (tempX != 0)
		{
			while (tempX > 0)
			{
				cout << cStep;
				tempX--;
			}
		}

		temp = 0;
		if (snake_size == 1)
		{
			cout << head_symbol;
		}
		else
		{
			size = 0;
			while (size < snake_size - 1)
			{
				cout << tail_symbol;
				size++;
			}
			cout << head_symbol;
		}


		
		Sleep(timeout);
		system("cls");
		while (temp < i + 1)
		{
			cout << cStep;
			temp++;
		}		
	}

}