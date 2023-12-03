#include <iostream>
#include <chrono>
#include "../mainPart/Sorting.h"
using namespace std;
using namespace chrono;


void startSorting() {
    cout << "Choose the sort methods" << endl;
    cout << "Press 1 for bubble sort" << endl;
    cout << "Press 2 for insertion sort" << endl;
    cout << "Press 3 for merge sort" << endl;
    cout << "Press 4 for shell sort" << endl;
    cout << "Press 5 for heap sort" << endl;
    cout << ">>> ";
}


template <typename T>
void fillArray(DynamicArray<T>& array1, DynamicArray<T>& array2, DynamicArray<T>& array3, int size) {
    for (int i = 0; i < size; ++i) {
        array1.push_back(rand()%1000);
    }

    for (int i = 0; i < size; ++i) {
        array2.push_back(i);
    }

    for (int i = 0; i < size; ++i) {
        array3.push_back(size - i - 1);
    }
}


int main() {
    int size;
    int sortChoice = 1;
    cout << "Enter how many elements will be sorting" << endl;
    cout << ">>> ";
    cin >> size;
    cout << endl;

    DynamicArray<int> array1;
    DynamicArray<int> array2;
    DynamicArray<int> array3;
    int averageTimeRand = 0;
    int averageTimeDirect = 0;
    int averageTimeReverse = 0;

    startSorting();
    cin >> sortChoice;
    cout << endl;

    fillArray(array1, array2, array3, size);

    if (sortChoice == 1) {
        for (int j = 0; j < 10; j++) {
            auto startRaw = high_resolution_clock::now();
            bubbleSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            averageTimeRand += durationRaw.count();

            auto startRaw2 = high_resolution_clock::now();
            bubbleSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            averageTimeDirect += durationRaw2.count();

            auto startRaw3 = high_resolution_clock::now();
            bubbleSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            averageTimeReverse += durationRaw3.count();

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }

            fillArray(array1, array2, array3, size);
        }

        cout << "Time taken by sorting random array with bubble sort: " << averageTimeRand / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array with bubble sort: " << averageTimeDirect / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array in the opposite direction with bubble sort: " << averageTimeReverse / 10 << " milliseconds" << endl << endl;
        averageTimeRand = 0;
        averageTimeReverse = 0;
        averageTimeDirect = 0;
    }

    if (sortChoice == 2) {
        for (int j = 0; j < 10; j++) {
            auto startRaw = high_resolution_clock::now();
            insertionSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            averageTimeRand += durationRaw.count();

            auto startRaw2 = high_resolution_clock::now();
            insertionSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            averageTimeDirect += durationRaw2.count();

            auto startRaw3 = high_resolution_clock::now();
            insertionSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            averageTimeReverse += durationRaw3.count();

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }

            fillArray(array1, array2, array3, size);
        }

        cout << "Time taken by sorting random array with insertion sort: " << averageTimeRand / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array with insertion sort: " << averageTimeDirect / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array in the opposite direction with insertion sort: " << averageTimeReverse / 10 << " milliseconds" << endl << endl;
        averageTimeRand = 0;
        averageTimeReverse = 0;
        averageTimeDirect = 0;
    }

    if (sortChoice == 3) {
        for (int j = 0; j < 10; j++) {
            auto startRaw = high_resolution_clock::now();
            mergeSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            averageTimeRand += durationRaw.count();

            auto startRaw2 = high_resolution_clock::now();
            mergeSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            averageTimeDirect += durationRaw2.count();

            auto startRaw3 = high_resolution_clock::now();
            mergeSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            averageTimeReverse += durationRaw3.count();

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }

            fillArray(array1, array2, array3, size);
        }

        cout << "Time taken by sorting random array with merge sort: " << averageTimeRand / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array with merge sort: " << averageTimeDirect / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array in the opposite direction with merge sort: " << averageTimeReverse / 10 << " milliseconds" << endl << endl;
        averageTimeRand = 0;
        averageTimeReverse = 0;
        averageTimeDirect = 0;
    }

    if (sortChoice == 4) {
        for (int j = 0; j < 10; j++) {
            auto startRaw = high_resolution_clock::now();
            shellSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            averageTimeRand += durationRaw.count();

            auto startRaw2 = high_resolution_clock::now();
            shellSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            averageTimeDirect += durationRaw2.count();

            auto startRaw3 = high_resolution_clock::now();
            shellSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            averageTimeReverse += durationRaw3.count();

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }

            fillArray(array1, array2, array3, size);
        }

        cout << "Time taken by sorting random array with shell sort: " << averageTimeRand / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array with shell sort: " << averageTimeDirect / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array in the opposite direction with shell sort: " << averageTimeReverse / 10 << " milliseconds" << endl << endl;
        averageTimeRand = 0;
        averageTimeReverse = 0;
        averageTimeDirect = 0;
    }

    if (sortChoice == 5) {
        for (int j = 0; j < 10; j++) {
            auto startRaw = high_resolution_clock::now();
            heapSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            averageTimeRand += durationRaw.count();

            auto startRaw2 = high_resolution_clock::now();
            heapSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            averageTimeDirect += durationRaw2.count();

            auto startRaw3 = high_resolution_clock::now();
            heapSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            averageTimeReverse += durationRaw3.count();

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }

            fillArray(array1, array2, array3, size);
        }

        cout << "Time taken by sorting random array with heap sort: " << averageTimeRand / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array with heap sort: " << averageTimeDirect / 10 << " milliseconds" << endl << endl;
        cout << "Time taken by sorting sorted array in the opposite direction with heap sort: " << averageTimeReverse / 10 << " milliseconds" << endl << endl;
        averageTimeRand = 0;
        averageTimeReverse = 0;
        averageTimeDirect = 0;
    }


    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}