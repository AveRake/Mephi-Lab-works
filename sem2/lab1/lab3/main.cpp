#include "class.h"
#include "SquareMatrix.h"
#include "RectangularMatrix.h"
#include "Stack.h"


void showMenu() {
    cout << " -----------------------------------------------------" << endl;
    cout << "| Welcome to the menu!                                |" << endl;
    cout << "| Choose the operation for your matrix                |" << endl;
    cout << "| 1 - multiply your matrix by a constant              |" << endl;
    cout << "| 2 - add another matrix with your matrix             |" << endl;
    cout << "| 3 - multiply another matrix with your matrix        |" << endl;
    cout << "| 4 - add a const to all elements of your matrix      |" << endl;
    cout << "| 5 - lineal combination                              |" << endl;
    cout << "| 6 - exit the program                                |" << endl;
    cout << " -----------------------------------------------------" << endl << endl;
    cout << "Your answer is ";
}


void showMenuStack() {
    cout << " ---------------------------------------" << endl;
    cout << "|Stack Menu:                            |" << endl;
    cout << "|1. Push element                        |" << endl;
    cout << "|2. Pop element                         |" << endl;
    cout << "|3. Get stack size                      |" << endl;
    cout << "|4. Print stack in reverse              |" << endl;
    cout << "|5. Check the empty of the stack        |" << endl;
    cout << "|6. Exit                                |" << endl;
    cout << " ---------------------------------------" << endl << endl;
    cout << "Enter your choice: ";
}


