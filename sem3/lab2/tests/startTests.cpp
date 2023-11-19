#include "SequencesTesting.h"
#include "SortingMethodsTesting.h"


int main() {
    startDynamicArrayTests();
    startLinkedListTests();
    bubbleSortTesting();
    insertionSortTesting();
    mergeSortTesting();
    shellSortTesting();
    heapSortTesting();

    cout << "All tests checked successfully!" << endl;
    return 0;
}