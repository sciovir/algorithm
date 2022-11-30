#pragma once

#include <iostream>

namespace data_structure {
namespace linked_list {

template <class T> class CircularlyLinkedList {
public:
  class Node {
  public:
    T data_;
    Node *next_;
    friend class CircularlyLinkedList;
    explicit Node(const T &data) : data_(data), next_(NULL) {}
  };

public:
  CircularlyLinkedList();
  ~CircularlyLinkedList();
  uint32_t Size() const;
  bool IsEmpty() const;
  void Rotate();
  bool Search(const T &data) const;
  void Insert(const T &data);
  T Remove(const T &data);

  friend std::ostream &operator<<(std::ostream &out,
                                  const CircularlyLinkedList &list) {
    if (list.IsEmpty()) {
      out << "Empty list";
    } else {
      typename CircularlyLinkedList::Node *temp = list.tail_->next_;
      out << "List: ";
      do {
        out << "[" << temp->data_ << "]->";
        temp = temp->next_;
      } while (temp != list.tail_->next_);
    }
    return out;
  }

private:
  Node *tail_;
  uint32_t size_;
};

} // namespace linked_list
} // namespace data_structure
