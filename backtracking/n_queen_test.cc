#include "n_queen.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(NQueenTest, HandlesVarietyAmountOfQueens) {
  const unsigned int kQueenQuantity = 4;
  int answer[kQueenQuantity][kQueenQuantity] = {
      {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}};

  int** board = backtracking::NQueen(kQueenQuantity);
  for (unsigned int i = 0; i < kQueenQuantity; i++) {
    for (unsigned int j = 0; j < kQueenQuantity; j++) {
      EXPECT_EQ(board[i][j], answer[i][j]);
    }
  }
}

}  // namespace
}  // namespace algorithm
