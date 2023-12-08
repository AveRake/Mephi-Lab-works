#include "sequence.h"
#include "sorting.h"
#include "smartPointers.h"


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
    cout << "|Choose the sequences that you want to use for testing Sorts methods  |" << endl;
    cout << "|Press 1 for Dynamic Array                                            |" << endl;
    cout << "|Press 2 for Linked List                                              |" << endl;
    cout << " ---------------------------------------------------------------------" << endl;
    cout << ">>> ";
}

void showMenu() {
    cout << " ------------------------------------------------------------" << endl;
    cout << "|Press 1 if you want add item for your sequence              |" << endl;
    cout << "|Press 2 if you want delete item from your sequence          |" << endl;
    cout << "|Press 3 if you want print your sequence                     |" << endl;
    cout << "|Press 4 if you want change type of data                     |" << endl;
    cout << "|Press 5 if you want change type of sequences                |" << endl;
    cout << "|Press 6 if you want start bubble sorting                    |" << endl;
    cout << "|Press 7 if you want start insertion sorting                 |" << endl;
    cout << "|Press 8 if you want start merge sorting                     |" << endl;
    cout << "|Press 9 if you want start shell sorting                     |" << endl;
    cout << "|Press 10 if you want start heap sorting                     |" << endl;
    cout << "|Press 0 if you want exit the programme                      |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    cout << ">>> ";
}


void findWayOfSorting(int* method) {
    cout << "How you want sorting your array?" << endl;
    cout << "Press 1 for sort in ascending order" << endl;
    cout << "Press 2 for sort descending" << endl;
    cout << ">>> ";
    cin >> (*method);
    cout << endl;
}


template<typename T, typename SequenceType>
void runSequence(SequenceType& sequence, int menuChoice, int* dataType, int* sequencesChoice) {
    int method;
    switch (menuChoice) {
        case 1:
            T item;
            cout << "Enter the item that you want push_back" << endl;
            cout << ">>> ";
            cin >> item;
            cout << endl << endl;
            sequence.push_back(item);
            break;
        case 2:
            cout << "operation pop back is done successfully" << endl << endl;
            sequence.pop_back();
            break;
        case 3:
            sequence.print();
            cout << endl;
            break;
        case 4:
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

            while (sequence.getSize() != 0) {
                sequence.pop_back();
            }
            break;
        case 5:
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
        case 6:
            findWayOfSorting(&method);
            if (method == 1)
                bubbleSort(sequence);
            else if (method == 2)
                bubbleSort(sequence, false);
            else {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                findWayOfSorting(&method);
            }
            break;
        case 7:
            findWayOfSorting(&method);
            if (method == 1)
                insertionSort(sequence);
            else if (method == 2)
                insertionSort(sequence, false);
            else {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                findWayOfSorting(&method);
            }
            break;
        case 8:
            findWayOfSorting(&method);
            if (method == 1)
                mergeSort(sequence);
            else if (method == 2)
                mergeSort(sequence, false);
            else {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                findWayOfSorting(&method);
            }
            break;
        case 9:
            findWayOfSorting(&method);
            if (method == 1)
                shellSort(sequence);
            else if (method == 2)
                shellSort(sequence, false);
            else {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                findWayOfSorting(&method);
            }
            break;
        case 10:
            findWayOfSorting(&method);
            if (method == 1)
                heapSort(sequence);
            else if (method == 2)
                heapSort(sequence, false);
            else {
                cout << "Wrong choice!" << endl;
                cout << "Try again" << endl;
                findWayOfSorting(&method);
            }
            break;
        case 0:
            cout << "exiting" << endl << endl;
            menuChoice = 0;
            break;
        default:
            cout << "Wrong choice, try again\n" << endl;
            break;
    }
}


int main() {
    cout << "Welcome to the programme about sorting methods" << endl;
    int sequencesChoice;
    showSequencesType();
    cin >> sequencesChoice;
    cout << endl;

    if (sequencesChoice != 1 && sequencesChoice != 2) {
        cout << "Wrong type of sequences" <<endl;
        cout << "Try again!" << endl;
        showSequencesType();
        cin >> sequencesChoice;
        cout << endl;
    }

    int dataType;
    showDataType();
    cin >> dataType;
    cout << endl;

    if (dataType != 1 && dataType != 2 && dataType != 3) {
        cout << "Wrong type of sequences" <<endl;
        cout << "Try again!" << endl;
        showDataType();
        cin >> dataType;
        cout << endl;
    }

    int menuChoice = 1;
    LinkedList<int> intList;
    LinkedList<double> doubleList;
    LinkedList<char> charList;
    DynamicArray<int> intArray;
    DynamicArray<double> doubleArray;
    DynamicArray<char> charArray;

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

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}
