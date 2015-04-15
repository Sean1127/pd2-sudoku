#include "Sudoku.h"
using namespace std;
int Next(int board[12][12], int x, int y);
bool CheckValid();
int BackTrack(int (&board)[12][12], int x, int y);

int main()
{
	Sudoku s;
	s.ReadIn();
	int x = Next(s.board, 0, 0)%12;
	int y = Next(s.board, 0, 0)/12;
	BackTrack(s.board, x, y);	
	s.Solve(s.board);
	return 0;
}

int Next(int board[12][12], int x, int y)
{
	int target = -1;
	for (int i = y; i < 12; i++)
	{
		for (int j = x; j < 12; j++)
		{
			if (board[i][j] == 0)
			{
				x = j;
			y = i;
			target = x + y*12;
				break;
			}
		}
	}
	return target;
}
//
bool CheckValid()
{
	return true;
}
//
int BackTrack(int (&board)[12][12], int x, int y)
{
	if (Next(board, x, y) == -1)
		return true;
	for (int i = 0; i < 9; i++)
	{
		board[x][y] = i;
		if (CheckValid() == true)
		{
			int nextx = Next(board, x, y)%12;
			int nexty = Next(board, x, y)/12;
			if (BackTrack(board, nextx, nexty) == true)
			{
				return true;
			}
		}
	}
	board[x][y] = 0;
	return false;
}
