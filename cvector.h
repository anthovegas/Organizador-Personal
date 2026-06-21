#ifndef __CVECTOR_H__
#define __CVECTOR_H__

//#include <stdexcept> ///////////////

using I = int;
using B = bool;

template <typename T>
class CVector {
private:
    T* data;
    I size_;
    I capacity_;

    void grow();

public:
    CVector();
    CVector(const CVector<T>& other);
    CVector<T>& operator=(const CVector<T>& other);
    ~CVector();

    void push_back(const T& value);
    I size() const;
    B empty() const;
    void clear();

    T& operator[](I index);
    const T& operator[](I index) const;
    T& at(I index);

};

#include "cvector.cpp"

#endif //__CVECTOR_H__