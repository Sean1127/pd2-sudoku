#include "Sudoku.h"
void Sudoku::GiveQuestion(int board[144])
{
	for (int i = 0; i < 144; i += 12)
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
