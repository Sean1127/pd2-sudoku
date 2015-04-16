#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku{
public:
	void GiveQuestion();
	void ReadIn();
	void Solve(int board[12][12]);
	int board[12][12];
};
