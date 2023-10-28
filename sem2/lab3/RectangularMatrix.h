#ifndef LAB3_RECTANGULAR_MATRIX_H
#define LAB3_RECTANGULAR_MATRIX_H
#include "class.h"

template <typename T>
class RectangularMatrix {
private:
    DynamicArray<DynamicArray<T>*> matrix;
    int rows;
    int cols;

public:
    RectangularMatrix(int matrix_rows, int matrix_cols) : rows(matrix_rows), cols(matrix_cols) {
        for (int i = 0; i < rows; i++) {
            DynamicArray<T>* row = new DynamicArray<T>();
            for (int j = 0; j < cols; j++) {
                row->push_back(T());
            }
            matrix.push_back(row);
        }
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    const DynamicArray<T>& operator[](int index) const {
        return *(matrix[index]);
    }

    DynamicArray<T>& operator[](int index) {
        return *(matrix[index]);
    }

    void multiplyByConstant(const T& constant) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                (*this)[i][j] *= constant;
            }
        }
    }

    void addByConstant(const T& constant) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                (*this)[i][j] += constant;
            }
        }
    }

    void addMatrix(const RectangularMatrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "\"Matrix sizes are not equal!\"" << endl;
            system("pause");
            throw std::invalid_argument("Matrix sizes are not equal!");
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                (*this)[i][j] += other[i][j];
            }
        }
    }

    void multiplyByMatrix(const RectangularMatrix<T>& other) {
        if (cols != other.rows) {
            cout << "\"Matrix sizes are not equal!\"" << endl;
            system("pause");
            throw std::invalid_argument("Matrix sizes are not compatible for multiplication!");
        }
        RectangularMatrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                T sum = T();
                for (int k = 0; k < cols; k++) {
                    sum += (*this)[i][k] * other[k][j];
                }
                result[i][j] = sum;
            }
        }
        matrix.resize(rows);
        for (int i = 0; i < rows; i++) {
            (*matrix[i]).resize(other.cols);
            for (int j = 0; j < other.cols; j++) {
                (*matrix[i])[j] = result[i][j];
            }
        }
    }

    void linealMatrix(int constant, int constant2) {
        for (int j = 0; j < cols; j++) {
            (*this)[constant][j] += (*this)[constant2][j];
        }
    }

    void printMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << (*this)[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~RectangularMatrix() {
        for (int i = 0; i < rows; i++) {
            delete matrix[i];
        }
    }
};


#endif //LAB3_RECTANGULAR_MATRIX_H
