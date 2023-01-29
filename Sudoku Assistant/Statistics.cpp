#include "statistics.h"


using namespace std;

void Digits(const vector<SudokuBoard>& sudokuBoard)
{
    map<int, int> countMap;
    map<int, int> rowCount;
    map<int, int> colCount;
    map<int, int> squareCount;
    SudokuBoard board;
    for (int i = 0; i < sudokuBoard.size(); i++)
    {
        board = sudokuBoard[i];
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                int number = board[j][k];
                //counting number of appearances in all boards
                if (countMap.count(number) == 0)
                {
                    countMap[number] = 1;
                }
                else
                {
                    countMap[number]++;
                }
                // counting number of appearances in the row
                if (rowCount.count(number + (j * 9)) == 0)
                {
                    rowCount[number + (j * 9)] = 1;
                }
                else
                {
                    rowCount[number + (j * 9)]++;
                }
                // counting number of appearances in the column
                if (colCount.count(number + (k * 9)) == 0)
                {
                    colCount[number + (k * 9)] = 1;
                }
                else
                {
                    colCount[number + (k * 9)]++;
                }
                // counting number of appearances in the square
                int sq = (j / 3) * 3 + (k / 3);
                if (squareCount.count(number + (sq * 9)) == 0)
                {
                    squareCount[number + (sq * 9)] = 1;
                }
                else
                {
                    squareCount[number + (sq * 9)]++;
                }
            }
        }
    }

    // sorting from the most frequent to the least frequent
    vector<pair<int, int> > v1(rowCount.begin(), rowCount.end());
    sort(v1.begin(), v1.end(), [](auto& left, auto& right)
        {
            return left.second > right.second;
        }
    );
    vector<pair<int, int> > v2(colCount.begin(), colCount.end());
    sort(v2.begin(), v2.end(), [](auto& left, auto& right)
        {
            return left.second > right.second;
        }
    );
    vector<pair<int, int> > v3(squareCount.begin(), squareCount.end());
    sort(v3.begin(), v3.end(), [](auto& left, auto& right)
        {
            return left.second > right.second;
        }
    );

    for (int i = 1; i <= 9; i++)
    {
        cout << "\t\t\t\tStatistics for number: " << i << endl;
        cout << "Number " << i << " appeared " << countMap[i] << " times in total." << endl;
        cout << "It appeared the most in row number: ";
        for (int j = 0; j < v1.size(); j++)
        {
            if (v1[j].first % 9 == i - 1)
            {
                cout << v1[j].first / 9 + 1 << " with " << v1[j].second << " appearances." << endl;
                break;
            }
        }
        cout << "It appeared the most in column number: ";
        for (int j = 0; j < v2.size(); j++)
        {
            if (v2[j].first % 9 == i - 1)
            {
                cout << v2[j].first / 9 + 1 << " with " << v2[j].second << " appearances." << endl;
                break;
            }
        }
        cout << "It appeared the most in square number: ";
        for (int j = 0; j < v3.size(); j++)
        {
            if (v3[j].first % 9 == i - 1)
            {
                cout << v3[j].first / 9 + 1 << " with " << v3[j].second << " appearances." << endl;
                break;
            }
        }
        cout << endl << endl;
    }
}

void solveTime(const vector<SudokuBoard>& sudokuBoard, long long solvingTimeBoard[])
{
    set<long long> uniqueSolvingTimes;
    for (int i = 0; i < BOARDS; i++) {
        uniqueSolvingTimes.insert(solvingTimeBoard[i]);
    }

    cout << endl << "Top 10 fastest sortings:" << endl;
    int count = 0;
    for (auto it = uniqueSolvingTimes.begin(); it != uniqueSolvingTimes.end() && count < 10; it++, count++) {
        cout << count + 1 << ": " << *it << " microseconds." << endl;
    }

    cout << endl << "Top 10 slowest sortings:" << endl;
    count = 0;
    for (auto it = uniqueSolvingTimes.rbegin(); it != uniqueSolvingTimes.rend() && count < 10; it++, count++) {
        cout << count + 1 << ": " << *it << " microseconds." << endl;
    }

    cout << endl << "Median value of solving times:" << solvingTimeBoard[int(BOARDS / 2)] << endl << endl;

    long double mean = 0;
    for (int i = 0; i < BOARDS; i++)
    {
        mean += solvingTimeBoard[i];
    }
    mean /= BOARDS;
    cout << "Mean value of solving times: " << mean << " microseconds." << endl << endl;

    long long std[BOARDS] = { 0 };
    long long std_value = 0;
    for (int i = 0; i < BOARDS; i++)
    {
       std[i] = (solvingTimeBoard[i]-mean)* (solvingTimeBoard[i] - mean);
       std_value += std[i];
    }
    std_value /= BOARDS;
    cout << "Standard deviation of solving times: " << std_value << " microseconds." << endl << endl;

    

    map<long long, int> uniqueValues;           //slownik, klucz-wartosc z tablicy, wartosc-licznik wystapien danej wartosci
    for (int i = 0; i < BOARDS; i++) {
        uniqueValues[solvingTimeBoard[i]]++;
    }
    int diversity = uniqueValues.size();
    cout << "Number of unique solving time values: " << diversity << endl << endl;

    long long most_common_value = solvingTimeBoard[0];
    int most_common_count = 0;

    // ZnajdŸ wartoœæ z najwiêkszym licznikiem
    for (auto x : uniqueValues) {
        if (x.second > most_common_count) {
            most_common_value = x.first;
            most_common_count = x.second;
        }
    }

    cout << "Value which occured the most frequently: " << most_common_value << " microseconds." << endl;
    cout << "Number of occurances: " << most_common_count << endl << endl;
}

void solveBoard(const vector<SudokuBoard>& sudokuBoard)
{
    while (true)
    {
        int board;
        cout << "Enter number of sudoku board you would like to see being solved from 1 to 28001: ", cin >> board, cout << endl;
        SudokuBoard nBoard = sudokuBoard[board-1];

        if (board > 0 && board <= 28001)
        {
            cout << "Sudoku board before solving: " << endl << endl;
            nBoard.print();
            long long solving;

            if (SudokuSolver::solve(nBoard, solving))
            {
                cout << endl << "Solved sudoku board: " << endl << endl;
                nBoard.print();
                cout << endl << "Solving sudoku took: " << solving << " microseconds." << endl << endl;
            }
        }
        else {
            cout << "Invalid value entered." << endl;
            continue;
        }
        cout << "Do you want to see another sudoku board being solved? (y/n) ";
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
