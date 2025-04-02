
// Anthony Schnuriger
// Eventually creating a sudoku solving game
using namespace std;
#include <iostream>
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

 vector<vector<int>> replaceNum(vector<vector<int>>& grid, vector<vector<int>>& sol, int row, int col, int num) {
    if (grid[row][col] == 0) {
        if (sol[row][col] == num) {
            grid[row][col] = num;
        } else {
            cout << "Invaild Number, Try again!" << endl;
        }
    } else {
        cout << "Invalid!" << endl;
    }
    return grid;
}

int main(){
  vector<vector<int>> matrix;
  // Example Matrix can and will be changed
  matrix = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}};
    vector<vector<int>> solvedMatrix = matrix;
    solve(solvedMatrix, 0, 0);

    bool game = true;
    int counter = 0;
    int row, col, n;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                cout << matrix[i][j] << " ";
                if (matrix[i][j] == 0) {counter++;}
            }
            cout << endl;
        }
        if (counter == 0){return 0;}
        counter = 0;
        cout << "Enter a row(1-9), column(1-9), and number(1-9)" << endl;
        cin >> row;
        cin >> col;
        cin >> n;
        matrix = replaceNum(matrix, solvedMatrix, row-1, col-1, n);

}
