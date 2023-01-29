#include "SudokuBoard.h"



SudokuBoard::SudokuBoard(const BoardVector& board)
{
    this->board = board;
}

void SudokuBoard::print()
{
    // Print the top border
    cout << "-------------------------" << endl;

    // Iterate through the rows of the sudoku board
    for (int i = 0; i < 9; i++)
    {
        // Print the left border and the first element in the row
        cout << "| " << this->board[i][0];

        // Iterate through the remaining elements in the row
        for (int j = 1; j < 9; j++)
        {
            // Print a vertical bar after every third element
            if (j % 3 == 0)
            {
                cout << " | " << this->board[i][j];
            }
            else
            {
                cout << " " << this->board[i][j];
            }
        }

        // Print the right border
        cout << " |";
        cout << endl;

        // Print a horizontal border after every third row
        if (i % 3 == 2)
        {
            cout << "-------------------------" << endl;
        }
    }
}

size_t SudokuBoard::size() const
{
    return board.size();
}

vector<int>& SudokuBoard::operator[](int index)
{
    return this->board[index];
}
