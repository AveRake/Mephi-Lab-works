#ifndef LAB3_MY_MAP_H
#define LAB3_MY_MAP_H

#include <iostream>
#include <vector>


template <typename KeyType, typename ValueType>
class myMap {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType& k, const ValueType& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;
    int size;
    int uniqueKeys;

public:
    myMap() : head(nullptr), size(0), uniqueKeys(0) {}

    ~myMap() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const KeyType& key, const ValueType& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        ++size;
        ++uniqueKeys;
    }

    ValueType* find(const KeyType& key) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return &(current->value);
            }
            current = current->next;
        }
        return nullptr;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    [[nodiscard]] int getUniqueKeys() const {
        return uniqueKeys;
    }

    class iterator {
    private:
        Node* current;

    public:
        explicit iterator(Node* start) : current(start) {}

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        void operator++() {
            if (current != nullptr) {
                current = current->next;
            }
        }

        std::pair<const KeyType&, const ValueType&> operator*() const {
            return {current->key, current->value};
        }
    };

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }
};

#endif //LAB3_MY_MAP_H
