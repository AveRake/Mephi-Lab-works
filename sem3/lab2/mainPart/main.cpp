#include "Sequence.h"
#include "Sorting.h"
#include "SmartPointers.h"


void dataType() {
    cout << " ------------------------" << endl;
    cout << "|For type int press 1    |" << endl;
    cout << "|For type double press 2 |" << endl;
    cout << "|For type char press 3   |" << endl;
    cout << " ------------------------" << endl;
    cout << ">>> ";
}

void sequenceType() {
    cout << " ---------------------------------------------------------------------" << endl;
    cout << "|Choose the sequences that you want to use for testing Sorts methods  |" << endl;
    cout << "|Press 1 for Dynamic Array                                            |" << endl;
    cout << "|Press 2 for Linked List                                              |" << endl;
    cout << " ---------------------------------------------------------------------" << endl;
    cout << ">>> ";
}

void menu() {
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


int main() {
    cout << "Welcome to the programme about sorting methods" << endl;
    int sequenceChoice;
    sequenceType();
    cin >> sequenceChoice;
    cout << endl;

    if (sequenceChoice != 1 && sequenceChoice != 2) {
        cout << "Wrong type of sequences" <<endl;
        system("pause");
        exit(-1);
    }

    int dataChoice;
    dataType();
    cin >> dataChoice;
    cout << endl;

    if (dataChoice != 1 && dataChoice != 2 && dataChoice != 3) {
        cout << "Wrong type of sequences" <<endl;
        system("pause");
        exit(-1);
    }

    LinkedList<int> intList;
    LinkedList<double> doubleList;
    LinkedList<char> charList;
    DynamicArray<int> intArray;
    DynamicArray<double> doubleArray;
    DynamicArray<char> charArray;

    int menuChoice = 1;
    int item;
    double doubleItem;
    char charItem;
    int method;

    while (menuChoice != 0) {
        if (sequenceChoice == 1) {
            if (dataChoice == 1) {
                menu();
                cin >> menuChoice;
                cout << endl;
                switch (menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> item;
                        cout << endl << endl;
                        intArray.push_back(item);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        intArray.pop_back();
                        break;
                    case 3:
                        intArray.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (intArray.getSize() != 0) {
                            intArray.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (intArray.getSize() != 0) {
                            intArray.pop_back();
                        }
                        break;
                    case 6:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            bubbleSort(intArray);
                        else if (method == 2)
                            bubbleSort(intArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 7:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            insertionSort(intArray);
                        else if (method == 2)
                            insertionSort(intArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 8:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            mergeSort(intArray);
                        else if (method == 2)
                            mergeSort(intArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 9:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            shellSort(intArray);
                        else if (method == 2)
                            shellSort(intArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 10:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            heapSort(intArray);
                        else if (method == 2)
                            heapSort(intArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
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

            if (dataChoice == 2) {
                menu();
                cin >> menuChoice;
                cout << endl;
                switch (menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> doubleItem;
                        cout << endl << endl;
                        doubleArray.push_back(doubleItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        doubleArray.pop_back();
                        break;
                    case 3:
                        doubleArray.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (doubleArray.getSize() != 0) {
                            doubleArray.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (doubleArray.getSize() != 0) {
                            doubleArray.pop_back();
                        }
                        break;
                    case 6:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            bubbleSort(doubleArray);
                        else if (method == 2)
                            bubbleSort(doubleArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 7:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            insertionSort(doubleArray);
                        else if (method == 2)
                            insertionSort(doubleArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 8:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            mergeSort(doubleArray);
                        else if (method == 2)
                            mergeSort(doubleArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 9:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            shellSort(doubleArray);
                        else if (method == 2)
                            shellSort(doubleArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 10:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            heapSort(intArray);
                        else if (method == 2)
                            heapSort(intArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
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

            if (dataChoice == 3) {
                menu();
                cin >> menuChoice;
                cout << endl;
                switch (menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> charItem;
                        cout << endl << endl;
                        charArray.push_back(charItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        charArray.pop_back();
                        break;
                    case 3:
                        charArray.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (charArray.getSize() != 0) {
                            charArray.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (charArray.getSize() != 0) {
                            charArray.pop_back();
                        }
                        break;
                    case 6:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            bubbleSort(charArray);
                        else if (method == 2)
                            bubbleSort(charArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 7:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            insertionSort(charArray);
                        else if (method == 2)
                            insertionSort(charArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 8:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            mergeSort(charArray);
                        else if (method == 2)
                            mergeSort(charArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 9:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            shellSort(charArray);
                        else if (method == 2)
                            shellSort(charArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 10:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            heapSort(charArray);
                        else if (method == 2)
                            heapSort(charArray, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
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
        }


        if (sequenceChoice == 2) {
            if (dataChoice == 1) {
                menu();
                cin >> menuChoice;
                cout << endl;
                switch (menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> item;
                        cout << endl << endl;
                        intList.push_back(item);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        intList.pop_back();
                        break;
                    case 3:
                        intList.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (intList.getSize() != 0) {
                            intList.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (intList.getSize() != 0) {
                            intList.pop_back();
                        }
                        break;
                    case 6:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            bubbleSort(intList);
                        else if (method == 2)
                            bubbleSort(intList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 7:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            insertionSort(intList);
                        else if (method == 2)
                            insertionSort(intList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 8:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            mergeSort(intList);
                        else if (method == 2)
                            mergeSort(intList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 9:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            shellSort(intList);
                        else if (method == 2)
                            shellSort(intList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 10:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            heapSort(intList);
                        else if (method == 2)
                            heapSort(intList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
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

            if (dataChoice == 2) {
                menu();
                cin >> menuChoice;
                cout << endl;
                switch (menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> doubleItem;
                        cout << endl << endl;
                        doubleList.push_back(doubleItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        doubleList.pop_back();
                        break;
                    case 3:
                        doubleList.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (doubleList.getSize() != 0) {
                            doubleList.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (doubleList.getSize() != 0) {
                            doubleList.pop_back();
                        }
                        break;
                    case 6:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            bubbleSort(doubleList);
                        else if (method == 2)
                            bubbleSort(doubleList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 7:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            insertionSort(doubleList);
                        else if (method == 2)
                            insertionSort(doubleList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 8:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            mergeSort(doubleList);
                        else if (method == 2)
                            mergeSort(doubleList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 9:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            shellSort(doubleList);
                        else if (method == 2)
                            shellSort(doubleList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 10:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            heapSort(doubleList);
                        else if (method == 2)
                            heapSort(doubleList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
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

            if (dataChoice == 3) {
                menu();
                cin >> menuChoice;
                cout << endl;
                switch (menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> charItem;
                        cout << endl << endl;
                        charList.push_back(charItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        charList.pop_back();
                        break;
                    case 3:
                        charList.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (charList.getSize() != 0) {
                            charList.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (charList.getSize() != 0) {
                            charList.pop_back();
                        }
                        break;
                    case 6:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            bubbleSort(charList);
                        else if (method == 2)
                            bubbleSort(charList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 7:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            insertionSort(charList);
                        else if (method == 2)
                            insertionSort(charList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 8:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            mergeSort(charList);
                        else if (method == 2)
                            mergeSort(charList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 9:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            shellSort(charList);
                        else if (method == 2)
                            shellSort(charList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
                        }
                        break;
                    case 10:
                        cout << "How you want sorting your array?" << endl;
                        cout << "Press 1 for sort in ascending order" << endl;
                        cout << "Press 2 for sort descending" << endl;
                        cout << ">>> ";
                        cin >> method;
                        cout << endl;

                        if (method == 1)
                            heapSort(charList);
                        else if (method == 2)
                            heapSort(charList, false);
                        else {
                            cout << "Wrong choice!" << endl;
                            system("pause");
                            exit(-1);
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
        }
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}
