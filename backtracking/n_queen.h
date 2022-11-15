#ifndef ALGORITHM_BACKTRACKING_N_QUEEN_H_
#define ALGORITHM_BACKTRACKING_N_QUEEN_H_

namespace algorithm {
namespace backtracking {

bool PossiblePlace(const int** board, unsigned int n, int x, int y);

bool NQueenRecursive(int** board, unsigned int n, int y);

int** NQueen(unsigned int n);

}  // namespace backtracking
}  // namespace algorithm

#endif  // ALGORITHM_BACKTRACKING_N_QUEEN_H_
