#include "../forHistogram/histogram .h"
#include "../sequence/human.h"
#include "../sequence/sequences.h"
#include "../taskCache/cache.h"
#include <vector>


int main() {
    histogram<int> intHistogram;
    std::vector<int> intSequence = {3, 7, 5, 8, 3, 5, 2, 6, 8, 4};
    for (const auto& element : intSequence) {
        intHistogram.addElement(element);
    }
    std::cout << "histogram for type int:" << std::endl;
    intHistogram.display();

    std::cout << "getTotalCount: " << intHistogram.getTotalCount() << std::endl;
    std::cout << "getBinCount 5: " << intHistogram.getBinCount(5) << std::endl;
    std::cout << "getNumBins: " << intHistogram.getNumBins() << std::endl;


    histogram<double> doubleHistogram;
    std::vector<double> doubleSequence = {2.5, 3.2, 4.1, 2.5, 3.7, 4.1, 2.5, 3.2};
    for (const auto& element : doubleSequence) {
        doubleHistogram.addElement(element);
    }
    std::cout << "histogram for type double:" << std::endl;
    doubleHistogram.display();


    histogram<std::string> stringHistogram;
    std::vector<std::string> stringSequence = {"apple", "orange", "banana", "apple", "banana"};
    for (const auto& element : stringSequence) {
        stringHistogram.addElement(element);
    }
    std::cout << "histogram for type string:" << std::endl;
    stringHistogram.display();


    std::vector<human> people = {
            human(25, 65.5),
            human(30, 72.1),
            human(25, 61.8),
            human(35, 80.2),
            human(30, 68.5)
    };

    histogram<int> ageHistogram;
    histogram<double> weightHistogram;

    for (const auto& person : people) {
        ageHistogram.addElement(person.age);
        weightHistogram.addElement(person.weight);
    }

    std::cout << "\nHistogram for age:" << std::endl;
    ageHistogram.display();

    std::cout << "\nHistogram for weight:" << std::endl;
    weightHistogram.display();

    histogram<int> arrayHistogram;
    DynamicArray<int> array;
    array.push_back(11);
    array.push_back(22);
    array.push_back(33);
    array.push_back(44);
    array.push_back(44);

    for (int i = 0; i < 5; ++i) {
        arrayHistogram.addElement(array[i]);
    }
    std::cout << "histogram for type array:" << std::endl;
    arrayHistogram.display();


    cache<std::string, human> myCache(3);

    // Создаем несколько объектов human
    human person1(25, 70.5);
    human person2(30, 65.2);
    human person3(22, 68.0);

    // Добавляем объекты в кеш с ключами
    myCache.put("John", person1);
    myCache.put("Alice", person2);
    myCache.put("Bob", person3);

    // Запрашиваем объект из кеша по ключу
    human result(0, 0.0);
    if (myCache.get("Alice", result)) {
        std::cout << "Person Alice found in cache. Age: " << result.age << ", Weight: " << result.weight << std::endl;
    } else {
        std::cout << "Person Alice not found in cache." << std::endl;
    }

    // Добавляем еще один объект в кеш
    human person4(28, 72.3);
    myCache.setCapacity(5);
    myCache.put("Eve", person4);

    // Запрашиваем объект из кеша по ключу
    if (myCache.get("John", result)) {
        std::cout << "Person John found in cache. Age: " << result.age << ", Weight: " << result.weight << std::endl;
    } else {
        std::cout << "Person John not found in cache." << std::endl;
    }

    std::size_t currentSize = myCache.getSize();
    std::cout << "Current size of the cache: " << currentSize << std::endl;

    myCache.clear();
    std::cout << "Cache cleared. Current size: " << myCache.getSize() << std::endl;

    myCache.put("Eve", person4);
    std::cout << "Current size of the cache: " << myCache.getSize() << std::endl;

    return 0;
}
