#include "Sudoku.h"
using namespace std;
int main()
{
	Sudoku s;
	int board[144];
	s.ReadIn();
	s.Solve(board);
	return 0;
}
