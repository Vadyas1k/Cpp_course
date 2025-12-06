#include "stack.h"
#include <iostream>
#include <vector>

// Тест для добавления элемента в стек
void testPush() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Test push: ";
    std::cout << stack.pop() << " ";  // Ожидаем 30
    std::cout << stack.pop() << " ";  // Ожидаем 20
    std::cout << stack.pop() << std::endl;  // Ожидаем 10
}

// Тест для извлечения элемента из стека
void testPop() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Test pop: ";
    std::cout << stack.pop() << " ";  // Ожидаем 3
    std::cout << stack.pop() << " ";  // Ожидаем 2
    std::cout << stack.pop() << std::endl;  // Ожидаем 1
}

// Тест для проверки пустоты стека (isEmpty)
void testIsEmpty() {
    Stack<int> stack;
    std::cout << "Test isEmpty (should be true initially): " << stack.isEmpty() << std::endl;

    stack.push(10);
    std::cout << "Test isEmpty (should be false after push): " << stack.isEmpty() << std::endl;

    stack.pop();
    std::cout << "Test isEmpty (should be true after pop): " << stack.isEmpty() << std::endl;
}

// Тест для получения верхнего элемента стека (top)
void testTop() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Test top: " << stack.top() << std::endl;  // Ожидаем 30
}

// Тест для метода сравнения стеков (operator==)
void testOperatorEquals() {
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    Stack<int> stack2;
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);

    std::cout << "Test operator==: ";
    if (stack1 == stack2) {
        std::cout << "Stacks are equal." << std::endl;
    } else {
        std::cout << "Stacks are not equal." << std::endl;
    }

    // Сделаем стеки не равными
    stack2.pop();
    std::cout << "Test operator== after pop: ";
    if (stack1 == stack2) {
        std::cout << "Stacks are equal." << std::endl;
    } else {
        std::cout << "Stacks are not equal." << std::endl;  // Ожидаем, что стеки не равны
    }
}

// Тест для присваивания через вектор (operator=)
void testOperatorAssign() {
    Stack<int> stack;
    std::vector<int> vec = {10, 20, 30};

    stack = vec;

    std::cout << "Test operator=: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";  // Ожидаем 30 20 10
    }
    std::cout << std::endl;
}

// Тест для добавления массива в стек (push_arr)
void testPushArr() {
    Stack<int> stack;
    int arr[] = {10, 20, 30};

    stack.push_arr(arr, 3);

    std::cout << "Test push_arr: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";  // Ожидаем 30 20 10
    }
    std::cout << std::endl;
}

// Тест для добавления вектора в стек (operator+=)
void testOperatorPlusEqual() {
    Stack<int> stack;
    std::vector<int> vec = {100, 200, 300};

    stack += vec;

    std::cout << "Test operator+=: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";  // Ожидаем 300 200 100
    }
    std::cout << std::endl;
}

// Тест для замены содержимого стека массивом (Replace_w_arr)
void testReplaceWithArr() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);

    int arr[] = {30, 40, 50};

    stack.Replace_w_arr(arr, 3);

    std::cout << "Test Replace_w_arr: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";  // Ожидаем 50 40 30
    }
    std::cout << std::endl;
}

// Тест для переинициализации стека (reinitialize)
void testReinitialize() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);

    stack.reinitialize();  // Очистка стека

    std::cout << "Test reinitialize: ";
    if (stack.isEmpty()) {
        std::cout << "Stack is empty after reinitialize" << std::endl;  // Ожидаем, что стек пуст
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }
}

// Тест для оставшейся ёмкости стека (remaining_capacity)
void testRemainingCapacity() {
    Stack<int> stack;

    std::cout << "Test remaining_capacity before push: " << stack.remaining_capacity() << std::endl;  // Ожидаем 64

    stack.push(10);
    stack.push(20);

    std::cout << "Test remaining_capacity after push: " << stack.remaining_capacity() << std::endl;  // Ожидаем 62
}

// Тест для очистки стека (clear)
void testClear() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);

    std::cout << "Test clear before: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";  // Ожидаем 20 10
    }
    std::cout << std::endl;

    stack.push(30);
    stack.push(40);

    stack.clear();

    std::cout << "Test clear after: ";
    if (stack.isEmpty()) {
        std::cout << "Stack is empty after clear" << std::endl;  // Ожидаем, что стек пуст
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }
}

// Тест для вывода данных из стека (printData)
void testPrintData() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Test printData: ";
    stack.printData();  // Ожидаем 30 20 10
}

int main() {
    testPush();
    testPop();
    testIsEmpty();
    testTop();
    testOperatorEquals();
    testOperatorAssign();
    testPushArr();
    testOperatorPlusEqual();
    testReplaceWithArr();
    testReinitialize();
    testRemainingCapacity();
    testClear();
    testPrintData();

    return 0;
}
