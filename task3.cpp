#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 9

void print(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void generatePuzzle(int grid[N][N], int difficulty) {
    srand(static_cast<unsigned int>(time(0)));

    solveSudoku(grid);

    int numToRemove = 0;
    switch (difficulty) {
        case 1:
            numToRemove = 40;
            break;
        case 2:
            numToRemove = 50;
            break;
        case 3:
            numToRemove = 60;
            break;
    }

    while (numToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            numToRemove--;
        }
    }
}

int main() {
    int grid[N][N] = {0};
    int difficulty;

    cout << "Choose the difficulty level:" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> difficulty;

    generatePuzzle(grid, difficulty);

    cout << "Generated Sudoku puzzle:" << endl;
    print(grid);

    cout << endl << "Solving Sudoku puzzle..." << endl;
    if (solveSudoku(grid)) {
        cout << "Sudoku puzzle solved:" << endl;
        print(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}


/*Easy: 40 filled cells removed
Medium: 50 filled cells removed
Hard: 60 filled cells removed*/