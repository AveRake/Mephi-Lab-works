#include "../forHistogram/histogram .h"
#include "../sequence/person.h"
#include "../sequence/sequences.h"
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


    std::vector<Person> people = {
            Person(25, 65.5),
            Person(30, 72.1),
            Person(25, 61.8),
            Person(35, 80.2),
            Person(30, 68.5)
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

    return 0;
}
