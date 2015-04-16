#include "Sudoku.h"

int main()
{
	Sudoku s;
	s.ReadIn();
	s.Solve(s.board);
	return 0;
}
