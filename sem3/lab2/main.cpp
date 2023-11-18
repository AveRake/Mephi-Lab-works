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

    LinkedList<int> list1;
    LinkedList<double> list2;
    LinkedList<char> list3;
    DynamicArray<int> array1;
    DynamicArray<double> array2;
    DynamicArray<char> array3;

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
                        array1.push_back(item);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        array1.pop_back();
                        break;
                    case 3:
                        array1.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (array1.getSize() != 0) {
                            array1.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (array1.getSize() != 0) {
                            array1.pop_back();
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
                            bubbleSort(array1);
                        else if (method == 2)
                            bubbleSort(array1, false);
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
                            insertionSort(array1);
                        else if (method == 2)
                            insertionSort(array1, false);
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
                            mergeSort(array1);
                        else if (method == 2)
                            mergeSort(array1, false);
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
                            shellSort(array1);
                        else if (method == 2)
                            shellSort(array1, false);
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
                            heapSort(array1);
                        else if (method == 2)
                            heapSort(array1, false);
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
                        array2.push_back(doubleItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        array2.pop_back();
                        break;
                    case 3:
                        array2.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (array2.getSize() != 0) {
                            array2.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (array2.getSize() != 0) {
                            array2.pop_back();
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
                            bubbleSort(array2);
                        else if (method == 2)
                            bubbleSort(array2, false);
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
                            insertionSort(array2);
                        else if (method == 2)
                            insertionSort(array2, false);
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
                            mergeSort(array2);
                        else if (method == 2)
                            mergeSort(array2, false);
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
                            shellSort(array2);
                        else if (method == 2)
                            shellSort(array2, false);
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
                            heapSort(array1);
                        else if (method == 2)
                            heapSort(array1, false);
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
                        array3.push_back(charItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        array3.pop_back();
                        break;
                    case 3:
                        array3.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (array3.getSize() != 0) {
                            array3.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (array3.getSize() != 0) {
                            array3.pop_back();
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
                            bubbleSort(array3);
                        else if (method == 2)
                            bubbleSort(array3, false);
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
                            insertionSort(array3);
                        else if (method == 2)
                            insertionSort(array3, false);
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
                            mergeSort(array3);
                        else if (method == 2)
                            mergeSort(array3, false);
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
                            shellSort(array3);
                        else if (method == 2)
                            shellSort(array3, false);
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
                            heapSort(array3);
                        else if (method == 2)
                            heapSort(array3, false);
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
                        list1.push_back(item);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        list1.pop_back();
                        break;
                    case 3:
                        list1.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (list1.getSize() != 0) {
                            list1.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (list1.getSize() != 0) {
                            list1.pop_back();
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
                            bubbleSort(list1);
                        else if (method == 2)
                            bubbleSort(list1, false);
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
                            insertionSort(list1);
                        else if (method == 2)
                            insertionSort(list1, false);
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
                            mergeSort(list1);
                        else if (method == 2)
                            mergeSort(list1, false);
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
                            shellSort(list1);
                        else if (method == 2)
                            shellSort(list1, false);
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
                            heapSort(list1);
                        else if (method == 2)
                            heapSort(list1, false);
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
                        list2.push_back(doubleItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        list2.pop_back();
                        break;
                    case 3:
                        list2.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (list2.getSize() != 0) {
                            list2.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (list2.getSize() != 0) {
                            list2.pop_back();
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
                            bubbleSort(list2);
                        else if (method == 2)
                            bubbleSort(list2, false);
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
                            insertionSort(list2);
                        else if (method == 2)
                            insertionSort(list2, false);
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
                            mergeSort(list2);
                        else if (method == 2)
                            mergeSort(list2, false);
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
                            shellSort(list2);
                        else if (method == 2)
                            shellSort(list2, false);
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
                            heapSort(list2);
                        else if (method == 2)
                            heapSort(list2, false);
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
                        list3.push_back(charItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        list3.pop_back();
                        break;
                    case 3:
                        list3.print();
                        cout << endl;
                        break;
                    case 4:
                        dataType();
                        cin >> dataChoice;
                        cout << endl;
                        while (list3.getSize() != 0) {
                            list3.pop_back();
                        }
                        break;
                    case 5:
                        sequenceType();
                        cin >> sequenceChoice;
                        cout << endl;
                        while (list3.getSize() != 0) {
                            list3.pop_back();
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
                            bubbleSort(list3);
                        else if (method == 2)
                            bubbleSort(list3, false);
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
                            insertionSort(list3);
                        else if (method == 2)
                            insertionSort(list3, false);
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
                            mergeSort(list3);
                        else if (method == 2)
                            mergeSort(list3, false);
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
                            shellSort(list3);
                        else if (method == 2)
                            shellSort(list3, false);
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
                            heapSort(list3);
                        else if (method == 2)
                            heapSort(list3, false);
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

    system("pause");
    return 0;
}
