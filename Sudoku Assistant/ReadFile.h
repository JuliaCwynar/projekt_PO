#pragma once
#include "SudokuBoard.h"
#include "sudokuSolver.h"
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <string>


using namespace std;

void countBoards(string fileName);

void txtRead(string fileName, vector<SudokuBoard>& vec);

void csvRead(string fileName, vector<SudokuBoard>& vec);

void xlsxRead(string fileName, vector<SudokuBoard>& vec);

// Function to compile all sudoku boards vectors into one array of 2d vectors
vector<SudokuBoard> joinVectors(const vector<SudokuBoard>& vec1, const vector<SudokuBoard>& vec2, const vector<SudokuBoard>& vec3);