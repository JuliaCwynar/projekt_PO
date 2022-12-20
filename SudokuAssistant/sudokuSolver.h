#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

class sudokuSolver
{
public:

    sudokuSolver();             // constructor

    int solvingTime;            // variable holding solving time of certain sudoku board

    vector<vector<int>> sudokuBoard;

    bool isCol(vector<vector<int>> sudokuBoard, int Number, int noCol);			// checking whether the digit is in a certain column

    bool isRow(vector<vector<int>> sudokuBoard, int Number, int noRow);				// checking whether the digit is in a certain row

    bool isBox(vector<vector<int>> sudokuBoard, int Number, int noRow, int noCol);      // number of column and row will always be eqal to multiple 3n+1

    bool isEmpty(vector<vector<int>> sudokuBoard, int& row, int& col);

    bool isValid(int row, int col, int Number);

    bool solveSudoku();

    ~sudokuSolver();                // destructor
};

