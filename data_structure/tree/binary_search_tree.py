"""
Binary Search Tree
"""
from __future__ import annotations

import unittest
from typing import TypeVar
from data_structure.tree.binary_tree import BinaryTree

T = TypeVar("T")


class BinarySearchTree(BinaryTree[T]):
    def __init__(
        self,
        root: BinaryTree.Node = None,
        size: int = 0,
        traversal: BinaryTree.TreeTraversal = BinaryTree.TreeTraversal.IN_ORDER,
    ) -> None:
        super().__init__(root, size, traversal)

    def _search(self, node: BinaryTree.Node, data: T) -> BinaryTree.Node | None:
        if node is None or node.data == data:
            return node

        return (
            self._search(node.left, data)
            if data < node.data
            else self._search(node.right, data)
        )

    def insert(self, data: T) -> None:
        node: BinaryTree.Node = BinaryTree.Node(data)
        tmp: BinaryTree.Node = self._root
        tmp_parent: BinaryTree.Node | None = None

        while tmp:
            tmp_parent = tmp
            tmp = tmp.left if data < tmp.data else tmp.right

        if tmp_parent is None:
            self._root = node
        elif data < tmp_parent.data:
            tmp_parent.left = node
        else:
            tmp_parent.right = node

        node.parent = tmp_parent
        self._size += 1

    def remove(self, data: T) -> T:
        if self.is_empty():
            raise RuntimeError("Tree is empty, can not remove")

        removed = self._search(self._root, data)
        if removed is None:
            raise RuntimeError("Node is not exist in this tree")

        removed_data = removed.data
        if removed.left is None:
            self._transplant(removed, removed.right)
        elif removed.right is None:
            self._transplant(removed, removed.left)
        else:
            node = self._minimum(removed.right)
            if node.parent is not removed:
                self._transplant(node, node.right)
                node.right = removed.right
                removed.right.parent = node

            self._transplant(removed, node)
            node.left = removed.left
            node.left.parent = node

        self._size -= 1
        return removed_data

    def maximum(self) -> BinaryTree.Node | None:
        if self.is_empty():
            raise RuntimeError("Tree is empty, can not get maximum")
        return self._maximum(self._root)

    def _maximum(self, node: BinaryTree.Node) -> BinaryTree.Node | None:
        if self.is_empty():
            return None
        while node.right:
            node = node.right
        return node

    def minimum(self) -> BinaryTree.Node | None:
        if self.is_empty():
            raise RuntimeError("Tree is empty, can not get minimum")
        return self._minimum(self._root)

    def _minimum(self, node: BinaryTree.Node) -> BinaryTree.Node | None:
        if self.is_empty():
            return None
        while node.left:
            node = node.left
        return node


class TestBinarySearchTree(unittest.TestCase):
    def test_integer_binary_search_tree(self):
        tree: BinarySearchTree[int] = BinarySearchTree()

        self.assertTrue(tree.is_empty())
        self.assertEqual(tree.size, 0)

        tree.insert(4)
        tree.insert(2)
        tree.insert(1)
        tree.insert(3)
        tree.insert(6)
        tree.insert(5)
        tree.insert(7)

        self.assertFalse(tree.is_empty())
        self.assertListEqual([node.data for node in tree], [1, 2, 3, 4, 5, 6, 7])

        tree.traversal = BinarySearchTree.TreeTraversal.PRE_ORDER
        self.assertListEqual([node.data for node in tree], [4, 2, 1, 3, 6, 5, 7])

        tree.traversal = BinarySearchTree.TreeTraversal.POST_ORDER
        self.assertListEqual([node.data for node in tree], [1, 3, 2, 5, 7, 6, 4])

        tree.traversal = BinarySearchTree.TreeTraversal.LEVEL_ORDER
        self.assertListEqual([node.data for node in tree], [4, 2, 6, 1, 3, 5, 7])

        self.assertTrue(tree.search(6))
        self.assertFalse(tree.search(9))

        self.assertEqual(tree.maximum().data, 7)
        self.assertEqual(tree.minimum().data, 1)

        tree.remove(4)
        self.assertListEqual([node.data for node in tree], [5, 2, 6, 1, 3, 7])
        tree.remove(6)
        self.assertListEqual([node.data for node in tree], [5, 2, 7, 1, 3])

        with self.assertRaises(RuntimeError):
            tree.remove(9)

        tree.remove(1)
        self.assertListEqual([node.data for node in tree], [5, 2, 7, 3])
        tree.remove(2)
        self.assertListEqual([node.data for node in tree], [5, 3, 7])
        tree.remove(3)
        self.assertListEqual([node.data for node in tree], [5, 7])
        tree.remove(7)
        self.assertListEqual([node.data for node in tree], [5])
        tree.remove(5)
        self.assertTrue(tree.is_empty())

        with self.assertRaises(RuntimeError):
            tree.remove(9)


if __name__ == "__main__":
    unittest.main()
