"""
Binary Tree
"""
from __future__ import annotations

import enum
import unittest
from typing import TypeVar, Generic, Generator, Any

from data_structure.queue.queue_q import Queue
from data_structure.stack.stack import Stack

T = TypeVar("T")


class BinaryTree(Generic[T]):
    class Node:
        def __init__(
            self, data: T, parent: Node = None, left: Node = None, right: Node = None
        ) -> None:
            self._data = data
            self._parent = parent
            self._left = left
            self._right = right

        def __repr__(self) -> str:
            return str(self._data)

        @property
        def data(self) -> T:
            return self._data

        @data.setter
        def data(self, data) -> None:
            self._data = data

        @property
        def parent(self) -> Node:
            return self._parent

        @parent.setter
        def parent(self, parent) -> None:
            self._parent = parent

        @property
        def left(self) -> Node:
            return self._left

        @left.setter
        def left(self, left) -> None:
            self._left = left

        @property
        def right(self) -> Node:
            return self._right

        @right.setter
        def right(self, right) -> None:
            self._right = right

    class TreeTraversal(enum.Enum):
        PRE_ORDER = 0
        IN_ORDER = 1
        POST_ORDER = 2
        LEVEL_ORDER = 3

    def __init__(
        self,
        root: Node = None,
        size: int = 0,
        traversal: TreeTraversal = TreeTraversal.IN_ORDER,
    ) -> None:
        self._root = root
        self._size = size
        self._traversal = traversal

    def __iter__(self) -> Generator[Node, Any, None]:
        if not self.is_empty():
            if self._traversal == BinaryTree.TreeTraversal.PRE_ORDER:
                return self._pre_order_iter(self._root, True)
            elif self._traversal == BinaryTree.TreeTraversal.IN_ORDER:
                return self._in_order_iter(self._root, True)
            elif self._traversal == BinaryTree.TreeTraversal.POST_ORDER:
                return self._post_order_iter(self._root, True)
            elif self._traversal == BinaryTree.TreeTraversal.LEVEL_ORDER:
                return self._level_order_iter(True)

    def __repr__(self) -> str:
        return ", ".join([str(node) for node in self])

    @property
    def traversal(self) -> TreeTraversal:
        return self._traversal

    @traversal.setter
    def traversal(self, traversal: TreeTraversal) -> None:
        self._traversal = traversal

    @property
    def size(self) -> int:
        return self._size

    def is_empty(self) -> bool:
        return self._root is None

    def search(self, data: T) -> Node:
        return self._search(self._root, data)

    def _search(self, node: Node, data: T) -> Node | None:
        if node is None or node.data == data:
            return node

        left_search: BinaryTree.Node = self._search(node.left, data)
        if left_search:
            return left_search

        return self._search(node.right, data)

    def insert(self, data: T) -> None:
        node = BinaryTree.Node(data)
        if self.is_empty():
            self._root = node
        else:
            queue: Queue[BinaryTree.Node] = Queue(self._size + 1)
            queue.enqueue(self._root)
            while not queue.is_empty():
                tmp: BinaryTree.Node = queue.dequeue()

                if tmp.left is None:
                    tmp.left = node
                    node.parent = tmp
                    break
                else:
                    queue.enqueue(tmp.left)

                if tmp.right is None:
                    tmp.right = node
                    node.parent = tmp
                    break
                else:
                    queue.enqueue(tmp.right)

        self._size += 1

    def remove(self, data: T) -> T:
        if self.is_empty():
            raise RuntimeError("Tree is empty, can not remove")

        removed: BinaryTree.Node | None = None
        node: BinaryTree.Node | None = None
        queue: Queue[BinaryTree.Node] = Queue(self._size + 1)
        queue.enqueue(self._root)
        while not queue.is_empty():
            node = queue.dequeue()
            if node.data == data:
                removed = node
            if node.left:
                queue.enqueue(node.left)
            if node.right:
                queue.enqueue(node.right)

        if removed is None:
            raise RuntimeError("Node is not exist in this tree")

        saved_data = node.data
        removed_data = removed.data
        self._transplant(node, None)
        removed.data = saved_data

        self._size -= 1
        return removed_data

    def _transplant(self, node: Node, child: Node | None) -> None:
        if node.parent is None:
            self._root = child
        elif node is node.parent.left:
            node.parent.left = child
        else:
            node.parent.right = child

        if child:
            child.parent = node.parent
        node.parent = None

    def _height(self, node: Node) -> int:
        if node is None:
            return 0
        else:
            return 1 + max(self._height(node.left), self._height(node.right))

    def _pre_order_iter(
        self, node: Node, recursive: bool
    ) -> Generator[Node, Any, None]:
        if recursive:
            if node:
                yield node
                yield from self._pre_order_iter(node.left, recursive)
                yield from self._pre_order_iter(node.right, recursive)
        else:
            tmp = self._root
            stack: Stack[BinaryTree.Node] = Stack(self._size)

            while True:
                if tmp:
                    stack.push(tmp)
                    yield tmp
                    tmp = tmp.left
                elif not stack.is_empty():
                    tmp = stack.pop()
                    tmp = tmp.right
                else:
                    break

    def _in_order_iter(self, node: Node, recursive: bool) -> Generator[Node, Any, None]:
        if recursive:
            if node:
                yield from self._in_order_iter(node.left, recursive)
                yield node
                yield from self._in_order_iter(node.right, recursive)
        else:
            tmp = self._root
            stack: Stack[BinaryTree.Node] = Stack(self._size)

            while True:
                if tmp:
                    stack.push(tmp)
                    tmp = tmp.left
                elif not stack.is_empty():
                    tmp = stack.pop()
                    yield tmp
                    tmp = tmp.right
                else:
                    break

    def _post_order_iter(
        self, node: Node, recursive: bool
    ) -> Generator[Node, Any, None]:
        if recursive:
            if node:
                yield from self._post_order_iter(node.left, recursive)
                yield from self._post_order_iter(node.right, recursive)
                yield node
        else:
            tmp = self._root
            stack: Stack[BinaryTree.Node] = Stack(self._size)

            while True:
                while tmp:
                    if tmp.right:
                        stack.push(tmp.right)
                    stack.push(tmp)
                    tmp = tmp.left

                tmp = stack.pop()
                if (
                    not stack.is_empty()
                    and tmp.right
                    and stack.top_value() is tmp.right
                ):
                    stack.pop()
                    stack.push(tmp)
                    tmp = tmp.right
                else:
                    yield tmp
                    tmp = None

                if stack.is_empty():
                    break

    def _level_order_iter(self, recursive: bool) -> Generator[Node, Any, None]:
        if recursive:
            for i in range(1, self._height(self._root) + 1):
                yield from self._level_iter(self._root, i)
        else:
            if not self.is_empty():
                queue: Queue[BinaryTree.Node] = Queue(self._size)
                queue.enqueue(self._root)

                while not queue.is_empty():
                    tmp = queue.dequeue()
                    yield tmp
                    if tmp.left:
                        queue.enqueue(tmp.left)
                    if tmp.right:
                        queue.enqueue(tmp.right)

    def _level_iter(self, node: Node, level: int) -> Generator[Node, Any, None]:
        if node:
            if level == 1:
                yield node
            elif level > 1:
                yield from self._level_iter(node.left, level - 1)
                yield from self._level_iter(node.right, level - 1)


