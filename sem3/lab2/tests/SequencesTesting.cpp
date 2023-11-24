#include <cassert>
#include "SequencesTesting.h"


void startDynamicArrayTests() {
    //Dynamic Array (int)
    //Test 1
    DynamicArray<int> array1;
    array1.push_back(1);
    array1.push_back(2);
    array1.push_back(3);
    array1.push_back(4);
    array1.push_back(5);

    for (int i = 0; i < array1.getSize(); i++) {
        assert(array1[i] == i + 1);
    }

    //Test 2
    DynamicArray<int> array2;
    array2.push_back(2);
    array2.push_back(4);
    array2.push_back(6);
    array2.push_back(8);
    array2.push_back(10);

    assert(array2[0] == 2);
    assert(array2[1] == 4);
    assert(array2[2] == 6);
    assert(array2[3] == 8);
    assert(array2[4] == 10);

    //Test 3
    DynamicArray<int> array3;
    array3.push_back(1);
    array3.push_back(3);
    array3.push_back(5);
    array3.push_back(7);
    array3.push_back(9);

    assert(array3[0] == 1);
    assert(array3[1] == 3);
    assert(array3[2] == 5);
    assert(array3[3] == 7);
    assert(array3[4] == 9);

    //Test 4
    array1.pop_back();
    array1.pop_back();

    for (int i = 0; i < array1.getSize(); i++) {
        assert(array1[i] == i + 1);
    }

    //Test 5
    array2.pop_back();
    array2.pop_back();

    assert(array2[0] == 2);
    assert(array2[1] == 4);
    assert(array2[2] == 6);

    //Test 6
    array3.pop_back();
    array3.pop_back();

    assert(array3[0] == 1);
    assert(array3[1] == 3);
    assert(array3[2] == 5);

    //Test 7
    assert(array1.getSize() == 3);

    array1.push_back(4);
    array1.push_back(5);

    assert(array1.getSize() != 3);
    assert(array1.getSize() == 5);

    //Test 8
    assert(array2.getSize() == 3);

    array2.push_back(4);
    array2.push_back(5);
    array2.push_back(6);

    assert(array2.getSize() != 3);
    assert(array2.getSize() == 6);

    //Test 9
    assert(array3.getSize() == 3);

    array3.push_back(4);
    array3.push_back(5);
    array3.push_back(6);
    array3.push_back(7);

    assert(array3.getSize() != 3);
    assert(array3.getSize() == 7);

    //Test 10
    array1.setIndex(12, 0);
    array1.setIndex(15, 1);

    assert(array1[0] == 12);
    assert(array1[1] == 15);
    assert(array1[2] == 3);
    assert(array1[3] == 4);
    assert(array1[4] == 5);

    //Test 11
    array2.setIndex(12, 0);
    array2.setIndex(15, 1);

    assert(array2[0] == 12);
    assert(array2[1] == 15);
    assert(array2[2] == 6);
    assert(array2[3] == 4);
    assert(array2[4] == 5);
    assert(array2[5] == 6);

    //Test 12
    array3.setIndex(12, 0);
    array3.setIndex(15, 1);

    assert(array3[0] == 12);
    assert(array3[1] == 15);
    assert(array3[2] == 5);
    assert(array3[3] == 4);
    assert(array3[4] == 5);
    assert(array3[5] == 6);
    assert(array3[6] == 7);

    //Test 13
    array1.resize(2);
    assert(array1.getSize() == 2);
    assert(array1[0] == 12);
    assert(array1[1] == 15);

    //Test 14
    array2.resize(10);
    assert(array2.getSize() == 10);
    assert(array2[0] == 12);
    assert(array2[1] == 15);
    assert(array2[2] == 6);
    assert(array2[3] == 4);
    assert(array2[4] == 5);
    assert(array2[5] == 6);

    //Test 15
    array3.resize(2);
    assert(array3.getSize() == 2);
    assert(array3[0] == 12);
    assert(array3[1] == 15);

    // Test 16
    array3.resize(1);
    assert(array3.getSize() == 1);
    assert(array3[0] == 12);

    // Test 17
    array3.resize(0);
    assert(array3.getSize() == 0);


    //Dynamic Array (double)
    //Test 1
    DynamicArray<double> array4;
    array4.push_back(1.1);
    array4.push_back(2.1);
    array4.push_back(3.1);
    array4.push_back(4.1);
    array4.push_back(5.1);

    assert(array4[0] == 1.1);
    assert(array4[1] == 2.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 4.1);
    assert(array4[4] == 5.1);

    //Test 2
    DynamicArray<double> array5;
    array5.push_back(2.1);
    array5.push_back(4.1);
    array5.push_back(6.1);
    array5.push_back(8.1);
    array5.push_back(10.1);

    assert(array5[0] == 2.1);
    assert(array5[1] == 4.1);
    assert(array5[2] == 6.1);
    assert(array5[3] == 8.1);
    assert(array5[4] == 10.1);

    //Test 3
    DynamicArray<double> array6;
    array6.push_back(1.1);
    array6.push_back(3.1);
    array6.push_back(5.1);
    array6.push_back(7.1);
    array6.push_back(9.1);

    assert(array6[0] == 1.1);
    assert(array6[1] == 3.1);
    assert(array6[2] == 5.1);
    assert(array6[3] == 7.1);
    assert(array6[4] == 9.1);

    //Test 4
    array4.pop_back();
    array4.pop_back();

    for (int i = 0; i < array4.getSize(); i++) {
        assert(array4[i] == i + 1.1);
    }

    //Test 5
    array5.pop_back();
    array5.pop_back();

    assert(array5[0] == 2.1);
    assert(array5[1] == 4.1);
    assert(array5[2] == 6.1);

    //Test 6
    array6.pop_back();
    array6.pop_back();

    assert(array6[0] == 1.1);
    assert(array6[1] == 3.1);
    assert(array6[2] == 5.1);

    //Test 7
    assert(array4.getSize() == 3);

    array4.push_back(4.1);
    array4.push_back(5.1);

    assert(array4.getSize() != 3);
    assert(array4.getSize() == 5);

    //Test 8
    assert(array5.getSize() == 3);

    array5.push_back(4.1);
    array5.push_back(5.1);
    array5.push_back(6.1);

    assert(array5.getSize() != 3);
    assert(array5.getSize() == 6);

    //Test 9
    assert(array6.getSize() == 3);

    array6.push_back(4.1);
    array6.push_back(5.1);
    array6.push_back(6.1);
    array6.push_back(7.1);

    assert(array6.getSize() != 3);
    assert(array6.getSize() == 7);

    //Test 10
    array4.setIndex(12.1, 0);
    array4.setIndex(15.1, 1);

    assert(array4[0] == 12.1);
    assert(array4[1] == 15.1);
    assert(array4[2] == 3.1);
    assert(array4[3] == 4.1);
    assert(array4[4] == 5.1);

    //Test 11
    array5.setIndex(12.1, 0);
    array5.setIndex(15.1, 1);

    assert(array5[0] == 12.1);
    assert(array5[1] == 15.1);
    assert(array5[2] == 6.1);
    assert(array5[3] == 4.1);
    assert(array5[4] == 5.1);
    assert(array5[5] == 6.1);

    //Test 12
    array6.setIndex(12.1, 0);
    array6.setIndex(15.1, 1);

    assert(array6[0] == 12.1);
    assert(array6[1] == 15.1);
    assert(array6[2] == 5.1);
    assert(array6[3] == 4.1);
    assert(array6[4] == 5.1);
    assert(array6[5] == 6.1);
    assert(array6[6] == 7.1);

    //Test 13
    array4.resize(2);
    assert(array4.getSize() == 2);
    assert(array4[0] == 12.1);
    assert(array4[1] == 15.1);

    //Test 14
    array5.resize(10);
    assert(array5.getSize() == 10);
    assert(array5[0] == 12.1);
    assert(array5[1] == 15.1);
    assert(array5[2] == 6.1);
    assert(array5[3] == 4.1);
    assert(array5[4] == 5.1);
    assert(array5[5] == 6.1);

    //Test 15
    array6.resize(2);
    assert(array6.getSize() == 2);
    assert(array6[0] == 12.1);
    assert(array6[1] == 15.1);

    // Test 16
    array6.resize(1);
    assert(array6.getSize() == 1);
    assert(array6[0] == 12.1);

    // Test 17
    array6.resize(0);
    assert(array6.getSize() == 0);


    //Dynamic Array (char)
    //Test 1
    DynamicArray<char> array7;
    array7.push_back(1);
    array7.push_back(2);
    array7.push_back(3);
    array7.push_back(4);
    array7.push_back(5);

    for (int i = 0; i < array7.getSize(); i++) {
        assert(array7[i] == i + 1);
    }

    //Test 2
    DynamicArray<char> array8;
    array8.push_back(2);
    array8.push_back(4);
    array8.push_back(6);
    array8.push_back(8);
    array8.push_back(10);

    assert(array8[0] == 2);
    assert(array8[1] == 4);
    assert(array8[2] == 6);
    assert(array8[3] == 8);
    assert(array8[4] == 10);

    //Test 3
    DynamicArray<char> array9;
    array9.push_back(1);
    array9.push_back(3);
    array9.push_back(5);
    array9.push_back(7);
    array9.push_back(9);

    assert(array9[0] == 1);
    assert(array9[1] == 3);
    assert(array9[2] == 5);
    assert(array9[3] == 7);
    assert(array9[4] == 9);

    //Test 4
    array7.pop_back();
    array7.pop_back();

    for (int i = 0; i < array7.getSize(); i++) {
        assert(array7[i] == i + 1);
    }

    //Test 5
    array8.pop_back();
    array8.pop_back();

    assert(array8[0] == 2);
    assert(array8[1] == 4);
    assert(array8[2] == 6);

    //Test 6
    array9.pop_back();
    array9.pop_back();

    assert(array9[0] == 1);
    assert(array9[1] == 3);
    assert(array9[2] == 5);

    //Test 7
    assert(array7.getSize() == 3);

    array7.push_back(4);
    array7.push_back(5);

    assert(array7.getSize() != 3);
    assert(array7.getSize() == 5);

    //Test 8
    assert(array8.getSize() == 3);

    array8.push_back(4);
    array8.push_back(5);
    array8.push_back(6);

    assert(array8.getSize() != 3);
    assert(array8.getSize() == 6);

    //Test 9
    assert(array9.getSize() == 3);

    array9.push_back(4);
    array9.push_back(5);
    array9.push_back(6);
    array9.push_back(7);

    assert(array9.getSize() != 3);
    assert(array9.getSize() == 7);

    //Test 10
    array7.setIndex(12, 0);
    array7.setIndex(15, 1);

    assert(array7[0] == 12);
    assert(array7[1] == 15);
    assert(array7[2] == 3);
    assert(array7[3] == 4);
    assert(array7[4] == 5);

    //Test 11
    array8.setIndex(12, 0);
    array8.setIndex(15, 1);

    assert(array8[0] == 12);
    assert(array8[1] == 15);
    assert(array8[2] == 6);
    assert(array8[3] == 4);
    assert(array8[4] == 5);
    assert(array8[5] == 6);

    //Test 12
    array9.setIndex(12, 0);
    array9.setIndex(15, 1);

    assert(array9[0] == 12);
    assert(array9[1] == 15);
    assert(array9[2] == 5);
    assert(array9[3] == 4);
    assert(array9[4] == 5);
    assert(array9[5] == 6);
    assert(array9[6] == 7);

    //Test 13
    array7.resize(2);
    assert(array7.getSize() == 2);
    assert(array7[0] == 12);
    assert(array7[1] == 15);

    //Test 14
    array8.resize(10);
    assert(array8.getSize() == 10);
    assert(array8[0] == 12);
    assert(array8[1] == 15);
    assert(array8[2] == 6);
    assert(array8[3] == 4);
    assert(array8[4] == 5);
    assert(array8[5] == 6);

    //Test 15
    array9.resize(2);
    assert(array9.getSize() == 2);
    assert(array9[0] == 12);
    assert(array9[1] == 15);

    // Test 16
    array9.resize(1);
    assert(array9.getSize() == 1);
    assert(array9[0] == 12);

    // Test 17
    array9.resize(0);
    assert(array9.getSize() == 0);
}


