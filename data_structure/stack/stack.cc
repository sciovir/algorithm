#include "stack.h"

namespace data_structure {
namespace stack {

template <class T>
Stack<T>::Stack()
    : data_(new T[DEFAULT_CAPACITY]), capacity_(DEFAULT_CAPACITY), top_(-1) {}

template <class T>
Stack<T>::Stack(uint32_t capacity)
    : data_(new T[capacity]), capacity_(capacity), top_(-1) {}

template <class T> Stack<T>::~Stack() { delete[] data_; }

template <class T> uint32_t Stack<T>::Size() const { return top_ + 1; }

template <class T> bool Stack<T>::IsEmpty() const { return top_ < 0; }

template <class T> bool Stack<T>::IsFull() const { return Size() == capacity_; }

template <class T> T &Stack<T>::Top() const {
  if (IsEmpty()) {
    throw std::runtime_error("Stack underflow, can not get top.");
  }
  return data_[top_];
}

template <class T> void Stack<T>::Push(const T &value) {
  if (IsFull()) {
    throw std::runtime_error("Stack overflow, can not push.");
  }
  data_[++top_] = value;
}

template <class T> T Stack<T>::Pop() {
  if (IsEmpty()) {
    throw std::runtime_error("Stack underflow, can not pop");
  }
  return data_[top_--];
}

} // namespace stack
} // namespace data_structure

int main() {
  std::cout << "TEST STACK\n" << std::endl;
  data_structure::stack::Stack<int> stack(20);
  std::cout << "Empty: " << stack.IsEmpty() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Push 8" << std::endl;
  stack.Push(8);
  std::cout << "Push 6" << std::endl;
  stack.Push(6);
  std::cout << "Push 26" << std::endl;
  stack.Push(26);
  std::cout << "Push 9" << std::endl;
  stack.Push(9);
  std::cout << "Push 7" << std::endl;
  stack.Push(7);
  std::cout << "Push 22" << std::endl;
  stack.Push(22);
  std::cout << stack << std::endl;
  std::cout << "Empty: " << stack.IsEmpty() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Top: " << stack.Top() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Top: " << stack.Top() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << "Pop: " << stack.Pop() << std::endl;
  std::cout << "Size: " << stack.Size() << std::endl;
  std::cout << stack << std::endl;

  return 0;
}
