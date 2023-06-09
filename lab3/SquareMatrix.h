#ifndef LAB3_SQUAREMA_TRIX_H
#define LAB3_SQUARE_MATRIX_H
#include "class.h"

// Класс для квадратной матрицы
template <typename T>
class SquareMatrix {
private:
    DynamicArray<DynamicArray<T>*> matrix;
    int size;

public:
    SquareMatrix(int matrix_size) : size(matrix_size) {
        for (int i = 0; i < size; i++) {
            DynamicArray<T>* row = new DynamicArray<T>();
            for (int j = 0; j < size; j++) {
                row->push_back(T());
            }
            matrix.push_back(row);
        }
    }

    int getSize() const {
        return size;
    }

    const DynamicArray<T>& operator[](int index) const {
        return *(matrix[index]);
    }

    DynamicArray<T>& operator[](int index) {
        return *(matrix[index]);
    }

    void multiplyByConstant(const T& constant) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*this)[i][j] *= constant;
            }
        }
    }

    void addByConstant(const T& constant) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*this)[i][j] += constant;
            }
        }
    }

    void addMatrix(const SquareMatrix<T>& other) {
        if (size != other.size) {
            cout << "Wrong!" << endl;
            system("pause");
            throw std::invalid_argument("Matrix sizes are not equal!");
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*this)[i][j] += other[i][j];
            }
        }
    }

    void multiplyByMatrix(const SquareMatrix<T>& other) {
        if (size != other.size) {
            cout << "Wrong!" << endl;
            system("pause");
            throw std::invalid_argument("Matrix sizes are not compatible for multiplication!");
        }
        SquareMatrix<T> result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                T sum = T();
                for (int k = 0; k < size; k++) {
                    sum += (*this)[i][k] * other[k][j];
                }
                result[i][j] = sum;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                (*this)[i][j] = result[i][j];
            }
        }
    }

    void linealMatrix(int constant, int constant2) {
        for (int j = 0; j < size; j++) {
            (*this)[constant][j] += (*this)[constant2][j];
        }
    }

    void printMatrix() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << (*this)[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~SquareMatrix() {
        for (int i = 0; i < size; i++) {
            delete matrix[i];
        }
    }
};

#endif //LAB3_SQUARE_MATRIX_H
