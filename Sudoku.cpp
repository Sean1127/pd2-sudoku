#include "Sudoku.h"
void Sudoku::GiveQuestion(int board[])
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
	
}
void Sudoku::Solve(int board[])
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
