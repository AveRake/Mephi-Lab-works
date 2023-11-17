#include "Sequence.h"


int main() {
    DynamicArray<double> array2(5);

    LinkedList<double> list1;
    list1.push_back(15.1);
    list1.push_back(16.1);
    list1.push_back(17.1);
    list1.print();

    list1.pop_back();
    list1.print();

    list1.setIndex(27.1, 1);
    list1.print();

    list1.resize(4);
    list1.print();



    for (int i = 0; i < array2.getSize(); ++i) {
        array2[i] = i + 0.1;
    }
    array2.print();

    array2.resize(6);
    array2.setIndex(6.1, 5);
    array2.print();

    return 0;
}
