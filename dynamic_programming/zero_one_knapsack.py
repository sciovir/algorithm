"""
0-1 Knapsack problem
"""
import unittest


def zero_one_knapsack(items: list[tuple[int, int]], target_weight: int) -> int:
    items.sort(key=lambda tup: tup[0])
    matrix: list[list[int]] = [
        [0 for _ in range(target_weight + 1)] for _ in range(len(items))
    ]

    for r in range(len(items)):
        for c in range(1, target_weight + 1):
            if r == 0:
                matrix[r][c] = items[r][1]
                continue
            if c < items[r][0]:
                matrix[r][c] = matrix[r - 1][c]
            else:
                matrix[r][c] = max(
                    items[r][1] + matrix[r - 1][c - items[r][0]], matrix[r - 1][c]
                )

    return matrix[len(items) - 1][target_weight]


class TestZeroOneKnapsack(unittest.TestCase):
    def test_multiple_valid_input(self):
        self.assertEqual(zero_one_knapsack([(1, 1), (4, 5), (3, 4), (5, 7)], 7), 9)
        self.assertEqual(zero_one_knapsack([(10, 60), (20, 100), (30, 120)], 50), 220)


if __name__ == "__main__":
    unittest.main()
