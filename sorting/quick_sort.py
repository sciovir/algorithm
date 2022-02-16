"""
Quick Sort
"""
import unittest
from typing import TypeVar

T = TypeVar('T')


def quick_sort(array: list[T], lo: int, hi: int):
    if lo < hi:
        separator = partition(array, lo, hi)
        quick_sort(array, lo, separator - 1)
        quick_sort(array, separator + 1, hi)


def partition(array: list[T], lo: int, hi: int) -> int:
    pivot = array[hi]
    i = lo - 1

    for j in range(lo, hi):
        if array[j] < pivot:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i + 1], array[hi] = array[hi], array[i + 1]
    return i + 1


def hoare_partition(array: list[T], lo: int, hi: int) -> int:
    pivot = array[lo]
    i, j = lo, hi

    while True:
        while array[i] < pivot:
            i += 1
        while array[j] > pivot:
            j -= 1

        if i >= j:
            return j
        array[i], array[j] = array[j], array[i]


class TestQuickSort(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestQuickSort, self).__init__(*args, **kwargs)
        self.integers = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3]
        self.strings = ['c', 'java', 'cpp', 'python', 'go', 'swift', 'sql']
        self.floats = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9]

    def test_handles_multiple_array_type_input(self):
        quick_sort(self.integers, 0, len(self.integers) - 1)
        self.assertListEqual(self.integers, [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40])
        quick_sort(self.strings, 0, len(self.strings) - 1)
        self.assertListEqual(self.strings, ['c', 'cpp', 'go', 'java', 'python', 'sql', 'swift'])
        quick_sort(self.floats, 0, len(self.floats) - 1)
        self.assertListEqual(self.floats, [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5])


if __name__ == '__main__':
    unittest.main()
