#include "Sudoku.h"

bool Sudoku::CheckUnity(int arr[], int size)
{
	int unity[size];
	for (int i = 0; i < size; ++i)
	{
		unity[i] = 0;
	}
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > 0)
			++unity[arr[i] - 1];
	}
	for (int i = 0; i < size; i++)
	{
		if (unity[i] > 1)
			return false;
	}
	return true;
}

bool Sudoku::CheckValid(int board[12][12], int x, int y)
{
	int arr[12];
	int i, j, k = 0;
	for (i = 0; i < 12; i++)//check row
	{
		arr[i] = board[y][i];
	}
	if (CheckUnity(arr, 12) == false)
		return false;
	for (i = 0; i < 12; i++)//check column
	{
		arr[i] = board[i][x];
	}
	if (CheckUnity(arr, 12) == false)
		return false;
	switch (x%3)//locate block x
	{
		case 0:
			j = x;
			break;
		case 1:
			j = x - 1;
			break;
		case 2:
			j = x - 2;
			break;
	}
	switch (y%3)//locate block y
	{
		case 0:
			i = y;
			break;
		case 1:
			i = y - 1;
			break;
		case 2:
			i = y - 2;
			break;
	}
	for (int m = j; m < j + 3; m++)//check block
	{
		for (int n = i; n < i + 3; n++)
		{
			 arr[k++] = board[n][m];
		}
	}
	if (CheckUnity(arr, 9) == false)
		return false;
	return true;
}

int Sudoku::Next(int board[12][12], int location)
{
	int target = -1;
	for (int i = location; i < 144; i++)
	{
		int x = i%12;
		int y = i/12;
		if (board[y][x] == 0)//meet empty cell
		{
			target = i;
			return target;
		}
	}
	return target;
}

int Sudoku::BackTrack(int (&board)[12][12], int x, int y)
{
	if (Next(board, x + 12*y) == -1)//game finish//
	{
		type++;
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
				map[i][j] = board[i][j];
		if (type == 2)
			return true;
		else
			return false;
	}
	for (int i = 1; i < 10; i++)//guess from 1 to 9
	{
		board[y][x] = i;
		if (CheckValid(board, x, y) == true)
		{
			int nextx = Next(board, x + 12*y)%12;
			int nexty = Next(board, x + 12*y)/12;
			if (BackTrack(board, nextx, nexty) == true)//do next cell
			{
				return true;
			}
		}
	}
	board[y][x] = 0;//no forget delete before go back
	return false;
}

void Sudoku::Solve()
{
	Solve(board);
}

void Sudoku::Solve(int (&board)[12][12])
{
	int x = Next(board, 0)%12;//find first x
	int y = Next(board, 0)/12;//find first y
	type = 0;
	for (int i = 0; i < 12; i ++)
		for (int j = 0; j < 12; j++)
			map[i][j] = 0;
	BackTrack(board, x, y);
	if (type == 1)
	{
		cout << type << endl;
		for (int i = 0; i < 12; i ++)
		{
			for (int j = 0; j < 12; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
		cout << type << endl;
}

void Sudoku::GiveQuestion()
{
	int board[144], count[9], swap[36];
	int A[9], B[9], C[9], D[9], E[9], F[9], G[9], H[9], I[9];
	int i, j, k;
	srand((unsigned)time(NULL));
	for (i = 0; i < 9; i++)//counter
	{
		count[i] = 1;
	}
	for (i = 0; i < 9;)//central block
	{
		k = rand()%9;
		if (count[k] != 0)
		{
			E[i] = k;
			count[k] = 0;
			i++;
		}
	}
	for (i = 0; i < 3; i++)//left right block
	{
		D[i] = E[i + 3];
		D[i + 3] = E[i + 6];
		D[i + 6] = E[i];
		F[i] = E[i + 6];
		F[i + 3] = E[i];
		F[i + 6] = E[i + 3];
	}
	for (i = 0; i < 9; i += 3)//up down block
	{
		B[i] = E[i + 1];
		B[i + 1] = E[i + 2];
		B[i + 2] = E[i];
		H[i] = E[i + 2];
		H[i + 1] = E[i];
		H[i + 2] = E[i + 1];
	}
	for (i = 0; i < 9; i += 3)//left up down block
	{
		A[i] = D[i + 2];
		A[i + 1] = D[i];
		A[i + 2] = D[i + 1];
		G[i] = D[i + 1];
		G[i + 1] = D[i + 2];
		G[i + 2] = D[i];
	}
	for (i = 0; i < 9; i += 3)//right up down block
	{
		C[i] = F[i + 2];
		C[i + 1] = F[i];
		C[i + 2] = F[i + 1];
		I[i] = F[i + 1];
		I[i + 1] = F[i + 2];
		I[i + 2] = F[i];
	}
	for (i = 0; i < 36; i += 12)//set the board(1)
	{
		for (j = 0; j < 3; j++)
		{
			board[i + j] = -1;
			board[i + j + 3] = B[i/4 + j];
			board[i + j + 6] = C[i/4 + j];
			board[i + j + 9] = A[i/4 + j];
		}
	}
	for (i = 36; i < 72; i += 12)//set the board(2)
	{
		for (j = 0; j < 3; j++)
		{
			board[i + j] = D[i/4 - 9 + j];
			board[i + j + 3] = -1;
			board[i + j + 6] = F[i/4 - 9 + j];
			board[i + j + 9] = E[i/4 - 9 + j];
		}
	}
	for (i = 72; i < 108; i += 12)//set the board(3)
	{
		for (j = 0; j < 3; j++)
		{
			board[i + j] = G[i/4 - 18 + j];
			board[i + j + 3] = H[i/4 - 18 + j];
			board[i + j + 6] = -1;
			board[i + j + 9] = I[i/4 - 18 + j];
		}
	}
	for (i = 108; i < 144; i += 12)//set the board(4)
	{
		for (j = 0; j < 3; j++)
		{
			board[i + j] = A[i/4 - 27 + j];
			board[i + j + 3] = E[i/4 - 27 + j];
			board[i + j + 6] = I[i/4 - 27 + j];
			board[i + j + 9] = -1;
		}
	}
	for (i = 0; i < 144; i++)//dig hole
	{
		if (board[i] != -1)
		{
			if (rand()%7 != 0)
				board[i] = 0;
		}
	}
	j = (rand()%4)*36;//swap
	for (i = 0; i < 36; i++)
	{
		swap[i] = board[i + j];
	}
	do
	{
		k = (rand()%4)*36;
	} while (k == j);
	for (i = 0; i < 36; i++)
	{
		board[i + j] = board[i + k];
	}
	for (i = 0; i < 36; i++)
	{
		board[i + k] = swap[i];
	}
	for (int i = 0; i < 144; i += 12)//output
	{
		for (int j = 0; j < 12; j++)
		{
			cout << board[i + j] << " ";
		}
		cout << endl;
	}
}

void Sudoku::ReadIn()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cin >> board[i][j];
		}
	}
}
