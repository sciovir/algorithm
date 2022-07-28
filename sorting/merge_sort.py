"""
Merge Sort
"""
import unittest
from typing import TypeVar

T = TypeVar("T")


def merge_sort(array: list[T], lo: int, hi: int):
    if lo < hi:
        mi: int = (lo + hi) // 2
        merge_sort(array, lo, mi)
        merge_sort(array, mi + 1, hi)
        merge(array, lo, mi, hi)


def merge(array: list[T], lo: int, mi: int, hi: int):
    l_len, r_len = mi - lo + 1, hi - mi
    l_arr, r_arr = [None] * l_len, [None] * r_len

    for i in range(l_len):
        l_arr[i] = array[lo + i]
    for i in range(r_len):
        r_arr[i] = array[mi + 1 + i]

    i, j, k = 0, 0, lo
    while i < l_len and j < r_len:
        if l_arr[i] > r_arr[j]:
            array[k] = r_arr[j]
            j += 1
        else:
            array[k] = l_arr[i]
            i += 1
        k += 1

    while i < l_len:
        array[k] = l_arr[i]
        k += 1
        i += 1

    while j < r_len:
        array[k] = r_arr[j]
        k += 1
        j += 1


class TestMergeSort(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.integers = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3]
        self.strings = ["c", "assembly", "cpp", "python", "go", "swift", "sql"]
        self.floats = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9]

    def test_handles_multiple_array_type_input(self):
        merge_sort(self.integers, 0, len(self.integers) - 1)
        self.assertListEqual(self.integers, [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40])
        merge_sort(self.strings, 0, len(self.strings) - 1)
        self.assertListEqual(
            self.strings, ["assembly", "c", "cpp", "go", "python", "sql", "swift"]
        )
        merge_sort(self.floats, 0, len(self.floats) - 1)
        self.assertListEqual(self.floats, [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5])


if __name__ == "__main__":
    unittest.main()
