#include "../mainPart/smartPointer.h"
#include "smartPointerTesting.h"


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