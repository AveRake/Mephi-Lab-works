#include <cassert>
#include "class.h"
#include "SquareMatrix.h"
#include "RectangularMatrix.h"
#include "Stack.h"
#include <string>

void testDynamicArrayInt() {
    DynamicArray<int> arr;
    assert(arr.size() == 0);

    arr.push_back(5);
    assert(arr.size() == 1);
    assert(arr[0] == 5);

    arr.push_back(10);
    assert(arr.size() == 2);
    assert(arr[1] == 10);

    arr.pop_back();
    assert(arr.size() == 1);
    assert(arr[0] == 5);

    arr.resize(3);
    assert(arr.size() == 3);

    DynamicArray<int>* copy = arr.copy();
    assert(copy->size() == arr.size());
    for (int i = 0; i < arr.size(); i++) {
        assert((*copy)[i] == arr[i]);
    }
    delete copy;
}

void testDynamicArrayDouble() {
    DynamicArray<double> arr;
    assert(arr.size() == 0);

    arr.push_back(5.1);
    assert(arr.size() == 1);
    assert(arr[0] == 5.1);

    arr.push_back(10.1);
    assert(arr.size() == 2);
    assert(arr[1] == 10.1);

    arr.pop_back();
    assert(arr.size() == 1);
    assert(arr[0] == 5.1);

    arr.resize(3);
    assert(arr.size() == 3);

    DynamicArray<double>* copy = arr.copy();
    assert(copy->size() == arr.size());
    for (int i = 0; i < arr.size(); i++) {
        assert((*copy)[i] == arr[i]);
    }
    delete copy;
}

void testDynamicArrayChar() {
    DynamicArray<char> arr;
    assert(arr.size() == 0);

    arr.push_back('q');
    assert(arr.size() == 1);
    assert(arr[0] == 'q');

    arr.push_back('w');
    assert(arr.size() == 2);
    assert(arr[1] == 'w');

    arr.pop_back();
    assert(arr.size() == 1);
    assert(arr[0] == 'q');

    arr.resize(3);
    assert(arr.size() == 3);

    DynamicArray<char>* copy = arr.copy();
    assert(copy->size() == arr.size());
    for (int i = 0; i < arr.size(); i++) {
        assert((*copy)[i] == arr[i]);
    }
    delete copy;
}

void testLinkedListInt() {
    LinkedList<int> list;
    assert(list.size() == 0);

    list.push_back(3);
    assert(list.size() == 1);
    assert(list[0] == 3);

    list.push_back(2);
    assert(list.size() == 2);
    assert(list[1] == 2);

    list.pop_back();
    assert(list.size() == 1);
    assert(list[0] == 3);

    list.resize(3);
    assert(list.size() == 3);

    LinkedList<int>* copy = list.copy();
    assert(copy->size() == list.size());
    for (int i = 0; i < list.size(); i++) {
        assert((*copy)[i] == list[i]);
    }
    delete copy;
}

void testLinkedListDouble() {
    LinkedList<double> list;
    assert(list.size() == 0);

    list.push_back(3.14);
    assert(list.size() == 1);
    assert(list[0] == 3.14);

    list.push_back(2.71);
    assert(list.size() == 2);
    assert(list[1] == 2.71);

    list.pop_back();
    assert(list.size() == 1);
    assert(list[0] == 3.14);

    list.resize(3);
    assert(list.size() == 3);

    LinkedList<double>* copy = list.copy();
    assert(copy->size() == list.size());
    for (int i = 0; i < list.size(); i++) {
        assert((*copy)[i] == list[i]);
    }
    delete copy;
}

void testLinkedListChar() {
    LinkedList<char> list;
    assert(list.size() == 0);

    list.push_back('q');
    assert(list.size() == 1);
    assert(list[0] == 'q');

    list.push_back('w');
    assert(list.size() == 2);
    assert(list[1] == 'w');

    list.pop_back();
    assert(list.size() == 1);
    assert(list[0] == 'q');

    list.resize(3);
    assert(list.size() == 3);

    LinkedList<char>* copy = list.copy();
    assert(copy->size() == list.size());
    for (int i = 0; i < list.size(); i++) {
        assert((*copy)[i] == list[i]);
    }
    delete copy;
}

void testSequenceOperationsInt() {
    DynamicArray<int> arr;
    Sequence<int>* sequence = &arr;

    sequence->push_back(1);
    sequence->push_back(2);
    sequence->push_back(3);
    assert(sequence->size() == 3);
    assert((*sequence)[0] == 1);
    assert((*sequence)[1] == 2);
    assert((*sequence)[2] == 3);

    sequence->pop_back();
    assert(sequence->size() == 2);
    assert((*sequence)[0] == 1);
    assert((*sequence)[1] == 2);

    sequence->resize(5);
    assert(sequence->size() == 5);

    sequence->resize(2);
    assert(sequence->size() == 2);
    assert((*sequence)[0] == 1);
    assert((*sequence)[1] == 2);

    Sequence<int>* copy = sequence->copy();
    assert(copy->size() == sequence->size());
    for (int i = 0; i < sequence->size(); i++) {
        assert((*copy)[i] == (*sequence)[i]);
    }
    delete copy;
}

