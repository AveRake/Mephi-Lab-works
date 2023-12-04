#include <chrono>
#include <algorithm>
#include <limits>
#include "smartPointer.h"
using namespace std;
using namespace chrono;


void Benchmark() {
    int N;
    cout << "Enter how many elements will be sorting" << endl;
    cout << ">>> ";
    cin >> N;
    cout << endl;

    auto startRaw = high_resolution_clock::now();

    int* rawArray = new int[N];

    for (int i = 0; i < N; ++i) {
        rawArray[i] = rand()%1000;
    }

    sort(rawArray, rawArray + N, [](const int a, const int b) {
        return a < b;
    });

//    for (int i = 0; i < N; ++i) {
//        cout << rawArray[i] << endl;
//    }

    delete[] rawArray;

    auto stopRaw = high_resolution_clock::now();
    auto durationRaw = duration_cast<milliseconds>(stopRaw - startRaw);

    cout << "Time taken by raw pointers: " << durationRaw.count() << " milliseconds" << endl;


    auto startSmart = high_resolution_clock::now();

    SmrtPtr<int[]> newData(new int[N]);

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


int main () {
    int benchChoice = 1;

    while (benchChoice != 0) {
        cout << "Benchmark starting" << endl;
        Benchmark();
        cout << endl;

        cout << "Would you like to continue testing?" << endl;
        cout << "If yes - press 1, if not - press 0" << endl;
        cout << ">>> ";
        cin >> benchChoice;
        cout << endl;


        if (benchChoice != 1 && benchChoice != 0) {
            cout << "Please try again" << endl;
            cout << ">>> ";
            cin >> benchChoice;
            cout << endl;
        }
    }

    cout << "Press any bottom to end the programme" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}