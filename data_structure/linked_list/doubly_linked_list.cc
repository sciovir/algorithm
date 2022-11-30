#include "doubly_linked_list.h"

namespace data_structure {
namespace linked_list {

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head_(NULL), size_(0) {}

template <class T> DoublyLinkedList<T>::~DoublyLinkedList() {
  while (!IsEmpty()) {
    Remove(head_->data_);
  }
  delete head_;
}

template <class T> uint32_t DoublyLinkedList<T>::Size() const { return size_; }

template <class T> bool DoublyLinkedList<T>::IsEmpty() const {
  return head_ == NULL;
}

template <class T> bool DoublyLinkedList<T>::Search(const T &data) const {
  auto *temp = head_;
  while (temp != NULL) {
    if (temp->data_ == data) {
      return true;
    }
    temp = temp->next_;
  }
  return false;
}

template <class T> void DoublyLinkedList<T>::Insert(const T &data) {
  auto *node = new Node(data);
  if (IsEmpty()) {
    head_ = node;
  } else {
    auto *temp = head_;
    while (temp->next_ != NULL) {
      temp = temp->next_;
    }
    node->prev_ = temp;
    temp->next_ = node;
  }
  size_++;
}

template <class T> T DoublyLinkedList<T>::Remove(const T &data) {
  if (IsEmpty()) {
    throw std::runtime_error("List is empty, can not remove");
  }
  auto *old = head_;
  while (old != NULL && old->data_ != data) {
    old = old->next_;
  }
  if (old == NULL) {
    throw std::runtime_error("Node is not exist in this list");
  }
  auto removed = old->data_;
  if (old == head_) {
    head_ = head_->next_;
    if (head_ != NULL) {
      head_->prev_ = NULL;
    }
  } else {
    old->prev_->next_ = old->next_;
    if (old->next_ != NULL) {
      old->next_->prev_ = old->prev_;
    }
  }
  old->prev_ = NULL;
  old->next_ = NULL;
  delete old;
  size_--;
  return removed;
}

} // namespace linked_list
} // namespace data_structure

int main() {
  std::cout << "TEST DOUBLY LINKED LIST\n" << std::endl;
  data_structure::linked_list::DoublyLinkedList<int> linked_list;
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

  return 0;
}
