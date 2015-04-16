#include "Sudoku.h"
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
			if (rand()%3 != 0)
				board[i] = 0;
		}
	}
	j = (rand()%4)*36;
	for (i = 0; i < 36; i++)//swap
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
void Sudoku::Solve(int board[12][12])
{
	for (int i = 0; i < 12; i ++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
