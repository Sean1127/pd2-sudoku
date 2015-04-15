#include "Sudoku.h"
using namespace std;
int Next(int board[144], int location);
bool CheckValid();
int BackTrack(int (&board)[144], int location);
//
int main()
{
	Sudoku s;
	s.ReadIn();
	BackTrack(s.board, Next(s.board, 0));	
	s.Solve(s.board);
	return 0;
}
//
int Next(int board[144], int location)
{
	int target = -1;
	for (int i = location; i < 144; i++)
	{
		if (board[i] == 0)
		{
			target = i;
			break;
		}
	}
	return target;
}
bool CheckValid()
{
	return false;
}
int BackTrack(int (&board)[144], int location)
{
	if (Next(board, location) == -1)
		return true;
	for (int i = 0; i < 9; i++)
	{
		board[location] = i;
		if (CheckValid() == true)
		{
			if (BackTrack(board, Next(board, location)) == true)
			{
				return true;
			}
		}
	}
	board[location] = 0;
	return false;
}
