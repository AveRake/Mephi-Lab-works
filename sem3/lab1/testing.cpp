#include "SmartPointer.h"
#include "Sequence.h"
#include <cassert>


int main () {
    // Tests for the operator bool, ==
    // Тест 1
    SmrtPtr<int> sp1(new int(42));
    assert(static_cast<bool>(sp1) == true);

    // Тест 2
    SmrtPtr<int> sp2;
    assert(static_cast<bool>(sp2) == false);

    // Тест 3
    SmrtPtr<int> sp3(new int(42));
    assert(static_cast<bool>(sp3) == true);

    sp3 = static_cast<const SmrtPtr<int>>(nullptr);
    assert(static_cast<bool>(sp3) == false);

    // Тест 4
    SmrtPtr<int> sp4(new int(42));
    const SmrtPtr<int>& sp5 = sp4;

    assert(static_cast<bool>(sp4) == true);
    assert(static_cast<bool>(sp5) == true);

    // Тест 5
    SmrtPtr<int> spd6(new int(42));
    SmrtPtr<int> spd7(new int(84));
    spd7 = spd6;

    assert(static_cast<bool>(spd6) == true);
    assert(static_cast<bool>(spd7) == true);

    // Тест 6
    SmrtPtr<double> spd1(new double(42.1));
    assert(static_cast<bool>(spd1) == true);

    // Тест 7
    SmrtPtr<double> spd2;
    assert(static_cast<bool>(spd2) == false);

    // Тест 8
    SmrtPtr<double> spd3(new double(42.2));
    assert(static_cast<bool>(spd3) == true);

    spd3 = static_cast<const SmrtPtr<double>>(nullptr);
    assert(static_cast<bool>(spd3) == false);

    // Тест 9
    SmrtPtr<double> spd4(new double(42.32));
    const SmrtPtr<double>& spd5 = spd4;

    assert(static_cast<bool>(spd4) == true);
    assert(static_cast<bool>(spd5) == true);

    // Тест 10
    SmrtPtr<double> sp6(new double(42.1));
    SmrtPtr<double> sp7(new double(84.1));
    sp7 = sp6;

    assert(static_cast<bool>(sp6) == true);
    assert(static_cast<bool>(sp7) == true);


    //  Tests for the operator *, ==, !=
    // Test 1
    SmrtPtr<int> sp11(new int(42));
    assert(*sp11 == 42);

    // Test 2
    SmrtPtr<int> sp13(new int(42));
    SmrtPtr<int> sp14 = sp13;
    assert(*sp14 == 42);

    // Test 3
    SmrtPtr<int> sp15(new int(42));
    SmrtPtr<int> sp16(new int(84));
    sp16 = sp15;
    assert(*sp16 == 42);

    // Test 4
    SmrtPtr<int> sp17(new int(54));
    *sp17 = 13;
    assert(*sp17 == 13);

    // Test 5
    SmrtPtr<double> spd11(new double(42.1));
    assert(*spd11 == 42.1);

    // Test 6
    SmrtPtr<double> spd13(new double(42.1));
    SmrtPtr<double> spd14 = spd13;
    assert(*spd14 == 42.1);

    // Test 7
    SmrtPtr<double> spd15(new double(42.123));
    SmrtPtr<double> spd16(new double(84.2));
    spd16 = spd15;
    assert(*spd16 == 42.123);

    // Test 8
    SmrtPtr<double> spd17(new double(54.3));
    *spd17 = 13.1;
    assert(*spd17 == 13.1);


    //  Tests for the operator ->, ==, !=
    // Test 1
    SmrtPtr<int> sp21(new int(42));
    assert(sp21.operator->() != nullptr);
    assert(*(sp21.operator->()) == 42);

    // Test 2
    SmrtPtr<int> sp24(new int(42));
    SmrtPtr<int> sp25 = sp24;
    assert(sp25.operator->() != nullptr);
    assert(*(sp25.operator->()) == 42);

    // Test 3
    SmrtPtr<int> sp26(new int(42));
    SmrtPtr<int> sp27(new int(84));
    sp27 = sp26;
    assert(sp27.operator->() != nullptr);
    assert(*(sp27.operator->()) == 42);

    // Test 4
    SmrtPtr<double> spd21(new double(42.1));
    assert(spd21.operator->() != nullptr);
    assert(*(spd21.operator->()) == 42.1);

    // Test 5
    SmrtPtr<double> spd24(new double(42.1));
    SmrtPtr<double> spd25 = spd24;
    assert(spd25.operator->() != nullptr);
    assert(*(spd25.operator->()) == 42.1);

    // Test 6
    SmrtPtr<double> spd26(new double(42.2));
    SmrtPtr<double> spd27(new double(84.2));
    spd27 = spd26;
    assert(spd27.operator->() != nullptr);
    assert(*(spd27.operator->()) == 42.2);


    // Tests for the operator [], ==
    //Test 1
    SmrtPtr<int> sp31(new int[5]{1, 2, 3, 4, 5}, 5);

    for (size_t i = 0; i < 5; ++i) {
        assert(sp31.operator[](i) == i + 1);
    }

    //Test 2
    SmrtPtr<int> sp32(new int[3]{1, 2, 3}, 3);
    sp32.operator[](1) = 10;
    assert(sp32.operator[](1) == 10);

    //Test 3
    SmrtPtr<int> sp33;
    try {
        sp33.operator[](0);
        assert(false);
    } catch (const exception& e) {
        assert(true);
    }

    //Test 4
    SmrtPtr<int> sp44(new int[4]{1, 2, 3, 4}, 4);
    const SmrtPtr<int>& sp45 = sp44;

    for (size_t i = 0; i < 4; ++i) {
        assert(sp45.operator[](i) == i + 1);
    }

    //Test 5
    SmrtPtr<int> sp46(new int[3]{1, 2, 3}, 3);
    SmrtPtr<int> sp47(new int[3]{4, 5, 6}, 3);
    sp47 = sp46;

    for (size_t i = 0; i < 3; ++i) {
        assert(sp47.operator[](i) == i + 1);
    }

    //Test 6
    SmrtPtr<double> spd31(new double[5]{1.5, 2.5, 3.5, 4.5, 5.5}, 5);

    for (size_t i = 0; i < 5; ++i) {
        assert(spd31.operator[](i) == i + 1.5);
    }

    //Test 7
    SmrtPtr<double> spd32(new double[3]{1.5, 2.5, 3.5}, 3);
    spd32.operator[](1) = 10.5;
    assert(spd32.operator[](1) == 10.5);

    //Test 8
    SmrtPtr<double> spd33;
    try {
        spd33.operator[](0);
        assert(false);
    } catch (const exception& e) {
        assert(true);
    }

    //Test 9
    SmrtPtr<double> spd44(new double[4]{1.5, 2.5, 3.5, 4.5}, 4);
    const SmrtPtr<double>& spd45 = spd44;

    for (size_t i = 0; i < 4; ++i) {
        assert(spd45.operator[](i) == i + 1.5);
    }

    //Test 10
    SmrtPtr<double> spd46(new double[3]{1.5, 2.5, 3.5}, 3);
    SmrtPtr<double> spd47(new double[3]{4.5, 5.5, 6.5}, 3);
    spd47 = spd46;

    for (size_t i = 0; i < 3; ++i) {
        assert(spd47.operator[](i) == i + 1.5);
    }


    // Tests for the operator =, ==
    //Test 1
    SmrtPtr<int> sp51(new int(42));
    SmrtPtr<int> sp52;
    sp52 = sp51;
    assert(*sp52 == 42);

    //Test 2
    SmrtPtr<int> sp53(new int[3]{1, 2, 3}, 3);
    SmrtPtr<int> sp54;
    sp54 = sp53;

    for (size_t i = 0; i < 3; ++i) {
        assert(sp54.operator[](i) == i + 1);
    }

    //Test 3
    SmrtPtr<int> sp55(new int(10));
    sp55 = sp55;
    assert(*sp55 == 10);

    //Test 4
    SmrtPtr<int> sp56(new int(5));
    SmrtPtr<int> sp57;
    sp57 = sp56;
    sp57 = static_cast<const SmrtPtr<int>>(nullptr);
    assert(!sp57);

    //Test 5
    SmrtPtr<double> spd51(new double(42.3));
    SmrtPtr<double> spd52;
    spd52 = spd51;
    assert(*spd52 == 42.3);

    //Test 6
    SmrtPtr<double> spd53(new double[3]{1.5, 2.5, 3.5}, 3);
    SmrtPtr<double> spd54;
    spd54 = spd53;

    for (size_t i = 0; i < 3; ++i) {
        assert(spd54.operator[](i) == i + 1.5);
    }

    //Test 7
    SmrtPtr<double> spd55(new double(10.1));
    spd55 = spd55;
    assert(*spd55 == 10.1);

    //Test 8
    SmrtPtr<double> spd56(new double(5.1));
    SmrtPtr<double> spd57;
    spd57 = spd56;
    spd57 = static_cast<const SmrtPtr<double>>(nullptr);
    assert(!spd57);


    // Tests for push_back Dynamic Array
    // Test 1
    DynamicArray<int> arr1;
    arr1.push_back(42);
    assert(arr1.getSize() == 1);
    assert(arr1[0] == 42);

    // Test 2
    DynamicArray<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    assert(arr2.getSize() == 3);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);

    // Test 3
    DynamicArray<int> arr3;
    arr3.push_back(5);
    arr3.push_back(10);
    arr3.resize(3);
    arr3.push_back(15);
    assert(arr3.getSize() == 4);
    assert(arr3[0] == 5);
    assert(arr3[1] == 10);
    assert(arr3[2] == 0);
    assert(arr3[3] == 15);


    // Tests for pop_back (dynamic array)
    // Test 1
    DynamicArray<int> arr11;
    assert(arr11.getSize() == 0);
    arr11.pop_back();
    assert(arr11.getSize() == 0);

    // Test 2
    DynamicArray<int> arr22;
    arr22.push_back(1);
    arr22.push_back(2);
    arr22.push_back(3);

    assert(arr22.getSize() == 3);
    arr22.pop_back();
    assert(arr22.getSize() == 2);

    assert(arr22[0] == 1);
    assert(arr22[1] == 2);

    // Test 3
    DynamicArray<int> arr33;
    arr33.push_back(1);
    arr33.push_back(2);
    arr33.push_back(3);

    assert(arr33.getSize() == 3);

    while (arr33.getSize() > 0) {
        arr33.pop_back();
    }

    assert(arr33.getSize() == 0);

    // Test 4
    DynamicArray<int> arr44;
    assert(arr44.getSize() == 0);

    arr44.resize(10);
    assert(arr44.getSize() == 10);

    arr44.pop_back();
    assert(arr44.getSize() == 9);


    // Test for resize (dynamic array)
    // Test 1
    DynamicArray<int> arr111;
    arr111.resize(5);

    assert(arr111.getSize() == 5);
    for (int i = 0; i < 5; ++i) {
        arr111[i] = i;
    }

    arr111.resize(3);
    assert(arr111.getSize() == 3);

    for (int i = 0; i < 3; ++i) {
        assert(arr111[i] == i);
    }

    // Test 2
    DynamicArray<int> arr333;
    arr333.resize(4);

    assert(arr333.getSize() == 4);

    for (int i = 0; i < 4; ++i) {
        arr333[i] = i;
    }

    arr333.resize(4);
    assert(arr333.getSize() == 4);

    for (int i = 0; i < 4; ++i) {
        assert(arr333[i] == i);  // Values should remain unchanged
    }

    // Test 3
    DynamicArray<int> arr444;
    arr444.resize(5);
    assert(arr444.getSize() == 5);
    assert(arr444.getSize() == 5);


    // Tests for (dynamic array)
    // Test 1
    DynamicArray<int> arr1111;
    assert(arr1111.getSize() == 0);

    // Test 2
    DynamicArray<int> arr2222;
    arr2222.push_back(1);
    arr2222.push_back(2);
    arr2222.push_back(3);
    assert(arr2222.getSize() == 3);

    // Test 3
    DynamicArray<int> arr3333;
    arr3333.push_back(1);
    arr3333.push_back(2);
    arr3333.resize(5);
    assert(arr3333.getSize() == 5);

    // Test 4
    DynamicArray<int> arr4444;
    arr4444.push_back(1);
    arr4444.push_back(2);
    arr4444.pop_back();
    assert(arr4444.getSize() == 1);

    // Test 5
    DynamicArray<int> arr5555;
    arr5555.push_back(1);
    arr5555.push_back(2);
    arr5555.pop_back();
    arr5555.push_back(3);
    arr5555.resize(10);
    assert(arr5555.getSize() == 10);


    // Tests for print (dynamic array)
    // Test 1
    DynamicArray<int> arr11111;
    assert(arr11111.getSize() == 0);

    // Test 2
    DynamicArray<int> arr22222;
    arr22222.push_back(1);
    arr22222.push_back(2);
    arr22222.push_back(3);
    assert(arr22222.getSize() == 3);

    // Test 3
    DynamicArray<int> arr33333;
    arr33333.push_back(1);
    arr33333.push_back(2);
    arr33333.resize(5);
    assert(arr33333.getSize() == 5);

    // Test 4
    DynamicArray<int> arr44444;
    arr44444.push_back(1);
    arr44444.push_back(2);
    arr44444.pop_back();
    assert(arr44444.getSize() == 1);

    // Test 5
    DynamicArray<int> arr55555;
    arr55555.push_back(1);
    arr55555.push_back(2);
    arr55555.pop_back();
    arr55555.push_back(3);
    arr55555.resize(10);
    assert(arr55555.getSize() == 10);


    // Tests for print(linked list)
    // Test 1
    LinkedList<int> list1;
    assert(list1.getSize() == 0);

    // Test 2:
    LinkedList<int> list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    assert(list2.getSize() == 3);

    // Test 3:
    LinkedList<int> list3;
    list3.push_back(1);
    list3.push_back(2);
    list3.resize(5);
    assert(list3.getSize() == 5);

    // Test 4:
    LinkedList<int> list4;
    list4.push_back(1);
    list4.push_back(2);
    list4.pop_back();
    assert(list4.getSize() == 1);

    // Test 5:
    LinkedList<int> list5;
    list5.push_back(1);
    list5.push_back(2);
    list5.pop_back();
    list5.push_back(3);
    list5.resize(10);
    assert(list5.getSize() == 10);


    // Tests for push_back (linked list)
    // Test 1
    LinkedList<int> list11;
    list11.push_back(1);
    assert(list11.getSize() == 1);

    // Test 2
    LinkedList<int> list12;
    list12.push_back(1);
    list12.push_back(2);
    assert(list12.getSize() == 2);

    // Test 3
    LinkedList<int> list13;
    list13.push_back(1);
    list13.push_back(2);
    list13.pop_back();
    list13.push_back(3);
    assert(list13.getSize() == 2);

    // Test 4
    LinkedList<int> list16;
    list16.push_back(1);
    list16.push_back(2);
    list16.push_back(3);
    assert(list16.getSize() == 3);


    // Tests for pop_back (linked list)
    // Test 1
    LinkedList<int> list21;
    assert(list21.getSize() == 0);

    // Test 2
    LinkedList<int> list22;
    list22.push_back(1);
    list22.pop_back();
    assert(list22.getSize() == 0);

    // Test 3
    LinkedList<int> list23;
    list23.push_back(1);
    list23.push_back(2);
    list23.push_back(3);
    list23.pop_back();
    assert(list23.getSize() == 2);

    // Test 4
    LinkedList<int> list24;
    list24.push_back(1);
    list24.push_back(2);
    list24.push_back(3);
    list24.pop_back();
    list24.pop_back();
    assert(list24.getSize() == 1);

    // Test 5
    LinkedList<int> list25;
    list25.resize(5);
    list25.pop_back();
    assert(list25.getSize() == 4);

    // Test 6
    LinkedList<int> list26;
    list26.resize(5);
    list26.pop_back();
    assert(list26.getSize() == 4);


    // Tests for resize (linked list)
    // Test 1
    LinkedList<int> list31;
    list31.push_back(1);
    list31.push_back(2);
    list31.push_back(3);
    list31.resize(2);
    assert(list31.getSize() == 2);

    // Test 2
    LinkedList<int> list32;
    list32.push_back(1);
    list32.push_back(2);
    list32.push_back(3);
    list32.resize(3);
    assert(list32.getSize() == 3);

    // Test 3
    LinkedList<int> list33;
    list33.push_back(1);
    list33.push_back(2);
    list33.push_back(3);
    list33.resize(5);
    assert(list33.getSize() == 5);

    // Test 4
    LinkedList<int> list34;
    list34.push_back(1);
    list34.push_back(2);
    list34.push_back(3);
    assert(list34.getSize() == 3);

    // Test 5
    LinkedList<int> list35;
    list35.resize(5);
    assert(list35.getSize() == 5);

    // Test 6
    LinkedList<int> list36;
    assert(list36.getSize() == 0);


    // Tests for getSize (linked list)
    // Test 1
    LinkedList<int> list41;
    assert(list41.getSize() == 0);

    // Test 2
    LinkedList<int> list42;
    list42.push_back(1);
    list42.push_back(2);
    list42.push_back(3);
    assert(list42.getSize() == 3);

    // Test 3
    LinkedList<int> list43;
    list43.push_back(1);
    list43.push_back(2);
    list43.push_back(3);
    list43.pop_back();
    assert(list43.getSize() == 2);

    // Test 4
    LinkedList<int> list44;
    list44.push_back(1);
    list44.push_back(2);
    list44.push_back(3);
    list44.resize(5);
    assert(list44.getSize() == 5);

    // Test 5
    LinkedList<int> list45;
    list45.push_back(1);
    list45.push_back(2);
    list45.push_back(3);
    list45.resize(2);
    assert(list45.getSize() == 2);

    // Test 6
    LinkedList<int> list46;
    list46.push_back(1);
    list46.push_back(2);
    list46.push_back(3);
    list46.resize(3);
    assert(list46.getSize() == 3);

    // Test 7
    LinkedList<int> list47;
    list47.push_back(1);
    list47.push_back(2);
    list47.push_back(3);
    assert(list47.getSize() == 3);


    cout << "All tests were checked successfully!" << endl;
}
