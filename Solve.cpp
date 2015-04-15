#include "Sudoku.h"
using namespace std;
int BackTrack(int location)
int main()
{
	Sudoku s;
	s.ReadIn();
	BackTrack();	
	s.Solve(s.board);
	return 0;
}
int BackTrack(int location)
{
	if (Question finish == true)
		return true;
	for (int i = 0; i < 9; i++)
	{
		grid[position] = i;
		if(gridisvalid)
		{
			if (BackTrack() == true)
			{
				return true;
			}
		}
	}
	grid[position] = 0;
	return false;
}
