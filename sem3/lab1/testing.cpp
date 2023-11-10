#include "SmartPointer.h"
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
}