int main() {
    int typeSequences;
    int operationType = 0;
    cout << "Choose the sequences" << endl;
    cout << "Press 1 if you want to use square matrix" << endl;
    cout << "Press 2 if you want to use rectangular matrix" << endl;
    cout << "Press 3 if you want to use stack" << endl;
    cout << "Your answer is  ";
    cin >> typeSequences;
    cout << endl;

    if (typeSequences == 1) {
        int dataType;
        cout << "Select the type of data for the matrix: " << endl;
        cout << "1. Integer" << endl;
        cout << "2. Double" << endl;
        cout << "Your answer is  ";
        cin >> dataType;
        cout << endl;

        if (dataType != 1 & dataType != 2) {
            cout << "Unknown type!" << endl;
            system("pause");
            exit(-1);
        }

        int size;
        cout << "Enter the size of your matrix" << endl;
        cin >> size;

        if (dataType == 1) {
            SquareMatrix<int> matrix(size);

            cout << "Enter the elements of your matrix:" << endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int element;
                    cin >> element;
                    matrix[i][j] = element;
                }
            }

            cout << "Your matrix:" << endl;
            matrix.printMatrix();

            while (operationType != 6) {
                showMenu();
                cin >> operationType;
                cout << endl;

                if (operationType != 1 & operationType != 2 & operationType != 3 & operationType != 4 & operationType != 5  & operationType != 6) {
                    cout << "Unknown operation!" << endl;
                    system("pause");
                    exit(-1);
                }

                if (operationType == 1) {
                    int constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.multiplyByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 2) {
                    cout << "Enter the size of another matrix: ";
                    int size2;
                    cin >> size2;

                    if (size != size2) {
                        cout << "The size of both matrix are not same!" << endl;
                        return 0;
                    }

                    SquareMatrix<int> matrix2(size);

                    cout << "Enter the size of another matrix:" << endl;
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            int element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.addMatrix(matrix2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 3) {
                    cout << "Enter the size of another matrix: ";
                    int size2;
                    cin >> size2;

                    if (size != size2) {
                        cout << "The size of both matrix are not same!!" << endl;
                        return 0;
                    }

                    SquareMatrix<int> matrix2(size);

                    cout << "Enter the elements of another matrix" << endl;
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            int element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.multiplyByMatrix(matrix2);
                    cout << "The result is" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 4) {
                    int constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.addByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 5) {
                    int constant;
                    cout << "Enter the rows which you would like to add: ";
                    cin >> constant;
                    int constant2;
                    cout << "Enter the rows which you would like to use: ";
                    cin >> constant2;
                    matrix.linealMatrix(constant, constant2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }
            }
        }

        if (dataType == 2) {
            SquareMatrix<double> matrix(size);

            cout << "Enter the elements of your matrix:" << endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    double element;
                    cin >> element;
                    matrix[i][j] = element;
                }
            }

            cout << "Your matrix:" << endl;
            matrix.printMatrix();

            while (operationType != 6) {
                showMenu();
                cin >> operationType;
                cout << endl;

                if (operationType != 1 & operationType != 2 & operationType != 3 & operationType != 4 & operationType != 5 & operationType != 6) {
                    cout << "Unknown operation!" << endl;
                    system("pause");
                    exit(-1);
                }

                if (operationType == 1) {
                    double constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.multiplyByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 2) {
                    cout << "Enter the size of another matrix: ";
                    int size2;
                    cin >> size2;

                    if (size != size2) {
                        cout << "The size of both matrix are not same!" << endl;
                        return 0;
                    }

                    SquareMatrix<double> matrix2(size);

                    cout << "Enter the size of another matrix:" << endl;
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            double element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.addMatrix(matrix2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 3) {
                    cout << "Enter the size of another matrix: ";
                    int size2;
                    cin >> size2;

                    if (size != size2) {
                        cout << "The size of both matrix are not same!!" << endl;
                        return 0;
                    }

                    SquareMatrix<double> matrix2(size);

                    cout << "Enter the elements of another matrix" << endl;
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            double element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.multiplyByMatrix(matrix2);
                    cout << "The result is" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 4) {
                    double constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.addByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 5) {
                    int constant;
                    cout << "Enter the rows which you would like to add: ";
                    cin >> constant;
                    int constant2;
                    cout << "Enter the rows which you would like to use: ";
                    cin >> constant2;

                    if (constant2 >= size || constant >= size) {
                        cout << "Wrong size!" << endl;
                        system("pause");
                        exit(-1);
                    }

                    matrix.linealMatrix(constant, constant2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }
            }
        }
    }

    if (typeSequences == 2) {
        cout << "Enter the number of rows in the matrix: ";
        int rows;
        cin >> rows;

        cout << "Enter the number of columns in the matrix: ";
        int cols;
        cin >> cols;

        int dataType;
        cout << "Select the type of data for the matrix: " << endl;
        cout << "1. Integer" << endl;
        cout << "2. Double" << endl;
        cout << "Your answer is  ";
        cin >> dataType;
        cout << endl;

        if (dataType != 1 & dataType != 2) {
            cout << "Unknown type!" << endl;
            system("pause");
            exit(-1);
        }

        if (dataType == 1) {
            RectangularMatrix<int> matrix(rows, cols);

            cout << "Enter the elements of your matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int element;
                    cin >> element;
                    matrix[i][j] = element;
                }
            }

            cout << "Your matrix:" << endl;
            matrix.printMatrix();

            while (operationType != 6) {
                showMenu();
                cin >> operationType;
                cout << endl;

                if (operationType != 1 & operationType != 2 & operationType != 3 & operationType != 4 &
                    operationType != 5 & operationType != 6) {
                    cout << "Unknown type!" << endl;
                    system("pause");
                    exit(-1);
                }

                if (operationType == 1) {
                    int constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.multiplyByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 2) {
                    cout << "Enter the size of another matrix" << endl;

                    cout << "Enter the number of rows in the matrix: ";
                    int rows2;
                    cin >> rows2;

                    cout << "Enter the number of columns in the matrix: ";
                    int cols2;
                    cin >> cols2;

                    if (cols != cols2) {
                        cout << "The size of both matrix are not same!!" << endl;
                        system("pause");
                        return 0;
                    }

                    RectangularMatrix<int> matrix2(rows2, cols2);

                    cout << "Enter the size of another matrix:" << endl;
                    for (int i = 0; i < rows2; i++) {
                        for (int j = 0; j < cols2; j++) {
                            int element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.addMatrix(matrix2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 3) {
                    cout << "Enter the size of another matrix" << endl;

                    cout << "Enter the number of rows in the matrix: ";
                    int rows2;
                    cin >> rows2;

                    cout << "Enter the number of columns in the matrix: ";
                    int cols2;
                    cin >> cols2;

                    RectangularMatrix<int> matrix2(rows2, cols2);

                    cout << "Enter the elements of another matrix" << endl;
                    for (int i = 0; i < rows2; i++) {
                        for (int j = 0; j < cols2; j++) {
                            int element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.multiplyByMatrix(matrix2);
                    cout << "The result is" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 4) {
                    int constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.addByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 5) {
                    int constant;
                    cout << "Enter the rows which you would like to add: ";
                    cin >> constant;
                    int constant2;
                    cout << "Enter the rows which you would like to use: ";
                    cin >> constant2;

                    if (constant2 >= rows || constant >= rows) {
                        cout << "Wrong size!" << endl;
                        system("pause");
                        exit(-1);
                    }

                    matrix.linealMatrix(constant, constant2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }
            }
        }

        if (dataType == 2) {
            RectangularMatrix<double> matrix(rows, cols);

            cout << "Enter the elements of your matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    double element;
                    cin >> element;
                    matrix[i][j] = element;
                }
            }

            cout << "Your matrix:" << endl;
            matrix.printMatrix();

            while (operationType != 6) {
                showMenu();
                cin >> operationType;
                cout << endl;

                if (operationType != 1 & operationType != 2 & operationType != 3 & operationType != 4 &
                    operationType != 5 & operationType != 6) {
                    cout << "Unknown type!" << endl;
                    system("pause");
                    exit(-1);
                }

                if (operationType == 1) {
                    double constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.multiplyByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 2) {
                    cout << "Enter the size of another matrix" << endl;

                    cout << "Enter the number of rows in the matrix: ";
                    int rows2;
                    cin >> rows2;

                    cout << "Enter the number of columns in the matrix: ";
                    int cols2;
                    cin >> cols2;

                    if (cols != cols2) {
                        cout << "The size of both matrix are not same!!" << endl;
                        system("pause");
                        return 0;
                    }

                    RectangularMatrix<double> matrix2(rows2, cols2);

                    cout << "Enter the size of another matrix:" << endl;
                    for (int i = 0; i < rows2; i++) {
                        for (int j = 0; j < cols2; j++) {
                            double element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.addMatrix(matrix2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 3) {
                    cout << "Enter the size of another matrix" << endl;

                    cout << "Enter the number of rows in the matrix: ";
                    int rows2;
                    cin >> rows2;

                    cout << "Enter the number of columns in the matrix: ";
                    int cols2;
                    cin >> cols2;

                    RectangularMatrix<double> matrix2(rows2, cols2);

                    cout << "Enter the elements of another matrix" << endl;
                    for (int i = 0; i < rows2; i++) {
                        for (int j = 0; j < cols2; j++) {
                            double element;
                            cin >> element;
                            matrix2[i][j] = element;
                        }
                    }

                    matrix.multiplyByMatrix(matrix2);
                    cout << "The result is" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 4) {
                    double constant;
                    cout << "Enter the constant: ";
                    cin >> constant;
                    matrix.addByConstant(constant);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }

                if (operationType == 5) {
                    int constant;
                    cout << "Enter the rows which you would like to add: ";
                    cin >> constant;
                    int constant2;
                    cout << "Enter the rows which you would like to use: ";
                    cin >> constant2;

                    if (constant2 >= rows || constant >= rows) {
                        cout << "Wrong size!" << endl;
                        system("pause");
                        exit(-1);
                    }

                    matrix.linealMatrix(constant, constant2);
                    cout << "The result is:" << endl;
                    matrix.printMatrix();
                }
            }
        }
    }

    if (typeSequences == 3) {
        cout << "Choose the data type for the stack (int, double, char, string): ";
        string dataType;
        cin >> dataType;

        if (dataType == "int") {
            Stack<int> stack;
            int choice;
            do {
                showMenuStack();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter an integer to push: ";
                        int item;
                        cin >> item;
                        stack.push(item);
                        cout << "Element pushed to the stack." << std::endl;
                        break;
                    }
                    case 2: {
                        try {
                            int item = stack.pop();
                            cout << "Popped element: " << item << std::endl;
                        } catch (const std::runtime_error& e) {
                            cout << "Error: " << e.what() << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        int stackSize = stack.size();
                        cout << "Stack size: " << stackSize << std::endl;
                        break;
                    }
                    case 4: {
                        cout << "Stack in reverse: ";
                        stack.printReverse();
                        break;
                    }
                    case 5: {
                        cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                        break;
                    }
                    case 6: {
                        cout << "Exiting..." << std::endl;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << std::endl;
                        break;
                    }
                }
            } while (choice != 6);
        } else if (dataType == "double") {
            Stack<double> stack;
            int choice;
            do {
                showMenuStack();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter an integer to push: ";
                        double item;
                        cin >> item;
                        stack.push(item);
                        cout << "Element pushed to the stack." << std::endl;
                        break;
                    }
                    case 2: {
                        try {
                            double item = stack.pop();
                            cout << "Popped element: " << item << std::endl;
                        } catch (const std::runtime_error& e) {
                            cout << "Error: " << e.what() << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        int stackSize = stack.size();
                        cout << "Stack size: " << stackSize << std::endl;
                        break;
                    }
                    case 4: {
                        cout << "Stack in reverse: ";
                        stack.printReverse();
                        break;
                    }
                    case 5: {
                        cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                        break;
                    }
                    case 6: {
                        cout << "Exiting..." << std::endl;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << std::endl;
                        break;
                    }
                }
            } while (choice != 6);
        } else if (dataType == "char") {
            Stack<char> stack;
            int choice;
            do {
                showMenuStack();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter an integer to push: ";
                        char item;
                        cin >> item;
                        stack.push(item);
                        cout << "Element pushed to the stack." << std::endl;
                        break;
                    }
                    case 2: {
                        try {
                            char item = stack.pop();
                            cout << "Popped element: " << item << std::endl;
                        } catch (const std::runtime_error& e) {
                            cout << "Error: " << e.what() << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        int stackSize = stack.size();
                        cout << "Stack size: " << stackSize << std::endl;
                        break;
                    }
                    case 4: {
                        cout << "Stack in reverse: ";
                        stack.printReverse();
                        break;
                    }
                    case 5: {
                        cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                        break;
                    }
                    case 6: {
                        cout << "Exiting..." << std::endl;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << std::endl;
                        break;
                    }
                }
            } while (choice != 6);
        } else if (dataType == "string") {
            Stack<std::string> stack;
            int choice;
            do {
                showMenuStack();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter an integer to push: ";
                        string item;
                        cin >> item;
                        stack.push(item);
                        cout << "Element pushed to the stack." << std::endl;
                        break;
                    }
                    case 2: {
                        try {
                            string item = stack.pop();
                            cout << "Popped element: " << item << std::endl;
                        } catch (const std::runtime_error& e) {
                            cout << "Error: " << e.what() << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        int stackSize = stack.size();
                        cout << "Stack size: " << stackSize << std::endl;
                        break;
                    }
                    case 4: {
                        cout << "Stack in reverse: ";
                        stack.printReverse();
                        break;
                    }
                    case 5: {
                        cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                        break;
                    }
                    case 6: {
                        cout << "Exiting..." << std::endl;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << std::endl;
                        break;
                    }
                }
            } while (choice != 6);
        } else {
            cout << "Unsupported data type!" << std::endl;
            system("pause");
            return 0;
        }

    }

    if (typeSequences != 1 & typeSequences != 2 & typeSequences != 3) {
        cout << "Unknown type!" << endl;
        system("pause");
        exit(-1);
    }

    system("pause");
    return 0;
}