#include "SequencesTesting.h"
#include "SortingMethodsTesting.h"


int main() {
    startDynamicArrayTests();
    startLinkedListTests();
    SortsTesting(1);
    SortsTesting(2);
    SortsTesting(3);
    SortsTesting(4);
    SortsTesting(5);

    cout << "All tests checked successfully!" << endl;
    return 0;
}