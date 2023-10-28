#include "detours.h"


void showMenu() {
    cout << "-------------------------------------------" << endl;
    cout << "|Choose the operation with your tree       |" << endl;
    cout << "|1 - insert the value                      |" << endl;
    cout << "|2 - detour with KLP                       |" << endl;
    cout << "|3 - detour with KPL                       |" << endl;
    cout << "|4 - detour with LPK                       |" << endl;
    cout << "|5 - detour with LKP                       |" << endl;
    cout << "|6 - detour with PLK                       |" << endl;
    cout << "|7 - detour with PKL                       |" << endl;
    cout << "|8 - convert with map                      |" << endl;
    cout << "|9 - create new tree with operation where  |" << endl;
    cout << "|10 - merge 2 trees                        |" << endl;
    cout << "|11 - Extract subtree                      |" << endl;
    cout << "|12 - Finding an element for an occurrence |" << endl;
    cout << "|0 - exit the programme                    |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << ">>> ";
}


int main() {
    int dataType;
    int operationType;
    int length;

    cout << "<<<Welcome to the menu!>>>" << endl;
    cout << "Select the type of data for the tree: " << endl;
    cout << "1. Integer" << endl;
    cout << "2. Double" << endl;
    cout << "3. Char" << endl;
    cout << "4. String" << endl;
    cout << ">>> ";
    cin >> dataType;

    if (dataType != 1 & dataType != 2 & dataType != 3 & dataType != 4) {
        cout << "Unknown type!" << endl;
        system("pause");
        exit(-1);
    }

    cout << "Enter the length of your trees" << endl;
    cout << ">>> ";
    cin >> length;

    auto condition = [](int value) {
        return value % 2 == 0;
    };

    auto conditionDouble = [](double value) {
        return value < 0.0;
    };

    auto conditionChar = [](char value) {
        return value == 'a' || value == 'e' || value == 'i' || value == 'o' || value == 'u';
    };

    auto conditionString = [](const string& value) {
        return value.length() > 5;
    };


    if (dataType == 1) {
        int value;
        Node<int>* root = nullptr;
        cout << "Enter the elements of your tree" << endl;

        for (int i = 0; i < length; i++) {
            cin >> value;
            root = insert(root, value);
        }

        showMenu();
        cin >> operationType;

        while (operationType != 0) {
            switch (operationType) {
                case 1:
                    cout << "Enter the element" << endl;
                    cout << ">>> ";
                    cin >> value;
                    root = insert(root, value);
                    break;
                case 2:
                    cout << "KLP: ";
                    KLP(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "KPL: ";
                    KPL(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "LPK: ";
                    LPK(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "LKP: ";
                    LKP(root);
                    cout << endl;
                    break;
                case 6:
                    cout << "PLK: ";
                    PLK(root);
                    cout << endl;
                    break;
                case 7:
                    cout << "PKL: ";
                    PKL(root);
                    cout << endl;
                    break;
                case 8:
                    if (operationType == 8) {
                        Node<int>* newRoot = map(root, multiplyByTwo);
                        cout << "All numbers are multiplied by 2" << endl;
                        cout << "New tree (after changing): ";
                        KLP(newRoot);
                        cout << endl;
                    }
                    break;
                case 9:
                    if (operationType == 9) {
                        Node<int>* filteredRoot = where(root, condition);
                        cout << "There are only numbers that are divisible by 2" << endl;
                        cout << "New tree (after changing): ";
                        KLP(filteredRoot);
                        cout << endl;
                    }
                    break;
                case 10:
                    if (operationType == 10) {
                        int size;
                        Node<int>* root2 = nullptr;
                        cout << "Create a new tree fpr merge" << endl;
                        cout << "Enter the length of your new tree" << endl;
                        cout << ">>> ";
                        cin >> size;

                        cout << "Enter the elements of your tree" << endl;
                        for (int i = 0; i < size; i++) {
                            cin >> value;
                            root = insert(root, value);
                        }

                        Node<int>* mergedRoot = merge(root, root2);

                        cout << "New tree after merge: ";
                        KLP(mergedRoot);
                        cout << endl;
                    }
                    break;
                case 11:
                    if (operationType == 11) {
                        int st;
                        cout << "choose the subtree" << endl;
                        cout << ">>> ";
                        cin >> st;

                        Node<int>* subtree = extractSubtree(root, st);

                        cout << "Extract Subtree = ";
                        KLP(subtree);
                        cout << endl;
                    }
                    break;
                case 12:
                    int con;
                    cout << "Choose the element for contain" << endl;
                    cout << ">>> ";
                    cin >> con;

                    if (contains(root, con)) {
                        cout << "Element " << con <<  " is present in the tree." << endl;
                    } else {
                        cout << "Element " << con <<  " is not present in the tree." << endl;
                    }
                    break;
                case 0:
                    cout << "Exiting" << endl;
                default:
                    cout << "Invalid input. Try again." << endl;
                    break;
            }

            showMenu();
            cin >> operationType;
        }
        delete root;
    }


    if (dataType == 2) {
        double value;
        Node<double>* root = nullptr;
        cout << "Enter the elements of your tree" << endl;

        for (int i = 0; i < length; i++) {
            cin >> value;
            root = insert(root, value);
        }

        showMenu();
        cin >> operationType;

        while (operationType != 0) {
            switch (operationType) {
                case 1:
                    cout << "Enter the element" << endl;
                    cout << ">>> ";
                    cin >> value;
                    root = insert(root, value);
                    break;
                case 2:
                    cout << "KLP: ";
                    KLP(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "KPL: ";
                    KPL(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "LPK: ";
                    LPK(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "LKP: ";
                    LKP(root);
                    cout << endl;
                    break;
                case 6:
                    cout << "PLK: ";
                    PLK(root);
                    cout << endl;
                    break;
                case 7:
                    cout << "PKL: ";
                    PKL(root);
                    cout << endl;
                    break;
                case 8:
                    if (operationType == 8) {
                        Node<double>* newRoot = map(root, multiplyByTwoDouble);
                        cout << "All numbers are multiplied by 2" << endl;
                        cout << "New tree (after changing): ";
                        KLP(newRoot);
                        cout << endl;
                    }
                    break;
                case 9:
                    if (operationType == 9) {
                        Node<double>* filteredRoot = where(root, conditionDouble);
                        cout << "There are only negative numbers" << endl;
                        cout << "New tree (after changing): ";
                        KLP(filteredRoot);
                        cout << endl;
                    }
                    break;
                case 10:
                    if (operationType == 10) {
                        int size;
                        Node<double>* root2 = nullptr;
                        cout << "Create a new tree fpr merge" << endl;
                        cout << "Enter the length of your new tree" << endl;
                        cout << ">>> ";
                        cin >> size;

                        cout << "Enter the elements of your tree" << endl;
                        for (int i = 0; i < size; i++) {
                            cin >> value;
                            root = insert(root, value);
                        }

                        Node<double>* mergedRoot = merge(root, root2);

                        cout << "New tree after merge: ";
                        KLP(mergedRoot);
                        cout << endl;
                    }
                    break;
                case 11:
                    if (operationType == 11) {
                        double st;
                        cout << "choose the subtree" << endl;
                        cout << ">>> ";
                        cin >> st;

                        Node<double>* subtree = extractSubtree(root, st);

                        cout << "Extract Subtree = ";
                        KLP(subtree);
                        cout << endl;
                    }
                    break;
                case 12:
                    double con;
                    cout << "Choose the element for contain" << endl;
                    cout << ">>> ";
                    cin >> con;

                    if (contains(root, con)) {
                        cout << "Element " << con <<  " is present in the tree." << endl;
                    } else {
                        cout << "Element " << con <<  " is not present in the tree." << endl;
                    }
                    break;
                case 0:
                    cout << "Exiting" << endl;
                default:
                    cout << "Invalid input. Try again." << endl;
                    break;
            }

            showMenu();
            cin >> operationType;
        }
        delete root;
    }


    if (dataType == 3) {
        char value;
        Node<char>* root = nullptr;
        cout << "Enter the elements of your tree" << endl;

        for (int i = 0; i < length; i++) {
            cin >> value;
            root = insert(root, value);
        }

        showMenu();
        cin >> operationType;

        while (operationType != 0) {
            switch (operationType) {
                case 1:
                    cout << "Enter the element" << endl;
                    cout << ">>> ";
                    cin >> value;
                    root = insert(root, value);
                    break;
                case 2:
                    cout << "KLP: ";
                    KLP(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "KPL: ";
                    KPL(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "LPK: ";
                    LPK(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "LKP: ";
                    LKP(root);
                    cout << endl;
                    break;
                case 6:
                    cout << "PLK: ";
                    PLK(root);
                    cout << endl;
                    break;
                case 7:
                    cout << "PKL: ";
                    PKL(root);
                    cout << endl;
                    break;
                case 8:
                    if (operationType == 8) {
                        Node<char>* newRoot = map(root, charToNextAscii);
                        cout << "Your letters are shifted by 1" << endl;
                        cout << "New tree (after changing): ";
                        KLP(newRoot);
                        cout << endl;
                    }
                    break;
                case 9:
                    if (operationType == 9) {
                        Node<char>* filteredRoot = where(root, conditionChar);
                        cout << "There only vowels" << endl;
                        cout << "New tree (after changing): ";
                        KLP(filteredRoot);
                        cout << endl;
                    }
                    break;
                case 10:
                    if (operationType == 10) {
                        int size;
                        Node<char>* root2 = nullptr;
                        cout << "Create a new tree fpr merge" << endl;
                        cout << "Enter the length of your new tree" << endl;
                        cout << ">>> ";
                        cin >> size;

                        cout << "Enter the elements of your tree" << endl;
                        for (int i = 0; i < size; i++) {
                            cin >> value;
                            root = insert(root, value);
                        }

                        Node<char>* mergedRoot = merge(root, root2);

                        cout << "New tree after merge: ";
                        KLP(mergedRoot);
                        cout << endl;
                    }
                    break;
                case 11:
                    if (operationType == 11) {
                        char st;
                        cout << "choose the subtree" << endl;
                        cout << ">>> ";
                        cin >> st;

                        Node<char>* subtree = extractSubtree(root, st);

                        cout << "Extract Subtree = ";
                        KLP(subtree);
                        cout << endl;
                    }
                    break;
                case 12:
                    char con;
                    cout << "Choose the element for contain" << endl;
                    cout << ">>> ";
                    cin >> con;

                    if (contains(root, con)) {
                        cout << "Element " << con <<  " is present in the tree." << endl;
                    } else {
                        cout << "Element " << con <<  " is not present in the tree." << endl;
                    }
                    break;
                case 0:
                    cout << "Exiting" << endl;
                default:
                    cout << "Invalid input. Try again." << endl;
                    break;
            }

            showMenu();
            cin >> operationType;
        }
        delete root;
    }


    if (dataType == 4) {
        string value;
        Node<string>* root = nullptr;
        cout << "Enter the elements of your tree" << endl;

        for (int i = 0; i < length; i++) {
            cin >> value;
            root = insert(root, value);
        }

        showMenu();
        cin >> operationType;

        while (operationType != 0) {
            switch (operationType) {
                case 1:
                    cout << "Enter the element" << endl;
                    cout << ">>> ";
                    cin >> value;
                    root = insert(root, value);
                    break;
                case 2:
                    cout << "KLP: ";
                    KLP(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "KPL: ";
                    KPL(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "LPK: ";
                    LPK(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "LKP: ";
                    LKP(root);
                    cout << endl;
                    break;
                case 6:
                    cout << "PLK: ";
                    PLK(root);
                    cout << endl;
                    break;
                case 7:
                    cout << "PKL: ";
                    PKL(root);
                    cout << endl;
                    break;
                case 8:
                    if (operationType == 8) {
                        Node<string>* newRoot = map(root, reverseString);
                        cout << "Your words are reversed" << endl;
                        cout << "New tree (after changing): ";
                        KLP(newRoot);
                        cout << endl;
                    }
                    break;
                case 9:
                    if (operationType == 9) {
                        Node<string>* filteredRoot = where(root, conditionString);
                        cout << "There are only string that length more than 3" << endl;
                        cout << "New tree (after changing): ";
                        KLP(filteredRoot);
                        cout << endl;
                    }
                    break;
                case 10:
                    if (operationType == 10) {
                        int size;
                        Node<string>* root2 = nullptr;
                        cout << "Create a new tree fpr merge" << endl;
                        cout << "Enter the length of your new tree" << endl;
                        cout << ">>> ";
                        cin >> size;

                        cout << "Enter the elements of your tree" << endl;
                        for (int i = 0; i < size; i++) {
                            cin >> value;
                            root = insert(root, value);
                        }

                        Node<string>* mergedRoot = merge(root, root2);

                        cout << "New tree after merge: ";
                        KLP(mergedRoot);
                        cout << endl;
                    }
                    break;
                case 11:
                    if (operationType == 11) {
                        string st;
                        cout << "choose the subtree" << endl;
                        cout << ">>> ";
                        cin >> st;

                        Node<string>* subtree = extractSubtree(root, st);

                        cout << "Extract Subtree = ";
                        KLP(subtree);
                        cout << endl;
                    }
                    break;
                case 12:
                    if (operationType == 12) {
                        string con;
                        cout << "Choose the element for contain" << endl;
                        cout << ">>> ";
                        cin >> con;

                        if (contains(root, con)) {
                            cout << "Element " << con <<  " is present in the tree." << endl;
                        } else {
                            cout << "Element " << con <<  " is not present in the tree." << endl;
                        }
                    }
                    break;
                case 0:
                    cout << "Exiting" << endl;
                default:
                    cout << "Invalid input. Try again." << endl;
                    break;
            }

            showMenu();
            cin >> operationType;
        }
        delete root;
    }

    system("pause");
    return 0;
}
