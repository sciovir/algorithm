#include "n_queen.h"

#include <iostream>

namespace algorithm {
namespace backtracking {

bool PossiblePlace(int** board, unsigned int n, int x, int y) {
  int i, j;
  for (i = 0; i < n; i++) {
    if (board[x][i] || board[i][y]) {
      return false;
    }
  }
  for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  for (i = x + 1, j = y + 1; i < n && j < n; i++, j++) {
    if (board[i][j]) {
      return false;
    }
  }
  for (i = x + 1, j = y - 1; i < n && j >= 0; i++, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  for (i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
    if (board[i][j]) {
      return false;
    }
  }
  return true;
}

bool NQueenRecursive(int** board, unsigned int n, int y) {
  if (y >= n) {
    return true;
  }
  for (int i = 0; i < n; i++) {
    if (PossiblePlace(board, n, i, y)) {
      board[i][y] = 1;
      if (NQueenRecursive(board, n, y + 1)) {
        return true;
      }
      board[i][y] = 0;
    }
  }
  return false;
}

int** NQueen(unsigned int n) {
  int** board = new int*[n];
  for (unsigned int r = 0; r < n; r++) {
    board[r] = new int[n];
    for (unsigned int c = 0; c < n; c++) {
      board[r][c] = 0;
    }
  }

  if (NQueenRecursive(board, n, 0)) {
    return board;
  } else {
    return nullptr;
  }
}

}  // namespace backtracking
}  // namespace algorithm
