#include "Sequence.h"
#include "Sorting.h"


int main() {
    DynamicArray<int> array2(5);
    for (int i = 0; i < 5; ++i) {
        array2[i] = i;
    }

    array2.setIndex(8, 0);
    array2.setIndex(18, 2);
    array2.print();
    heapSort(array2, false);
    array2.print();

    LinkedList<int> list1;
    list1.push_back(3);
    list1.push_back(7);
    list1.push_back(5);
    list1.push_back(9);
    list1.push_back(1);
    list1.push_back(2);

    list1.print();
    heapSort(list1, false);
    list1.print();

    return 0;
}
