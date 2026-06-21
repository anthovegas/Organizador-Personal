#include "cmatrix.h"
using namespace std;

template <typename T>
I CMatrix<T>::indexOf(I row, I col) const {
    return row * cols_ + col;
}

template <typename T>
CMatrix<T>::CMatrix(I rows, I cols, T defaultValue)
    : data(nullptr), rows_(rows), cols_(cols) {
    data = new T[rows_ * cols_];
    for (auto i = 0; i < rows_ * cols_; i++) {
        data[i] = defaultValue;
    }
}

template <typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& other)
    : data(nullptr), rows_(other.rows_), cols_(other.cols_) {
    I total = rows_ * cols_;
    data = new T[total];
    for (auto i = 0; i < total; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& other) {
    if (this == &other)  return *this;

    delete[] data;
    rows_ = other.rows_;
    cols_ = other.cols_;
    I total = rows_ * cols_;
    data = new T[total];
    for (auto i = 0; i < total; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
CMatrix<T>::~CMatrix() {
    delete[] data;
}

template <typename T>
I CMatrix<T>::rows() const { return rows_; }

template <typename T>
I CMatrix<T>::cols() const { return cols_; }

template <typename T>
T& CMatrix<T>::at(I row, I col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw out_of_range("CMatrix::at - indice fuera de rango");
    }
    return data[indexOf(row, col)];
}

template <typename T>
const T& CMatrix<T>::at(I row, I col) const {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw out_of_range("CMatrix::at - indice fuera de rango");
    }
    return data[indexOf(row, col)];
}