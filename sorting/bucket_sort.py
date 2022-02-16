"""
Bubble Sort is mainly useful when sorting a large set of floating point
numbers which are in range [0, 1). It works by distributing elements to
buckets, then sorts each bucket and finally concatenates all sorted buckets.

Examples:
- Giving an array [0.52, 0.12, 0.86, 0.29, 0.46, 0.4, 0.18, 0.6], 10 buckets
and assuming that we sort the array by ascending order.
- Distributing all the elements to corresponding buckets by multiplying the
element and buckets' slots. Each bucket is a linked list. [0.52, 0.12, 0.86,
0.29, 0.46, 0.4, 0.18, 0.6] -> array
   [[], [], [], [], [], [], [], [], [], []] -> buckets
   [0 []
    1 [] -> [0.12] -> [0.18]   0.12 * 10 = 1.2, 0.18 * 10 = 1.8
    2 [] -> [0.29]   0.29 * 10 = 2.9
    3 []
    4 [] -> [0.46] -> [0.4]   0.46 * 10 = 4.6, 0.4 * 10 = 4.0
    5 [] -> [0.52]   0.52 * 10 = 5.2
    6 [] -> [0.6]
    7 []
    8 [] -> [0.86]   0.86 * 10 = 8.6
    9 []
    ]
- We sort each bucket using insertion sort.
   [[], [0.12, 0.18], [0.29], [], [0.4, 0.46], [0.52], [0.6], [], [0.86], []]
- Concatenating all non-empty buckets, array is now sorted.
"""
import unittest
from typing import Final


def bucket_sort(array: list[float]):
    if not all(0 <= element < 1 for element in array):
        raise ValueError('Only accept non-negative floating point number array in range [0, 1)')

    slots: Final = 10
    buckets: list[list[float]] = [[] for _ in range(slots)]

    for i in range(len(array)):
        bucket_index = int(slots * array[i])
        buckets[bucket_index].append(array[i])

    index = 0
    for i in range(slots):
        buckets[i].sort()
        for j in range(len(buckets[i])):
            array[index] = buckets[i][j]
            index += 1


class TestBubbleSort(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestBubbleSort, self).__init__(*args, **kwargs)
        self.floats = [0.52, 0.44, 0.68, 0.95, 0.1, 0.12, 0.32, 0.59]

    def test_handles_valid_input(self):
        bucket_sort(self.floats)
        self.assertListEqual(self.floats, [0.1, 0.12, 0.32, 0.44, 0.52, 0.59, 0.68, 0.95])

    def test_invalid_input(self):
        with self.assertRaises(ValueError):
            bucket_sort([0.52, 0.44, 0.68, 0.95, 1.1, 0.12, 0.32, 0.59])


if __name__ == '__main__':
    unittest.main()
