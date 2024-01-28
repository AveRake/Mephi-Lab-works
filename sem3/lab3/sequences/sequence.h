#ifndef LAB3_SEQUENCE_H
#define LAB3_SEQUENCE_H

#include "smartPointer.h"


template <typename T>
class sequence {
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
class ListNode {
public:
    T data;
    SmrtPtr<ListNode<T>> next;

    explicit ListNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedListIterator {
public:
    SmrtPtr<ListNode<T>> current;

    explicit LinkedListIterator(SmrtPtr<ListNode<T>> ptr) : current(ptr) {}

    LinkedListIterator& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    bool operator!=(const LinkedListIterator& other) const {
        return current != other.current;
    }

    const T& operator*() const {
        return current->data;
    }

    T& operator*() {
        return current->data;
    }

    const T* operator->() const {
        return &(current->data);
    }

    T* operator->() {
        return &(current->data);
    }
};


template <typename T>
class LinkedList : public sequence<T> {
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

    SmrtPtr<ListNode<T>> getNodeAt(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }

        SmrtPtr<ListNode<T>> current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        return current;
    }

    SmrtPtr<ListNode<T>> getNodeAt(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }

        SmrtPtr<ListNode<T>> current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        return current;
    }

    SmrtPtr<ListNode<T>> getHead() const {
        return head;
    }

    LinkedListIterator<T> begin() const {
        return LinkedListIterator<T>(head);
    }

    LinkedListIterator<T> end() const {
        return LinkedListIterator<T>(SmrtPtr<ListNode<T>>(nullptr));
    }

    int getBinCount(T value) const {
        int count = 0;
        LinkedListIterator<T> iter = begin();
        while (iter != end()) {
            if (*iter == value) {
                count++;
            }
            ++iter;
        }
        return count;
    }

private:
    SmrtPtr<ListNode<T>> head;
    size_t size;
};

#endif //LAB3_SEQUENCE_H
