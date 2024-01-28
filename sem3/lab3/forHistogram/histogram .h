#ifndef LAB3_HISTOGRAM_H
#define LAB3_HISTOGRAM_H

#include <iostream>
#include "../sequences/sequence.h"


template <typename T>
struct histogram {
    LinkedList<T> bins;

    histogram() = default;

    void addElement(T value) {
        bins.push_back(value);
    }

    void display() const {
        LinkedListIterator<T> iter = bins.begin();
        while (iter != bins.end()) {
            std::cout << "Category: " << *iter << ", Elements count: " << bins.getBinCount(*iter) << " ";
            std::cout << "| ";
            for (int i = 0; i < bins.getBinCount(*iter); ++i) {
                std::cout << '*';
            }
            std::cout << std::endl;
            ++iter;
        }
    }

    [[nodiscard]] int getTotalCount() const {
        int totalCount = 0;
        LinkedListIterator<T> iter = bins.begin();
        while (iter != bins.end()) {
            totalCount += bins.getBinCount(*iter);
            ++iter;
        }
        return totalCount;
    }

    [[nodiscard]] int getBinCount(T value) const {
        int count = 0;
        LinkedListIterator<T> iter = bins.begin();
        while (iter != bins.end()) {
            if (*iter == value) {
                count++;
            }
            ++iter;
        }
        return count;
    }

    [[nodiscard]] int getNumBins() const {
        return bins.getSize();
    }
};

#endif //LAB3_HISTOGRAM_H
