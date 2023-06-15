#ifndef LAB3_CLASS_H
#define LAB3_CLASS_H
#include <iostream>
#include <stdexcept>
using namespace std;

// Абстрактный класс для последовательности
template <typename T>
class Sequence {
public:
    virtual void push_back(const T& item) = 0;
    virtual void pop_back() = 0;
    virtual const T& operator[](int index) const = 0;
    virtual int size() const = 0;
    virtual Sequence<T>* copy() const = 0;
    virtual void resize(int new_size) = 0;
    virtual ~Sequence() {}
};

// Шаблонный класс для динамического массива
template <typename T>
class DynamicArray : public Sequence<T> {
private:
    T* arr;
    int capacity;
    int current_size;

public:
    DynamicArray() : arr(nullptr), capacity(0), current_size(0) {}

    void push_back(const T& item) override {
        if (current_size >= capacity) {
            int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            T* new_arr = new T[new_capacity];
            for (int i = 0; i < current_size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity = new_capacity;
        }
        arr[current_size] = item;
        current_size++;
    }

    void pop_back() override {
        if (current_size == 0) {
            throw std::out_of_range("Sequence is empty!");
        }
        current_size--;
    }

    T& operator[](int index) const override {
        if (index < 0 || index >= current_size) {
            throw std::out_of_range("Invalid index!");
        }
        return arr[index];
    }

    int size() const override {
        return current_size;
    }

    DynamicArray<T>* copy() const override {
        DynamicArray<T>* copy_arr = new DynamicArray<T>();
        for (int i = 0; i < current_size; i++) {
            copy_arr->push_back(arr[i]);
        }
        return copy_arr;
    }

    void resize(int new_size) override {
        if (new_size < 0) {
            throw std::invalid_argument("Invalid size!");
        }
        if (new_size < current_size) {
            current_size = new_size;
        } else if (new_size > current_size) {
            T* new_arr = new T[new_size];
            for (int i = 0; i < current_size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity = new_size;
            current_size = new_size;
        }
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

// Шаблонный класс для узла связанного списка
template <typename T>
struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(const T& item) : data(item), next(nullptr) {}
};

// Шаблонный класс для связанного списка
template <typename T>
class LinkedList : public Sequence<T> {
private:
    ListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void push_back(const T& item) override {
        ListNode<T>* new_node = new ListNode<T>(item);
        if (head == nullptr) {
            head = new_node;
        } else {
            ListNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void pop_back() override {
        if (head == nullptr) {
            throw std::out_of_range("Sequence is empty!");
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            ListNode<T>* current = head;
            ListNode<T>* prev = nullptr;
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }
            delete current;
            prev->next = nullptr;
        }
    }

    const T& operator[](int index) const override {
        if (index < 0) {
            throw std::out_of_range("Invalid index!");
        }
        ListNode<T>* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                throw std::out_of_range("Invalid index!");
            }
            current = current->next;
        }
        if (current == nullptr) {
            throw std::out_of_range("Invalid index!");
        }
        return current->data;
    }

    int size() const override {
        int count = 0;
        ListNode<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    LinkedList<T>* copy() const override {
        LinkedList<T>* copy_list = new LinkedList<T>();
        ListNode<T>* current = head;
        while (current != nullptr) {
            copy_list->push_back(current->data);
            current = current->next;
        }
        return copy_list;
    }

    void resize(int new_size) override {
        if (new_size < 0) {
            throw std::invalid_argument("Invalid size!");
        }
        int current_size = size();
        if (new_size < current_size) {
            ListNode<T>* current = head;
            ListNode<T>* prev = nullptr;
            for (int i = 0; i < new_size; i++) {
                prev = current;
                current = current->next;
            }
            if (prev == nullptr) {
                head = nullptr;
            } else {
                prev->next = nullptr;
            }
            while (current != nullptr) {
                ListNode<T>* temp = current;
                current = current->next;
                delete temp;
            }
        } else if (new_size > current_size) {
            ListNode<T>* current = head;
            ListNode<T>* prev = nullptr;
            for (int i = 0; i < current_size; i++) {
                prev = current;
                current = current->next;
            }
            for (int i = current_size; i < new_size; i++) {
                ListNode<T>* new_node = new ListNode<T>(T());
                if (prev == nullptr) {
                    head = new_node;
                } else {
                    prev->next = new_node;
                }
                prev = new_node;
            }
        }
    }

    ~LinkedList() {
        ListNode<T>* current = head;
        while (current != nullptr) {
            ListNode<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

#endif //LAB3_CLASS_H
