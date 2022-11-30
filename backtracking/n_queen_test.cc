#include "n_queen.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(NQueenTest, HandlesVarietyAmountOfQueens) {
  const uint32_t kQueenQuantity = 4;
  int32_t answer[kQueenQuantity][kQueenQuantity] = {
      {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}};

  auto **board = backtracking::NQueen(kQueenQuantity);
  for (auto i = 0; i < kQueenQuantity; i++) {
    for (auto j = 0; j < kQueenQuantity; j++) {
      EXPECT_EQ(board[i][j], answer[i][j]);
    }
  }
}

} // namespace
} // namespace algorithm
