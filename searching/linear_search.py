"""
Linear search
"""
from typing import Any
import unittest


def linear_search(sorted_array: list, key: Any) -> int:
    for i in range(len(sorted_array)):
        if sorted_array[i] == key:
            return i
    return -1


class TestLinearSearch(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.integers = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40]
        self.strings = ["assembly", "c", "cpp", "go", "python", "sql", "swift"]
        self.floats = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5]

    def test_handles_multiple_array_type_input(self):
        self.assertEqual(linear_search(self.integers, 8), 4)
        self.assertEqual(linear_search(self.strings, "c"), 1)
        self.assertEqual(linear_search(self.floats, 9.5), 7)

    def test_handles_non_exist_element_input(self):
        self.assertEqual(linear_search(self.integers, 1), -1)
        self.assertEqual(linear_search(self.strings, "rust"), -1)
        self.assertEqual(linear_search(self.floats, 4.5), -1)


if __name__ == "__main__":
    unittest.main()
