#ifndef LAB3_STACK_H
#define LAB3_STACK_H
#include "class.h"

// Класс стека
template <typename T>
class Stack {
private:
    LinkedList<T> list;

public:
    // Помещает элемент на вершину стека
    void push(const T& item) {
        list.push_back(item);
    }

    // Удаляет элемент с вершины стека и возвращает его
    T pop() {
        if (list.size() == 0) {
            throw std::runtime_error("Stack is empty!");
        }
        T item = list[list.size() - 1];
        list.pop_back();
        return item;
    }

    // Возвращает элемент с вершины стека без удаления
    T& top() {
        if (list.size() == 0) {
            throw std::runtime_error("Stack is empty!");
        }
        return (int &) list[list.size() - 1];
    }

    // Возвращает размер стека
    int size() const {
        return list.size();
    }

    // Проверяет, пустой ли стек
    bool isEmpty() const {
        return list.size() == 0;
    }

    // Печатает сам стек с конца
    void printReverse() const {
        for (int i = list.size() - 1; i >= 0; i--) {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif //LAB3_STACK_H
