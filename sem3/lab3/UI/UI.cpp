#include "../forHistogram/histogram .h"
#include "../taskCache/cache.h"


void taskType(int* taskChoice) {
    std::cout << "Choose the type of tasks that you want to solve" << std::endl;
    std::cout << "Press 1 for Histogram" << std::endl;
    std::cout << "Press 2 for Cache" << std::endl;
    std::cout << ">>> ";
    std::cin >> *(taskChoice);
    std::cout << std::endl;
}

void dataType(int* dataChoice) {
    std::cout << "Choose the data type for your type" << std::endl;
    std::cout << "Press 1 for int type" << std::endl;
    std::cout << "Press 2 for double type" << std::endl;
    std::cout << "Press 3 for char type" << std::endl;
    std::cout << "Press 4 for string type" << std::endl;
    std::cout << ">>> ";
    std::cin >> *(dataChoice);
    std::cout << std::endl;
}

void actionTypeHistogram(int* actionChoice) {
    std::cout << "Choose action for your histogram" << std::endl;
    std::cout << "Press 1 to add element to your sequence" << std::endl;
    std::cout << "Press 2 to display histogram" << std::endl;
    std::cout << "Press 3 to get total elements" << std::endl;
    std::cout << "Press 4 to get elements count by index" << std::endl;
    std::cout << "Press 5 to get categories count" << std::endl;
    std::cout << ">>> ";
    std::cin >> *(actionChoice);
    std::cout << std::endl;
}

void actionTypeCache(int* actionChoice) {
    std::cout << "Choose action for your histogram" << std::endl;
    std::cout << "Press 1 to add element to your sequence and put cache" << std::endl;
    std::cout << "Press 2 to get element from cache" << std::endl;
    std::cout << "Press 3 to change capacity for your cache" << std::endl;
    std::cout << "Press 4 to get size of your cache" << std::endl;
    std::cout << "Press 5 to clear your cache" << std::endl;
    std::cout << ">>> ";
    std::cin >> *(actionChoice);
    std::cout << std::endl;
}


void changeCapacity(int* capacity) {
    std::cout << "Choose capacity of your cache" << std::endl;
    std::cout << ">>> ";
    std::cin >> (*capacity);
    std::cout << std::endl;
}

template<typename T>
void runHistogram(histogram<T>& histogram, int actionChoice) {
    T item;
    switch (actionChoice) {
        case 1:
            std::cout << "Add elements for your histogram" << std::endl;
            std::cout << ">>> ";
            std::cin >> item;
            std::cout << std::endl;
            histogram.addElement(item);
            break;
        case 2:
            histogram.display();
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Total elements count: " << histogram.getTotalCount() << std::endl;
            break;
        case 4:
            std::cout << "Choose your elemets" << std::endl;
            std::cout << ">>> ";
            std::cin >> item;
            std::cout << std::endl;
            std::cout << "Bins count by your elements: " << histogram.getBinCount(item) << std::endl;
            break;
        case 5:
            std::cout << "Total categories count: " << histogram.getNumBins() << std::endl;
            break;
    }
}

template<typename T>
void runCashe(cache<std::string, T>& cache, int actionChoice, int* capacity) {
    T item;
    T result;
    std::string key;
    switch (actionChoice) {
        case 1:
            std::cout << "Write the name(key) of your element" << std::endl;
            std::cout << ">>> ";
            std::cin >> key;
            std::cout << std::endl;

            std::cout << "Enter your element" << std::endl;
            std::cout << ">>> ";
            std::cin >> item;
            std::cout << std::endl;

            cache.put(key, item);
            break;
        case 2:
            std::cout << "To find neccery elemnet write the key of this element" << std::endl;
            std::cout << ">>> ";
            std::cin >> key;
            std::cout << std::endl;

            if (cache.get(key, result)) {
                std::cout << "Value found in cache: " << result << std::endl;
            } else {
                std::cout << "Value not found in cache." << std::endl;
            }
            break;
        case 3:
            changeCapacity(capacity);
            cache.setCapacity(*capacity);
            std::cout << "Capacity of your cache was successfully changed" << std::endl;
            break;
        case 4:
            std::cout << "Current size of the cache: " << cache.getSize() << std::endl;
            break;
        case 5:
            cache.clear();
            std::cout << "Cache cleared. Current size: " << cache.getSize() << std::endl;
            break;

    }
}


int main() {
    std::cout << "Welcome to my program" << std::endl;

    int taskChoice;
    taskType(&taskChoice);
    while (taskChoice != 1 && taskChoice != 2) {
        std::cout << "Wrong type of task! Try again" << std::endl;
        taskType(&taskChoice);
    }

    int dataChoice;
    dataType(&dataChoice);
    while (dataChoice != 1 && dataChoice != 2 && dataChoice != 3 && dataChoice != 4) {
        std::cout << "Wrong type of data! Try again" << std::endl;
        dataType(&dataChoice);
    }

    int actionChoice;
    if (taskChoice == 1) {
        int choice = 1;
        histogram<int> intHistohram;
        histogram<double> doubleHistohram;
        histogram<char> charHistohram;
        histogram<std::string> stringHistohram;

        while (choice != 0) {
            actionTypeHistogram(&actionChoice);
            while (actionChoice != 1 && actionChoice != 2 && actionChoice != 3 && actionChoice != 4 && actionChoice != 5) {
                std::cout << "Wrong type of action! Try again" << std::endl;
                actionTypeHistogram(&actionChoice);
            }

            switch (dataChoice) {
                case 1:
                    runHistogram(intHistohram, actionChoice);
                    break;
                case 2:
                    runHistogram(doubleHistohram, actionChoice);
                    break;
                case 3:
                    runHistogram(charHistohram, actionChoice);
                    break;
                case 4:
                    runHistogram(stringHistohram, actionChoice);
                    break;
            }

            std::cout << "If you want continue work with histogram - press 1, else - pless 0" << std::endl;
            std::cout << ">>> ";
            std::cin >> choice;
            std::cout << std::endl;
        }
    } else {
        int capacity;
        int choice = 1;
        changeCapacity(&capacity);
        cache<std::string, int> intCache(capacity);
        cache<std::string, double> doubleCache(capacity);
        cache<std::string, char> charCache(capacity);
        cache<std::string, std::string> stringCache(capacity);

        while (choice != 0) {
            actionTypeCache(&actionChoice);
            while (actionChoice != 1 && actionChoice != 2 && actionChoice != 3 && actionChoice != 4 && actionChoice != 5) {
                std::cout << "Wrong type of action! Try again" << std::endl;
                actionTypeCache(&actionChoice);
            }

            switch (dataChoice) {
                case 1:
                    runCashe(intCache, actionChoice, &capacity);
                    break;
                case 2:
                    runCashe(doubleCache, actionChoice, &capacity);
                    break;
                case 3:
                    runCashe(charCache, actionChoice, &capacity);
                    break;
                case 4:
                    runCashe(stringCache, actionChoice, &capacity);
                    break;
            }

            std::cout << "If you want continue work with histogram - press 1, else - pless 0" << std::endl;
            std::cout << ">>> ";
            std::cin >> choice;
            std::cout << std::endl;
        }
    }

    std::cout << "Press any bottom to end the programme" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
