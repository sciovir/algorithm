"""
Binary search
"""
from typing import Any
import unittest


def binary_search(sorted_array: list, key: Any, lo: int, hi: int) -> int:
    if lo > hi:
        return -1
    mi = (lo + hi) // 2

    if sorted_array[mi] == key:
        return mi
    elif key < sorted_array[mi]:
        return binary_search(sorted_array, key, lo, mi - 1)
    return binary_search(sorted_array, key, mi + 1, hi)


class TestBinarySearch(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.integers = [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40]
        self.strings = ["assembly", "c", "cpp", "go", "python", "sql", "swift"]
        self.floats = [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5]

    def test_handles_multiple_array_type_input(self):
        self.assertEqual(binary_search(self.integers, 8, 0, len(self.integers) - 1), 4)
        self.assertEqual(binary_search(self.strings, "c", 0, len(self.strings) - 1), 1)
        self.assertEqual(binary_search(self.floats, 9.5, 0, len(self.floats) - 1), 7)

    def test_handles_non_exist_element_input(self):
        self.assertEqual(binary_search(self.integers, 1, 0, len(self.integers) - 1), -1)
        self.assertEqual(
            binary_search(self.strings, "rust", 0, len(self.strings) - 1), -1
        )
        self.assertEqual(binary_search(self.floats, 4.5, 0, len(self.floats) - 1), -1)


if __name__ == "__main__":
    unittest.main()
