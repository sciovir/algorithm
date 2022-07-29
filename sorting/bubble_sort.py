"""
Bubble Sort works by repeatedly swapping the elements if they are in wrong order.

Examples:
- Giving an array [5, 2, 3, 1, 4], assuming that we sort the array by
ascending order.
- Starting with the first index, we compare the element at current index
with the rest. At the end of first loop, we get the smallest element at
current index. 0  1  2  3  4 -> array's indexes [5, 2, 3, 1, 4] we compare
the first 2 elements then swap 5 and 2 cause 5 > 2 i  j [2, 5, 3, 1, 4] since
these elements are in order (2 < 3), we don't swap them i     j [2, 5, 3, 1, 4]
swap 2 and 1 i        j [1, 5, 3, 2, 4] don't swap i           j
- Keep looping i to pre-last index and j from i + 1 to the last index.
- After all the loops, array is now sorted.
"""
import unittest


def bubble_sort(array: list):
    for i in range(len(array)):
        for j in range(i + 1, len(array)):
            if array[i] > array[j]:
                array[i], array[j] = array[j], array[i]


class TestBubbleSort(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.integers = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3]
        self.strings = ["c", "assembly", "cpp", "python", "go", "swift", "sql"]
        self.floats = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9]

    def test_handles_multiple_array_type_input(self):
        bubble_sort(self.integers)
        self.assertListEqual(self.integers, [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40])
        bubble_sort(self.strings)
        self.assertListEqual(
            self.strings, ["assembly", "c", "cpp", "go", "python", "sql", "swift"]
        )
        bubble_sort(self.floats)
        self.assertListEqual(self.floats, [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5])


if __name__ == "__main__":
    unittest.main()
