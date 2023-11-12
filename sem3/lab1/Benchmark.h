#ifndef SEM3LAB1_BENCHMARK_H
#define SEM3LAB1_BENCHMARK_H
#include "Sequence.h"
#include <chrono>
#include <algorithm>


using namespace std;
using namespace chrono;


void Benchmark() {
    int N;
    cout << "Enter how many elements will be sorting" << endl;
    cout << ">>> ";
    cin >> N;
    cout << endl;

    auto startRaw = high_resolution_clock::now();

    int** rawArray = new int*[N];

    for (int i = 0; i < N; ++i) {
        rawArray[i] = new int(rand()%1000);
    }

    sort(rawArray, rawArray + N, [](const int* a, const int* b) {
        return *a < *b;
    });

//    for (int i = 0; i < N; ++i) {
//        cout << *(rawArray)[i] << endl;
//    }

    for (int i = 0; i < N; ++i) {
        delete rawArray[i];
    }

    delete[] rawArray;

    auto stopRaw = high_resolution_clock::now();
    auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);

    cout << "Time taken by raw pointers: " << durationRaw.count() << " milliseconds" << endl;


    auto startSmart = high_resolution_clock::now();

    SmrtPtr<int> newData(new int[N], N);

    for (int i = 0; i < N; ++i) {
        newData[i] = rand()%1000;
    }

    sort(newData.operator->(), newData.operator->() + N);

//    for (int i = 0; i < N; ++i) {
//        cout << newData[i] << endl;
//    }

    auto stopSmart = high_resolution_clock::now();
    auto durationSmart = duration_cast<milliseconds>(stopSmart - startSmart);

    cout << "Time taken by smart pointers: " << durationSmart.count() << " milliseconds" << endl;
}

#endif //SEM3LAB1_BENCHMARK_H
