#pragma once
#include "data_structure/heap/min_heap.h"

namespace data_structure {
namespace queue {

template <class T>
class MinPriorityQueue : public heap::MinHeap<T> {
 public:
  using heap::MinHeap<T>::MinHeap;
  template <size_t N>
  explicit MinPriorityQueue(const T (&array)[N]);
  template <size_t N>
  explicit MinPriorityQueue(const T (&array)[N], int capacity);
  T Minimum() const;
  T ExtractMin();
  void DecreaseKey(int index, const T &key);
  void Insert(const T &value);

  friend std::ostream &operator<<(std::ostream &out,
                                  const MinPriorityQueue &queue) {
    out << "Queue: ";
    for (int i = 0; i < queue.size_; i++)
      out << "(" << queue.data_[i] << " [" << i << "]) ";
    return out;
  }
};

template <class T>
template <size_t N>
MinPriorityQueue<T>::MinPriorityQueue(const T (&array)[N])
    : heap::MinHeap<T>(array) {
  this->data_ = new T[N];
  this->capacity_ = N;
  this->size_ = 0;
  for (unsigned int i = 0; i < N; i++) Insert(array[i]);
}

template <class T>
template <size_t N>
MinPriorityQueue<T>::MinPriorityQueue(const T (&array)[N], int capacity)
    : heap::MinHeap<T>(array, capacity) {
  this->data_ = new T[capacity];
  this->capacity_ = capacity;
  this->size_ = 0;
  for (int i = 0; i < N; i++) Insert(array[i]);
}

template <class T>
T MinPriorityQueue<T>::Minimum() const {
  return this->data_[0];
}

template <class T>
T MinPriorityQueue<T>::ExtractMin() {
  if (this->IsEmpty()) throw std::runtime_error("Priority queue underflow");
  return this->Remove(0);
}

template <class T>
void MinPriorityQueue<T>::DecreaseKey(int index, const T &key) {
  if (key > this->data_[index])
    throw std::runtime_error("New key is larger than current key");
  this->data_[index] = key;
  while (index > 0 && this->data_[this->Parent(index)] > this->data_[index]) {
    this->Swap(index, this->Parent(index));
    index = this->Parent(index);
  }
}

template <class T>
void MinPriorityQueue<T>::Insert(const T &value) {
  if (this->IsFull()) throw std::runtime_error("Priority queue overflow");
  this->data_[this->size_++] = value;
  DecreaseKey(this->size_ - 1, value);
}

}  // namespace queue
}  // namespace data_structure
