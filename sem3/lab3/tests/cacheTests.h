#ifndef LAB3_CACHE_TESTS_H
#define LAB3_CACHE_TESTS_H

#include <iostream>
#include "../taskCache/unorderedMap.h"
#include "../taskCache/cache.h"
#include "unorderedMaptests.h"


void runCacheTest () {
    cache<std::string, int> stringCache(3);
    stringCache.put("one", 1);
    stringCache.put("two", 2);
    stringCache.put("three", 3);

    int stringValue;
    bool stringResult = stringCache.get("two", stringValue);
    check(stringResult && stringValue == 2, "Test 1");

    // Тест для cache с ключами типа int
    cache<int, std::string> intCache(3);
    intCache.put(1, "One");
    intCache.put(2, "Two");
    intCache.put(3, "Three");

    std::string intValue;
    bool intResult = intCache.get(2, intValue);
    check(intResult && intValue == "Two", "Test 2");

    // Тест для cache с ключами типа double
    cache<double, char> doubleCache(3);
    doubleCache.put(1.1, 'A');
    doubleCache.put(2.2, 'B');
    doubleCache.put(3.3, 'C');

    char doubleValue;
    bool doubleResult = doubleCache.get(2.2, doubleValue);
    check(doubleResult && doubleValue == 'B', "Test 3");

    stringCache.setCapacity(2);
    int newCapacity = static_cast<int>(stringCache.getSize());
    check(newCapacity == 2, "Test 4");

    // Тест для очистки кеша
    stringCache.clear();
    newCapacity = static_cast<int>(stringCache.getSize());
    check(newCapacity == 0, "Test 5");

    stringCache.put("Key1", 1);
    stringCache.put("Key2", 2);
    std::size_t sizeAfterPut = stringCache.getSize();
    check(sizeAfterPut == 2, "Test 6");

    // Тест для метода getSize после удаления элементов
    stringCache.setCapacity(1);
    std::size_t sizeAfterSetCapacity = stringCache.getSize();
    check(sizeAfterSetCapacity == 1, "Test 7");

    std::cout << std::endl;
    std::cout <<"Testing cache class was completed" << std::endl;
    std::cout << std::endl;
}

#endif //LAB3_CACHE_TESTS_H
