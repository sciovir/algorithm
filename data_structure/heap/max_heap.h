#include "heap.h"

#ifndef ALGORITHM_DATA_STRUCTURE_HEAP_MAX_HEAP_H_
#define ALGORITHM_DATA_STRUCTURE_HEAP_MAX_HEAP_H_

namespace data_structure {
namespace heap {

template <class T>
class MaxHeap : public Heap<T> {
 public:
  using Heap<T>::Heap;
  template <size_t N>
  explicit MaxHeap(const T (&array)[N]);
  template <size_t N>
  explicit MaxHeap(const T (&array)[N], int capacity);
  void BuildHeap();
  void Heapify(int index);
  virtual void Insert(const T &value);
  T Remove(int index);
};

template <class T>
template <size_t N>
MaxHeap<T>::MaxHeap(const T (&array)[N]) {
  this->data_ = new T[N];
  for (unsigned int i = 0; i < N; i++) this->data_[i] = array[i];
  this->size_ = N;
  this->capacity_ = N;
  BuildHeap();
}

template <class T>
template <size_t N>
MaxHeap<T>::MaxHeap(const T (&array)[N], int capacity) {
  this->data_ = new T[capacity];
  for (unsigned int i = 0; i < N; i++) this->data_[i] = array[i];
  this->size_ = N;
  this->capacity_ = capacity;
  BuildHeap();
}

template <class T>
void MaxHeap<T>::BuildHeap() {
  for (int i = this->size_ / 2; i >= 0; i--) Heapify(i);
}

template <class T>
void MaxHeap<T>::Heapify(int index) {
  int left = this->Left(index), right = this->Right(index), largest;
  largest = (left < this->size_ && this->data_[left] > this->data_[index])
                ? left
                : index;
  if (right < this->size_ && this->data_[right] > this->data_[largest])
    largest = right;
  if (largest != index) {
    this->Swap(index, largest);
    Heapify(largest);
  }
}

template <class T>
void MaxHeap<T>::Insert(const T &value) {
  if (this->IsFull()) throw std::runtime_error("Heap overflow");
  this->data_[this->size_++] = value;
  int cur = this->size_ - 1;
  while (cur > 0 && (this->data_[cur] > this->data_[this->Parent(cur)])) {
    this->Swap(cur, this->Parent(cur));
    cur = this->Parent(cur);
  }
}

template <class T>
T MaxHeap<T>::Remove(int index) {
  if (this->IsEmpty()) throw std::runtime_error("Heap underflow");
  T removed = this->data_[index];
  this->data_[index] = this->data_[--this->size_];
  Heapify(index);
  return removed;
}

}  // namespace heap
}  // namespace data_structure

#endif  // ALGORITHM_DATA_STRUCTURE_HEAP_MAX_HEAP_H_
