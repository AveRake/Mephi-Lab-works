#ifndef SEM3LAB1_SEQUENCE_H
#define SEM3LAB1_SEQUENCE_H
#include "SmartPointer.h"


template <typename T>
class Sequence {
public:
    virtual void push_back(const T& item) = 0;
    virtual void pop_back() = 0;
    virtual int getSize() const = 0;
    virtual void resize(int newSize) = 0;
    virtual void print() const = 0;
};


template <typename T>
class DynamicArray : public Sequence<T> {
public:
    DynamicArray() {
        arraySize = 0;
        data = static_cast<const SmrtPtr<T>>(nullptr);
    }

    T& operator[](int index) const {
        if (index >= 0 && index < arraySize) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    void push_back(const T& item) override {
        SmrtPtr<T> newData(new T[arraySize + 1], arraySize + 1);
        for (int i = 0; i < arraySize; ++i) {
            newData[i] = data[i];
        }

        newData[arraySize] = item;

        data = newData;
        arraySize++;
    }

    void pop_back() override {
        if (arraySize > 0) {
            SmrtPtr<T> newData(new T[arraySize - 1], arraySize - 1);

            for (int i = 0; i < arraySize - 1; ++i) {
                newData[i] = data[i];
            }

            data = newData;
            arraySize--;
        }
    }

    int getSize() const override {
        return arraySize;
    }

    void print() const override {
        if (data) {
            cout << "DynamicArray:" << endl;
            for (int i = 0; i < arraySize; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        else {
            cout << "DynamicArray is empty" << endl;
        }
    }

    void resize(int newSize) override {
        if (newSize < 0) {
            cout << "Cannot resize to a negative size." << endl;
            return;
        }

        SmrtPtr<T> newData(new T[newSize], newSize);

        int minSize = (newSize < arraySize) ? newSize : arraySize;
        for (int i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }

        arraySize = newSize;
        data = newData;
    }

private:
    SmrtPtr<T> data;
    int arraySize;
};


template <typename T>
struct Node {
    T data;
    SmrtPtr<Node<T>> next;

    Node(const T& item) {
        data = item;
        next = static_cast<const SmrtPtr<Node<T>>>(nullptr);
    }
};


template <typename T>
class LinkedList : public Sequence<T> {
public:
    LinkedList() {
        head = SmrtPtr<Node<T>>(nullptr);
        size = 0;
    }

    void push_back(const T& item) override {
        SmrtPtr<Node<T>> newNode = SmrtPtr<Node<T>>(new Node<T>(item));
        if (!head) {
            head = newNode;
        }

        else {
            SmrtPtr<Node<T>> current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    void pop_back() override {
        if (!head) {
            cout << "Trying to pop from an empty list." << endl;
            return;
        }

        if (size == 1) {
            head = static_cast<const SmrtPtr<Node<T>>>(nullptr);
        }

        else {
            SmrtPtr<Node<T>> current = head;
            while (current->next && current->next->next) {
                current = current->next;
            }
            current->next = SmrtPtr<Node<T>>(nullptr);
        }

        size--;
    }

    void resize(int newSize) override {
        if (newSize < 0) {
            cout << "Cannot resize to a negative size." << endl;
            return;
        }

        while (size > newSize) {
            pop_back();
        }

        while (size < newSize) {
            push_back(T());
        }
    }

    int getSize() const override {
        return size;
    }

    void print() const override {
        SmrtPtr<Node<T>> current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    SmrtPtr<Node<T>> head;
    int size;
};


#endif //SEM3LAB1_SEQUENCE_H


