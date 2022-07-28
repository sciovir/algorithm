"""
Fractional Knapsack problem
"""
import unittest


def fractional_knapsack(items: list[tuple[int, int]], target_weight: int) -> int:
    items.sort(key=lambda tup: tup[1] / tup[0], reverse=True)
    max_value: int = 0

    for item in items:
        if target_weight <= 0:
            break

        if target_weight < item[0]:
            max_value += target_weight * item[1] // item[0]
            target_weight = 0
        else:
            max_value += item[1]
            target_weight -= item[0]

    return max_value


class TestFractionalKnapsack(unittest.TestCase):
    def test_multiple_valid_input(self):
        items: list[tuple[int, int]] = [(10, 60), (30, 120), (20, 100)]

        self.assertEqual(fractional_knapsack(items, 50), 240)
        self.assertEqual(fractional_knapsack(items, 60), 280)
        self.assertEqual(fractional_knapsack(items, 30), 160)
        self.assertEqual(fractional_knapsack(items, 5), 30)


if __name__ == "__main__":
    unittest.main()
