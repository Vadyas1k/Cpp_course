#ifndef STACK_H
#define STACK_H
#include "dyn_arr.h"
#include <cstdint>
#include <stdexcept>
#include <vector>
template <typename T>

class Stack {
    private:
        DynamicArray<T> a;
        int64_t max_size = 64;
    public:
        Stack();
        void push(T x);
        T top();
        T pop();
        bool isEmpty();
        void push_arr(T* data, int64_t size);
        void operator+=(std::vector<T>& data);  // добавление вектором
        int64_t getSize();
        bool operator==(Stack& other);  // сравнение 2 стеков
        void Replace_w_arr(T* data, int64_t size);
        void operator=(std::vector<T>& data);  // присваивание через вектор
        void reinitialize();
        void clear();
        int64_t remaining_capacity();
        void printData();
        ~Stack() = default;
};




template <typename T>
Stack<T>::Stack() {
    a.increase_capacity(this->max_size);
}
template <typename T>
void Stack<T>::push(T x) {
    if (a.isFull()) {
        throw std::overflow_error("stack overflow");
    }
    a.push_back(x);
}
template <typename T>
T Stack<T>::top() {
    return a.back();
}
template <typename T>
T Stack<T>::pop() {
    T temp = a.back();
    a.delete_last();
    return temp;
}
template <typename T>
bool Stack<T>::isEmpty() {
    return a.isEmpty();
}
template <typename T>
int64_t Stack<T>::getSize() {
    return a.getSize();
}
template <typename T>
bool Stack<T>::operator==(Stack& other) {
    if (this->getSize() != other.getSize()) {
        return false;
    }
    Stack temp1 = *this;
    Stack temp2 = other;
    while (!temp1.isEmpty()) {
        if (!(temp1.pop() == temp2.pop())) {
            return false;
        }
    }
    return true;
}
template <typename T>
void Stack<T>::Replace_w_arr(T* data, int64_t size) {
    if (size > this->max_size) {
        throw std::overflow_error("overflow");
    }
    a.reinitialize();
    for (int i = 0; i < size; ++i) {
        this->push(data[i]);
    }
    
}
template <typename T>
void Stack<T>::operator=(std::vector<T>& data) {
    if (data.size() > this->max_size) {
        throw std::overflow_error("overflow");
    }
    while (!this->isEmpty()) {
        this->pop();
    }
    for (int i = 0; i < data.size(); ++i) {
        this->push(data[i]);
    }
}
template <typename T>
void Stack<T>::push_arr(T* data, int64_t size) {
    if (size + this->getSize() > this->max_size) {
        throw std::overflow_error("overflow");
    }
    for (int i = 0; i < size; ++i) {
        this->push(data[i]);
    }
}
template <typename T>
void Stack<T>::operator+=(std::vector<T>& data) {
    if (data.size() + this->getSize() > this->max_size) {
        throw std::overflow_error("overflow");
    }
    for (int i = 0; i < data.size(); ++i) {
        this->push(data[i]);
    }
}
template <typename T>
void Stack<T>::reinitialize() {
    a.reinitialize();
}
template <typename T>
int64_t Stack<T>::remaining_capacity() {
    return this->max_size - this->getSize();
}
template <typename T>
void Stack<T>::clear() {
    a.clear();
}
template <typename T>
void Stack<T>::printData() {
    DynamicArray<T> temp = a;
    DynamicArray<T> data;
    while (!temp.isEmpty()) {
        data.push_back(temp.back());
        temp.delete_last();
    }
    data.printData();
}


#endif // STACK_H