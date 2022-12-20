// SudokuCSV.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;                    // FILE IN PROGRESS

class File {

public:
    int noBoards;
    fstream inputFile;

    void readFile()
    {
        inputFile.open("sudoku.txt", ios::in);              // opening file
        if (inputFile.fail())                               // checking if file opens
        {
            cout << "Error. The file does not open.";
            return;
        }

        string line;                            // going through lines to read file
        int lineNo = 0;                         // variable to hold number of line (=number of boards) in file
        char ch;                                // variable to hold each digit in row
        int Digit;
        while (getline(inputFile, line))
        {
            while (inputFile >> noskipws >> ch)
            {
                cout << ch;
                //int Digit = (int)ch;
                //cout << Digit;
            }
            cout << endl;
            lineNo++;
        }
    }

};


//int main()
//{
//    fstream inputFile;
//    vector<int> Digits;         // vector holding digits of a sudoku board
//
//    inputFile.open("sudoku.txt", ios::in);              // opening file
//    if (inputFile.fail())                               // checking if file opens
//    {
//        cout << "Error. The file does not open.";
//        return 1;
//    }
//
//    string line;                            // going through lines to read file
//    int lineNo = 0;                         // variable to hold number of line (=number of boards) in file
//    char ch;                                // variable to hold each digit in row
//    int Digit;
//    while (getline(inputFile, line))
//    {
//        while (inputFile >> noskipws >> ch)
//        {
//            cout << ch;
//            //int Digit = (int)ch;
//            //cout << Digit;
//        }
//        cout << endl;
//        lineNo++;
//    }
//    cout << lineNo << endl;             // number of sudoku boards
//    cout << line.length() << endl;      // number of digits in sudoku board
//
//    int Size = line.length();
//
//    int* SudokuBoard = new int[Size];
//
//    /*while (inputFile)
//    {
//        for (int i = 0; i < Size; i++)
//        {
//            inputFile >> SudokuBoard[i];
//            cout << SudokuBoard[i] << endl;
//        }
//    }*/
//    cout << "done";
//}
