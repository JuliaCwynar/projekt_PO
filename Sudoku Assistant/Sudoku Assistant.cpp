#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include "ReadFile.h"
#include "Statistics.h"
#include "Windows.h"

using namespace std;

int main()
{
    vector<SudokuBoard> boards1;
    txtRead("sudoku_txt.txt", boards1);
    vector<SudokuBoard> boards2;        //vector holding sudokuBoards from csv file
    csvRead("sudoku_csv.csv", boards2);
    vector<SudokuBoard> boards3;        //vector holding sudokuBoards from xlsx file
    xlsxRead("sudoku_xlsx.csv", boards3);

    vector<SudokuBoard> mergedBoards = joinVectors(boards1, boards2, boards3);      //vector holding all sudokuBoards

    long long solvingTimeBoard[BOARDS] = { 0 };
    for (int i = 0; i < BOARDS; i++)
    {
        long long solvingTime = 0;

        SudokuBoard board = mergedBoards[i];
        if (SudokuSolver::solve(board, solvingTime))
        {
            solvingTimeBoard[i] = solvingTime;
        }
        sort(solvingTimeBoard, solvingTimeBoard + BOARDS);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
    // Menu
    while (true) {
        cout << "----------------------------------------MENU----------------------------------------" << endl;
        cout << "\t\t\t\t1. Solving time statistics" << endl;
        cout << "\t\t\t\t2. Digit statistics" << endl;
        cout << "\t\t\t\t3. Solve sudoku board" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        int option;
        cout << "Enter number which indicates operation you would like Sudoku Assistant to perform: ", cin >> option;
        switch (option)
        {
        case 1:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << endl << "-------------------------------Solving time statistics------------------------------" << endl << endl;
            solveTime(mergedBoards, solvingTimeBoard);
            break;
        case 2:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << endl << "----------------------------------Digit statistics----------------------------------" << endl << endl;
            Digits(mergedBoards);
            break;
        case 3:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);

            cout << endl << "---------------------------------Solve sudoku board---------------------------------" << endl << endl;
            solveBoard(mergedBoards);
            break;
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "Invalid option selected. Please try again." << endl;
            continue;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        cout << "Do you want to continue using the program? (y/n) ";
        char n;
        cin >> n;
        if (n == 'y') {
            continue;
        }
        if (n == 'n') {
            break;
        }
    }
}