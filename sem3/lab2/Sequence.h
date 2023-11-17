#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H
#include "SmartPointers.h"


template <typename T>
class Sequence {
public:
    // Modifiers
    virtual void push_back(const T& item) = 0;
    virtual void pop_back() = 0;
    [[maybe_unused]] virtual void resize(int newSize) = 0;
    [[maybe_unused]] virtual void setIndex(const T& item, int index) = 0;

    // Observers
    [[maybe_unused]] [[nodiscard]] virtual int getSize() const = 0;
    [[maybe_unused]] virtual void getIndex(int index) const = 0;
    [[maybe_unused]] virtual void print() const = 0;
};


template <typename T>
class DynamicArray : public Sequence<T>{
public:
    DynamicArray() {
        array = SmrtPtr<T[]>();
        arraySize = 0;
    }

    explicit DynamicArray(size_t size) : array(new T[size]) {
        arraySize = size;
    }

    T& operator[](size_t index) const {
        return array[index];
    }

    DynamicArray<T>& operator=(const DynamicArray<T>& other) {
        if (this != &other) {
            delete[] array;

            size_t size = other.size();
            array = new T[size];

            for (size_t i = 0; i < size; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    void push_back(const T& item) override {
        SmrtPtr<T[]> newData(new T[arraySize + 1]);
        for (int i = 0; i < arraySize; ++i) {
            newData[i] = array[i];
        }

        newData[arraySize] = item;

        array = newData;
        arraySize++;
    }

    void pop_back() override {
        if (arraySize > 0) {
            SmrtPtr<T[]> newData(new T[arraySize - 1]);

            for (int i = 0; i < arraySize - 1; ++i) {
                newData[i] = array[i];
            }

            array = newData;
            arraySize--;
        }
    }

    [[nodiscard]] int getSize() const override {
        return arraySize;
    }

    void print() const override {
        if (array) {
            cout << "DynamicArray:" << endl;
            for (int i = 0; i < arraySize; ++i) {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        else {
            cout << "DynamicArray is empty" << endl;
        }
    }

    void getIndex(int index) const override {
        if (array) {
            if (index < arraySize && index >= 0) {
                cout << "array[" << index << "] = ";
                cout << array[index] << endl;
            }
        }

        else {
            cout << "DynamicArray is empty" << endl;
        }
    }

    void setIndex(const T& item, int index) override {
        if (array) {
            if (index < arraySize && index >= 0) {
                array[index] = item;
            }
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

        SmrtPtr<T[]> newData(new T[newSize]);

        int minSize = (newSize < arraySize) ? newSize : arraySize;
        for (int i = 0; i < minSize; ++i) {
            newData[i] = array[i];
        }

        arraySize = newSize;
        array = newData;
    }

private:
    SmrtPtr<T[]> array;
    size_t arraySize;
};


template <typename T>
class ListNode {
public:
    T data;
    SmrtPtr<ListNode<T>> next;

    explicit ListNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList : public Sequence<T> {
    template <typename U>
    friend void bubbleSort(LinkedList<U>& list);
public:
    LinkedList() : head(nullptr), size(0) {}

    void push_back(const T& item) override {
        SmrtPtr<ListNode<T>> newNode = SmrtPtr<ListNode<T>>(new ListNode<T>(item));

        if (!head) {
            head = newNode;
        } else {
            SmrtPtr<ListNode<T>> current = head;
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
            head = static_cast<const SmrtPtr<ListNode<T>>>(nullptr);
        }

        else {
            SmrtPtr<ListNode<T>> current = head;
            while (current->next && current->next->next) {
                current = current->next;
            }
            current->next = SmrtPtr<ListNode<T>>(nullptr);
        }

        size--;
    }

    void getIndex(int index) const override {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        SmrtPtr<ListNode<T>> current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        cout << "linked list[" << index << "] = " << current->data << endl;
    }

    void setIndex(const T& item, int index) override {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        SmrtPtr<ListNode<T>> current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = item;
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

    [[nodiscard]] int getSize() const override {
        return size;
    }

    void print() const override {
        SmrtPtr<ListNode<T>> current = head;
        cout << "LinkedList:" << endl;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    SmrtPtr<ListNode<T>> head;
    size_t size;
};


#endif //LAB2_SEQUENCE_H
