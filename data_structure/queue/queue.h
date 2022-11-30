#pragma once

#include <iostream>

namespace data_structure {
namespace queue {

template <class T> class Queue {
  enum { DEFAULT_CAPACITY = 100 };

public:
  Queue();
  explicit Queue(uint32_t capacity);
  ~Queue();
  uint32_t Size() const;
  bool IsEmpty() const;
  bool IsFull() const;
  T Head() const;
  void Enqueue(const T &value);
  T Dequeue();

  friend std::ostream &operator<<(std::ostream &out, const Queue &queue) {
    if (queue.IsEmpty())
      out << "Empty queue";
    else {
      int index = queue.head_;
      out << "Queue: ";
      while (true) {
        out << queue.data_[index] << " ";
        index = (index + 1) == queue.capacity_ ? 0 : index + 1;
        bool cond = queue.head_ < queue.tail_;
        if (cond)
          cond = index >= queue.head_ && index < queue.tail_;
        else
          cond = (index >= queue.head_ && index < queue.capacity_) ||
                 (index >= 0 && index < queue.tail_);
        if (!cond)
          break;
      }
    }
    return out;
  }

private:
  T *data_;
  uint32_t capacity_;
  uint32_t head_;
  uint32_t tail_;
};

} // namespace queue
} // namespace data_structure
