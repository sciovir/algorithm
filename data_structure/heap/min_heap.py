"""
Min Heap
"""
import unittest
from typing import TypeVar, Generic

from data_structure.heap.abstract_heap import AbstractHeap

T = TypeVar('T')


class MinHeap(AbstractHeap, Generic[T]):

    def __init__(self, array: list[T], cap: int = 10):
        if array:
            super().__init__(max(len(array), cap))
            for i in range(len(array)):
                self._data[i] = array[i]
            self._size = len(array)
            self.build_heap()
        else:
            super().__init__(cap)

    def heapify(self, index: int):
        left, right = self._left(index), self._right(index)
        smallest = left if left < self._size and self._data[left] < self._data[index] else index

        if right < self._size and self._data[right] < self._data[smallest]:
            smallest = right

        if smallest != index:
            self.swap(index, smallest)
            self.heapify(smallest)

    def insert(self, value: T):
        if self.is_full():
            raise RuntimeError('Heap overflow')

        self._data[self._size] = value
        cur = self._size
        while cur > 0 and self._data[cur] < self._data[self._parent(cur)]:
            self.swap(cur, self._parent(cur))
            cur = self._parent(cur)

        self._size += 1


class TestMinHeap(unittest.TestCase):

    def test_integer_heap(self):
        heap: MinHeap[int] = MinHeap([6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3], 13)

        self.assertFalse(heap.is_empty())
        self.assertEqual(heap.size, 11)

        heap.insert(18)
        heap.insert(6)

        self.assertEqual(heap.size, 13)
        self.assertListEqual([element for element in heap],
                             [2, 3, 6, 5, 8, 6, 40, 22, 26, 32, 9, 18, 10])

        with self.assertRaises(RuntimeError):
            heap.insert(19)

        self.assertEqual(heap.remove(5), 6)
        self.assertEqual(heap.remove(8), 26)
        self.assertEqual(heap.remove(0), 2)
        self.assertEqual(heap.remove(2), 6)
        self.assertEqual(heap.remove(5), 32)
        self.assertEqual(heap.remove(6), 40)
        self.assertEqual(heap.remove(1), 5)
        self.assertEqual(heap.remove(2), 10)
        self.assertEqual(heap.remove(3), 9)
        self.assertEqual(heap.remove(3), 22)
        self.assertEqual(heap.remove(1), 8)
        self.assertEqual(heap.remove(0), 3)
        self.assertEqual(heap.remove(0), 18)

        with self.assertRaises(RuntimeError):
            heap.remove(0)


if __name__ == '__main__':
    unittest.main()
