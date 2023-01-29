#pragma once
#include "SudokuBoard.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;

// Class holding all methods to solve sudoku 
class SudokuSolver
{
private:
    // Checking whether the digit is in a certain column
    static bool isCol(SudokuBoard& sudokuBoard, int number, int noCol);

    // Checking whether the digit is in a certain row
    static bool isRow(SudokuBoard& sudokuBoard, int number, int noRow);

    // Number of column and row will always be eqal to multiple 3n+1
    static bool isBox(SudokuBoard& sudokuBoard, int number, int noRow, int noCol);

    static bool isEmpty(SudokuBoard& sudokuBoard, int& noRow, int& noCol);

    static bool isValid(SudokuBoard& sudokuBoard, int noRow, int noCol, int number);

public:
    static bool solve(SudokuBoard& sudokuBoard, long long& solvingTime);
};