class TestBinaryTree(unittest.TestCase):
    def test_integer_binary_tree(self):
        tree: BinaryTree[int] = BinaryTree()

        self.assertTrue(tree.is_empty())
        self.assertEqual(tree.size, 0)

        tree.insert(1)
        tree.insert(2)
        tree.insert(3)
        tree.insert(4)
        tree.insert(5)
        tree.insert(6)
        tree.insert(7)

        self.assertFalse(tree.is_empty())
        self.assertListEqual([node.data for node in tree], [4, 2, 5, 1, 6, 3, 7])

        tree.traversal = BinaryTree.TreeTraversal.PRE_ORDER
        self.assertListEqual([node.data for node in tree], [1, 2, 4, 5, 3, 6, 7])

        tree.traversal = BinaryTree.TreeTraversal.POST_ORDER
        self.assertListEqual([node.data for node in tree], [4, 5, 2, 6, 7, 3, 1])

        tree.traversal = BinaryTree.TreeTraversal.LEVEL_ORDER
        self.assertListEqual([node.data for node in tree], [1, 2, 3, 4, 5, 6, 7])

        self.assertTrue(tree.search(6))
        self.assertFalse(tree.search(9))

        tree.remove(4)
        self.assertListEqual([node.data for node in tree], [1, 2, 3, 7, 5, 6])
        tree.remove(6)
        self.assertListEqual([node.data for node in tree], [1, 2, 3, 7, 5])

        with self.assertRaises(RuntimeError):
            tree.remove(9)

        tree.remove(1)
        self.assertListEqual([node.data for node in tree], [5, 2, 3, 7])
        tree.remove(2)
        self.assertListEqual([node.data for node in tree], [5, 7, 3])
        tree.remove(3)
        self.assertListEqual([node.data for node in tree], [5, 7])
        tree.remove(5)
        self.assertListEqual([node.data for node in tree], [7])
        tree.remove(7)
        self.assertTrue(tree.is_empty())

        with self.assertRaises(RuntimeError):
            tree.remove(9)


if __name__ == "__main__":
    unittest.main()
