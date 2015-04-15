#include <iostream>
#include <fstream>
using namespace std;

class Sudoku{
public:
	void GiveQuestion(int board[]);
	void ReadIn();
	void Solve(int board[]);
	int board[144];
};
