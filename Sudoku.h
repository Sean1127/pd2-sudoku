#include <iostream>
#include <fstream>
using namespace std;

class Sudoku{
public:
	void GiveQuestion(int board[144]);
	void ReadIn();
	void Solve(int board[12][12]);
	int board[12][12];
};
