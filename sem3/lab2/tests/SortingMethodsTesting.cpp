#include "SortingMethodsTesting.h"


template <typename T>
void chooseSortsArray(int typeOfSorts, int typeofSorting, DynamicArray<T>& array) {
    if (typeOfSorts == 1) {
        if (typeofSorting == 1)
            bubbleSort(array);
        else
            bubbleSort(array, false);
    }

    if (typeOfSorts == 2) {
        if (typeofSorting == 1)
            insertionSort(array);
        else
            insertionSort(array, false);
    }

    if (typeOfSorts == 3) {
        if (typeofSorting == 1)
            mergeSort(array);
        else
            mergeSort(array, false);
    }

    if (typeOfSorts == 4) {
        if (typeofSorting == 1)
            shellSort(array);
        else
            shellSort(array, false);
    }

    if (typeOfSorts == 5) {
        if (typeofSorting == 1)
            heapSort(array);
        else
            heapSort(array, false);
    }
}


template <typename T>
void chooseSortsList(int typeOfSorts, int typeofSorting, LinkedList<T>& list) {
    if (typeOfSorts == 1) {
        if (typeofSorting == 1)
            bubbleSort(list);
        else
            bubbleSort(list, false);
    }

    if (typeOfSorts == 2) {
        if (typeofSorting == 1)
            insertionSort(list);
        else
            insertionSort(list, false);
    }

    if (typeOfSorts == 3) {
        if (typeofSorting == 1)
            mergeSort(list);
        else
            mergeSort(list, false);
    }

    if (typeOfSorts == 4) {
        if (typeofSorting == 1)
            shellSort(list);
        else
            shellSort(list, false);
    }

    if (typeOfSorts == 5) {
        if (typeofSorting == 1)
            heapSort(list);
        else
            heapSort(list, false);
    }
}


void SortsTesting(int type) {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    chooseSortsArray(type, 1, array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    array1.resize(1);
    chooseSortsArray(type, 1, array1);
    assert(array1[0] == 0);

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    chooseSortsArray(type, 2, array2);

    for (int i = 0; i < 5; i++) {
        assert(array2[i] == 4 - i);
    }

    array2.resize(1);
    chooseSortsArray(type, 1, array2);
    assert(array2[0] == 4);

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    chooseSortsArray(type, 1, array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    array3.resize(0);
    chooseSortsArray(type, 1, array3);
    assert(array3.getSize() == 0);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    chooseSortsArray(type, 2, array4);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    array4.resize(0);
    chooseSortsArray(type, 1, array4);
    assert(array4.getSize() == 0);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    chooseSortsArray(type, 1, array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    array5.resize(0);
    chooseSortsArray(type, 1, array5);
    assert(array5.getSize() == 0);

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    chooseSortsArray(type, 2, array6);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }

    array6.resize(0);
    chooseSortsArray(type, 1, array6);
    assert(array6.getSize() == 0);


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    chooseSortsList(type, 1, list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    chooseSortsList(type, 2, list2);

    for (int i = 0; i < 5; i++) {
        assert(list2.getNodeAt(i)->data == 4 - i);
    }

    // Test 9
    LinkedList<double> list3;
    list3.push_back(3.1);
    list3.push_back(2.1);
    list3.push_back(4.1);
    list3.push_back(1.1);
    list3.push_back(5.1);

    chooseSortsList(type, 1, list3);

    assert(list3.getNodeAt(0)->data == 1.1);
    assert(list3.getNodeAt(1)->data == 2.1);
    assert(list3.getNodeAt(2)->data == 3.1);
    assert(list3.getNodeAt(3)->data == 4.1);
    assert(list3.getNodeAt(4)->data == 5.1);

    // Test 10
    LinkedList<double> list4;
    list4.push_back(3.1);
    list4.push_back(2.1);
    list4.push_back(4.1);
    list4.push_back(1.1);
    list4.push_back(5.1);

    chooseSortsList(type, 2, list4);

    assert(list4.getNodeAt(0)->data == 5.1);
    assert(list4.getNodeAt(1)->data == 4.1);
    assert(list4.getNodeAt(2)->data == 3.1);
    assert(list4.getNodeAt(3)->data == 2.1);
    assert(list4.getNodeAt(4)->data == 1.1);

    // Test 11
    LinkedList<char> list5;
    for (int i = 0; i < 5; ++i) {
        list5.push_back(i);
    }

    chooseSortsList(type, 1, list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    chooseSortsList(type, 2, list6);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}



