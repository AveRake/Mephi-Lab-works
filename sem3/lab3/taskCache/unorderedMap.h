#ifndef LAB3_UNORDERED_MAP_H
#define LAB3_UNORDERED_MAP_H

#include <iostream>
#include <list>


template <typename Key, typename Value>
class myUnorderedMap {
public:
    void insert(const Key& key, const Value& value) {
        auto it = find(key);
        if (it == data.end()) {
            data.push_back({key, value});
        } else {
            it->second = value;
        }
    }

    typename std::list<std::pair<Key, Value>>::iterator find(const Key& key) {
        auto it = data.begin();
        for (; it != data.end(); ++it) {
            if (it->first == key) {
                break;
            }
        }
        return it;
    }

    void erase(const Key& key) {
        auto it = find(key);
        if (it != data.end()) {
            data.erase(it);
        }
    }

    bool get(const Key& key, Value& result) {
        auto it = find(key);
        if (it != data.end()) {
            result = it->second;
            return true;
        }
        return false;
    }

    typename std::list<std::pair<Key, Value>>::iterator end() {
        return data.end();
    }

    [[nodiscard]] std::size_t size() const {
        return data.size();
    }

    void clear() {
        data.clear();
    }

private:
    std::list<std::pair<Key, Value>> data;
};

#endif //LAB3_UNORDERED_MAP_H
