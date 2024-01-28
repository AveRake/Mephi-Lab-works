#ifndef LAB3_MY_MAP_TEST_H
#define LAB3_MY_MAP_TEST_H

#include "unorderedMaptests.h"
#include "../forHistogram/myMap.h"


void runMyMapTest() {
    myMap<int, std::string> intStringMap;
    int sizeEmpty = intStringMap.getSize();
    check(sizeEmpty == 0, "Test 1");

    // Тест для метода getSize после добавления элементов
    intStringMap.insert(1, "One");
    intStringMap.insert(2, "Two");
    int sizeAfterInsert = intStringMap.getSize();
    check(sizeAfterInsert == 2, "Test 2");

    // Тест для метода getSize после изменения значения по ключу
    intStringMap.insert(1, "First");
    int sizeAfterUpdate = intStringMap.getSize();
    check(sizeAfterUpdate == 2, "Test 3");

    // Тест для метода getSize
    intStringMap.insert(3, "Three");
    intStringMap.insert(4, "Four");
    intStringMap.insert(5, "Five");
    intStringMap.insert(6, "Six");
    intStringMap.insert(7, "Seven");
    intStringMap.insert(8, "Eight");
    intStringMap.insert(9, "Nine");
    intStringMap.insert(10, "Ten");
    intStringMap.insert(11, "Eleven");
    intStringMap.insert(12, "Twelve");
    intStringMap.insert(13, "Thirteen");
    intStringMap.insert(14, "Fourteen");
    intStringMap.insert(15, "Fifteen");
    intStringMap.insert(16, "Sixteen");
    intStringMap.insert(17, "Seventeen");
    intStringMap.insert(18, "Eighteen");
    intStringMap.insert(19, "Nineteen");
    intStringMap.insert(20, "Twenty");
    intStringMap.insert(21, "Twenty-One");
    intStringMap.insert(22, "Twenty-Two");
    intStringMap.insert(23, "Twenty-Three");
    intStringMap.insert(24, "Twenty-Four");
    intStringMap.insert(25, "Twenty-Five");
    intStringMap.insert(26, "Twenty-Six");
    intStringMap.insert(27, "Twenty-Seven");
    intStringMap.insert(28, "Twenty-Eight");
    intStringMap.insert(29, "Twenty-Nine");
    intStringMap.insert(30, "Thirty");
    intStringMap.insert(31, "Thirty-One");
    intStringMap.insert(32, "Thirty-Two");
    intStringMap.insert(33, "Thirty-Three");
    intStringMap.insert(34, "Thirty-Four");
    intStringMap.insert(35, "Thirty-Five");
    intStringMap.insert(36, "Thirty-Six");
    intStringMap.insert(37, "Thirty-Seven");
    intStringMap.insert(38, "Thirty-Eight");
    intStringMap.insert(39, "Thirty-Nine");
    intStringMap.insert(40, "Forty");
    intStringMap.insert(41, "Forty-One");
    intStringMap.insert(42, "Forty-Two");
    intStringMap.insert(43, "Forty-Three");
    intStringMap.insert(44, "Forty-Four");
    intStringMap.insert(45, "Forty-Five");
    intStringMap.insert(46, "Forty-Six");
    intStringMap.insert(47, "Forty-Seven");
    intStringMap.insert(48, "Forty-Eight");
    intStringMap.insert(49, "Forty-Nine");
    int sizeAfterInsertMany = intStringMap.getSize();
    check(sizeAfterInsertMany == 49, "Test 4");

    // Тест для метода find для существующего ключа
    auto foundValue = intStringMap.find(5);
    check(foundValue != nullptr && *foundValue == "Five", "Test 5");

    // Тест для метода find для несуществующего ключа
    auto notFoundValue = intStringMap.find(100);
    check(notFoundValue == nullptr, "Test 6");

    // Тест для метода getUniqueKeys после добавления элементов
    int uniqueKeysAfterInsert = intStringMap.getUniqueKeys();
    check(uniqueKeysAfterInsert == 49, "Test 7");

    std::cout << std::endl;
    std::cout <<"Testing myMap class was completed" << std::endl;
    std::cout << std::endl;
};

#endif //LAB3_MY_MAP_TEST_H
