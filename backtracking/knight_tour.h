#pragma once

namespace algorithm {
namespace backtracking {

#define CHESS_BOARD_SIZE 8

bool PossibleMove(int** board, int x, int y);

bool KnightTourRecursive(int** board, const int (&x_mv)[8],
                         const int (&y_mv)[8], int mv, int x, int y);

int** KnightTour(unsigned int x, unsigned int y);

}  // namespace backtracking
}  // namespace algorithm
