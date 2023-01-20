#include "utils/test.h"

namespace algorithm {
namespace backtracking {

bool PossiblePlace(int32_t** board, uint32_t n, int32_t x, int32_t y) {
  int32_t i, j;

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

bool NQueenRecursive(int32_t** board, uint32_t n, int32_t y) {
  if (y >= n) {
    return true;
  }

  for (auto i = 0; i < n; i++) {
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

int32_t** NQueen(uint32_t n) {
  auto board = new int32_t*[n];
  for (auto r = 0; r < n; r++) {
    board[r] = new int32_t[n];
    for (auto c = 0; c < n; c++) {
      board[r][c] = 0;
    }
  }

  if (NQueenRecursive(board, n, 0)) {
    return board;
  } else {
    return nullptr;
  }
}

namespace test {

void NQueen_HandlesVarietyAmountOfQueens() {
  const uint32_t kQueenQuantity = 4;
  int32_t answer[kQueenQuantity][kQueenQuantity] = {
      {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}};

  auto board = NQueen(kQueenQuantity);
  for (auto i = 0; i < kQueenQuantity; i++) {
    for (auto j = 0; j < kQueenQuantity; j++) {
      EXPECT_EQ(board[i][j], answer[i][j]);
    }
  }
}

void RunTests() { TEST(NQueen_HandlesVarietyAmountOfQueens); }

}  // namespace test

}  // namespace backtracking
}  // namespace algorithm

int main() {
  std::cout << "-----Running n queen tests-----" << std::endl;
  algorithm::backtracking::test::RunTests();
  return 0;
}