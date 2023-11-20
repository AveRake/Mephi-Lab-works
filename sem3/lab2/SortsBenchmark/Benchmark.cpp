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
    cout << "Press 6 for change size" << endl;
    cout << "Press 0 for exiting" << endl;
    cout << ">>> ";
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

    while(sortChoice != 0) {
        startSorting();
        cin >> sortChoice;
        cout << endl;

        for (int i = 0; i < size; ++i) {
            array1.push_back(rand()%1000);
        }

        for (int i = 0; i < size; ++i) {
            array2.push_back(i);
        }

        for (int i = 0; i < size; ++i) {
            array3.push_back(size - i - 1);
        }

        if (sortChoice == 1) {
            auto startRaw = high_resolution_clock::now();
            bubbleSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            cout << "Time taken by sorting random array with bubble sort: " << durationRaw.count() << " milliseconds" << endl << endl;

            auto startRaw2 = high_resolution_clock::now();
            bubbleSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            cout << "Time taken by sorting sorted array with bubble sort: " << durationRaw2.count() << " milliseconds" << endl << endl;

            auto startRaw3 = high_resolution_clock::now();
            bubbleSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            cout << "Time taken by sorting sorted array in the opposite direction with bubble sort: " << durationRaw3.count() << " milliseconds" << endl << endl;

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }
        }

        if (sortChoice == 2) {
            auto startRaw = high_resolution_clock::now();
            insertionSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            cout << "Time taken by sorting random array with insertion sort: " << durationRaw.count() << " milliseconds" << endl << endl;

            auto startRaw2 = high_resolution_clock::now();
            insertionSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            cout << "Time taken by sorting sorted array with insertion sort: " << durationRaw2.count() << " milliseconds" << endl << endl;

            auto startRaw3 = high_resolution_clock::now();
            insertionSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            cout << "Time taken by sorting sorted array in the opposite direction with insertion sort: " << durationRaw3.count() << " milliseconds" << endl << endl;

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }
        }

        if (sortChoice == 3) {
            auto startRaw = high_resolution_clock::now();
            mergeSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            cout << "Time taken by sorting random array with merge sort: " << durationRaw.count() << " milliseconds" << endl << endl;

            auto startRaw2 = high_resolution_clock::now();
            mergeSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            cout << "Time taken by sorting sorted array with merge sort: " << durationRaw2.count() << " milliseconds" << endl << endl;

            auto startRaw3 = high_resolution_clock::now();
            mergeSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            cout << "Time taken by sorting sorted array in the opposite direction with merge sort: " << durationRaw3.count() << " milliseconds" << endl << endl;

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }
        }

        if (sortChoice == 4) {
            auto startRaw = high_resolution_clock::now();
            shellSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            cout << "Time taken by sorting random array with shell sort: " << durationRaw.count() << " milliseconds" << endl << endl;

            auto startRaw2 = high_resolution_clock::now();
            shellSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            cout << "Time taken by sorting sorted array with shell sort: " << durationRaw2.count() << " milliseconds" << endl << endl;

            auto startRaw3 = high_resolution_clock::now();
            shellSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            cout << "Time taken by sorting sorted array in the opposite direction with shell sort: " << durationRaw3.count() << " milliseconds" << endl << endl;

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }
        }

        if (sortChoice == 5) {
            auto startRaw = high_resolution_clock::now();
            heapSort(array1);
            auto stopRaw = high_resolution_clock::now();
            auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);
            cout << "Time taken by sorting random array with heap sort: " << durationRaw.count() << " milliseconds" << endl << endl;

            auto startRaw2 = high_resolution_clock::now();
            heapSort(array2);
            auto stopRaw2 = high_resolution_clock::now();
            auto durationRaw2 = duration_cast<milliseconds>(stopRaw2 - startRaw2);
            cout << "Time taken by sorting sorted array with heap sort: " << durationRaw2.count() << " milliseconds" << endl << endl;

            auto startRaw3 = high_resolution_clock::now();
            heapSort(array3);
            auto stopRaw3 = high_resolution_clock::now();
            auto durationRaw3 = duration_cast<milliseconds>(stopRaw3 - startRaw3);
            cout << "Time taken by sorting sorted array in the opposite direction with heap sort: " << durationRaw3.count() << " milliseconds" << endl << endl;

            for (int i = 0; i < size; i++) {
                array1.pop_back();
                array2.pop_back();
                array3.pop_back();
            }
        }

        if (sortChoice == 6) {
            cout << "Enter how many elements will be sorting" << endl;
            cout << ">>> ";
            cin >> size;
            cout << endl;
        }
    }

    system("pause");
    return 0;
}