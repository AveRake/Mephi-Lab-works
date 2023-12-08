#include "smartPointer.h"
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
    }

    static void testDereference() {
        SmrtPtr<T> sp8(new T(42));
        assert(*sp8 == 42);

        SmrtPtr<T> sp9(new T(42));
        SmrtPtr<T> sp10 = sp9;
        assert(*sp10 == 42);
    }

    static void testComparison() {
        SmrtPtr<T> sp11(new T(42));
        SmrtPtr<T> sp12(new T(84));
        assert(sp11!= sp12);

        SmrtPtr<T> sp13(new T(42));
        SmrtPtr<T> sp14(new T(84));
        sp14 = sp13;
        assert(sp14 == sp13);
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
    }
};


int main() {
    TestHelper<int>::runTests();
    TestHelper<double>::runTests();
    TestHelper<float>::runTests();
    TestHelper<char>::runTests();

    cout << "All tests were checked successfully!" << endl;
    cout << "Press any bottom to end the programme" << endl;
    cin.get();
    return 0;
}
