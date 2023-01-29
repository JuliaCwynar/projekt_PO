#pragma once
#include <vector>
#include <iostream>
#define BOARDS 28001

using namespace std;
using BoardVector = vector<vector<int>>;

class SudokuBoard
{
private:
	BoardVector board;

	// Variable holding solving time of certain sudoku board
	//Milliseconds solvingTime;

public:
	// Constructors
	SudokuBoard() = default;
	SudokuBoard(const SudokuBoard&) = default;
	SudokuBoard(const BoardVector& board);

	void print();

	// size() method overload
	size_t size() const;

	vector<int>& operator[](int index);

};

