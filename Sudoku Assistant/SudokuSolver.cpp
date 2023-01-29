#include "SudokuSolver.h"

using namespace std;

// Checking whether the digit is in a certain column
bool SudokuSolver::isCol(SudokuBoard& sudokuBoard, int number, int noCol)
{
    for (int row = 0; row < sudokuBoard.size(); row++)
    {
        if (sudokuBoard[row][noCol] == number)
        {
            //cout << "COL: Element " << Number << " found in row " << row+1 << endl;
            return true;
        }
    }
    //cout << "COL: Element not found." << endl;
    return false;
}

// Checking whether the digit is in a certain row
bool SudokuSolver::isRow(SudokuBoard& sudokuBoard, int number, int noRow)
{
    for (int col = 0; col < sudokuBoard.size(); col++)
    {
        if (sudokuBoard[noRow][col] == number)
        {
            //cout << "ROW: Element " << Number << " found in column " << col+1 << endl;
            return true;
        }
    }
    //cout << "ROW: Element not found." << endl;
    return false;
}

// number of column and row will always be eqal to multiple 3n+1
bool SudokuSolver::isBox(SudokuBoard& sudokuBoard, int number, int noRow, int noCol)
{
    // this way we can divide board into 9 eqaul squares
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (sudokuBoard[row + noRow][col + noCol] == number)
            {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::isEmpty(SudokuBoard& sudokuBoard, int& noRow, int& noCol)
{
    for (noRow = 0; noRow < sudokuBoard.size(); noRow++)
    {
        for (noCol = 0; noCol < sudokuBoard.size(); noCol++)
        {
            if (sudokuBoard[noRow][noCol] == 0)
            {
                // grid with 0 is considered as empy
                return true;
            }
        }
    }
    return false;
}

// Checking whether certain digit is in certain grid
bool SudokuSolver::isValid(SudokuBoard& sudokuBoard, int noRow, int noCol, int number)
{
    int noBoxRow = noRow - noRow % 3;    // row number must be equal to multiplication of 3n+1
    int noBoxCol = noCol - noCol % 3;    // col number must be equal to multiplication of 3n+1

    return !(isRow(sudokuBoard, number, noRow) || isCol(sudokuBoard, number, noCol) || isBox(sudokuBoard, number, noBoxRow, noBoxCol));
}

bool SudokuSolver::solve(SudokuBoard& sudokuBoard, long long& solvingTime)
{
    int row = 0, col = 0;
    high_resolution_clock clock;     // initializing high resolution clock
    auto start = clock.now();        // start measuring time

    SudokuBoard localBoardCopy = sudokuBoard;

    if (!isEmpty(localBoardCopy, row, col))
    {
        auto end = clock.now();                                       // end measuring time
        auto time_span = duration_cast<microseconds>(end - start);    // measuring time difference between start and stop 
        solvingTime = time_span.count();
        return true;                                                  //when sudoku is fully filled
    }

    for (int number = 1; number <= 9; number++)    // going through 1-9 numbers ( numbers to fill grids)
    {
        if (isValid(localBoardCopy, row, col, number))             // checking whether we can put number in grid
        {
            localBoardCopy[row][col] = number;

            if (solve(localBoardCopy, solvingTime))
            {
                sudokuBoard = localBoardCopy;
                return true;
            }

            localBoardCopy[row][col] = 0;             //if failure, assign 0 value (=blank grid)
        }
    }

    //sudokuBoard = localBoardCopy;
    return false;
}