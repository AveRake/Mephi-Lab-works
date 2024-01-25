#ifndef LAB3_HISTOGRAM_H
#define LAB3_HISTOGRAM_H

#include <iostream>
#include <map>
#include "myMap.h"


template <typename T>
struct histogram {
    myMap<T, int> bins;

    void addElement(T value) {
        int* binCount = bins.find(value);
        if (binCount != nullptr) {
            (*binCount)++;
        } else {
            bins.insert(value, 1);
        }
    }

    void display() const {
        for (const auto& bin : bins) {
            std::cout << "Category: " << bin.first << ", Elements count: " << bin.second << " ";
            std::cout << "| ";
            for (int i = 0; i < bin.second; ++i) {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }

    [[nodiscard]] int getTotalCount() const {
        int totalCount = 0;
        for (const auto& bin : bins) {
            totalCount += bin.second;
        }
        return totalCount;
    }

    [[nodiscard]] int getBinCount(T value) const {
        int* binCount = bins.find(value);
        return (binCount != nullptr) ? *binCount : 0;
    }

    [[nodiscard]] int getNumBins() const {
        return bins.getSize();
    }
};

#endif //LAB3_HISTOGRAM_H
