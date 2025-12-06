#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdlib>
#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
// size_t == unsigned long long
template <typename T>

class DynamicArray {
private:
  T* data;
  std::int64_t size = -1; // actual (last occupied)
  std::int64_t capacity; // max


public:
  DynamicArray(); // default ctor
  DynamicArray(std::int64_t capacity); // parametrized ctor
  DynamicArray(DynamicArray& other);
  ~DynamicArray(); // destructor

  void push_back(T x);
  T add(std::int64_t idx1, std::int64_t idx2);
  T max();
  T min();
  void clear(); // deallocate the data
  void reinitialize(); // restore to default
  void printData();
  void push_front(T x);
  T front();
  T back();
  void insert(std::int64_t idx, T x);
  void delete_(std::int64_t idx);
  void erase_after(std::int64_t idx);
  void increase_capacity(std::int64_t x);
  void decrease_capacity(std::int64_t x);
  bool isFull();
  void delete_last();
  bool isEmpty() {
    return size == -1;
  }
  int64_t getSize();

  T operator[](std::int64_t idx);
  T operator()();
};


template <typename T>
DynamicArray<T>::DynamicArray() {
  this->capacity = 8;
  this->data = new T[this->capacity];
}
template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity) {
  // check if user is dumb
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1"); // https://en.cppreference.com/w/cpp/error/exception.html
    // std::exception like an animal
    // std::invalid_argument like a dog (heir of animal)
  }
  this->capacity = capacity;
  this->data = new T[this->capacity];
}
template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }
}
template <typename T>
DynamicArray<T>::~DynamicArray() {
  // deallocate if allocated
  if (this->data) {
    delete[] this->data;
  }
}
template <typename T>
void DynamicArray<T>::push_back(T x) {
  // reallocate memory
  // increase capacity
  // copy data
  // dealloc old
  // assign new to old
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;
  // data[size + 1] = x;
  // ++size;
}
template <typename T>
T DynamicArray<T>::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}
template <typename T>
T DynamicArray<T>::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMax = this->data[0];
  // T currentMax = std::numeric_limits<T>::lowest();
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}
template <typename T>
T DynamicArray<T>::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  T currentMin = this->data[0];
  // T currentMin = std::numeric_limits<T>::max();
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}
template <typename T>
void DynamicArray<T>::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 64;
}
template <typename T>
void DynamicArray<T>::reinitialize() {
  clear();
  data = new T[capacity](); // init with zeros
}
template <typename T>
void DynamicArray<T>::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}
template <typename T>
T DynamicArray<T>::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx]; // Arabic operator[]
  // return data[idx];     // European operator[]
}
template <typename T>
T DynamicArray<T>::operator()() {
  if (isEmpty()) {
    return 0;
  }
  T sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;
}
template <typename T>
void DynamicArray<T>::push_front(T x) {
  if (this->size + 1  == this->capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    tempArray[0] = x;
    for (int i = 0; i < this->capacity; ++i) {
      tempArray[i+1] = this->data[i];
    }
    delete[] this->data;
    this->data = tempArray;
    this->capacity = newCapacity;
  }
  else {
    T* tempArray = new T[this->capacity];
    tempArray[0] = x;
    for (int i = 0; i < this->size + 1; ++i) {
      tempArray[i+1] = this->data[i];
    }
    delete[] this->data;
    this->data = tempArray;
  }
  ++this->size;
}
template <typename T>
T DynamicArray<T>::front() {
  if (isEmpty()) {
    throw std::invalid_argument("List is empty");
  }
  return this->data[0];
}
template <typename T>
T DynamicArray<T>::back() {
  if (isEmpty()) {
    throw std::invalid_argument("List is empty");
  }
  return this->data[this->size];
}
template <typename T>
void DynamicArray<T>::insert(std::int64_t idx, T x) {
  if (idx < 0 || idx > this->size) {
    throw std::invalid_argument("Out of range");
  }
  if (this->size + 1  == this->capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    tempArray[idx] = x;
    for (int i = 0; i < idx; ++i) {
      tempArray[i] = this->data[i];
    }
    for (int i = idx; i < this->capacity; ++i) {
      tempArray[i+1] = this->data[i];
    }
    delete[] this->data;
    this->data = tempArray;
    this->capacity = newCapacity;
  }
  else {
    T* tempArray = new T[this->capacity];
    tempArray[idx] = x;
    for (int i = 0; i < idx; ++i) {
      tempArray[i] = this->data[i];
    }
    for (int i = idx; i < this->size + 1; ++i) {
      tempArray[i+1] = this->data[i];
    }
    delete[] this->data;
    this->data = tempArray;
  }
  ++this->size;
}
template <typename T>
void DynamicArray<T>::delete_(std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > this->size) {
    throw std::invalid_argument("Out of range");
  }
  T* tempArray = new T[this->capacity];
    for (int i = 0; i < idx; ++i) {
      tempArray[i] = this->data[i];
    }
    for (int i = idx + 1; i <= this->size; ++i) {
      tempArray[i-1] = this->data[i];
    }
    delete[] this->data;
    this->data = tempArray;
    --this->size;
}
template <typename T>
void DynamicArray<T>::erase_after(std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > this->size) {
    throw std::invalid_argument("Out of range");
  }
  // T* tempArray = new T[(idx+1)*2];
  // for (int i = 0; i <= idx; ++i) {
  //     tempArray[i] = this->data[i];
  //   }
  //   delete[] this->data;
  //   this->data = tempArray;
  //   this->capacity = (idx+1)*2;
  //   this->size = idx - 1;
  //
  //   ^ тоже рабочий вариант
  this->size = idx;
}
template <typename T>
void DynamicArray<T>::increase_capacity(std::int64_t x) {
  if (x <= this->capacity) {
    throw std::invalid_argument("Inappropriate argument");
  }
  T* tempArray = new T[x];
    for (int i = 0; i < this->size + 1; ++i) {
      tempArray[i] = this->data[i];
    }
    delete[] this->data;
    this->data = tempArray;
    this->capacity = x;
}
template <typename T>
void DynamicArray<T>::decrease_capacity(std::int64_t x) {
  if (x < 1) {
    throw std::invalid_argument("Inappropriate argument");
  }
  T* tempArray = new T[x];
  for (int i = 0; i < x ; ++i) {
    tempArray[i] = this->data[i];
  }
  delete[] this->data;
  this->data = tempArray;
  this->capacity = x;
  if (x <= this->size) {
    this->size = x - 1;
  }
}
template <typename T>
bool DynamicArray<T>::isFull() {
    return this->size + 1 == this->capacity;
}
template <typename T>
void DynamicArray<T>::delete_last() {
  if (isEmpty()) {
    throw std::invalid_argument("arr is empty");
  }
  size -= 1;
}
template <typename T>
int64_t DynamicArray<T>::getSize() {
  return this->size + 1;
}

#endif // DYN_ARR_H
