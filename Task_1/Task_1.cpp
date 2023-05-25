// Task 1. Write a program that implements the Tic Tac Toe game on a 3x3 two-dimensional array. 
// The program should allow the player to enter his moves in the form of row and column coordinates.
// Rules of the game :
// The game is played between two players, one using "X" and the other using "O".
// Players take turns making their moves on free cells of the reachable array.
// The game ends when one of the players gets three of his symbols in a row, column or diagonal.
// After each move, the program should check whether there is already a winner or whether there are no free cells for the move.
// If one of the players wins or the game is tied, the program should display a corresponding messageand end the game.
// The use of multidimensional arrays will make it possible to present the playing fieldand monitor the state of the game.
// You will need logic to verify the winand determine the next player.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

char** GenerateArray(int& N);
void PrintGrid(char** arr, int& size, bool player);
void NumPadAdapter(int& controller, int& row, int& column);
void Eror();
bool Row(char** arr, int size, char P);
bool Columns(char** arr, int size, char P);
bool Diag(char** arr, int size, char P);
bool Victory(char** arr, int size, char P);

int main()
{
	int count = 0;
	int N = 3;
	char** arr = GenerateArray(N);
	char X = 'X', O = 'O';
	int row = 0, column = 0;
	bool player = true;
	int controller = 0;

	PrintGrid(arr, N, player);
	while (true)
	{
		cout << "\tEnter where to move: "; cin >> controller;
		
		if (controller >= 1 && controller <= 9)
		{
			NumPadAdapter(controller, row, column);

			if ((arr[row - 1][column - 1] == ' '))
			{
				if (player)
				{
					arr[row - 1][column - 1] = X;
					PrintGrid(arr, N, player);

					player = false;
					if (Victory(arr, N, X))
					{
						printf("\n\tPlayer %c Win\n\n", X);
						break;
					}
					count++;
				}
				else
				{
					arr[row - 1][column - 1] = O;
					PrintGrid(arr, N, player);

					player = true;
					if (Victory(arr, N, O))
					{
						printf("\n\tPlayer %c Win\n\n", O);
						break;
					}
					count++;
				}
			}
			else
			{
				Eror();
			}
		}
		else
		{
			Eror();
		}
		if (count == 9)
		{
			cout << "\n\t DRAW\n\n\n\n";
			break;
		}
	}
}

char** GenerateArray(int& N)
{
	char** arr = new char* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
		}
	}
	return arr;
}

void PrintGrid(char** arr, int& size, bool player)
{
	system("cls");
	if (player)
	{
		cout << "\n\tPlayer O move\t\tUse numpad to play";
	}
	else
	{
		cout << "\n\tPlayer X move\t\tUse numpad to play";
	}
	printf("\n\n\t%c | %c | %c\t\t7 | 8 | 9\n\t---------\t\t---------\n\t%c | %c | %c\t\t4 | 5 | 6\n\t---------\t\t---------\n\t%c | %c | %c\t\t1 | 2 | 3\n\n\n\n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2], arr[2][0], arr[2][1], arr[2][2]);
}

void NumPadAdapter(int& controller, int& row, int& column)
{
	switch (controller)
	{
	case 1:
		row = 3;
		column = 1;
		break;
	case 2:
		row = 3;
		column = 2;
		break;
	case 3:
		row = 3;
		column = 3;
		break;
	case 4:
		row = 2;
		column = 1;
		break;
	case 5:
		row = 2;
		column = 2;
		break;
	case 6:
		row = 2;
		column = 3;
		break;
	case 7:
		row = 1;
		column = 1;
		break;
	case 8:
		row = 1;
		column = 2;
		break;
	case 9:
		row = 1;
		column = 3;
		break;
	default:
		break;
	}
}

void Eror()
{
	cout << "\n\tEnter diferent valume\n\n";
}

bool Row(char** arr, int size, char P)
{
	if ((arr[0][0] == P && arr[0][1] == P && arr[0][2] == P) || (arr[1][0] == P && arr[1][1] == P && arr[1][2] == P) || (arr[2][0] == P && arr[2][1] == P && arr[2][2] == P))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Columns(char** arr, int size, char P)
{
	if ((arr[0][0] == P && arr[1][0] == P && arr[2][0] == P) || (arr[0][1] == P && arr[1][1] == P && arr[2][1] == P) || (arr[0][2] == P && arr[1][2] == P && arr[2][2] == P))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Diag(char** arr, int size, char P)
{
	if ((arr[0][0] == P && arr[1][1] == P && arr[2][2] == P) || (arr[2][0] == P && arr[1][1] == P && arr[0][2] == P))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Victory(char** arr, int size, char P)
{
	if ((Row(arr, size, P)) || (Columns(arr, size, P)) || (Diag(arr, size, P)))
	{
		return true;
	}
	else
	{
		return false;
	}
}