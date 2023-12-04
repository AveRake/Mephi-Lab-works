#include "sequence.h"
#include <iostream>
#include <limits>


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


template<typename T>
void runArray(DynamicArray<T>& arr, int menuChoice, int* dataType, int* sequencesChoice) {
    switch (menuChoice) {
        case 1:
            T newItem;
            cout << "Enter the item that you want push_back" << endl;
            cout << ">>> ";
            cin >> newItem;
            cout << endl << endl;
            arr.push_back(newItem);
            break;
        case 2:
            cout << "Operation pop back is done successfully" << endl << endl;
            arr.pop_back();
            break;
        case 3:
            int newSize;
            cout << "Enter newSize for your Sequence" << endl;
            cout << ">>> ";
            cin >> newSize;
            cout << endl << endl;
            arr.resize(newSize);
            break;
        case 4:
            cout << "Size of your Sequence is " << arr.getSize() << endl << endl;
            break;
        case 5:
            arr.print();
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

            while (arr.getSize() != 0) {
                arr.pop_back();
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

            while (arr.getSize() != 0) {
                arr.pop_back();
            }
            break;
        case 8:
            int index;
            cout << "Enter the number of index" << endl;
            cout << ">>> ";
            cin >> index;
            cout << endl;
            arr.getIndex(index);
            break;
        case 9:
            T item;
            cout << "Enter the number of index" << endl;
            cout << ">>> ";
            cin >> index;
            cout << endl;

            cout << "Enter the item" << endl;
            cout << ">>> ";
            cin >> item;
            cout << endl;

            arr.setIndex(item, index);
            break;
        case 0:
            cout << "exiting" << endl << endl;
            break;
        default:
            cout << "Wrong choice, try again\n" << endl;
            break;
    }
}


template<typename T>
void runList(LinkedList<T>& list, int menuChoice, int* dataType, int* sequencesChoice) {
    switch (menuChoice) {
        case 1:
            T newItem;
            cout << "Enter the item that you want push_back" << endl;
            cout << ">>> ";
            cin >> newItem;
            cout << endl << endl;
            list.push_back(newItem);
            break;
        case 2:
            cout << "Operation pop back is done successfully" << endl << endl;
            list.pop_back();
            break;
        case 3:
            int newSize;
            cout << "Enter newSize for your Sequence" << endl;
            cout << ">>> ";
            cin >> newSize;
            cout << endl << endl;
            list.resize(newSize);
            break;
        case 4:
            cout << "Size of your Sequence is " << list.getSize() << endl << endl;
            break;
        case 5:
            list.print();
            cout << endl;
            break;
        case 6:
            showDataType();
            cin >> *(dataType);
            cout << endl;

            if (*(dataType) != 1 && *(dataType) != 2 && *(dataType) != 3) {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                showDataType();
                cin >> *(dataType);
                cout << endl;
            }

            while (list.getSize() != 0) {
                list.pop_back();
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

            while (list.getSize() != 0) {
                list.pop_back();
            }
            break;
        case 8:
            int index;
            cout << "Enter the number of index" << endl;
            cout << ">>> ";
            cin >> index;
            cout << endl;
            list.getIndex(index);
            break;
        case 9:
            T item;
            cout << "Enter the number of index" << endl;
            cout << ">>> ";
            cin >> index;
            cout << endl;

            cout << "Enter the item" << endl;
            cout << ">>> ";
            cin >> item;
            cout << endl;

            list.setIndex(item, index);
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
                    runArray(intArray, menuChoice, &dataType, &sequencesChoice);
                else if (sequencesChoice == 2)
                    runList(intList, menuChoice, &dataType, &sequencesChoice);
                break;
            case 2:
                if (sequencesChoice == 1)
                    runArray(doubleArray, menuChoice, &dataType, &sequencesChoice);
                else if (sequencesChoice == 2)
                    runList(doubleList, menuChoice, &dataType, &sequencesChoice);
                break;
            case 3:
                if (sequencesChoice == 1)
                    runArray(charArray, menuChoice, &dataType, &sequencesChoice);
                else if (sequencesChoice == 2)
                    runList(charList, menuChoice, &dataType, &sequencesChoice);
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