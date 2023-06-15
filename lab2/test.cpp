#include <cassert>
#include "class.h"

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


/*void testAddElement() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    assert(sequence->size() == 1);
    assert((*sequence)[0] == 42);
    delete sequence;
}

void testRemoveElement() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    removeElement<int>(sequence);
    assert(sequence->size() == 0);
    delete sequence;
}

void testGetElement() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    int element = 0;
    getElement<int>(sequence);
    assert(element == 42);
    delete sequence;
}

void testGetSize() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    getSize<int>(sequence);
    assert(sequence->size() == 1);
    delete sequence;
}

void testCopySequence() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    Sequence<int>* copy = sequence->copy();
    assert(copy->size() == sequence->size());
    assert((*copy)[0] == (*sequence)[0]);
    delete sequence;
    delete copy;
}

void testResizeSequence() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    resizeSequence<int>(sequence);
    assert(sequence->size() == 3);
    delete sequence;
}

void testPrintSequence() {
    Sequence<int>* sequence = new DynamicArray<int>();
    addElement<int>(sequence);
    printSequence<int>(sequence);
    delete sequence;
}*/

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

    /*testAddElement();
    testRemoveElement();
    testGetElement();
    testGetSize();
    testCopySequence();
    testResizeSequence();
    testPrintSequence();*/

    cout << "All tests checked!" << endl;
    cout << "No issues found" << endl;

    system("pause");
    return 0;
}

