#include <iostream>
#include "sudokuSolver.cpp"
#include "ReadFile.cpp"

using namespace std;

int main()
{
    File txtFile;                   // initializing object to process the file
    txtFile.readFile();

    sudokuSolver Sudoku;            // initializing sudokuSolver object
    Sudoku.solveSudoku();
}