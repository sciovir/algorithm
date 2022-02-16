"""
Insertion Sort
"""
import unittest
from typing import TypeVar

T = TypeVar('T')


def insertion_sort(array: list[T]):
    for j in range(1, len(array)):
        key = array[j]
        i = j - 1
        while i >= 0 and array[i] > key:
            array[i + 1] = array[i]
            i -= 1
        array[i + 1] = key


class TestInsertionSort(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestInsertionSort, self).__init__(*args, **kwargs)
        self.integers = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3]
        self.strings = ['c', 'java', 'cpp', 'python', 'go', 'swift', 'sql']
        self.floats = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9]

    def test_handles_multiple_array_type_input(self):
        insertion_sort(self.integers)
        self.assertListEqual(self.integers, [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40])
        insertion_sort(self.strings)
        self.assertListEqual(self.strings, ['c', 'cpp', 'go', 'java', 'python', 'sql', 'swift'])
        insertion_sort(self.floats)
        self.assertListEqual(self.floats, [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5])


if __name__ == '__main__':
    unittest.main()
