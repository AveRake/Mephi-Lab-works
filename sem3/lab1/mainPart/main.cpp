#include "sequence.h"
#include <iostream>
#include <limits>


template<typename T>
void fillValue(T* item) {
    cout << "Enter the value" << endl;
    cout << ">>> ";
    cin >> (*item);
    cout << endl << endl;
}


void showMenu() {
    cout << " ------------------------------------------------------------" << endl;
    cout << "|Press 1 if you want add item for your sequence              |" << endl;
    cout << "|Press 2 if you want delete item from your sequence          |" << endl;
    cout << "|Press 3 if you want resize your sequence                    |" << endl;
    cout << "|Press 4 if you want to known the size of your sequence      |" << endl;
    cout << "|Press 5 if you want print your sequence                     |" << endl;
    cout << "|Press 6 if you want change type of data                     |" << endl;
    cout << "|Press 7 if you want change type of sequences                |" << endl;
    cout << "|Press 8 if you want get the item by index                   |" << endl;
    cout << "|Press 9 if you want set the item by index                   |" << endl;
    cout << "|Press 0 if you want exit the programme                      |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << ">>> ";
}

void showDataType() {
    cout << " ------------------------" << endl;
    cout << "|For type int press 1    |" << endl;
    cout << "|For type double press 2 |" << endl;
    cout << "|For type char press 3   |" << endl;
    cout << " ------------------------" << endl;
    cout << ">>> ";
}

void showSequencesType() {
    cout << " ---------------------------------------------------------------------" << endl;
    cout << "|Choose the sequences that you want to use for testing Smart Pointers |" << endl;
    cout << "|Press 1 for Dynamic Array                                            |" << endl;
    cout << "|Press 2 for Linked List                                              |" << endl;
    cout << " ---------------------------------------------------------------------" << endl;
    cout << ">>> ";
}


template<typename T, typename SequenceType>
void runSequence(SequenceType& sequence, int menuChoice, int* dataType, int* sequencesChoice) {
    switch (menuChoice) {
        case 1:
            T newItem;
            fillValue(&newItem);
            sequence.push_back(newItem);
            break;
        case 2:
            cout << "Operation pop back is done successfully" << endl << endl;
            sequence.pop_back();
            break;
        case 3:
            int newSize;
            fillValue(&newSize);
            sequence.resize(newSize);
            break;
        case 4:
            cout << "Size of your Sequence is " << sequence.getSize() << endl << endl;
            break;
        case 5:
            sequence.print();
            cout << endl;
            break;
        case 6:
            showDataType();
            cin >> *(dataType);
            cout << endl;

            if (*(dataType) != 1 && *(dataType) != 2 && *(dataType)!= 3) {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                showDataType();
                cin >> *(dataType);
                cout << endl;
            }

            while (sequence.getSize() != 0) {
                sequence.pop_back();
            }
            break;
        case 7:
            showSequencesType();
            cin >> *(sequencesChoice);
            cout << endl;

            if (*(sequencesChoice) != 1 && *(sequencesChoice) != 2) {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                showSequencesType();
                cin >> *(sequencesChoice);
                cout << endl;
            }

            while (sequence.getSize() != 0) {
                sequence.pop_back();
            }
            break;
        case 8:
            int index;
            fillValue(&index);
            sequence.getIndex(index);
            break;
        case 9:
            cout << "First is index!" << endl;
            fillValue(&index);
            cout << "Second is new item!" << endl;
            fillValue(&newItem);
            sequence.setIndex(newItem, index);
            break;
        case 0:
            cout << "exiting" << endl << endl;
            break;
        default:
            cout << "Wrong choice, try again\n" << endl;
            break;
    }
}


int main() {
    cout << "Welcome to the my programme about Smart Pointers" << endl;
    showSequencesType();
    int sequencesChoice;
    cin >> sequencesChoice;
    cout << endl;

    if (sequencesChoice != 1 && sequencesChoice != 2 && sequencesChoice != 3) {
        cout << "Wrong choice!" << endl;
        cout << "Try again" << endl;
        showSequencesType();
        cin >> sequencesChoice;
        cout << endl;
    }

    int menuChoice = 1;
    DynamicArray<int> intArray;
    DynamicArray<double> doubleArray;
    DynamicArray<char> charArray;
    LinkedList<int> intList;
    LinkedList<double> doubleList;
    LinkedList<char> charList;

    int dataType = 0;
    showDataType();
    cin >> dataType;
    cout << endl;

    if (dataType != 1 && dataType != 2 && dataType != 3) {
        cout << "Wrong choice!" << endl;
        cout << "Try again" << endl;
        showDataType();
        cin >> dataType;
        cout << endl;
    }

    while (menuChoice != 0) {
        showMenu();
        cin >> menuChoice;
        cout << endl;

        switch (dataType) {
            case 1:
                if (sequencesChoice == 1)
                    runSequence<int, DynamicArray<int>>(intArray, menuChoice, &dataType, &sequencesChoice);
                else if (sequencesChoice == 2)
                    runSequence<int, LinkedList<int>>(intList, menuChoice, &dataType, &sequencesChoice);
                break;
            case 2:
                if (sequencesChoice == 1)
                    runSequence<double, DynamicArray<double>>(doubleArray, menuChoice, &dataType, &sequencesChoice);
                else if (sequencesChoice == 2)
                    runSequence<double, LinkedList<double>>(doubleList, menuChoice, &dataType, &sequencesChoice);
                break;
            case 3:
                if (sequencesChoice == 1)
                    runSequence<char, DynamicArray<char>>(charArray, menuChoice, &dataType, &sequencesChoice);
                else if (sequencesChoice == 2)
                    runSequence<char, LinkedList<char>>(charList, menuChoice, &dataType, &sequencesChoice);
                break;
            default:
                break;
        }
    }

    cout << "Press any bottom to end the programme" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}