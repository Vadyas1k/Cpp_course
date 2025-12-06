#ifndef QUEUE_H
#define QUEUE_H
#include "stack.h"
#include <cstdint>
#include <stdexcept>
template <typename T>

class Queue {
    private:
        Stack<T> in;
        Stack<T> out;
    public:
        Queue() = default;
        ~Queue() = default;
        void enqueue(T x);
        T dequeue();
        bool isEmpty();
        int64_t size();
        void push_arr(T* data, int64_t size);
        void Replace_w_arr(T* data, int64_t size);
        void operator=(std::vector<T>& data);  // присваивание через вектор
        void operator+=(std::vector<T>& data);  // добавление вектором
        void reinitialize();
        void clear();
        int64_t remaining_capacity();
        void printData();
};

template <typename T>
void Queue<T>::enqueue(T x) {
    in.push(x);
}
template <typename T>
T Queue<T>::dequeue() {
    if (out.isEmpty()) {
        while (!in.isEmpty()) {
            out.push(in.pop());
        }
    }
    return out.pop();
}
template <typename T>
bool Queue<T>::isEmpty() {
    return in.isEmpty() && out.isEmpty();
}
template <typename T>
int64_t Queue<T>::size() {
    return in.getSize() + out.getSize();
}
template <typename T>
void Queue<T>::reinitialize() {
    this->in.reinitialize();
    this->out.reinitialize();
}
template <typename T>
void Queue<T>::Replace_w_arr(T* data, int64_t size) {
    this->out.reinitialize();
    this->in.Replace_w_arr(data, size);
}
template <typename T>
void Queue<T>::operator=(std::vector<T>& data) {
    this->out.reinitialize();
    this->in = data;
}
template <typename T>
void Queue<T>::operator+=(std::vector<T>& data) {
    this->out.reinitialize();
    this->in += data;
}
template <typename T>
int64_t Queue<T>::remaining_capacity() {
    return this->in.remaining_capacity();
}
template <typename T>
void Queue<T>::clear() {
    in.clear();
    out.clear();
}
template <typename T>
void Queue<T>::push_arr(T* data, int64_t size) {
    in.push_arr(data, size);
}
template <typename T>
void Queue<T>::printData() {
    Stack<T> temp1 = out;
    Stack<T> temp2 = in;
    Stack<T> temp3;
    Stack<T> data;
    while (!temp2.isEmpty()) {
        data.push(temp2.pop());
    }
    while (!temp1.isEmpty()) {
        temp3.push(temp1.pop());
    }
    while (!temp3.isEmpty()) {
        data.push(temp3.pop());
    }
    data.printData(); // Да простят меня боги за этот код
}

#endif // QUEUE_H