#pragma once
#include "SudokuBoard.h"
#include "SudokuSolver.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>


using namespace std;

void Digits(const vector<SudokuBoard>& sudokuBoard);

void solveTime(const vector<SudokuBoard>& sudokuBoard, long long solvingTimeBoard[]);

void solveBoard(const vector<SudokuBoard>& sudokuBoard);