void testSequenceOperationsDouble() {
    DynamicArray<double> arr;
    Sequence<double>* sequence = &arr;

    sequence->push_back(1.1);
    sequence->push_back(2.1);
    sequence->push_back(3.1);
    assert(sequence->size() == 3);
    assert((*sequence)[0] == 1.1);
    assert((*sequence)[1] == 2.1);
    assert((*sequence)[2] == 3.1);

    sequence->pop_back();
    assert(sequence->size() == 2);
    assert((*sequence)[0] == 1.1);
    assert((*sequence)[1] == 2.1);

    sequence->resize(5);
    assert(sequence->size() == 5);

    sequence->resize(2);
    assert(sequence->size() == 2);
    assert((*sequence)[0] == 1.1);
    assert((*sequence)[1] == 2.1);

    Sequence<double>* copy = sequence->copy();
    assert(copy->size() == sequence->size());
    for (int i = 0; i < sequence->size(); i++) {
        assert((*copy)[i] == (*sequence)[i]);
    }
    delete copy;
}

void testSequenceOperationsChar() {
    DynamicArray<char> arr;
    Sequence<char>* sequence = &arr;

    sequence->push_back('q');
    sequence->push_back('w');
    sequence->push_back('e');
    assert(sequence->size() == 3);
    assert((*sequence)[0] == 'q');
    assert((*sequence)[1] == 'w');
    assert((*sequence)[2] == 'e');

    sequence->pop_back();
    assert(sequence->size() == 2);
    assert((*sequence)[0] == 'q');
    assert((*sequence)[1] == 'w');

    sequence->resize(5);
    assert(sequence->size() == 5);

    sequence->resize(2);
    assert(sequence->size() == 2);
    assert((*sequence)[0] == 'q');
    assert((*sequence)[1] == 'w');

    Sequence<char>* copy = sequence->copy();
    assert(copy->size() == sequence->size());
    for (int i = 0; i < sequence->size(); i++) {
        assert((*copy)[i] == (*sequence)[i]);
    }
    delete copy;
}

void runMatrixTests() {
    // Тесты для конструктора и операции получения элемента
    {
        // Тест с типом данных int
        {
            RectangularMatrix<int> matrix(2, 3);
            assert(matrix.getRows() == 2);
            assert(matrix.getCols() == 3);

            matrix[0][0] = 1;
            matrix[0][1] = 2;
            matrix[0][2] = 3;
            matrix[1][0] = 4;
            matrix[1][1] = 5;
            matrix[1][2] = 6;

            assert(matrix[0][0] == 1);
            assert(matrix[0][1] == 2);
            assert(matrix[0][2] == 3);
            assert(matrix[1][0] == 4);
            assert(matrix[1][1] == 5);
            assert(matrix[1][2] == 6);
        }

        // Тест с типом данных double
        {
            RectangularMatrix<double> matrix(2, 2);
            assert(matrix.getRows() == 2);
            assert(matrix.getCols() == 2);

            matrix[0][0] = 3.14;
            matrix[0][1] = 2.718;
            matrix[1][0] = 1.618;
            matrix[1][1] = 0.577;

            assert(matrix[0][0] == 3.14);
            assert(matrix[0][1] == 2.718);
            assert(matrix[1][0] == 1.618);
            assert(matrix[1][1] == 0.577);
        }

        // Тест с типом данных std::string
        {
            RectangularMatrix<std::string> matrix(2, 2);
            assert(matrix.getRows() == 2);
            assert(matrix.getCols() == 2);

            matrix[0][0] = "Hello";
            matrix[0][1] = "World";
            matrix[1][0] = "Open";
            matrix[1][1] = "AI";

            assert(matrix[0][0] == "Hello");
            assert(matrix[0][1] == "World");
            assert(matrix[1][0] == "Open");
            assert(matrix[1][1] == "AI");
        }
    }

    // Тесты для операции изменения размера матрицы
    {
        // Тест с типом данных int
        {
            RectangularMatrix<int> matrix(2, 3);
            matrix[0][0] = 1;
            matrix[0][1] = 2;
            matrix[0][2] = 3;
            matrix[1][0] = 4;
            matrix[1][1] = 5;
            matrix[1][2] = 6;
        }
    }
}

