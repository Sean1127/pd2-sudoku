all: Sudoku.o GiveQuestion.cpp Solve.cpp
		g++ -o GiveQuestion GiveQuestion.cpp Sudoku.o
		g++ -o Solve Solve.cpp Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
		g++ -c Sudoku.cpp -o Sudoku.o

clean:
		\rm *.o GiveQuestion Solve
