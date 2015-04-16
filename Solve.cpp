#include "Sudoku.h"
using namespace std;
int Next(int board[12][12], int x, int y);
bool CheckUnity(int arr[], int size);
bool CheckValid(int board[12][12], int x, int y);
int BackTrack(int (&board)[12][12], int x, int y);

int main()
{
	Sudoku s;
	s.ReadIn();
	int x = Next(s.board, 0, 0)%12;//find first x
	int y = Next(s.board, 0, 0)/12;//find first y
	BackTrack(s.board, x, y);
	s.Solve(s.board);
	return 0;
}

bool CheckUnity(int arr[], int size)
{
	int unity[size];
	for (int i = 0; i < size; ++i)
	{
		unity[i] = 0;
	}
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > 0)
			++unity[arr[i] - 1];
	}
	for (int i = 0; i < size; i++)
	{
		if (unity[i] > 1)
			return false;
	}
	return true;
}

int Next(int board[12][12], int x, int y)
{
	int target = -1;
	for (int i = y; i < 12; i++)
	{
		for (int j = x; j < 12; j++)
		{
			if (board[i][j] == 0)//meet empty cell
			{
				x = j;
				y = i;
				target = x + y*12;
				return target;
			}
		}
	}
	return target;
}

bool CheckValid(int board[12][12], int x, int y)
{
	int arr[12];
	int i, j, k = 0;
	for (i = 0; i < 12; i++)//check row
	{
		arr[i] = board[y][i];
	}
	if (CheckUnity(arr, 12) == false)
		return false;
	for (i = 0; i < 12; i++)//check column
	{
		arr[i] = board[i][x];
	}
	if (CheckUnity(arr, 12) == false)
		return false;
	switch (x%3)//locate block x
	{
		case 0:
			j = x;
			break;
		case 1:
			j = x - 1;
			break;
		case 2:
			j = x - 2;
			break;
	}
	switch (y%3)//locate block y
	{
		case 0:
			i = y;
			break;
		case 1:
			i = y - 1;
			break;
		case 2:
			i = y - 2;
			break;
	}
	for (int m = j; m < j + 3; m++)//check block
	{
		for (int n = i; n < i + 3; n++)
		{
			 arr[k++] = board[n][m];
		}
	}
	if (CheckUnity(arr, 9) == false)
		return false;
	return true;
}

int BackTrack(int (&board)[12][12], int x, int y)
{
	if (Next(board, x, y) == -1)//game finish
		return true;
	for (int i = 1; i < 10; i++)//guess from 1 to 9
	{
		board[x][y] = i;
		if (CheckValid(board, x, y) == true)
		{
			int nextx = Next(board, x, y)%12;
			int nexty = Next(board, x, y)/12;
			if (BackTrack(board, nextx, nexty) == true)//do next cell
			{
				return true;
			}
		}
	}
	board[x][y] = 0;//no forget delete before go back
	return false;
}
