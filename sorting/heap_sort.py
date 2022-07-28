"""
Heap Sort
"""
import unittest
from typing import TypeVar

from data_structure.heap.max_heap import MaxHeap

T = TypeVar("T")


def heap_sort(array: list[T]):
    max_heap: MaxHeap[T] = MaxHeap(array, len(array))
    for i in range(len(array) - 1, 0, -1):
        max_heap.swap(0, i)
        max_heap.size = max_heap.size - 1
        max_heap.heapify(0)

    max_heap.size = len(array)
    out: list[T] = [element for element in max_heap]
    for i in range(len(array)):
        array[i] = out[i]


class TestHeapSort(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.integers = [6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3]
        self.strings = ["c", "assembly", "cpp", "python", "go", "swift", "sql"]
        self.floats = [5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9]

    def test_handles_multiple_array_type_input(self):
        heap_sort(self.integers)
        self.assertListEqual(self.integers, [2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40])
        heap_sort(self.strings)
        self.assertListEqual(
            self.strings, ["assembly", "c", "cpp", "go", "python", "sql", "swift"]
        )
        heap_sort(self.floats)
        self.assertListEqual(self.floats, [0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5])


if __name__ == "__main__":
    unittest.main()
