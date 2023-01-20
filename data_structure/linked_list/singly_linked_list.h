#pragma once

#include <iostream>

namespace data_structure {
namespace linked_list {

/**
 * Linked List is a linear data structure. Unlike arrays, linked list elements
 *  are not stored at a contiguous location the elements are linked using
 * pointers. Singly linked list is represented by a pointer to the first node
 * called head, if linked list is empty then the value of head is NULL (None).
 *  Each node of a singly linked list contains 2 parts:
 *  - Stored data
 *  - Pointer to the next node (or reference)
 *       HEAD
 *    [data1|-]->[data2|-]->[data3|-]->[data4|-]->[data5|-]->NULL
 * @tparam T node's class
 */
template <typename T>
class SinglyLinkedList {
 public:
  class Node {
   public:
    T data_;
    Node *next_;
    friend class SinglyLinkedList;
    explicit Node(const T &data) : data_(data), next_(NULL) {}
  };

 public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  std::size_t Size() const;
  bool IsEmpty() const;
  bool Search(const T &data) const;
  void Insert(const T &data);
  T Remove(const T &data);

  friend std::ostream &operator<<(std::ostream &out,
                                  const SinglyLinkedList &list) {
    if (list.IsEmpty()) {
      out << "Empty list";
    } else {
      typename SinglyLinkedList::Node *temp = list.head_;
      out << "List: ";
      while (temp != NULL) {
        out << "[" << temp->data_ << "]->";
        temp = temp->next_;
      }
    }
    return out;
  }

 private:
  Node *head_;
  uint32_t size_;
};

}  // namespace linked_list
}  // namespace data_structure