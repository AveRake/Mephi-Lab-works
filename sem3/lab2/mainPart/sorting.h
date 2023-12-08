#ifndef LAB2_SORTING_H
#define LAB2_SORTING_H
#include "sequence.h"
#include "smartPointers.h"


// Bubble sorting

template <typename T>
void bubbleSort(DynamicArray<T>& arr, bool ascending = true) {
    int n = arr.getSize();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename U>
void bubbleSort(LinkedList<U>& list, bool ascending = true)  {
    int n = list.getSize();

    for (int i = 0; i < n - 1; ++i) {
        SmrtPtr<ListNode<U>> current = list.head;
        SmrtPtr<ListNode<U>> nextNode = list.head->next;

        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && current->data > nextNode->data) || (!ascending && current->data < nextNode->data)) {
                U temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }

            current = nextNode;
            nextNode = nextNode->next;
        }
    }
}


// Insertion sorting

template <typename T>
void insertionSort(DynamicArray<T>& arr, bool ascending = true) {
    int n = arr.getSize();

    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && (ascending ? arr[j] > key : arr[j] < key)) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}


template <typename U>
void insertionSort(LinkedList<U>& list, bool ascending = true) {
    if (!list.head || !list.head->next) {
        return;
    }

    SmrtPtr<ListNode<U>> sorted = SmrtPtr<ListNode<U>>();

    while (list.head) {
        SmrtPtr<ListNode<U>> current = list.head;
        list.head = list.head->next;

        if (!sorted || (ascending ? sorted->data > current->data : sorted->data < current->data)) {
            current->next = sorted;
            sorted = current;
        } else {
            SmrtPtr<ListNode<U>> temp = sorted;

            while (temp->next && (ascending ? temp->next->data < current->data : temp->next->data > current->data)) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }
    }

    list.head = sorted;
}


// Merge Sorting

template <typename T>
void merge(DynamicArray<T>& arr, int left, int mid, int right, bool ascending = true) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    DynamicArray<T> leftArray(n1);
    DynamicArray<T> rightArray(n2);

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if ((ascending && leftArray[i] <= rightArray[j]) || (!ascending && leftArray[i] >= rightArray[j])) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSort(DynamicArray<T>& arr, int left, int right, bool ascending = true) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);

        merge(arr, left, mid, right, ascending);
    }
}

template <typename T>
void mergeSort(DynamicArray<T>& arr, bool ascending = true) {
    mergeSort(arr, 0, arr.getSize() - 1, ascending);
}


template <typename U>
SmrtPtr<ListNode<U>> merge(LinkedList<U>& list, SmrtPtr<ListNode<U>> left, SmrtPtr<ListNode<U>> right, bool ascending = true) {
    SmrtPtr<ListNode<U>> temp = SmrtPtr<ListNode<U>>();
    SmrtPtr<ListNode<U>> current;

    while (left && right) {
        bool condition = (ascending) ? (left->data <= right->data) : (left->data >= right->data);

        if (condition) {
            if (!temp) {
                temp = left;
                current = left;
            } else {
                current->next = left;
                current = left;
            }
            left = std::move(left->next);
        } else {
            if (!temp) {
                temp = right;
                current = right;
            } else {
                current->next = right;
                current = right;
            }
            right = std::move(right->next);
        }
    }

    if (left) {
        current->next = left;
    }

    if (right) {
        current->next = right;
    }

    return temp;
}

template <typename U>
SmrtPtr<ListNode<U>> mergeSort(LinkedList<U>& list, SmrtPtr<ListNode<U>> head, bool ascending = true) {
    if (!head || !head->next) {
        return head;
    }

    SmrtPtr<ListNode<U>> mid;
    SmrtPtr<ListNode<U>> fast = head;
    SmrtPtr<ListNode<U>> slow = head;

    while (fast && fast->next) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (mid) {
        mid->next.reset();
    }

    SmrtPtr<ListNode<U>> left = mergeSort(list, head, ascending);
    SmrtPtr<ListNode<U>> right = mergeSort(list, slow, ascending);

    return merge(list, left, right, ascending);
}

template <typename U>
void mergeSort(LinkedList<U>& list, bool ascending = true) {
    list.head = mergeSort(list, list.head, ascending);
}


// Shell sorting

template <typename T>
void shellSort(DynamicArray<T>& arr, bool ascending = true) {
    int n = arr.getSize();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && ((ascending && arr[j - gap] > temp) || (!ascending && arr[j - gap] < temp)); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


template <typename U>
void shellSort(LinkedList<U>& list, bool ascending = true) {
    int size = list.getSize();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            SmrtPtr<ListNode<U>> tempNode = list.getNodeAt(i);
            U temp = tempNode->data;
            int j;
            for (j = i; j >= gap && ((ascending && list.getNodeAt(j - gap)->data > temp) || (!ascending && list.getNodeAt(j - gap)->data < temp)); j -= gap) {
                list.getNodeAt(j)->data = list.getNodeAt(j - gap)->data;
            }
            list.getNodeAt(j)->data = temp;
        }
    }
}


// Heap sorting

template <typename T>
void heapify(DynamicArray<T>& arr, int n, int i, bool ascending = true) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((ascending && arr[left] > arr[largest]) || (!ascending && arr[left] < arr[largest]))) {
        largest = left;
    }

    if (right < n && ((ascending && arr[right] > arr[largest]) || (!ascending && arr[right] < arr[largest]))) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, ascending);
    }
}

template <typename T>
void heapSort(DynamicArray<T>& arr, bool ascending = true) {
    int n = arr.getSize();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, ascending);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}


template <typename U>
void heapify(LinkedList<U>& list, int n, int i, bool ascending = true) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    SmrtPtr<ListNode<U>> largestNode = list.getNodeAt(largest);

    if (left < n) {
        SmrtPtr<ListNode<U>> leftNode = list.getNodeAt(left);
        if ((ascending && leftNode->data > largestNode->data) || (!ascending && leftNode->data < largestNode->data)) {
            largestNode = leftNode;
            largest = left;
        }
    }

    if (right < n) {
        SmrtPtr<ListNode<U>> rightNode = list.getNodeAt(right);
        if ((ascending && rightNode->data > largestNode->data) || (!ascending && rightNode->data < largestNode->data)) {
            largestNode = rightNode;
            largest = right;
        }
    }

    if (largest != i) {
        swap(list.getNodeAt(i)->data, largestNode->data);
        heapify(list, n, largest, ascending);
    }
}

template <typename U>
void heapSort(LinkedList<U>& list, bool ascending = true) {
    int n = list.getSize();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(list, n, i, ascending);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(list.getNodeAt(0)->data, list.getNodeAt(i)->data);
        heapify(list, i, 0, ascending);
    }
}


#endif //LAB2_SORTING_H
