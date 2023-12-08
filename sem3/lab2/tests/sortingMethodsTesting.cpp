#include "sortingMethodsTesting.h"


template<typename SequenceType>
void chooseSorts(int typeOfSorts, int wayOfSorting, SequenceType& sequnece) {
    if (typeOfSorts == 1) {
        if (wayOfSorting == 1)
            bubbleSort(sequnece);
        else
            bubbleSort(sequnece, false);
    }

    if (typeOfSorts == 2) {
        if (wayOfSorting == 1)
            insertionSort(sequnece);
        else
            insertionSort(sequnece, false);
    }

    if (typeOfSorts == 3) {
        if (wayOfSorting == 1)
            mergeSort(sequnece);
        else
            mergeSort(sequnece, false);
    }

    if (typeOfSorts == 4) {
        if (wayOfSorting == 1)
            shellSort(sequnece);
        else
            shellSort(sequnece, false);
    }

    if (typeOfSorts == 5) {
        if (wayOfSorting == 1)
            heapSort(sequnece);
        else
            heapSort(sequnece, false);
    }
}


void SortsTesting(int type) {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    chooseSorts<DynamicArray<int>>(type, 1, array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    array1.resize(1);
    chooseSorts<DynamicArray<int>>(type, 1, array1);
    assert(array1[0] == 0);

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    chooseSorts<DynamicArray<int>>(type, 2, array2);

    for (int i = 0; i < 5; i++) {
        assert(array2[i] == 4 - i);
    }

    array2.resize(1);
    chooseSorts<DynamicArray<int>>(type, 1, array2);
    assert(array2[0] == 4);

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    chooseSorts<DynamicArray<double>>(type, 1, array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    array3.resize(0);
    chooseSorts<DynamicArray<double>>(type, 1, array3);
    assert(array3.getSize() == 0);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    chooseSorts<DynamicArray<double>>(type, 2, array4);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    array4.resize(0);
    chooseSorts<DynamicArray<double>>(type, 1, array4);
    assert(array4.getSize() == 0);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    chooseSorts<DynamicArray<char>>(type, 1, array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    array5.resize(0);
    chooseSorts<DynamicArray<char>>(type, 1, array5);
    assert(array5.getSize() == 0);

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    chooseSorts<DynamicArray<char>>(type, 2, array6);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }

    array6.resize(0);
    chooseSorts<DynamicArray<char>>(type, 1, array6);
    assert(array6.getSize() == 0);


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    chooseSorts<LinkedList<int>>(type, 1, list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    chooseSorts<LinkedList<int>>(type, 2, list2);

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

    chooseSorts<LinkedList<double>>(type, 1, list3);

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

    chooseSorts<LinkedList<double>>(type, 2, list4);

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

    chooseSorts<LinkedList<char>>(type, 1, list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    chooseSorts<LinkedList<char>>(type, 2, list6);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}



