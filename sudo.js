// Anthony Schnuriger

let board = [
  [0, 0, 0, 2, 6, 0, 7, 0, 1],
  [6, 8, 0, 0, 7, 0, 0, 9, 0],
  [1, 9, 0, 0, 0, 4, 5, 0, 0],
  [8, 2, 0, 1, 0, 0, 0, 4, 0],
  [0, 0, 4, 6, 0, 2, 9, 0, 0],
  [0, 5, 0, 0, 0, 3, 0, 2, 8],
  [0, 0, 9, 3, 0, 0, 0, 7, 4],
  [0, 4, 0, 0, 5, 0, 0, 3, 6],
  [7, 0, 3, 0, 1, 8, 0, 0, 0]
];

let solvedBoard = JSON.parse(JSON.stringify(board));

function numSafe(grid, row, col, num) {
  for (let i = 0; i < 9; i++) {
    if (grid[row][i] === num || grid[i][col] === num) {
      return false;
    }
  }

  let boxRow = row - (row % 3);
  let boxCol = col - (col % 3);

  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (grid[boxRow + i][boxCol + j] === num) {
        return false;
      }
    }
  }

  return true;
}

function solve(grid, row = 0, col = 0) {
  if (row === 8 && col === 9) 
    return true;
  if (col === 9) {
    row++;
    col = 0;
  }

  if (grid[row][col] !== 0) return solve(grid, row, col + 1);

  for (let num = 1; num <= 9; num++) {
    if (numSafe(grid, row, col, num)) {
      grid[row][col] = num;
      if (solve(grid, row, col + 1)) return true;
      grid[row][col] = 0;
    }
  }

  return false;
}

function replaceNum(userGrid, solutionGrid, row, col, num) {
  if (userGrid[row][col] === 0) {
    if (solutionGrid[row][col] === num) {
      userGrid[row][col] = num;
      console.log("Correct!");
    } else {
      console.log("Invalid number, try again!");
    }
  } else {
    console.log("Already filled!");
  }
  return userGrid;
}
