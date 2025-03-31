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

}
