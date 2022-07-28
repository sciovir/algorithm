"""
Adjacency List Graph
"""
from __future__ import annotations

import enum
import unittest
from typing import TypeVar, Generic, Generator, Any

T = TypeVar("T")


class Graph(Generic[T]):
    class Vertex:
        def __init__(self, data: T):
            self._data = data
            self._adjacent_vertices: list[Graph.Vertex] = []

        def __repr__(self) -> str:
            return str(self._data)

        @property
        def data(self) -> T:
            return self._data

        @data.setter
        def data(self, data):
            self._data = data

        @property
        def adjacent_vertices(self):
            return self._adjacent_vertices

        def insert_adjacent_vertex(self, dst: Graph.Vertex) -> None:
            for v in self._adjacent_vertices:
                if v._data == dst._data:
                    raise RuntimeError("The edge is already exist")
            self._adjacent_vertices.append(dst)

        def remove_adjacent_vertex(self, dst_data: T) -> T:
            for i in range(len(self._adjacent_vertices)):
                if self._adjacent_vertices[i]._data == dst_data:
                    del self._adjacent_vertices[i]
                    return dst_data
            raise RuntimeError("The edge is not exist")

    class GraphTraversal(enum.Enum):
        BREADTH_FIRST = 0
        DEPTH_FIRST = 1

    def __init__(self, traversal: GraphTraversal = GraphTraversal.BREADTH_FIRST):
        self._vertices: list[Graph.Vertex] = []
        self._traversal = traversal

    def __iter__(self) -> Generator[Vertex, Any, None]:
        if not self.is_empty():
            if self._traversal == Graph.GraphTraversal.BREADTH_FIRST:
                return self._breadth_first_iter()
            elif self._traversal == Graph.GraphTraversal.DEPTH_FIRST:
                return self._depth_first_iter()

    def __repr__(self) -> str:
        return ", ".join([str(vertex) for vertex in self])

    @property
    def size(self) -> int:
        return len(self._vertices)

    @property
    def traversal(self) -> GraphTraversal:
        return self._traversal

    @traversal.setter
    def traversal(self, traversal: GraphTraversal) -> None:
        self._traversal = traversal

    def is_empty(self) -> bool:
        return self.size == 0

    def insert_edge(self, src: T, dst: T) -> None:
        src_vertex: Graph.Vertex | None = None
        dst_vertex: Graph.Vertex | None = None

        for i in range(len(self._vertices)):
            if self._vertices[i].data == src:
                src_vertex = self._vertices[i]
            if self._vertices[i].data == dst:
                dst_vertex = self._vertices[i]
            if src_vertex and dst_vertex:
                break

        if src_vertex is None:
            src_vertex = Graph.Vertex(src)
            self._vertices.append(src_vertex)

        if dst_vertex is None:
            dst_vertex = Graph.Vertex(dst)
            self._vertices.append(dst_vertex)

        src_vertex.insert_adjacent_vertex(dst_vertex)

    def remove_edge(self, src: T, dst: T) -> T:
        for i in range(len(self._vertices)):
            if self._vertices[i].data == src:
                return self._vertices[i].remove_adjacent_vertex(dst)
        raise RuntimeError("The edge is not exist")

    def _breadth_first_iter(self) -> Generator[Vertex, Any, None]:
        visited: list[T] = []
        for v in self._vertices:
            if v.data not in visited:
                visited.append(v.data)
                yield v

            for av in v.adjacent_vertices:
                if av not in visited:
                    visited.append(av.data)
                    yield av

    def _depth_first_iter(self) -> Generator[Vertex, Any, None]:
        if not self.is_empty():
            visited: list[T] = []
            for i in range(len(self._vertices)):
                yield from self._depth_first_recursive_iter(self._vertices[i], visited)

    def _depth_first_recursive_iter(
        self, v: Vertex, visited: list[T]
    ) -> Generator[Vertex, Any, None]:
        if v.data not in visited:
            visited.append(v.data)
            yield v

        for av in v.adjacent_vertices:
            if av.data not in visited:
                yield from self._depth_first_recursive_iter(av, visited)


class TestAdjacencyGraph(unittest.TestCase):
    def test_integer_graph(self):
        graph: Graph[int] = Graph()

        self.assertTrue(graph.is_empty())
        self.assertEqual(graph.size, 0)

        graph.insert_edge(2, 0)
        graph.insert_edge(0, 2)
        graph.insert_edge(2, 3)
        graph.insert_edge(0, 1)
        graph.insert_edge(1, 2)
        graph.insert_edge(3, 3)

        self.assertFalse(graph.is_empty())
        self.assertListEqual([vertex.data for vertex in graph], [2, 0, 3, 2, 1, 3, 2])
        graph.traversal = Graph.GraphTraversal.DEPTH_FIRST
        self.assertListEqual([vertex.data for vertex in graph], [2, 0, 1, 3])
        graph.traversal = Graph.GraphTraversal.BREADTH_FIRST

        graph.remove_edge(0, 2)
        self.assertListEqual([vertex.data for vertex in graph], [2, 0, 3, 1, 3, 2])
        graph.remove_edge(2, 0)
        self.assertListEqual([vertex.data for vertex in graph], [2, 3, 0, 1, 3, 2])

        with self.assertRaises(RuntimeError):
            graph.remove_edge(9, 0)

        graph.remove_edge(0, 1)
        graph.remove_edge(2, 3)
        graph.remove_edge(3, 3)
        graph.remove_edge(1, 2)

        with self.assertRaises(RuntimeError):
            graph.remove_edge(6, 5)


if __name__ == "__main__":
    unittest.main()
