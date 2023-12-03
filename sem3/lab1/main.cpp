#include "SmartPointer.h"
#include "Sequence.h"
#include "Benchmark.h"


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
    cout << "|Press 3 to start Benchmark                                           |" << endl;
    cout << " ---------------------------------------------------------------------" << endl;
    cout << ">>> ";
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

    if (sequencesChoice == 3) {
        int benchChoice = 1;

        while (benchChoice != 0) {
            cout << "Benchmark starting" << endl;
            Benchmark();
            cout << endl;

            cout << "Would you like to continue testing?" << endl;
            cout << "If yes - press 1, if not - press 0" << endl;
            cout << ">>> ";
            cin >> benchChoice;
            cout << endl;

            if (benchChoice != 1 && benchChoice != 0) {
                cout << "Please try again" << endl;
                cout << ">>> ";
                cin >> benchChoice;
                cout << endl;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 0;
    }

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

    int menuChoice = 1;
    int newSize;
    int index;
    int item;
    double doubleItem;
    char charItem;
    DynamicArray<int> dynamicArray;
    DynamicArray<double> dynamicArrayDouble;
    DynamicArray<char> dynamicArrayChar;
    LinkedList<int> linkedList;
    LinkedList<double> linkedListDouble;
    LinkedList<char> linkedListChar;

    while (menuChoice != 0) {
        if (sequencesChoice == 1) {
            if (dataType == 1) {
                showMenu();
                cin >> menuChoice;
                cout << endl;
                switch(menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> item;
                        cout << endl << endl;
                        dynamicArray.push_back(item);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        dynamicArray.pop_back();
                        break;
                    case 3:
                        cout << "Enter newSize for your Dynamic Array" << endl;
                        cout << ">>> ";
                        cin >> newSize;
                        cout << endl << endl;
                        dynamicArray.resize(newSize);
                        break;
                    case 4:
                        cout << "Size of your Dynamic Array is ";
                        cout << dynamicArray.getSize() << endl << endl;
                        break;
                    case 5:
                        dynamicArray.print();
                        cout << endl;
                        break;
                    case 6:
                        showDataType();
                        cin >> dataType;
                        cout << endl;
                        while (dynamicArray.getSize() != 0) {
                            dynamicArray.pop_back();
                        }
                        break;
                    case 7:
                        showSequencesType();
                        cin >> sequencesChoice;
                        cout << endl;
                        while (dynamicArray.getSize() != 0) {
                            dynamicArray.pop_back();
                        }
                        break;
                    case 8:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;
                        dynamicArray.getIndex(index);
                        break;
                    case 9:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;

                        cout << "Enter the item" << endl;
                        cout << ">>> ";
                        cin >> item;
                        cout << endl;
                        dynamicArray.setIndex(item, index);
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

            if (dataType == 2) {
                showMenu();
                cin >> menuChoice;
                cout << endl;
                switch(menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> doubleItem;
                        cout << endl << endl;
                        dynamicArrayDouble.push_back(doubleItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        dynamicArrayDouble.pop_back();
                        break;
                    case 3:
                        cout << "Enter newSize for your Dynamic Array" << endl;
                        cout << ">>> ";
                        cin >> newSize;
                        cout << endl << endl;
                        dynamicArrayDouble.resize(newSize);
                        break;
                    case 4:
                        cout << "Size of your Dynamic Array is ";
                        cout << dynamicArrayDouble.getSize() << endl << endl;
                        break;
                    case 5:
                        dynamicArrayDouble.print();
                        cout << endl;
                        break;
                    case 6:
                        showDataType();
                        cin >> dataType;
                        cout << endl;
                        while (dynamicArrayDouble.getSize() != 0) {
                            dynamicArrayDouble.pop_back();
                        }
                        break;
                    case 7:
                        showSequencesType();
                        cin >> sequencesChoice;
                        cout << endl;
                        while (dynamicArrayDouble.getSize() != 0) {
                            dynamicArrayDouble.pop_back();
                        }
                        break;
                    case 8:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;
                        dynamicArrayDouble.getIndex(index);
                        break;
                    case 9:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;

                        cout << "Enter the item" << endl;
                        cout << ">>> ";
                        cin >> doubleItem;
                        cout << endl;
                        dynamicArrayDouble.setIndex(doubleItem, index);
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

            if (dataType == 3) {
                showMenu();
                cin >> menuChoice;
                cout << endl;
                switch(menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> charItem;
                        cout << endl << endl;
                        dynamicArrayChar.push_back(charItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        dynamicArrayChar.pop_back();
                        break;
                    case 3:
                        cout << "Enter newSize for your Dynamic Array" << endl;
                        cout << ">>> ";
                        cin >> newSize;
                        cout << endl << endl;
                        dynamicArrayChar.resize(newSize);
                        break;
                    case 4:
                        cout << "Size of your Dynamic Array is ";
                        cout << dynamicArrayChar.getSize() << endl << endl;
                        break;
                    case 5:
                        dynamicArrayChar.print();
                        cout << endl;
                        break;
                    case 6:
                        showDataType();
                        cin >> dataType;
                        cout << endl;
                        while (dynamicArrayChar.getSize() != 0) {
                            dynamicArrayChar.pop_back();
                        }
                        break;
                    case 7:
                        showSequencesType();
                        cin >> sequencesChoice;
                        cout << endl;
                        while (dynamicArrayChar.getSize() != 0) {
                            dynamicArrayChar.pop_back();
                        }
                        break;
                    case 8:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;
                        dynamicArrayChar.getIndex(index);
                        break;
                    case 9:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;

                        cout << "Enter the item" << endl;
                        cout << ">>> ";
                        cin >> charItem;
                        cout << endl;
                        dynamicArrayChar.setIndex(charItem, index);
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

        if (sequencesChoice == 2) {
            if (dataType == 1) {
                showMenu();
                cin >> menuChoice;
                cout << endl;
                switch(menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> item;
                        cout << endl << endl;
                        linkedList.push_back(item);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        linkedList.pop_back();
                        break;
                    case 3:
                        cout << "Enter newSize for your Linked List" << endl;
                        cout << ">>> ";
                        cin >> newSize;
                        cout << endl << endl;
                        linkedList.resize(newSize);
                        break;
                    case 4:
                        cout << "Size of your Linked List is ";
                        cout << linkedList.getSize() << endl << endl;
                        break;
                    case 5:
                        linkedList.print();
                        cout << endl;
                        break;
                    case 6:
                        showDataType();
                        cin >> dataType;
                        cout << endl;
                        while (linkedList.getSize() != 0) {
                            linkedList.pop_back();
                        }
                        break;
                    case 7:
                        showSequencesType();
                        cin >> sequencesChoice;
                        cout << endl;
                        while (linkedList.getSize() != 0) {
                            linkedList.pop_back();
                        }
                        break;
                    case 8:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;
                        linkedList.getIndex(index);
                        break;
                    case 9:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;

                        cout << "Enter the item" << endl;
                        cout << ">>> ";
                        cin >> item;
                        cout << endl;
                        linkedList.setIndex(item, index);
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

            if (dataType == 2) {
                showMenu();
                cin >> menuChoice;
                cout << endl;
                switch(menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> doubleItem;
                        cout << endl << endl;
                        linkedListDouble.push_back(doubleItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        linkedListDouble.pop_back();
                        break;
                    case 3:
                        cout << "Enter newSize for your Linked List" << endl;
                        cout << ">>> ";
                        cin >> newSize;
                        cout << endl << endl;
                        linkedListDouble.resize(newSize);
                        break;
                    case 4:
                        cout << "Size of your Linked List is ";
                        cout << linkedListDouble.getSize() << endl << endl;
                        break;
                    case 5:
                        linkedListDouble.print();
                        cout << endl;
                        break;
                    case 6:
                        showDataType();
                        cin >> dataType;
                        cout << endl;
                        while (linkedListDouble.getSize() != 0) {
                            linkedListDouble.pop_back();
                        }
                        break;
                    case 7:
                        showSequencesType();
                        cin >> sequencesChoice;
                        cout << endl;
                        while (linkedListDouble.getSize() != 0) {
                            linkedListDouble.pop_back();
                        }
                        break;
                    case 8:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;
                        linkedListDouble.getIndex(index);
                        break;
                    case 9:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;

                        cout << "Enter the item" << endl;
                        cout << ">>> ";
                        cin >> doubleItem;
                        cout << endl;
                        linkedListDouble.setIndex(doubleItem, index);
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

            if (dataType == 3) {
                showMenu();
                cin >> menuChoice;
                cout << endl;
                switch(menuChoice) {
                    case 1:
                        cout << "Enter the item that you want push_back" << endl;
                        cout << ">>> ";
                        cin >> charItem;
                        cout << endl << endl;
                        linkedListChar.push_back(charItem);
                        break;
                    case 2:
                        cout << "operation pop back is done successfully" << endl << endl;
                        linkedListChar.pop_back();
                        break;
                    case 3:
                        cout << "Enter newSize for your Linked List" << endl;
                        cout << ">>> ";
                        cin >> newSize;
                        cout << endl << endl;
                        linkedListChar.resize(newSize);
                        break;
                    case 4:
                        cout << "Size of your Linked List is ";
                        cout << linkedListChar.getSize() << endl << endl;
                        break;
                    case 5:
                        linkedListChar.print();
                        cout << endl;
                        break;
                    case 6:
                        showDataType();
                        cin >> dataType;
                        cout << endl;
                        while (linkedListChar.getSize() != 0) {
                            linkedListChar.pop_back();
                        }
                        break;
                    case 7:
                        showSequencesType();
                        cin >> sequencesChoice;
                        cout << endl;
                        while (linkedListChar.getSize() != 0) {
                            linkedListChar.pop_back();
                        }
                        break;
                    case 8:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;
                        linkedListChar.getIndex(index);
                        break;
                    case 9:
                        cout << "Enter the number of index" << endl;
                        cout << ">>> ";
                        cin >> index;
                        cout << endl;

                        cout << "Enter the item" << endl;
                        cout << ">>> ";
                        cin >> charItem;
                        cout << endl;
                        linkedListChar.setIndex(charItem, index);
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

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}