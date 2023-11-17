#ifndef LAB2_SORTING_H
#define LAB2_SORTING_H
#include "Sequence.h"
#include "SmartPointers.h"


template <typename T>
void bubbleSort(DynamicArray<T>& arr) {
    int n = arr.getSize();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename U>
void bubbleSort(LinkedList<U>& list)  {
    int n = list.getSize();

    for (int i = 0; i < n - 1; ++i) {
        SmrtPtr<ListNode<U>> current = list.head;
        SmrtPtr<ListNode<U>> nextNode = list.head->next;

        for (int j = 0; j < n - i - 1; ++j) {
            if (current->data > nextNode->data) {
                U temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }

            current = nextNode;
            nextNode = nextNode->next;
        }
    }
}


#endif //LAB2_SORTING_H
