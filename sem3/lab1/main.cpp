#include <iostream>
using namespace std;


template <typename T>
class SmrtPtr {
public:
    SmrtPtr() {
        ptr = nullptr;
        refCount = nullptr;
    }

    SmrtPtr(T* ptr) {
        this->ptr = ptr;
        refCount = new size_t(1);
    }

    SmrtPtr(const SmrtPtr<T>& other) {
        this->ptr = other.ptr;
        this->refCount = other.refCount;

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

            if (refCount) {
                (*refCount)++;
            }
        }
        return *this;
    }

    T& operator *() {
        return *ptr;
    }

    T* operator ->() {
        return ptr;
    }

    ~SmrtPtr() {
        if (refCount && --(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
    }

private:
    T* ptr;
    size_t* refCount;
};


int main() {
    SmrtPtr<int> sp1(new int(42));
    SmrtPtr<int> sp2 = sp1;
    SmrtPtr<int> sp3(new int(100));

    sp3 = sp2;

    cout << *sp1 << endl;
    cout << *sp2 << endl;
    cout << *sp3 << endl;

    system("pause");
    return 0;
}