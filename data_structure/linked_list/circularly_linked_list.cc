#include "circularly_linked_list.h"

namespace data_structure {
namespace linked_list {

template <class T>
CircularlyLinkedList<T>::CircularlyLinkedList() : tail_(NULL), size_(0) {}

template <class T> CircularlyLinkedList<T>::~CircularlyLinkedList() {
  while (!IsEmpty()) {
    Remove(tail_->data_);
  }
  delete tail_;
}

template <class T> uint32_t CircularlyLinkedList<T>::Size() const { return size_; }

template <class T> bool CircularlyLinkedList<T>::IsEmpty() const {
  return tail_ == NULL;
}

template <class T> void CircularlyLinkedList<T>::Rotate() {
  tail_ = tail_->next_;
}

template <class T> bool CircularlyLinkedList<T>::Search(const T &data) const {
  if (IsEmpty()) {
    return false;
  }
  auto *temp = tail_->next_;
  do {
    if (temp->data_ == data) {
      return true;
    }
    temp = temp->next_;
  } while (temp != tail_->next_);
  return false;
}

template <class T> void CircularlyLinkedList<T>::Insert(const T &data) {
  auto *node = new Node(data);
  if (IsEmpty()) {
    tail_ = node;
    tail_->next_ = tail_;
  } else {
    node->next_ = tail_->next_;
    tail_->next_ = node;
  }
  size_++;
  Rotate();
}

template <class T> T CircularlyLinkedList<T>::Remove(const T &data) {
  if (IsEmpty()) {
    throw std::runtime_error("List is empty, can not remove");
  }
  Node *old = tail_->next_, *prev;
  do {
    prev = old;
    old = old->next_;
  } while (old != tail_->next_ && old->data_ != data);
  if (old == NULL) {
    throw std::runtime_error("Node is not exist in this list");
  }
  auto removed = old->data_;
  if (tail_->next_ == tail_) {
    tail_->next_ = NULL;
    tail_ = NULL;
  } else {
    prev->next_ = old->next_;
    if (old == tail_) {
      tail_ = prev;
    }
  }
  delete old;
  size_--;
  return removed;
}

} // namespace linked_list
} // namespace data_structure

int main() {
  std::cout << "TEST CIRCULARLY LINKED LIST\n" << std::endl;
  data_structure::linked_list::CircularlyLinkedList<int> linked_list;
  std::cout << "Empty: " << linked_list.IsEmpty() << std::endl;
  std::cout << "Size: " << linked_list.Size() << std::endl;
  std::cout << "Insert 8" << std::endl;
  linked_list.Insert(8);
  std::cout << "Insert 12" << std::endl;
  linked_list.Insert(12);
  std::cout << "Insert 6" << std::endl;
  linked_list.Insert(6);
  std::cout << "Insert 10" << std::endl;
  linked_list.Insert(10);
  std::cout << "Size: " << linked_list.Size() << std::endl;
  std::cout << "Empty: " << linked_list.IsEmpty() << std::endl;
  std::cout << linked_list << std::endl;
  std::cout << "Search 8: " << linked_list.Search(8) << std::endl;
  std::cout << "Search 9: " << linked_list.Search(9) << std::endl;
  std::cout << "Remove 10: " << linked_list.Remove(10) << std::endl;
  std::cout << linked_list << std::endl;
  std::cout << "Remove 6: " << linked_list.Remove(6) << std::endl;
  std::cout << linked_list << std::endl;
  std::cout << "Rotate" << std::endl;
  linked_list.Rotate();
  std::cout << linked_list << std::endl;

  return 0;
}