void runStackTests() {
    // Тесты для операции push
    {
        // Тест с типом данных int
        {
            Stack<int> stack;
            stack.push(1);
            stack.push(2);
            stack.push(3);

            assert(stack.size() == 3);
            assert(stack.pop() == 3);
            assert(stack.pop() == 2);
            assert(stack.pop() == 1);
            assert(stack.size() == 0);
        }

        // Тест с типом данных double
        {
            Stack<double> stack;
            stack.push(3.14);
            stack.push(2.718);
            stack.push(1.618);

            assert(stack.size() == 3);
            assert(stack.pop() == 1.618);
            assert(stack.pop() == 2.718);
            assert(stack.pop() == 3.14);
            assert(stack.size() == 0);
        }

        // Тест с типом данных std::string
        {
            Stack<std::string> stack;
            stack.push("Hello");
            stack.push("World");
            stack.push("OpenAI");

            assert(stack.size() == 3);
            assert(stack.pop() == "OpenAI");
            assert(stack.pop() == "World");
            assert(stack.pop() == "Hello");
            assert(stack.size() == 0);
        }
    }

    // Тесты для операции pop
    {
        // Тест с типом данных int
        {
            Stack<int> stack;
            stack.push(1);
            stack.push(2);
            stack.push(3);

            assert(stack.pop() == 3);
            assert(stack.size() == 2);
            assert(stack.pop() == 2);
            assert(stack.size() == 1);
            assert(stack.pop() == 1);
            assert(stack.size() == 0);
        }

        // Тест с типом данных double
        {
            Stack<double> stack;
            stack.push(3.14);
            stack.push(2.718);
            stack.push(1.618);

            assert(stack.pop() == 1.618);
            assert(stack.size() == 2);
            assert(stack.pop() == 2.718);
            assert(stack.size() == 1);
            assert(stack.pop() == 3.14);
            assert(stack.size() == 0);
        }

        // Тест с типом данных std::string
        {
            Stack<std::string> stack;
            stack.push("Hello");
            stack.push("World");
            stack.push("OpenAI");

            assert(stack.pop() == "OpenAI");
            assert(stack.size() == 2);
            assert(stack.pop() == "World");
            assert(stack.size() == 1);
            assert(stack.pop() == "Hello");
            assert(stack.size() == 0);
        }
    }
}

void runSquareMatrixTests() {
    // Тесты для типа данных int
    {
        SquareMatrix<int> matrix(3);
        matrix[0][0] = 1;
        matrix[0][1] = 2;
        matrix[0][2] = 3;
        matrix[1][0] = 4;
        matrix[1][1] = 5;
        matrix[1][2] = 6;
        matrix[2][0] = 7;
        matrix[2][1] = 8;
        matrix[2][2] = 9;

        assert(matrix.getSize() == 3);
        assert(matrix[0][0] == 1);
        assert(matrix[0][1] == 2);
        assert(matrix[0][2] == 3);
        assert(matrix[1][0] == 4);
        assert(matrix[1][1] == 5);
        assert(matrix[1][2] == 6);
        assert(matrix[2][0] == 7);
        assert(matrix[2][1] == 8);
        assert(matrix[2][2] == 9);

        matrix.multiplyByConstant(2);
        assert(matrix[0][0] == 2);
        assert(matrix[0][1] == 4);
        assert(matrix[0][2] == 6);
        assert(matrix[1][0] == 8);
        assert(matrix[1][1] == 10);
        assert(matrix[1][2] == 12);
        assert(matrix[2][0] == 14);
        assert(matrix[2][1] == 16);
        assert(matrix[2][2] == 18);

        SquareMatrix<int> other(3);
        other[0][0] = 1;
        other[0][1] = 1;
        other[0][2] = 1;
        other[1][0] = 1;
        other[1][1] = 1;
        other[1][2] = 1;
        other[2][0] = 1;
        other[2][1] = 1;
        other[2][2] = 1;

        matrix.addMatrix(other);
        assert(matrix[0][0] == 3);
        assert(matrix[0][1] == 5);
        assert(matrix[0][2] == 7);
        assert(matrix[1][0] == 9);
        assert(matrix[1][1] == 11);
        assert(matrix[1][2] == 13);
        assert(matrix[2][0] == 15);
        assert(matrix[2][1] == 17);
        assert(matrix[2][2] == 19);
    }

    // Тесты для типа данных double
    {
        SquareMatrix<double> matrix(2);
        matrix[0][0] = 1.1;
        matrix[0][1] = 2.2;
        matrix[1][0] = 3.3;
        matrix[1][1] = 4.4;

        assert(matrix.getSize() == 2);
        assert(matrix[0][0] == 1.1);
        assert(matrix[0][1] == 2.2);
        assert(matrix[1][0] == 3.3);
        assert(matrix[1][1] == 4.4);

        matrix.multiplyByConstant(2.5);
        assert(matrix[0][0] == 2.75);
        assert(matrix[0][1] == 5.5);
        assert(matrix[1][0] == 8.25);
        assert(matrix[1][1] == 11.0);

        SquareMatrix<double> other(2);
        other[0][0] = 0.5;
        other[0][1] = 0.5;
        other[1][0] = 0.5;
        other[1][1] = 0.5;

        matrix.addMatrix(other);
        assert(matrix[0][0] == 3.25);
        assert(matrix[0][1] == 6.0);
        assert(matrix[1][0] == 8.75);
        assert(matrix[1][1] == 11.5);
    }
}

int main() {
    testDynamicArrayInt();
    testDynamicArrayDouble();
    testDynamicArrayChar();
    testLinkedListInt();
    testLinkedListDouble();
    testLinkedListChar();
    testSequenceOperationsInt();
    testSequenceOperationsDouble();
    testSequenceOperationsChar();
    runSquareMatrixTests();
    runMatrixTests();
    runStackTests();

    cout << "All tests checked!" << endl;
    cout << "No issues found" << endl;

    system("pause");
    return 0;
}

