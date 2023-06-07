#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <memory>
#include <vector>

// Шаблон класса TreeNode для представления узлов дерева
template <typename T>
struct TreeNode {
    T data;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;

    explicit TreeNode(const T& value)
            : data(value), left(nullptr), right(nullptr) {}
};

// Шаблон класса Tree для представления абстрактного типа данных "дерево"
template <typename T>
class Tree {
private:
    std::shared_ptr<TreeNode<T>> root;

public:
    Tree() : root(nullptr) {}

    // Функция для вставки элемента в дерево
    void insert(const T& value) {
        auto newNode = std::make_shared<TreeNode<T>>(value);

        if (root == nullptr) {
            root = newNode;
        } else {
            std::shared_ptr<TreeNode<T>> currentNode = root;
            std::shared_ptr<TreeNode<T>> parentNode = nullptr;

            while (currentNode != nullptr) {
                parentNode = currentNode;
                if (value < currentNode->data) {
                    currentNode = currentNode->left;
                } else {
                    currentNode = currentNode->right;
                }
            }

            if (value < parentNode->data) {
                parentNode->left = newNode;
            } else {
                parentNode->right = newNode;
            }
        }
    }

    // Функция для обхода дерева в порядке КЛП (Корень-Лево-Право)
    void preorderTraversal(const std::shared_ptr<TreeNode<T>>& node, std::function<void(const T&)> visit) {
        if (node == nullptr) {
            return;
        }

        visit(node->data);
        preorderTraversal(node->left, visit);
        preorderTraversal(node->right, visit);
    }

    // Функция для обхода дерева в порядке КПЛ (Корень-Право-Лево)
    void inorderTraversal(const std::shared_ptr<TreeNode<T>>& node, std::function<void(const T&)> visit) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left, visit);
        visit(node->data);
        inorderTraversal(node->right, visit);
    }

    // Функция для обхода дерева в порядке ЛПК (Лево-Право-Корень)
    void postorderTraversal(const std::shared_ptr<TreeNode<T>>& node, std::function<void(const T&)> visit) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left, visit);
        postorderTraversal(node->right, visit);
        visit(node->data);
    }
};

// Функции посещения узлов для различных типов данных

// Для целых чисел
void visitInt(const int& value) {
    std::cout << value << " ";
}

// Для вещественных чисел
void visitDouble(const double& value) {
    std::cout << value << " ";
}

// Для комплексных чисел
void visitComplex(const std::complex<double>& value) {
    std::cout << value << " ";
}

// Для строк
void visitString(const std::string& value) {
    std::cout << value << " ";
}

int main() {
    int choice;
    std::cout << "Выберите тип данных для хранения в дереве:" << std::endl;
    std::cout << "1. Целые числа" << std::endl;
    std::cout << "2. Вещественные числа" << std::endl;
    std::cout << "3. Комплексные числа" << std::endl;
    std::cout << "4. Строки" << std::endl;
    std::cout << "Введите номер выбранного типа данных: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            Tree<int> tree;
            int value;
            char continueChoice;

            do {
                std::cout << "Введите целое число для добавления в дерево: ";
                std::cin >> value;
                tree.insert(value);

                std::cout << "Хотите добавить еще одно число? (y/n): ";
                std::cin >> continueChoice;
            } while (continueChoice == 'y');

            std::cout << "Обход дерева в порядке КЛП: ";
            tree.preorderTraversal(tree.getRoot(), visitInt);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке КПЛ: ";
            tree.inorderTraversal(tree.getRoot(), visitInt);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке ЛПК: ";
            tree.postorderTraversal(tree.getRoot(), visitInt);
            std::cout << std::endl;

            break;
        }
        case 2: {
            Tree<double> tree;
            double value;
            char continueChoice;

            do {
                std::cout << "Введите вещественное число для добавления в дерево: ";
                std::cin >> value;
                tree.insert(value);

                std::cout << "Хотите добавить еще одно число? (y/n): ";
                std::cin >> continueChoice;
            } while (continueChoice == 'y');

            std::cout << "Обход дерева в порядке КЛП: ";
            tree.preorderTraversal(tree.getRoot(), visitDouble);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке КПЛ: ";
            tree.inorderTraversal(tree.getRoot(), visitDouble);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке ЛПК: ";
            tree.postorderTraversal(tree.getRoot(), visitDouble);
            std::cout << std::endl;

            break;
        }
        case 3: {
            Tree<std::complex<double>> tree;
            double real, imag;
            char continueChoice;

            do {
                std::cout << "Введите вещественную часть комплексного числа: ";
                std::cin >> real;
                std::cout << "Введите мнимую часть комплексного числа: ";
                std::cin >> imag;
                tree.insert(std::complex<double>(real, imag));

                std::cout << "Хотите добавить еще одно комплексное число? (y/n): ";
                std::cin >> continueChoice;
            } while (continueChoice == 'y');

            std::cout << "Обход дерева в порядке КЛП: ";
            tree.preorderTraversal(tree.getRoot(), visitComplex);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке КПЛ: ";
            tree.inorderTraversal(tree.getRoot(), visitComplex);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке ЛПК: ";
            tree.postorderTraversal(tree.getRoot(), visitComplex);
            std::cout << std::endl;

            break;
        }
        case 4: {
            Tree<std::string> tree;
            std::string value;
            char continueChoice;

            do {
                std::cout << "Введите строку для добавления в дерево: ";
                std::cin >> value;
                tree.insert(value);

                std::cout << "Хотите добавить еще одну строку? (y/n): ";
                std::cin >> continueChoice;
            } while (continueChoice == 'y');

            std::cout << "Обход дерева в порядке КЛП: ";
            tree.preorderTraversal(tree.getRoot(), visitString);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке КПЛ: ";
            tree.inorderTraversal(tree.getRoot(), visitString);
            std::cout << std::endl;

            std::cout << "Обход дерева в порядке ЛПК: ";
            tree.postorderTraversal(tree.getRoot(), visitString);
            std::cout << std::endl;

            break;
        }
        default:
            std::cout << "Некорректный выбор." << std::endl;
    }

    return 0;
}
