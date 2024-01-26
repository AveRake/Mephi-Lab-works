#ifndef LAB3_CACHE_H
#define LAB3_CACHE_H

#include "unorderedMap.h"


template <typename Key, typename Value>
class cache {
public:
    explicit cache(int capacity) : capacity(capacity) {}

    // Получение значения из кеша
    bool get(const Key& key, Value& result) {
        auto it = cacheMap.find(key);

        if (cacheMap.size() > 0 && it != cacheMap.end()) {
            // Перемещаем найденный элемент в начало списка (LRU)
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            result = it->second->second;
            return true;
        }

        return false;
    }

    // Добавление значения в кеш
    void put(const Key& key, const Value& value) {
        // Если кеш переполнен, удаляем самый старый элемент
        if (cacheMap.size() >= capacity) {
            auto last = cacheList.end();
            --last;
            cacheMap.erase(last->first);
            cacheList.pop_back();
        }

        // Вставляем новый элемент в начало списка
        cacheList.emplace_front(key, value);
        cacheMap.insert(key, cacheList.begin());
    }

    void setCapacity(int newCapacity) {
        if (newCapacity < 0) {
            // Обработка случая некорректного значения размера кэша
            std::cerr << "Error: Invalid capacity value." << std::endl;
            return;
        }

        capacity = newCapacity;

        // Обрезаем кеш до нового размера
        while (cacheMap.size() > capacity) {
            auto last = cacheList.end();
            --last;
            cacheMap.erase(last->first);
            cacheList.pop_back();
        }
    }

    [[nodiscard]] std::size_t getSize() const {
        return cacheMap.size();
    }

    void clear() {
        cacheMap.clear();
        cacheList.clear();
    }

private:
    int capacity;
    myUnorderedMap<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap;
    std::list<std::pair<Key, Value>> cacheList;
};

#endif //LAB3_CACHE_H
