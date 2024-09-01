#include <iostream>

class Stack {
public:
    int array[10]; // Открытый целочисленный фиксированный массив длиной 10
    int length; // Открытое целочисленное значение для отслеживания длины стека

    // Конструктор по умолчанию
    Stack() : length(0) {}

    // Метод reset()
    void reset() {
        length = 0;
        for (int i = 0; i < 10; ++i) {
            array[i] = 0;
        }
    }

    // Метод push()
    bool push(int value) {
        if (length == 10) {
            return false; // Массив уже заполнен
        }
        array[length++] = value;
        return true;
    }

    // Метод pop()
    void pop() {
        if (length == 0) {
            std::cout << "Stack is empty!" << std::endl;
        }
        else {
            array[--length] = 0;
        }
    }

    // Метод print()
    void print() {
        std::cout << "( ";
        for (int i = 0; i < length; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}