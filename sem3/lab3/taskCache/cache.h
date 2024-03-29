#ifndef LAB3_CACHE_H
#define LAB3_CACHE_H

#include "unorderedMap.h"
#include <unordered_map>
#include <algorithm>


template <typename Key, typename Value>
class cache {
public:
    explicit cache(int capacity) : capacity(capacity) {}

    bool get(const Key& key, Value& result) {
        auto it = cacheMap.find(key);

        if (cacheMap.size() > 0 && it != cacheMap.end()) {
            usageCount[key]++;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            result = it->second->second;
            return true;
        }

        return false;
    }

    void put(const Key& key, const Value& value) {
        if (cacheMap.size() >= capacity) {
            auto minElement = std::min_element(
                    usageCount.begin(), usageCount.end(),
                    [](const auto& p1, const auto& p2) {
                        return p1.second < p2.second;
                    });

            if (minElement != usageCount.end()) {
                cacheMap.erase(minElement->first);
                usageCount.erase(minElement->first);
            }
        }

        cacheList.emplace_front(key, value);
        cacheMap.insert(key, cacheList.begin());
        usageCount[key] = 1;
    }

    void setCapacity(int newCapacity) {
        if (newCapacity < 0) {
            std::cerr << "Error: Invalid capacity value." << std::endl;
            return;
        }

        capacity = newCapacity;

        while (cacheMap.size() > capacity) {
            auto minElement = std::min_element(
                    usageCount.begin(), usageCount.end(),
                    [](const auto& p1, const auto& p2) {
                        return p1.second < p2.second;
                    });

            if (minElement != usageCount.end()) {
                cacheMap.erase(minElement->first);
                usageCount.erase(minElement->first);
            }
        }
    }

    [[nodiscard]] std::size_t getSize() const {
        return cacheMap.size();
    }

    [[nodiscard]] int getUsageCount(const Key& key) const {
        auto it = usageCount.find(key);
        return (it != usageCount.end()) ? it->second : 0;
    }

    void clear() {
        cacheMap.clear();
        cacheList.clear();
        usageCount.clear();
    }

private:
    int capacity;
    myUnorderedMap<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap;
    std::list<std::pair<Key, Value>> cacheList;
    myUnorderedMap<Key, int> usageCount;
};

#endif //LAB3_CACHE_H
