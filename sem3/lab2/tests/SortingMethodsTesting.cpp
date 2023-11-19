#include "SortingMethodsTesting.h"


void bubbleSortTesting() {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    bubbleSort(array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    bubbleSort(array1, false);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == 4 - i);
    }

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    bubbleSort(array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    bubbleSort(array4, false);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    bubbleSort(array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    bubbleSort(array6, false);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    bubbleSort(list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    bubbleSort(list2, false);

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

    bubbleSort(list3);

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

    bubbleSort(list4, false);

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

    bubbleSort(list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    bubbleSort(list6, false);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}


void insertionSortTesting() {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    insertionSort(array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    insertionSort(array1, false);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == 4 - i);
    }

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    insertionSort(array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    insertionSort(array4, false);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    insertionSort(array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    insertionSort(array6, false);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    insertionSort(list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    insertionSort(list2, false);

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

    insertionSort(list3);

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

    insertionSort(list4, false);

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

    insertionSort(list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    insertionSort(list6, false);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}


void mergeSortTesting() {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    mergeSort(array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    mergeSort(array1, false);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == 4 - i);
    }

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    mergeSort(array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    mergeSort(array4, false);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    mergeSort(array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    mergeSort(array6, false);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    mergeSort(list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    mergeSort(list2, false);

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

    mergeSort(list3);

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

    mergeSort(list4, false);

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

    mergeSort(list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    mergeSort(list6, false);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}


void shellSortTesting() {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    shellSort(array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    shellSort(array1, false);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == 4 - i);
    }

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    shellSort(array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    shellSort(array4, false);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    shellSort(array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    shellSort(array6, false);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    shellSort(list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    shellSort(list2, false);

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

    shellSort(list3);

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

    shellSort(list4, false);

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

    shellSort(list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    shellSort(list6, false);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}


void heapSortTesting() {
    // Test 1
    DynamicArray<int> array1;
    for (int i = 0; i < 5; ++i) {
        array1.push_back(i);
    }

    heapSort(array1);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == i);
    }

    // Test 2
    DynamicArray<int> array2;
    for (int i = 0; i < 5; ++i) {
        array2.push_back(i);
    }

    heapSort(array1, false);

    for (int i = 0; i < 5; i++) {
        assert(array1[i] == 4 - i);
    }

    // Test 3
    DynamicArray<double> array3;
    array3.push_back(3.1);
    array3.push_back(2.1);
    array3.push_back(4.1);
    array3.push_back(1.1);
    array3.push_back(5.1);

    heapSort(array3);

    assert(array3[0] == 1.1);
    assert(array3[1] == 2.1);
    assert(array3[2] == 3.1);
    assert(array3[3] == 4.1);
    assert(array3[4] == 5.1);

    // Test 4
    DynamicArray<double> array4;
    array4.push_back(3.1);
    array4.push_back(2.1);
    array4.push_back(4.1);
    array4.push_back(1.1);
    array4.push_back(5.1);

    heapSort(array4, false);

    assert(array4[0] == 5.1);
    assert(array4[1] == 4.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 2.1);
    assert(array4[4] == 1.1);

    // Test 5
    DynamicArray<char> array5;
    for (int i = 0; i < 5; ++i) {
        array5.push_back(i);
    }

    heapSort(array5);

    for (int i = 0; i < 5; i++) {
        assert(array5[i] == i);
    }

    // Test 6
    DynamicArray<char> array6;
    for (int i = 0; i < 5; ++i) {
        array6.push_back(i);
    }

    heapSort(array6, false);

    for (int i = 0; i < 5; i++) {
        assert(array6[i] == 4 - i);
    }


    // Test 7
    LinkedList<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }

    heapSort(list1);

    for (int i = 0; i < 5; i++) {
        assert(list1.getNodeAt(i)->data == i);
    }

    // Test 8
    LinkedList<int> list2;
    for (int i = 0; i < 5; ++i) {
        list2.push_back(i);
    }

    heapSort(list2, false);

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

    heapSort(list3);

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

    heapSort(list4, false);

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

    heapSort(list5);

    for (int i = 0; i < 5; i++) {
        assert(list5.getNodeAt(i)->data == i);
    }

    // Test 12
    LinkedList<char> list6;
    for (int i = 0; i < 5; ++i) {
        list6.push_back(i);
    }

    heapSort(list6, false);

    for (int i = 0; i < 5; i++) {
        assert(list6.getNodeAt(i)->data == 4 - i);
    }
}