#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;



class sudokuSolver              // CLASS HOLDING ALL FUNCTIONS TO SOLVE SUDOKU
{
public:

    vector<vector<int>> sudokuBoard
    {
        // initialize here 2d vector of sudoku board
    };

    bool isCol(vector<vector<int>> sudokuBoard, int Number, int noCol)			// checking whether the digit is in a certain column
    {
        for (int row = 0; row < sudokuBoard.size(); row++)
        {
            if (sudokuBoard[row][noCol] == Number)
            {
                //cout << "COL: Element " << Number << " found in row " << row+1 << endl;
                return 1;
            }
        }
        //cout << "COL: Element not found." << endl;
        return 0;
    }

    bool isRow(vector<vector<int>> sudokuBoard, int Number, int noRow)				// checking whether the digit is in a certain row
    {
        for (int col = 0; col < sudokuBoard.size(); col++)
        {
            if (sudokuBoard[noRow][col] == Number)
            {
                //cout << "ROW: Element " << Number << " found in column " << col+1 << endl;
                return 1;
            }
        }
        //cout << "ROW: Element not found." << endl;
        return 0;
    }

    bool isBox(vector<vector<int>> sudokuBoard, int Number, int noRow, int noCol)       // number of column and row will always be eqal to multiple 3n+1
    {                                                                                   // this way we can divide board into 9 eqaul squares
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (sudokuBoard[row + noRow][col + noCol] == Number)
                    return 1;
        return 0;
    }

    bool isEmpty(vector<vector<int>> sudokuBoard, int& noRow, int& noCol)
    {
        for (noRow = 0; noRow < sudokuBoard.size(); noRow++)
            for (noCol = 0; noCol < sudokuBoard.size(); noCol++)
                if (sudokuBoard[noRow][noCol] == 0)                                     // grid with 0 is considered as empy
                    return 1;
        return 0;
    }

    bool isValid(int noRow, int noCol, int Number)              // checking whether certain digit is in certain grid
    {
        int noBoxRow = noRow - noRow % 3;               // row number must be equal to multiplication of 3n+1
        int noBoxCol = noCol - noCol % 3;                // col number must be equal to multiplication of 3n+1

        return !(isRow(sudokuBoard, Number, noRow) && isCol(sudokuBoard, Number, noCol) && isBox(sudokuBoard, Number, noBoxRow, noBoxCol));
    }

    bool solveSudoku()
    {
        int Row;
        int Col;
        chrono::high_resolution_clock clock;        // initializing high resolution clock
        auto start = clock.now();          // start measuring time
        if (!isEmpty(sudokuBoard, Row, Col))
        {
            auto end = clock.now();                                                     // end measuring time
            auto time_span = static_cast<chrono::duration<double>>(end - start);        // measuring time difference between start and stop 
            cout << "Solving sudoku took: " << time_span.count() << " seconds." << endl;
            return 1;                                                           //when sudoku is fully filled
        }
        for (int Number = 1; Number <= 9; Number++)          // going through 1-9 numbers ( numbers to fill grids)
        {
            if (isValid(Row, Col, Number))             // checking whether we can put number in grid
            {
                sudokuBoard[Row][Col] = Number;
                if (solveSudoku())
                    return 1;
                sudokuBoard[Row][Col] = 0;          //if failure, assign 0 value (=blank grid)
            }
        }
        return 0;
    }

};


