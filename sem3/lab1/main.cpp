#include <iostream>

template <typename T>
class SmartPointer {
public:
    // Конструктор, принимающий указатель
    SmartPointer(T* ptr) : ptr_(ptr), refCount_(new size_t(1)) {}

    // Копирующий конструктор
    SmartPointer(const SmartPointer<T>& other) : ptr_(other.ptr_), refCount_(other.refCount_) {
        ++(*refCount_);
    }

    // Оператор присваивания
    SmartPointer<T>& operator=(const SmartPointer<T>& other) {
        if (this != &other) {
            // Уменьшаем счетчик ссылок текущего объекта
            Release();

            ptr_ = other.ptr_;
            refCount_ = other.refCount_;
            ++(*refCount_);
        }
        return *this;
    }

    // Деструктор
    ~SmartPointer() {
        Release();
    }

    // Оператор разыменования
    T& operator*() {
        return *ptr_;
    }

    // Оператор доступа к членам указателя
    T* operator->() {
        return ptr_;
    }

private:
    T* ptr_;
    size_t* refCount_;

    void Release() {
        if (ptr_ && --(*refCount_) == 0) {
            delete ptr_;
            delete refCount_;
            ptr_ = nullptr;
            refCount_ = nullptr;
        }
    }
};

int main() {
    SmartPointer<int> sp1(new int(42));
    SmartPointer<int> sp2 = sp1; // Копирующий конструктор

    std::cout << "sp1: " << *sp1 << std::endl;
    std::cout << "sp2: " << *sp2 << std::endl;

    sp1 = sp2; // Оператор присваивания

    std::cout << "sp1: " << *sp1 << std::endl;
    std::cout << "sp2: " << *sp2 << std::endl;

    return 0;
}
