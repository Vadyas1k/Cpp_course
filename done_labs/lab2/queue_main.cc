#include "queue.h"
#include <iostream>
#include <vector>

// Тест для добавления элементов в очередь (enqueue)
void testEnqueue() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Test enqueue and dequeue: ";
    std::cout << queue.dequeue() << " ";  // Ожидаем 10
    std::cout << queue.dequeue() << " ";  // Ожидаем 20
    std::cout << queue.dequeue() << std::endl;  // Ожидаем 30
}

// Тест для проверки пустоты очереди (isEmpty)
void testIsEmpty() {
    Queue<int> queue;
    std::cout << "Test isEmpty (should be true initially): " << queue.isEmpty() << std::endl;

    queue.enqueue(10);
    std::cout << "Test isEmpty (should be false after enqueue): " << queue.isEmpty() << std::endl;

    queue.dequeue();
    std::cout << "Test isEmpty (should be true after dequeue): " << queue.isEmpty() << std::endl;
}

// Тест для вычисления размера очереди (size)
void testSize() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Test size: " << queue.size() << std::endl;  // Ожидаем 3

    queue.dequeue();
    std::cout << "Test size after dequeue: " << queue.size() << std::endl;  // Ожидаем 2
}

// Тест для оператора присваивания (operator=) с вектором
void testOperatorAssign() {
    Queue<int> queue;
    std::vector<int> vec = {10, 20, 30};

    queue = vec;

    std::cout << "Test operator=: ";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";  // Ожидаем 10 20 30
    }
    std::cout << std::endl;
}

// Тест для оператора добавления элементов из вектора (operator+=)
void testOperatorPlusEqual() {
    Queue<int> queue;
    std::vector<int> vec = {100, 200, 300};

    queue += vec;

    std::cout << "Test operator+=: ";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";  // Ожидаем 100 200 300
    }
    std::cout << std::endl;
}

// Тест для замены содержимого очереди на новый массив (Replace_w_arr)
void testReplaceWithArr() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);

    int arr[] = {30, 40, 50};

    queue.Replace_w_arr(arr, 3);

    std::cout << "Test Replace_w_arr: ";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";  // Ожидаем 30 40 50
    }
    std::cout << std::endl;
}

// Тест для метода reinitialize
void testReinitialize() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);

    queue.reinitialize();  // Очистка очереди

    std::cout << "Test reinitialize: ";
    if (queue.isEmpty()) {
        std::cout << "Queue is empty after reinitialize" << std::endl;  // Ожидаем, что очередь пуста
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }
}

// Тест для метода remaining_capacity
void testRemainingCapacity() {
    Queue<int> queue;

    std::cout << "Test remaining_capacity before enqueue: " << queue.remaining_capacity() << std::endl;  // Ожидаем 64

    queue.enqueue(10);
    queue.enqueue(20);

    std::cout << "Test remaining_capacity after enqueue: " << queue.remaining_capacity() << std::endl;  // Ожидаем 62
}

// Тест для метода clear
void testClear() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);

    std::cout << "Test clear before: ";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";  // Ожидаем 10 20
    }
    std::cout << std::endl;

    queue.enqueue(30);
    queue.enqueue(40);

    queue.clear();

    std::cout << "Test clear after: ";
    if (queue.isEmpty()) {
        std::cout << "Queue is empty after clear" << std::endl;  // Ожидаем, что очередь пуста
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }
}

// Тест для вывода данных из очереди (printData)
void testPrintData() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Test printData: ";
    queue.printData();  // Ожидаем: 10 20 30

    queue.dequeue();

    std::cout << "Test printData after dequeue: ";
    queue.printData();  // Ожидаем: 20 30
}
// Тест для добавления массива в очередь (push_arr)
void testPushArr() {
    Queue<int> queue;
    int arr[] = {10, 20, 30};

    queue.push_arr(arr, 3);  // Добавляем массив в очередь

    std::cout << "Test push_arr: ";
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";  // Ожидаем 10 20 30
    }
    std::cout << std::endl;
}


int main() {
    testEnqueue();
    testIsEmpty();
    testSize();
    testOperatorAssign();
    testOperatorPlusEqual();
    testReplaceWithArr();
    testReinitialize();
    testRemainingCapacity();
    testClear();
    testPrintData();
    testPushArr();

    return 0;
}
