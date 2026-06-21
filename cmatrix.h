#ifndef __CMATRIX_H__
#define __CMATRIX_H__

using I = int;

//#include <stdexcept> ///////////////

template <typename T>
class CMatrix {
private:
    T* data;
    I rows_;
    I cols_;

    I indexOf(I row, I col) const;

public:
    CMatrix(I rows, I cols, T defaultValue = T());
    CMatrix(const CMatrix<T>& other);
    CMatrix<T>& operator=(const CMatrix<T>& other);
    ~CMatrix();

    I rows() const;
    I cols() const;

    T& at(I row, I col);
    const T& at(I row, I col) const;
};

#include "cmatrix.cpp"

#endif // __CMATRIX_H__