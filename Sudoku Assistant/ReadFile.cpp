#include "ReadFile.h"


using namespace std;

void countBoards(string fileName)
{
    fstream inputFile;
    string line;                            // going through lines to read file
    int lineNo = 0;                         // variable to hold number of line (=number of boards) in file
    inputFile.open(fileName, ios::in);
    while (getline(inputFile, line))
    {
        int n = 0;
        regex number_regex("^[0-9]+");
        if (regex_match(line, number_regex))
        {
            lineNo++;
        }
    }
    cout << "Number of sudoku Boards: " << lineNo << endl;
}

void txtRead(string fileName, vector<SudokuBoard>& vec)
{
    fstream inputFile;
    string line;

    inputFile.open(fileName, ios::in);              // opening file
    if (inputFile.fail())                               // checking if file opens
    {
        cout << "Error. The file does not open.";
        return;
    }
    int n = 0;
    while (getline(inputFile, line))
    {
        int k = 0;
        regex number_regex("^[0-9]+");
        BoardVector sudokuBoard;
        if (regex_match(line, number_regex))
        {
            for (int i = 0; i < 9; ++i)
            {
                vector<int> row;
                for (int j = 0; j < 9; ++j)
                {
                    row.push_back(line[k++] - '0');
                }
                sudokuBoard.push_back(row);
            }
            vec.push_back(SudokuBoard(sudokuBoard));
            n++;
        }
    }
    inputFile.close();
}

void csvRead(string fileName, vector<SudokuBoard>& vec)
{
    fstream inputFile;
    string line;
    int k = 0;
    inputFile.open(fileName, ios::in);              // opening file
    if (inputFile.fail())                               // checking if file opens
    {
        cout << "Error. The file does not open.";
        return;
    }

    int n = 0;
    while (getline(inputFile, line))
    {
        int k = 0;  // Declare and initialize k outside of the inner loop
        BoardVector sudokuBoard;
        for (int i = 0; i < 9; ++i)
        {
            vector<int> row;
            for (int j = 0; j < 9; ++j)
            {
                // Read the next digit from the string, ignoring hyphen characters
                while (k < line.length() && line[k] == '-')
                {
                    k++;
                }
                if (k >= line.length() || j > 8)  // Check if k is within the valid range of indices for the line string
                {
                    break;  // Exit the loop if k is out of range
                }
                row.push_back(line[k] - '0');
                k++;
            }
            sudokuBoard.push_back(row);
        }
        vec.push_back(SudokuBoard(sudokuBoard));
        n++; // Increment n to store digits in the next index of vec
    }
    inputFile.close();
}

// Print the contents of vec
/*for (int n = 0; n < vec.size(); n++)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << vec[n][i][j];
        }
        cout << endl;
    }
    cout << endl;
}*/


void xlsxRead(string fileName, vector<SudokuBoard>& vec)
{
    ifstream inputFile;
    string line;
    int k = 0;

    inputFile.open(fileName, ios::in);              // opening file
    if (inputFile.fail())                               // checking if file opens
    {
        cout << "Error. The file does not open.";
        return;
    }
    bool firstLine = true;  // Flag to track if the current line is the first line of the file
    int n = 0;
    while (getline(inputFile, line))
    {
        int k = 0;  // Declare and initialize k outside of the inner loop
        BoardVector sudokuBoard;
        if (firstLine)  // Check if the current line is the first line of the file
        {
            k = 3;  // Start reading from the fourth character of the first line
            firstLine = false;  // Set the flag to false so that this is not done on subsequent lines
        }

        for (int i = 0; i < 9; ++i)
        {
            vector<int> row;
            for (int j = 0; j < 9; ++j)
            {
                // Read the next digit from the string, ignoring semicolon characters
                while (line[k] == ';')
                {
                    k++;
                }
                row.push_back(line[k] - '0');
                k++;
            }
            sudokuBoard.push_back(row);
        }
        vec.push_back(SudokuBoard(sudokuBoard));

        n++;  // Increment n to store digits in the next index of vec
    }
    inputFile.close();
}


vector<SudokuBoard> joinVectors(const vector<SudokuBoard>& vec1, const vector<SudokuBoard>& vec2, const vector<SudokuBoard>& vec3)
{
    vector<SudokuBoard> mergedVec;
    mergedVec.reserve(vec1.size() + vec2.size() + vec3.size());  // Reserve space for the merged vector
    mergedVec.insert(mergedVec.end(), vec1.begin(), vec1.end());  // Insert the elements of vec1 into mergedVec
    mergedVec.insert(mergedVec.end(), vec2.begin(), vec2.end());  // Insert the elements of vec2 into mergedVec
    mergedVec.insert(mergedVec.end(), vec3.begin(), vec3.end());  // Insert the elements of vec3 into mergedVec
    return mergedVec;
}

vector<vector<int>> passVector(vector<vector<vector<int>>> vecToPass, int n)
{
    vector<vector<int>> resultVector = vecToPass[n];
    return resultVector;
}