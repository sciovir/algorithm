"""
Doubly Linked List
"""
from __future__ import annotations

import unittest
from typing import TypeVar, Generic, Generator, Any

T = TypeVar("T")


class DoublyLinkedList(Generic[T]):
    class Node:
        def __init__(self, data: T, prv: Node = None, nxt: Node = None):
            self._data = data
            self._prv = prv
            self._nxt = nxt

        def __repr__(self) -> str:
            if not self._prv and not self._nxt:
                return f"[]<-[{self._data}]->[]"
            elif not self._prv:
                return f"[]<-[{self._data}]->"
            elif not self._nxt:
                return f"<-[{self._data}]->[]"
            return f"<-[{self._data}]->"

        @property
        def data(self) -> T:
            return self._data

        @data.setter
        def data(self, data):
            self._data = data

        @property
        def prv(self) -> Node:
            return self._prv

        @prv.setter
        def prv(self, prv):
            self._prv = prv

        @property
        def nxt(self) -> Node:
            return self._nxt

        @nxt.setter
        def nxt(self, nxt):
            self._nxt = nxt

    def __init__(self, head: Node = None, size: int = 0):
        self._head = head
        self._size = size

    def __iter__(self) -> Generator[Node, Any, None]:
        tmp = self._head
        while tmp:
            yield tmp
            tmp = tmp.nxt

    def __repr__(self) -> str:
        return "".join([str(node) for node in self])

    @property
    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._head is None

    def search(self, data: T) -> bool:
        tmp = self._head
        while tmp:
            if tmp.data == data:
                return True
            tmp = tmp.nxt
        return False

    def insert(self, data: T):
        node = DoublyLinkedList.Node(data)
        if self.is_empty():
            self._head = node
        else:
            tmp = self._head
            while tmp.nxt:
                tmp = tmp.nxt
            node.prv = tmp
            tmp.nxt = node
        self._size += 1

    def remove(self, data: T) -> T:
        if self.is_empty():
            raise RuntimeError("List is empty, can not remove")

        old = self._head
        while old and old.data != data:
            old = old.nxt

        if not old:
            raise RuntimeError("Node is not exist in this list")

        removed = old.data
        if old is self._head:
            self._head = self._head.nxt
            if self._head:
                self._head.prv = None
        else:
            old.prv.nxt = old.nxt
            if old.nxt:
                old.nxt.prv = old.prv

        old.prv = None
        old.nxt = None

        self._size -= 1
        return removed


class TestDoublyLinkedList(unittest.TestCase):
    def test_integer_linked_list(self):
        linked_list: DoublyLinkedList[int] = DoublyLinkedList()

        self.assertTrue(linked_list.is_empty())
        self.assertEqual(linked_list.size, 0)

        linked_list.insert(8)
        linked_list.insert(12)
        linked_list.insert(6)
        linked_list.insert(10)

        self.assertFalse(linked_list.is_empty())
        self.assertListEqual([node.data for node in linked_list], [8, 12, 6, 10])

        self.assertTrue(linked_list.search(8))
        self.assertFalse(linked_list.search(9))

        linked_list.remove(10)
        self.assertListEqual([node.data for node in linked_list], [8, 12, 6])
        linked_list.remove(6)
        self.assertListEqual([node.data for node in linked_list], [8, 12])

        with self.assertRaises(RuntimeError):
            linked_list.remove(9)

        linked_list.remove(8)
        self.assertListEqual([node.data for node in linked_list], [12])
        linked_list.remove(12)
        self.assertListEqual([node.data for node in linked_list], [])

        with self.assertRaises(RuntimeError):
            linked_list.remove(9)


if __name__ == "__main__":
    unittest.main()
