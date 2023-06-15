#ifndef LAB4_DETOURS_H
#define LAB4_DETOURS_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
Node<T>* insert(Node<T>* root, T value) {
    if (root == nullptr) {
        return new Node<T>(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

template <typename T>
void KLP(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    KLP(root->left);
    KLP(root->right);
}

template <typename T>
void KPL(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    KPL(root->right);
    KPL(root->left);
}

template <typename T>
void LPK(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    LPK(root->left);
    LPK(root->right);
    cout << root->data << " ";
}

template <typename T>
void LKP(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    LKP(root->left);
    cout << root->data << " ";
    LPK(root->right);
}


template <typename T>
void PLK(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    PLK(root->right);
    PLK(root->left);
    cout << root->data << " ";
}

template <typename T>
void PKL(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    PKL(root->right);
    cout << root->data << " ";
    PLK(root->left);
}

template <typename T, typename F>
Node<T>* map(Node<T>* root, F function) {
    if (root == nullptr) {
        return nullptr;
    }

    Node<T>* newNode = new Node<T>(function(root->data));
    newNode->left = map(root->left, function);
    newNode->right = map(root->right, function);

    return newNode;
}

template <typename T, typename Predicate>
Node<T>* where(Node<T>* root, Predicate condition) {
    if (root == nullptr) {
        return nullptr;
    }

    if (condition(root->data)) {
        Node<T>* newNode = new Node<T>(root->data);
        newNode->left = where(root->left, condition);
        newNode->right = where(root->right, condition);
        return newNode;
    } else {
        Node<T>* newLeft = where(root->left, condition);
        Node<T>* newRight = where(root->right, condition);
        if (newLeft == nullptr && newRight == nullptr) {
            return nullptr;
        }
        Node<T>* newNode = new Node<T>(root->data);
        newNode->left = newLeft;
        newNode->right = newRight;
        return newNode;
    }
}

#endif //LAB4_DETOURS_H
