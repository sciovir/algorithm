#pragma once

namespace algorithm {
namespace backtracking {

#define MAZE_SIZE 4

bool PossibleMove(int** board, int x, int y);

bool RatInMazeRecursive(int** board, int** out, int x, int y, int dx, int dy);

int** RatInMaze(int** board, unsigned int x, unsigned int y, unsigned int dx,
                unsigned int dy);

}  // namespace backtracking
}  // namespace algorithm
