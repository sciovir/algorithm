#include "singly_linked_list.h"

#include "utils/test.h"

namespace data_structure {
namespace linked_list {

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head_(NULL), size_(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
  while (!IsEmpty()) {
    Remove(head_->data_);
  }
  delete head_;
}

template <typename T>
std::size_t SinglyLinkedList<T>::Size() const {
  return static_cast<std::size_t>(size_);
}

template <typename T>
bool SinglyLinkedList<T>::IsEmpty() const {
  return (head_ == NULL);
}

template <typename T>
bool SinglyLinkedList<T>::Search(const T &data) const {
  auto *temp = head_;
  while (temp != NULL) {
    if (temp->data_ == data) {
      return true;
    }
    temp = temp->next_;
  }
  return false;
}

template <typename T>
void SinglyLinkedList<T>::Insert(const T &data) {
  Node *node = new Node(data);
  if (IsEmpty()) {
    head_ = node;
  } else {
    Node *temp = head_;
    while (temp->next_ != NULL) {
      temp = temp->next_;
    }
    temp->next_ = node;
  }
  size_++;
}

template <typename T>
T SinglyLinkedList<T>::Remove(const T &data) {
  if (IsEmpty()) {
    throw std::runtime_error("List is empty, can not remove");
  }

  Node *old = head_, *prev;
  while (old != NULL && old->data_ != data) {
    prev = old;
    old = old->next_;
  }

  if (old == NULL) {
    throw std::runtime_error("Node is not exist in this list");
  }

  auto removed = old->data_;
  if (old == head_) {
    head_ = head_->next_;
  } else {
    prev->next_ = old->next_;
  }

  delete old;
  size_--;
  return removed;
}

namespace test {

void SinglyLinkedList_FunctionalTest() {
  SinglyLinkedList<int32_t> linked_list;

  EXPECT_EQ(linked_list.IsEmpty(), true);
  EXPECT_EQ(linked_list.Size(), 0);

  linked_list.Insert(8);
  linked_list.Insert(12);
  linked_list.Insert(6);
  linked_list.Insert(10);

  EXPECT_EQ(linked_list.Size(), 4);
  EXPECT_EQ(linked_list.IsEmpty(), false);
  std::cout << linked_list << std::endl;

  EXPECT_EQ(linked_list.Search(8), true);
  EXPECT_EQ(linked_list.Search(9), false);

  EXPECT_EQ(linked_list.Remove(10), 10);
  EXPECT_EQ(linked_list.Size(), 3);

  EXPECT_EQ(linked_list.Remove(6), 6);
  EXPECT_EQ(linked_list.Size(), 2);

  EXPECT_THROW(linked_list.Remove(6));
}

void RunTests() { TEST(SinglyLinkedList_FunctionalTest); }

}  // namespace test

}  // namespace linked_list
}  // namespace data_structure

int main() {
  std::cout << "-----Running Singly Linked List tests-----" << std::endl;
  data_structure::linked_list::test::RunTests();
  return 0;
}