#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku{
public:
	void GiveQuestion();
	void ReadIn();
	void Solve(int (&board)[12][12]);
	bool CheckUnity(int arr[], int size);
	bool CheckValid(int board[12][12], int x, int y);
	int Next(int board[12][12], int location);
	int BackTrack(int (&board)[12][12], int x, int y);
	int board[12][12];
};
