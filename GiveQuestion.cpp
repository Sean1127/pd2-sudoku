#include "Sudoku.h"

main()
{
	int board(144) = 0;
	int temp();
	int A(9), B(9), C(9), D(9), E(9), F(9), G(9), H(9), I(9);
	int i, j, k;
	for (i = 0, i < 9, i++)//central cell
	{
		E(i) = i + 1;
		cout << E(i) << endl;
	}
	for (i = 0, i < 3, i++)//left right cell
	{
		D(i) = E(i + 3);
		D(i + 3) = E(i + 6);
		D(i + 6) = E(i);
		F(i) = E(i + 6);
		F(i + 3) = E(i);
		F(i + 6) = E(i + 3);
	}
	for (i = 0, i < 9, i += 3)//up down cell
	{
		B(i) = E(i + 1);
		B(i + 1) = E(i + 2);
		B(i + 2) = E(i);
		H(i) = E(i + 2);
		H(i + 1) = E(i);
		H(i + 2) = E(i + 1);
	}
	for (i = 0, i < 9, i += 3)//left up down cell
	{
		A(i) = D(i + 2);
		A(i + 1) = D(i);
		A(i + 2) = D(i + 1);
		G(i) = D(i + 1);
		G(i + 1) = D(i + 2);
		G(i + 2) = D(i);
	}
	for (i = 0, i < 9, i += 3)//right up down cell
	{
		C(i) = F(i + 2);
		C(i + 1) = F(i);
		C(i + 2) = F(i + 1);
		I(i) = F(i + 1);
		I(i + 1) = F(i + 2);
		I(i + 2) = F(i);
	}
	
	return 0;
}
