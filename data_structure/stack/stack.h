#pragma once

#include <iostream>

namespace data_structure {
namespace stack {

template <class T> class Stack {
  enum { DEFAULT_CAPACITY = 100 };

public:
  Stack();
  explicit Stack(uint32_t capacity);
  ~Stack();
  uint32_t Size() const;
  bool IsEmpty() const;
  bool IsFull() const;
  T &Top() const;
  void Push(const T &value);
  T Pop();

  friend std::ostream &operator<<(std::ostream &out, const Stack &stack) {
    if (stack.IsEmpty())
      out << "Empty stack";
    else {
      out << "Stack: ";
      for (int i = 0; i <= stack.top_; i++)
        out << stack.data_[i] << " ";
    }
    return out;
  }

private:
  T *data_;
  uint32_t capacity_;
  int32_t top_;
};

} // namespace stack
} // namespace data_structure
