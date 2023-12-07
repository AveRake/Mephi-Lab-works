#ifndef SEM3LAB1_SMART_POINTER_H
#define SEM3LAB1_SMART_POINTER_H
#include <iostream>
using namespace std;


template <typename T>
void releaseResources(T* ptr, size_t* refCount) {
    if (refCount && --(*refCount) == 0) {
        delete ptr;
        delete refCount;
    }
}

template <typename T>
void releaseArrayResources(T* ptr, size_t* refCount) {
    if (refCount && --(*refCount) == 0) {
        delete[] ptr;
        delete refCount;
    }
}


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

    SmrtPtr(const SmrtPtr<T>& other) {
        ptr = other.ptr;
        refCount = other.refCount;

        if (refCount) {
            (*refCount)++;
        }
    }

    SmrtPtr& operator =(const SmrtPtr<T>& other) {
        if (this != &other) {
            releaseResources(ptr, refCount);

            ptr = other.ptr;
            refCount = other.refCount;

            if (refCount) {
                (*refCount)++;
            }
        }
        return *this;
    }

    explicit operator bool() const {
        return ptr != nullptr;
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

    [[nodiscard]] bool isNull() const {
        return ptr == nullptr;
    }

    [[nodiscard]] bool unique() const {
        return refCount != nullptr && (*refCount == 1);
    }

    void reset(T* newPtr = nullptr, size_t newSize = 0) {
        releaseResources(ptr, refCount);

        ptr = newPtr;
        refCount = new size_t(1);
    }

    T* release() {
        T* releasedPtr = ptr;
        size_t* releasedRefCount = refCount;

        ptr = nullptr;
        refCount = nullptr;

        releaseResources(ptr, refCount);

        return releasedPtr;
    }

    ~SmrtPtr() {
        releaseResources(ptr, refCount);
    }

private:
    T* ptr;
    size_t* refCount;
};


template <typename T>
class SmrtPtr<T[]> {
public:
    SmrtPtr() {
        ptr = nullptr;
        refCount = nullptr;
    }

    explicit SmrtPtr(T* ptr) {
        this->ptr = ptr;
        refCount = new size_t(1);
    }

    SmrtPtr(const SmrtPtr<T[]>& other) {
        ptr = other.ptr;
        refCount = other.refCount;

        if (refCount) {
            (*refCount)++;
        }
    }

    SmrtPtr<T[]>& operator =(const SmrtPtr<T[]>& other) {
        if (this != &other) {
            releaseArrayResources(ptr, refCount);

            ptr = other.ptr;
            refCount = other.refCount;

            if (refCount) {
                (*refCount)++;
            }
        }
        return *this;
    }

    T& operator[](size_t index) const {
        return ptr[index];
    }

    T& operator *() {
        return *ptr;
    }

    T* operator ->() {
        return ptr;
    }

    bool operator==(const SmrtPtr<T[]>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const SmrtPtr<T[]>& other) const {
        return ptr != other.ptr;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }

    [[nodiscard]] size_t getRefCount() const {
        return refCount ? *refCount : 0;
    }

    [[nodiscard]] bool isNull() const {
        return ptr == nullptr;
    }

    [[nodiscard]] bool unique() const {
        return refCount != nullptr && (*refCount == 1);
    }

    void reset(T* newPtr = nullptr, size_t newSize = 0) {
        if (this->ptr != newPtr) {
            releaseArrayResources(ptr, refCount);

            ptr = newPtr;
            refCount = new size_t(1);
        }
    }

    ~SmrtPtr() {
        releaseArrayResources(ptr, refCount);
    }

private:
    T* ptr;
    size_t* refCount;
};


#endif //SEM3LAB1_SMART_POINTER_H