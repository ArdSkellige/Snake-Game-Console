#include<iostream>
#include<conio.h>
using namespace std;

enum Direction
{
	UP = 72,
	DOWN = 80,
	RIGHT = 77,
	LEFT = 75
};


void main()
{
	cout << "Start " << endl;

	//unsigned int direction = _getch();
	//cout << "Symbol = " << direction << endl;
	//direction = _getch();
	//cout << "Symbol = " << direction << endl;

	unsigned int direction;
	do
	{
		direction = _getch();
		if (direction == 27)
		{
			cout << "Game over" << endl;
		}
		else if (direction == 224)
		{
			direction = _getch();
				if (direction == LEFT)
				{
					cout << '<' << endl;
				}
				else if (direction == RIGHT)
				{
					cout << '>' << endl;
				}
				else if (direction == UP)
				{
					cout << '^' << endl;
				}
				else if (direction == DOWN)
				{
					cout << 'v' << endl;
				}
		}		
		else
		{
			cout << "Unknown symbol !" << endl;
		}
	} while (direction != 27);


	//unsigned int direction;
	//do
	//{
	//	direction = _getch();
	//	direction = _getch();
	//	if (direction == 75)
	//	{
	//		cout << '<' << endl;
	//	}
	//	else if (direction == 77)
	//	{
	//		cout << '>' << endl;
	//	}
	//	else if (direction == 72)
	//	{
	//		cout << '^' << endl;
	//	}
	//	else if (direction == 80)
	//	{
	//		cout << 'v' << endl;
	//	}
	//	else if (direction == 27)
	//	{
	//		cout << "Game over" << endl;
	//	}
	//	else
	//	{
	//		cout << "Unknown symbol !" << endl;
	//	}
	//	

	//} while (direction != 27);


#pragma region do-while2.0
	/*char ch;
	do
	{
		ch = _getch();
		switch (ch)
		{
			case 'S':
			case 's':
				cout << 'v' << endl;
				continue;
			case 'W':
			case 'w':
				cout << '^' << endl;
				continue;
			case 'A':
			case 'a':
				cout << '<' << endl;
				continue;
			case 'D':
			case 'd':
				cout << '>' << endl;
				continue;			
			default:
				cout << "Error symbol !!!" << endl;
				break;
		}
		if (ch == 27)
		{
			cout << "Game over" << endl;
		}

	} while (ch != 27);*/
#pragma endregion

#pragma region do-while
	//char ch;
	//do
	//{
	//	//cin >> ch;
	//	ch = _getch();
	//	switch (ch)
	//	{
	//		case 'S':
	//		case 's':
	//			cout << 'v' << endl;
	//			continue;
	//		case 'W':
	//		case 'w':
	//			cout << '^' << endl;
	//			continue;
	//		case 'A':
	//		case 'a':
	//			cout << '<' << endl;
	//			continue;
	//		case 'D':
	//		case 'd':
	//			cout << '>' << endl;
	//			continue;
	//		case '0':
	//			cout << "Game over" << endl;
	//			continue;
	//		default:
	//			cout << "Error symbol !!!" << endl;
	//			continue;
	//	}
	//} while (ch != '0');
#pragma endregion

#pragma region while
	//while (true)
	//{
	//	char ch;
	//	cin >> ch;
	//	switch (ch)
	//	{
	//		case 'S':
	//		case 's':
	//			cout << 'v' << endl;
	//			continue;
	//		case 'W':
	//		case 'w':
	//			cout << '^' << endl;
	//			continue;
	//		case 'A':
	//		case 'a':
	//			cout << '<' << endl;
	//			continue;
	//		case 'D':
	//		case 'd':
	//			cout << '>' << endl;
	//			continue;
	//		case '0':
	//			cout << "Game over" << endl;
	//			break;
	//		default:
	//			cout << "Error symbol !!!" << endl;
	//			continue;
	//	}
	//	break;
	//}
#pragma endregion


}
