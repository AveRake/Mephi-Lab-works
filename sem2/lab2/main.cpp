#include "class.h"


int showMenu() {
    int choice;
    std::cout << "===== Menu =====\n";
    std::cout << "1. Add element\n";
    std::cout << "2. Remove element\n";
    std::cout << "3. Get element\n";
    std::cout << "4. Get size\n";
    std::cout << "5. Create DynamicArray\n";
    std::cout << "6. Create LinkedList\n";
    std::cout << "7. Copy sequence\n";
    std::cout << "8. Resize sequence\n";
    std::cout << "9. Print sequence\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    return choice;
}

template <typename T>
void addElement(Sequence<T>* sequence) {
    T item;
    std::cout << "Enter the element: ";
    std::cin >> item;
    sequence->push_back(item);
    std::cout << "Element added!\n";
}

template <typename T>
void removeElement(Sequence<T>* sequence) {
    try {
        sequence->pop_back();
        std::cout << "Element removed!\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

template <typename T>
void getElement(const Sequence<T>* sequence) {
    int index;
    std::cout << "Enter the index: ";
    std::cin >> index;

    try {
        const T& item = (*sequence)[index];
        std::cout << "Element at index " << index << ": " << item << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

template <typename T>
void getSize(const Sequence<T>* sequence) {
    int size = sequence->size();
    std::cout << "Size of the sequence: " << size << "\n";
}

template <typename T>
void copySequence(const Sequence<T>* sequence) {
    Sequence<T>* copy = sequence->copy();
    std::cout << "Sequence copied!\n";
    // Выполните необходимые действия с копией
    delete copy;
}

template <typename T>
void resizeSequence(Sequence<T>* sequence) {
    int new_size;
    std::cout << "Enter the new size: ";
    std::cin >> new_size;
    try {
        sequence->resize(new_size);
        std::cout << "Sequence resized!\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

template <typename T>
void printSequence(const Sequence<T>* sequence) {
    int size = sequence->size();
    std::cout << "Sequence: ";
    for (int i = 0; i < size; i++) {
        std::cout << (*sequence)[i] << " ";
    }
    std::cout << "\n";
}


int main() {
    Sequence<int>* sequence_int = nullptr;
    Sequence<double>* sequence_double = nullptr;
    Sequence<char>* sequence_char = nullptr;

    int dataTypeChoice;
    std::cout << "Choose the data type:\n";
    std::cout << "1. int\n";
    std::cout << "2. double\n";
    std::cout << "3. char\n";
    std::cout << "Choice: ";
    std::cin >> dataTypeChoice;

    switch (dataTypeChoice) {
        case 1:
            sequence_int = new DynamicArray<int>();
            break;
        case 2:
            sequence_double = new DynamicArray<double>();
            break;
        case 3:
            sequence_char = new DynamicArray<char>();
            break;
        default:
            std::cout << "Invalid data type choice!\n";
            return 0;
    }

    int choice;
    do {
        choice = showMenu();
        switch (choice) {
            case 1:
                if (dataTypeChoice == 1) {
                    addElement<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    addElement<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    addElement<char>(sequence_char);
                }
                break;
            case 2:
                if (dataTypeChoice == 1) {
                    removeElement<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    removeElement<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    removeElement<char>(sequence_char);
                }
                break;
            case 3:
                if (dataTypeChoice == 1) {
                    getElement<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    getElement<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    getElement<char>(sequence_char);
                }
                break;
            case 4:
                if (dataTypeChoice == 1) {
                    getSize<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    getSize<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    getSize<char>(sequence_char);
                }
                break;
            case 5:
                delete sequence_int;
                sequence_int = new DynamicArray<int>();
                std::cout << "DynamicArray created!\n";
                break;
            case 6:
                delete sequence_double;
                sequence_double = new LinkedList<double>();
                std::cout << "LinkedList created!\n";
                break;
            case 7:
                if (dataTypeChoice == 1) {
                    copySequence<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    copySequence<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    copySequence<char>(sequence_char);
                }
                break;
            case 8:
                if (dataTypeChoice == 1) {
                    resizeSequence<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    resizeSequence<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    resizeSequence<char>(sequence_char);
                }
                break;
            case 9:
                if (dataTypeChoice == 1) {
                    printSequence<int>(sequence_int);
                } else if (dataTypeChoice == 2) {
                    printSequence<double>(sequence_double);
                } else if (dataTypeChoice == 3) {
                    printSequence<char>(sequence_char);
                }
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);

    delete sequence_int;
    delete sequence_double;
    delete sequence_char;

    system("pause");

    return 0;
}
