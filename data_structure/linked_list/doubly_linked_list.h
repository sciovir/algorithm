#pragma once

#include <iostream>

namespace data_structure {
namespace linked_list {

template <class T> class DoublyLinkedList {
public:
  class Node {
  public:
    T data_;
    Node *prev_;
    Node *next_;
    friend class DoublyLinkedList;
    explicit Node(const T &data) : data_(data), prev_(NULL), next_(NULL) {}
  };

public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  uint32_t Size() const;
  bool IsEmpty() const;
  bool Search(const T &data) const;
  void Insert(const T &data);
  T Remove(const T &data);

  friend std::ostream &operator<<(std::ostream &out,
                                  const DoublyLinkedList &list) {
    if (list.IsEmpty()) {
      out << "Empty list";
    } else {
      typename DoublyLinkedList::Node *temp = list.head_;
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

} // namespace linked_list
} // namespace data_structure
