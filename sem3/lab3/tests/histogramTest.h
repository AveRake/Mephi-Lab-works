#ifndef LAB3_HISTOGRAM_TEST_H
#define LAB3_HISTOGRAM_TEST_H

#include "../forHistogram/histogram .h"
#include "unorderedMaptests.h"


void runHistogramTest() {
    histogram<int> intHistogram;
    intHistogram.addElement(1);
    intHistogram.addElement(2);
    intHistogram.addElement(3);
    intHistogram.addElement(1);
    intHistogram.addElement(2);
    intHistogram.addElement(4);
    intHistogram.addElement(1);

// Тест для метода getBinCount
    int binCount1 = intHistogram.getBinCount(1);
    int binCount2 = intHistogram.getBinCount(2);
    int binCount3 = intHistogram.getBinCount(3);
    int binCount4 = intHistogram.getBinCount(4);

    check(binCount1 == 3, "Test 1");
    check(binCount2 == 2, "Test 2");
    check(binCount3 == 1, "Test 3");
    check(binCount4 == 1, "Test 4");

// Тест для метода getNumBins
    int numBinsInt = intHistogram.getNumBins();
    check(numBinsInt == 4, "Test 5");

// Тест для метода getTotalCount
    int totalCountInt = intHistogram.getTotalCount();
    check(totalCountInt == 7, "Test 6");

// Тест для histogram с типом данных double
    histogram<double> doubleHistogram;
    doubleHistogram.addElement(1.1);
    doubleHistogram.addElement(2.2);
    doubleHistogram.addElement(3.3);
    doubleHistogram.addElement(1.1);
    doubleHistogram.addElement(2.2);
    doubleHistogram.addElement(4.4);
    doubleHistogram.addElement(1.1);

// Тест для метода getBinCount
    int binCount1Double = doubleHistogram.getBinCount(1.1);
    int binCount2Double = doubleHistogram.getBinCount(2.2);
    int binCount3Double = doubleHistogram.getBinCount(3.3);
    int binCount4Double = doubleHistogram.getBinCount(4.4);

    check(binCount1Double == 3, "Test 7");
    check(binCount2Double == 2, "Test 8");
    check(binCount3Double == 1, "Test 9");
    check(binCount4Double == 1, "Test 10");
}

#endif //LAB3_HISTOGRAM_TEST_H
