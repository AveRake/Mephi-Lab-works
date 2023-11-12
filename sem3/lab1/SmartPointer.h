#ifndef SEM3LAB1_SMART_POINTER_H
#define SEM3LAB1_SMART_POINTER_H
#include <iostream>
using namespace std;


template <typename T>
class SmrtPtr {
public:
    SmrtPtr() {
        ptr = nullptr;
        refCount = nullptr;
    }

    explicit SmrtPtr(T* ptr) {
        this->ptr = ptr;
        refCount = new size_t(1);
    }

    explicit SmrtPtr(T* ptr, size_t size) {
        this->ptr = ptr;
        refCount = new size_t(1);
        arraySize = size;
    }

    explicit SmrtPtr(const T& other) {
        ptr = other.ptr;
        refCount = other.refCount;

        if (refCount) {
            (*refCount)++;
        }
    }

    SmrtPtr(const SmrtPtr<T>& other) {
        ptr = other.ptr;
        arraySize = other.arraySize;
        refCount = other.refCount;

        if (refCount) {
            (*refCount)++;
        }
    }

    SmrtPtr& operator =(const SmrtPtr<T>& other) {
        if (this != &other) {
            if (refCount && --(*refCount) == 0) {
                delete ptr;
                delete refCount;
            }

            ptr = other.ptr;
            refCount = other.refCount;
            arraySize = other.arraySize;

            if (refCount) {
                (*refCount)++;
            }
        }
        return *this;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }

    T& operator[](size_t index) const {
        if (ptr) {
            if (index < arraySize) {
                return ptr[index];
            } else {
                throw out_of_range("Index out of bounds");
            }
        } else {
            throw invalid_argument("nullptr");
        }
    }

    T& operator *() {
        return *ptr;
    }

    T* operator ->() {
        return ptr;
    }

    bool operator==(const SmrtPtr<T>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const SmrtPtr<T>& other) const {
        return ptr != other.ptr;
    }

    [[nodiscard]] size_t getRefCount() const {
        return refCount ? *refCount : 0;
    }

    [[nodiscard]] bool isArray() const {
        return arraySize > 0;
    }

    [[nodiscard]] bool isNull() const {
        return ptr == nullptr;
    }

    [[nodiscard]] bool unique() const {
        return refCount != nullptr && (*refCount == 1);
    }

    void reset(T* newPtr = nullptr, size_t newSize = 0) {
        if (refCount && --(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }

        ptr = newPtr;
        refCount = new size_t(1);
        arraySize = newSize;
    }

    T* release() {
        T* releasedPtr = ptr;
        size_t* releasedRefCount = refCount;

        ptr = nullptr;
        refCount = nullptr;
        arraySize = 0;

        return releasedPtr;
    }

    ~SmrtPtr() {
        if (refCount && --(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
    }

private:
    T* ptr;
    size_t arraySize{};
    size_t* refCount;
};


#endif //SEM3LAB1_SMART_POINTER_H
