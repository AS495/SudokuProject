#include <iostream>
// Anthony Schnuriger
// Eventually creating a sudoku solving game
using namespace std;
#include <vector>

bool numSafe(vector<vector<int>>& grid, int row, int col, int num) {
    for (int i = 0; i <= 8; i++) {
        if (grid[row][i] == num) {
            return false;
        }
        if (grid[i][col] == num) {
            return false;
        }
    }
    int threeMatRow = row - (row % 3);
    int threeMatCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i+threeMatRow][j+threeMatCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& grid, int row, int col) {
    int size = grid.size();
    if (row == size - 1 && col == size) {
        return true;
    }

    if (col == size) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0) {
        return solve(grid, row, col + 1);
    }

    for (int i = 1; i <= size; i++) {
        if (numSafe(grid, row, col, i)) {
            grid[row][col] = i;
            if (solve(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
  vector<vector<int>> matrix;
  // Example Matrix can and will be changed
  matrix = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solve(matrix, 0, 0);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
