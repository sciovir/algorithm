#include "queue.h"

namespace data_structure {
namespace queue {

template <class T>
Queue<T>::Queue()
    : data_(new T[DEFAULT_CAPACITY]), capacity_(DEFAULT_CAPACITY), head_(0),
      tail_(0) {}

template <class T>
Queue<T>::Queue(uint32_t capacity)
    : data_(new T[capacity]), capacity_(capacity), head_(0), tail_(0) {}

template <class T> Queue<T>::~Queue() { delete[] data_; }

template <class T> uint32_t Queue<T>::Size() const {
  return (head_ > tail_) ? capacity_ - head_ + tail_ : tail_ - head_;
}

template <class T> bool Queue<T>::IsEmpty() const { return head_ == tail_; }

template <class T> bool Queue<T>::IsFull() const {
  auto temp = (tail_ + 1 == capacity_) ? 0 : tail_ + 1;
  return head_ == temp;
}

template <class T> T Queue<T>::Head() const {
  if (IsEmpty()) {
    throw std::runtime_error("Queue underflow, can not get head.");
  }
  return data_[head_];
}

template <class T> void Queue<T>::Enqueue(const T &value) {
  if (IsFull()) {
    throw std::runtime_error("Queue overflow, can not enqueue.");
  }
  data_[tail_] = value;
  tail_ = (capacity_ == (tail_ + 1)) ? 0 : tail_ + 1;
}

template <class T> T Queue<T>::Dequeue() {
  if (IsEmpty()) {
    throw std::runtime_error("Queue underflow, can not dequeue.");
  }
  auto removed = data_[head_];
  head_ = (capacity_ == head_ + 1) ? 0 : head_ + 1;
  return removed;
}

} // namespace queue
} // namespace data_structure

int main() {
  std::cout << "TEST QUEUE\n" << std::endl;
  data_structure::queue::Queue<int> queue(20);
  std::cout << "Empty: " << queue.IsEmpty() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Enqueue 8" << std::endl;
  queue.Enqueue(8);
  std::cout << "Enqueue 6" << std::endl;
  queue.Enqueue(6);
  std::cout << "Enqueue 26" << std::endl;
  queue.Enqueue(26);
  std::cout << "Enqueue 9" << std::endl;
  queue.Enqueue(9);
  std::cout << "Enqueue 7" << std::endl;
  queue.Enqueue(7);
  std::cout << "Enqueue 22" << std::endl;
  queue.Enqueue(22);
  std::cout << queue << std::endl;
  std::cout << "Empty: " << queue.IsEmpty() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Head: " << queue.Head() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Head: " << queue.Head() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
  std::cout << "Size: " << queue.Size() << std::endl;
  std::cout << queue << std::endl;

  return 0;
}
