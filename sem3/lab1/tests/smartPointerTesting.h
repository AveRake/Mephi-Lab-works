#ifndef SEM3LAB1_SMART_POINTER_TESTING_H
#define SEM3LAB1_SMART_POINTER_TESTING_H
#include "../mainPart/smartPointer.h"
#include <cassert>


template <typename T>
class TestHelper {
public:
    static void runTests() {
        testCreation();
        testAssignment();
        testDereference();
        testComparison();
        testModifiers();
    }

private:
    static void testCreation() {
        SmrtPtr<T> sp1(new T(42));
        assert(static_cast<bool>(sp1) == true);
        assert(sp1.unique());

        SmrtPtr<T> sp2;
        assert(static_cast<bool>(sp2) == false);

        SmrtPtr<T> sp3(new T(42));
        assert(static_cast<bool>(sp3) == true);
        sp3 = static_cast<const SmrtPtr<T>>(nullptr);
        assert(static_cast<bool>(sp3) == false);


        SmrtPtr<T[]> array1(new T[1]{42});
        assert(static_cast<bool>(sp1) == true);
        assert(array1.unique());

        SmrtPtr<T[]> array2;
        assert(static_cast<bool>(array2) == false);

        SmrtPtr<T[]> array3(new T[1]{42});
        assert(static_cast<bool>(array3) == true);
        array3 = static_cast<const SmrtPtr<T[]>>(nullptr);
        assert(static_cast<bool>(array3) == false);
    }

    static void testAssignment() {
        SmrtPtr<T> sp4(new T(42));
        const SmrtPtr<T>& sp5 = sp4;

        assert(static_cast<bool>(sp4) == true);
        assert(static_cast<bool>(sp5) == true);

        SmrtPtr<T> sp6(new T(42));
        SmrtPtr<T> sp7(new T(84));
        sp7 = sp6;

        assert(static_cast<bool>(sp6) == true);
        assert(static_cast<bool>(sp7) == true);


        SmrtPtr<T[]> array4(new T[5]{1, 2, 3, 4, 5});
        const SmrtPtr<T[]>& array5 = array4;

        assert(static_cast<bool>(array4) == true);
        assert(static_cast<bool>(array5) == true);

        SmrtPtr<T[]> array6(new T[2]{1, 2});
        SmrtPtr<T[]> array7(new T[2]{2, 4});
        array7 = array6;

        assert(static_cast<bool>(array6) == true);
        assert(static_cast<bool>(array7) == true);
    }

    static void testDereference() {
        SmrtPtr<T> sp8(new T(42));
        assert(*sp8 == 42);

        SmrtPtr<T> sp9(new T(42));
        SmrtPtr<T> sp10 = sp9;
        assert(*sp10 == 42);


        SmrtPtr<T[]> array8(new T[3]{1, 2, 3});
        assert(array8[0] != 42);
        assert(array8[1] == 2);
        assert(array8[2] == 3);

        SmrtPtr<T[]> array9(new T[1]{42});
        SmrtPtr<T[]> array10 = array9;
        assert(array10[0] == 42);
    }

    static void testComparison() {
        SmrtPtr<T> sp11(new T(42));
        SmrtPtr<T> sp12(new T(84));
        assert(sp11!= sp12);

        SmrtPtr<T> sp13(new T(42));
        SmrtPtr<T> sp14(new T(84));
        sp14 = sp13;
        assert(sp14 == sp13);


        SmrtPtr<T[]> array11(new T[5]{1, 2, 3, 4, 5});
        SmrtPtr<T[]> array12(new T[5]{0, 1, 2, 3, 4});
        assert(array11 != array12);

        SmrtPtr<T[]> array13(new T[3]{42, 13, 21});
        SmrtPtr<T[]> array14(new T[3]{84, 15, 15});
        array14 = array13;
        assert(array14 == array13);
    }

    static void testModifiers() {
        SmrtPtr<T> sp15(new T(42));
        *sp15 = 13;
        assert(*sp15 == 13);

        SmrtPtr<T> sp16(new T(42));
        assert(sp16.operator->() != nullptr);
        assert(*(sp16.operator->()) == 42);

        SmrtPtr<T> sp17(new T(42));
        SmrtPtr<T> sp18 = sp17;
        assert(sp18.operator->() != nullptr);
        assert(*(sp18.operator->()) == 42);

        SmrtPtr<T> sp19(new T(42));
        SmrtPtr<T> sp20(new T(84));
        sp20 = sp19;
        assert(sp20.operator->() != nullptr);
        assert(*(sp20.operator->()) == 42);


        SmrtPtr<T[]> array15(new T[5]{1, 2, 4, 8, 16});
        array15[0] = 13;
        array15[2] = 13;
        array15[4] = 13;
        assert(array15[0] == 13);
        assert(array15[1] == 2);
        assert(array15[2] == 13);
        assert(array15[3] == 8);
        assert(array15[4] == 13);

        SmrtPtr<T[]> array16(new T[1]{42});
        assert(array16.operator->() != nullptr);
        assert(*(array16.operator->()) == 42);

        SmrtPtr<T[]> array17(new T[1]{42});
        SmrtPtr<T[]> array18 = array17;
        assert(array18.operator->() != nullptr);
        assert(*(array18.operator->()) == 42);

        SmrtPtr<T[]> array19(new T[2]{42, 84});
        SmrtPtr<T[]> array20(new T[2]{84, 42});
        array20 = array19;
        assert(array20.operator->() != nullptr);
        assert(*(array20.operator->()) == 42);
        assert(*(array20.operator->()) != 84);
    }
};

#endif //SEM3LAB1_SMART_POINTER_TESTING_H