void startLinkedListTests() {
    // Tests for Linked list
    // Test 1
    LinkedList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    assert(intList.getSize() == 3);

    intList.pop_back();
    assert(intList.getSize() == 2);

    intList.setIndex(10, 0);
    assert(intList.getNodeAt(0)->data == 10);

    intList.resize(5);
    assert(intList.getSize() == 5);

    // Test 2
    LinkedList<double> doubleList;
    doubleList.push_back(1.1);
    doubleList.push_back(2.2);
    doubleList.push_back(3.3);

    assert(doubleList.getSize() == 3);

    doubleList.pop_back();
    assert(doubleList.getSize() == 2);

    doubleList.setIndex(5.5, 0);
    assert(doubleList.getNodeAt(0)->data == 5.5);

    doubleList.resize(4);
    assert(doubleList.getSize() == 4);

    // Test 3
    LinkedList<char> charList;
    charList.push_back('a');
    charList.push_back('b');
    charList.push_back('c');

    assert(charList.getSize() == 3);

    charList.pop_back();
    assert(charList.getSize() == 2);

    charList.setIndex('z', 0);
    assert(charList.getNodeAt(0)->data == 'z');

    charList.resize(4);
    assert(charList.getSize() == 4);

    // Test 4
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    assert(list1.getSize() == 2);
    assert(list1.getNodeAt(0)->data == 1);
    assert(list1.getNodeAt(1)->data == 2);

    // Test 5
    LinkedList<double> doubleList1;
    doubleList1.push_back(3.5);
    doubleList1.push_back(2.8);
    doubleList1.pop_back();
    assert(doubleList1.getSize() == 1);
    assert(doubleList1.getNodeAt(0)->data == 3.5);

    // Test 6
    LinkedList<char> charList1;
    charList1.push_back('a');
    charList1.push_back('b');
    assert(charList1.getSize() == 2);
    assert(charList1.getNodeAt(1)->data == 'b');

    // Test 7
    LinkedList<int> intList1;
    intList1.push_back(5);
    intList1.push_back(10);
    intList1.setIndex(7, 0);
    assert(intList1.getNodeAt(0)->data == 7);

    // Test 8
    LinkedList<int> intList3;
    intList3.push_back(1);
    intList3.push_back(2);
    intList3.push_back(3);

    assert(intList3.getSize() == 3);

    intList3.pop_back();
    assert(intList3.getSize() == 2);

    intList3.setIndex(10, 0);
    intList3.setIndex(20, 1);

    assert(intList3.getNodeAt(0)->data == 10);
    assert(intList3.getNodeAt(1)->data == 20);

    // Test 9
    LinkedList<double> doubleList2;
    doubleList2.push_back(1.5);
    doubleList2.push_back(2.5);
    doubleList2.push_back(3.5);

    assert(doubleList2.getSize() == 3);

    doubleList2.pop_back();
    assert(doubleList2.getSize() == 2);

    doubleList2.setIndex(15.5, 0);
    doubleList2.setIndex(25.5, 1);

    assert(doubleList2.getNodeAt(0)->data == 15.5);
    assert(doubleList2.getNodeAt(1)->data == 25.5);

    // Test 10
    LinkedList<char> charList2;
    charList2.push_back('a');
    charList2.push_back('b');
    charList2.push_back('c');

    assert(charList2.getSize() == 3);

    charList2.pop_back();
    assert(charList2.getSize() == 2);

    charList2.setIndex('x', 0);
    charList2.setIndex('y', 1);

    assert(charList2.getNodeAt(0)->data == 'x');
    assert(charList2.getNodeAt(1)->data == 'y');

    // Test 11
    LinkedList<int> intLists;
    intLists.push_back(1);
    intLists.push_back(2);
    intLists.push_back(3);
    assert(intLists.getSize() == 3);

    // Test 12
    assert(intLists.getNodeAt(0)->data == 1);
    assert(intLists.getNodeAt(1)->data == 2);
    assert(intLists.getNodeAt(2)->data == 3);

    // Test 13
    intLists.pop_back();
    assert(intLists.getSize() == 2);

    intLists.resize(4);
    assert(intLists.getSize() == 4);

    // Test 14
    LinkedList<double> doubleLists;
    doubleLists.push_back(1.5);
    doubleLists.push_back(2.5);
    doubleLists.push_back(3.5);
    assert(doubleLists.getSize() == 3);

    // Test 15
    assert(doubleLists.getNodeAt(0)->data == 1.5);
    assert(doubleLists.getNodeAt(1)->data == 2.5);
    assert(doubleLists.getNodeAt(2)->data == 3.5);

    doubleLists.pop_back();
    assert(doubleLists.getSize() == 2);

    doubleLists.resize(4);
    assert(doubleLists.getSize() == 4);

    doubleLists.setIndex(15.5, 1);
    assert(doubleLists.getNodeAt(1)->data == 15.5);
};