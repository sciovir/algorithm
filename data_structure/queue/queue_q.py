"""
Queue
"""
import unittest
from typing import TypeVar, Generic, Generator, Any

T = TypeVar("T")


class Queue(Generic[T]):
    def __init__(self, cap: int = 100):
        self._data: list[T] = [None] * cap
        self._cap = cap
        self._size = 0
        self._front = 0
        self._rear = cap - 1

    def __iter__(self) -> Generator[T, Any, None]:
        if not self.is_empty():
            index = self._front
            while True:
                yield self._data[index]

                if index == self._rear:
                    break

                index = (index + 1) % self._cap

    def __repr__(self) -> str:
        return ",".join([str(e) for e in self])

    @property
    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._size == 0

    def is_full(self) -> bool:
        return self._size == self._cap

    def front_value(self) -> T:
        if self.is_empty():
            raise RuntimeError("Queue underflow, can not get front")
        return self._data[self._front]

    def enqueue(self, value: T):
        if self.is_full():
            raise RuntimeError("Queue overflow, can not enqueue")
        self._rear = (self._rear + 1) % self._cap
        self._data[self._rear] = value
        self._size += 1

    def dequeue(self) -> T:
        if self.is_empty():
            raise RuntimeError("Queue underflow, can not dequeue")
        removed = self._data[self._front]
        self._front = (self._front + 1) % self._cap
        self._size -= 1
        return removed


class TestQueue(unittest.TestCase):
    def test_integer_queue(self):
        queue: Queue[int] = Queue(8)

        self.assertTrue(queue.is_empty())
        self.assertEqual(queue.size, 0)

        queue.enqueue(8)
        queue.enqueue(6)
        queue.enqueue(26)
        queue.enqueue(29)
        queue.enqueue(2)
        queue.enqueue(9)
        queue.enqueue(7)
        queue.enqueue(22)

        self.assertFalse(queue.is_empty())
        self.assertListEqual([e for e in queue], [8, 6, 26, 29, 2, 9, 7, 22])

        with self.assertRaises(RuntimeError):
            queue.enqueue(19)

        self.assertEqual(queue.front_value(), 8)
        self.assertEqual(queue.dequeue(), 8)
        self.assertEqual(queue.front_value(), 6)
        self.assertEqual(queue.dequeue(), 6)

        self.assertEqual(queue.size, 6)

        self.assertEqual(queue.dequeue(), 26)
        self.assertEqual(queue.dequeue(), 29)
        self.assertEqual(queue.dequeue(), 2)
        self.assertEqual(queue.dequeue(), 9)

        self.assertListEqual([e for e in queue], [7, 22])

        self.assertEqual(queue.dequeue(), 7)
        self.assertEqual(queue.dequeue(), 22)

        with self.assertRaises(RuntimeError):
            queue.dequeue()


if __name__ == "__main__":
    unittest.main()
