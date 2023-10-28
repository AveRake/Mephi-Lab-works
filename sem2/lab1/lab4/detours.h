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

template <typename T>
Node<T>* merge(Node<T>* root1, Node<T>* root2) {
    if (root1 == nullptr) {
        return root2;
    }
    if (root2 == nullptr) {
        return root1;
    }

    Node<T>* mergedRoot = new Node<T>(root1->data);
    mergedRoot->left = merge(root1->left, root2->left);
    mergedRoot->right = merge(root1->right, root2->right);

    return mergedRoot;
}

template <typename T>
Node<T>* extractSubtree(Node<T>* root, T value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == value) {
        Node<T>* newRoot = new Node<T>(root->data);
        newRoot->left = root->left;
        newRoot->right = root->right;
        return newRoot;
    }

    if (value < root->data) {
        return extractSubtree(root->left, value);
    } else {
        return extractSubtree(root->right, value);
    }
}

template <typename T>
bool contains(Node<T>* root, T value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return contains(root->left, value);
    } else {
        return contains(root->right, value);
    }
}

int multiplyByTwo(int value) {
    return value * 2;
}

double multiplyByTwoDouble(double value) {
    return value * 2;
}

char charToNextAscii(char c) {
    return c + 1;
}

string reverseString(const string& str) {
    string result = str;
    reverse(result.begin(), result.end());
    return result;
}

#endif //LAB4_DETOURS_H
