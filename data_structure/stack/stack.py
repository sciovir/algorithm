"""
Stack
"""
import unittest
from typing import TypeVar, Generic, Generator, Any

T = TypeVar('T')


class Stack(Generic[T]):

    def __init__(self, cap: int = 100):
        self._data: list[T] = [None] * cap
        self._cap = cap
        self._top = -1

    def __iter__(self) -> Generator[T, Any, None]:
        if not self.is_empty():
            for i in range(self._top + 1):
                yield self._data[i]

    def __repr__(self) -> str:
        return ','.join([e for e in self])

    @property
    def size(self) -> int:
        return self._top + 1

    def is_empty(self) -> bool:
        return self._top < 0

    def is_full(self) -> bool:
        return self.size == self._cap

    def top_value(self) -> T:
        if self.is_empty():
            raise RuntimeError('Stack underflow, can not get top')
        return self._data[self._top]

    def push(self, value: T):
        if self.is_full():
            raise RuntimeError('Stack overflow, can not push')
        self._top += 1
        self._data[self._top] = value

    def pop(self) -> T:
        if self.is_empty():
            raise RuntimeError('Stack underflow, can not pop')
        removed = self._data[self._top]
        self._top -= 1
        return removed


class TestStack(unittest.TestCase):

    def test_integer_stack(self):
        stack: Stack[int] = Stack(8)

        self.assertTrue(stack.is_empty())
        self.assertEqual(stack.size, 0)

        stack.push(8)
        stack.push(6)
        stack.push(26)
        stack.push(29)
        stack.push(2)
        stack.push(9)
        stack.push(7)
        stack.push(22)

        self.assertFalse(stack.is_empty())
        self.assertListEqual([e for e in stack],
                             [8, 6, 26, 29, 2, 9, 7, 22])

        with self.assertRaises(RuntimeError):
            stack.push(19)

        self.assertEqual(stack.top_value(), 22)
        self.assertEqual(stack.pop(), 22)
        self.assertEqual(stack.top_value(), 7)
        self.assertEqual(stack.pop(), 7)

        self.assertEqual(stack.size, 6)

        self.assertEqual(stack.pop(), 9)
        self.assertEqual(stack.pop(), 2)
        self.assertEqual(stack.pop(), 29)
        self.assertEqual(stack.pop(), 26)

        self.assertListEqual([e for e in stack], [8, 6])

        self.assertEqual(stack.pop(), 6)
        self.assertEqual(stack.pop(), 8)

        with self.assertRaises(RuntimeError):
            stack.pop()


if __name__ == '__main__':
    unittest.main()
