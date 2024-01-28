#ifndef LAB3_UNORDERED_MAP_TEST_H
#define LAB3_UNORDERED_MAP_TEST_H

#include <iostream>
#include "../taskCache/unorderedMap.h"


void check(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << testName << " - Passed" << std::endl;
    } else {
        std::cout << testName << " - Failed" << std::endl;
    }
}

void runUnorderedMapTest() {
    // Тест 1: Вставка и получение
    myUnorderedMap<int, std::string> myMap1;
    myMap1.insert(1, "One");
    myMap1.insert(2, "Two");

    std::string value1;
    myMap1.get(1, value1);
    check(value1 == "One", "Test 1");

    std::string value2;
    myMap1.get(2, value2);
    check(value2 == "Two", "Test 2");

    // Тест 2: Удаление
    myUnorderedMap<int, std::string> myMap2;
    myMap2.insert(1, "One");
    myMap2.insert(2, "Two");

    myMap2.erase(1);

    std::string value3;
    myMap2.get(1, value3);
    check(value3.empty(), "Test 3");

    std::string value4;
    myMap2.get(2, value4);
    check(value4 == "Two", "Test 4");

    // Тест 3: Размер и очистка
    myUnorderedMap<int, std::string> myMap3;
    check(myMap3.size() == 0, "Test 5");

    myMap3.insert(1, "One");
    myMap3.insert(2, "Two");

    check(myMap3.size() == 2, "Test 6");

    myMap3.clear();

    check(myMap3.size() == 0, "Test 7");

    // Тест для int
    myUnorderedMap<int, std::string> intMap;
    intMap.insert(1, "One");
    intMap.insert(2, "Two");

    std::string intValue1;
    intMap.get(1, intValue1);
    check(intValue1 == "One", "Test 8");

    std::string intValue2;
    intMap.get(2, intValue2);
    check(intValue2 == "Two", "Test 9");

    // Тест для double
    myUnorderedMap<double, std::string> doubleMap;
    doubleMap.insert(1.1, "One point One");
    doubleMap.insert(2.2, "Two point Two");

    std::string doubleValue1;
    doubleMap.get(1.1, doubleValue1);
    check(doubleValue1 == "One point One", "Test 10");

    std::string doubleValue2;
    doubleMap.get(2.2, doubleValue2);
    check(doubleValue2 == "Two point Two", "Test 11");

    // Тест для char
    myUnorderedMap<char, std::string> charMap;
    charMap.insert('a', "A");
    charMap.insert('b', "B");

    std::string charValue1;
    charMap.get('a', charValue1);
    check(charValue1 == "A", "Test 12");

    std::string charValue2;
    charMap.get('b', charValue2);
    check(charValue2 == "B", "Test 13");

    std::cout << std::endl;
    std::cout <<"Testing unorderedMap class was completed" << std::endl;
    std::cout << std::endl;
}

#endif //LAB3_UNORDERED_MAP_TEST_H
