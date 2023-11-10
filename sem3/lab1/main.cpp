#include "SmartPointer.h"
#include "Sequence.h"


void showMenu() {
    cout << "Press 1 if you want add item for your sequence" << endl;
    cout << "Press 2 if you want delete item from your sequence" << endl;
    cout << "Press 3 if you want resize your sequence" << endl;
    cout << "Press 4 if you want to known the size of your sequence" << endl;
    cout << "Press 5 if you want print your sequence" << endl;
    cout << "Press 0 if you want exit the programme" << endl;
    cout << ">>> ";
}


int main() {
    cout << "Welcome to the my programme about Smart Pointers" << endl;
    cout << "Choose the sequences that you want to use for testing Smart Pointers" << endl;
    cout << "Press 1 for Dynamic Array and 2 for Linked List" << endl;
    cout << ">>> ";
    int sequencesChoice;
    cin >> sequencesChoice;
    cout << endl;

    int dataType = 0;
    cout << "For type int press 1" << endl;
    cout << "For type double press 2" << endl;
    cout << ">>> ";
    cin >> dataType;
    cout << endl;


    int menuChoice = 1;
    int item;
    double doubleItem;
    int newSize;
    DynamicArray<int> dynamicArray;
    DynamicArray<double> dynamicArrayDouble;
    LinkedList<int> linkedList;
    LinkedList<double> linkedListDouble;

    while (menuChoice != 0) {
        showMenu();
        cin >> menuChoice;
        cout << endl;
        if (sequencesChoice == 1) {
            if (dataType == 1) {
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
                    case 0:
                        cout << "exiting" << endl << endl;
                        menuChoice = 0;
                        break;
                }
            }

            if (dataType == 2) {
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
                    case 0:
                        cout << "exiting" << endl << endl;
                        menuChoice = 0;
                        break;
                }
            }
        }

        if (sequencesChoice == 2) {
            if (dataType == 1) {
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
                    case 0:
                        cout << "exiting" << endl << endl;
                        menuChoice = 0;
                        break;
                }
            }

            if (dataType == 2) {
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
                    case 0:
                        cout << "exiting" << endl << endl;
                        menuChoice = 0;
                        break;
                }
            }
        }
    }

    system("pause");
    return 0;
}