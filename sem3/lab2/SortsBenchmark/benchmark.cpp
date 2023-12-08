#include <iostream>
#include <chrono>
#include "../mainPart/sorting.h"
using namespace std;
using namespace chrono;


void clear(DynamicArray<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        array.pop_back();
    }
}


void fillArrays(DynamicArray<int>& array1, DynamicArray<int>& array2, DynamicArray<int>& array3, int size) {
    for (int i = 0; i < size; ++i) {
        array1.push_back(rand() % 1000);
        array2.push_back(i);
        array3.push_back(size - i - 1);
    }
}


void performSorting(DynamicArray<int>& array, int wayOfSorting, int sortChoice) {
    switch (sortChoice) {
        case 1:
            bubbleSort(array);
            break;
        case 2:
            insertionSort(array);
            break;
        case 3:
            mergeSort(array);
            break;
        case 4:
            shellSort(array);
            break;
        case 5:
            heapSort(array);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}


void runBenchmark(DynamicArray<int>& array, int wayOfSorting, int sortChoice, int* averageTime) {
    auto startRaw = high_resolution_clock::now();
    performSorting(array, wayOfSorting, sortChoice);
    auto stopRaw = high_resolution_clock::now();
    auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
    *averageTime += durationRaw.count();
}


int main() {
    int size;
    cout << "Enter how many elements will be sorting" << endl;
    cout << ">>> ";
    cin >> size;

    int sortChoice;
    cout << "Choose the sort method" << endl;
    cout << "Press 1 for bubble sort" << endl;
    cout << "Press 2 for insertion sort" << endl;
    cout << "Press 3 for merge sort" << endl;
    cout << "Press 4 for shell sort" << endl;
    cout << "Press 5 for heap sort" << endl;
    cout << ">>> ";
    cin >> sortChoice;

    DynamicArray<int> array1;
    DynamicArray<int> array2;
    DynamicArray<int> array3;
    int averageTimeRandom = 0;
    int averageTimeDirect = 0;
    int averageTimeReverse = 0;

    for (int i = 0; i < 10; ++i) {
        fillArrays(array1, array2, array3, size);
        runBenchmark(array1, 1, sortChoice, &averageTimeRandom);
        runBenchmark(array2, 2, sortChoice, &averageTimeDirect);
        runBenchmark(array3, 3, sortChoice, &averageTimeReverse);
        clear(array1, size);
        clear(array2, size);
        clear(array3, size);
    }

    cout << "Average Time taken by sorting random array: " << averageTimeRandom / 10 << " milliseconds" << endl << endl;
    cout << "Average time taken by sorting direct array: " << averageTimeDirect / 10 << " milliseconds" << endl << endl;
    cout << "Average Time taken by sorting reverse array: " << averageTimeReverse / 10 << " milliseconds" << endl << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}
