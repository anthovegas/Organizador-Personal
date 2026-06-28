#include "cvector.h"
using namespace std;

template <typename T>
CVector<T>::CVector() : data(nullptr), size_(0), capacity_(0) {}

template <typename T>
CVector<T>::CVector(const CVector<T>& other) : data(nullptr), size_(0), capacity_(0) {
    if (other.capacity_ > 0) {
        data = new T[other.capacity_];
        capacity_ = other.capacity_;
        size_ = other.size_;
        for (auto i = 0; i < size_; i++) {
            data[i] = other.data[i];
        }
    }
}

template <typename T>
CVector<T>& CVector<T>::operator=(const CVector<T>& other) {
    if (this == &other) return *this;

    delete[] data;

    capacity_ = other.capacity_;
    size_ = other.size_;
    data = (capacity_ > 0) ? new T[capacity_] : nullptr;
    for (auto i = 0; i < size_; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
CVector<T>::~CVector() {
    delete[] data;
}

template <typename T>
void CVector<T>::grow() {
    I newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    T* newData = new T[newCapacity];

    for (auto i = 0; i < size_; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity_ = newCapacity;
}

template <typename T>
void CVector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        grow();
    }
    data[size_] = value;
    size_++;
}

template <typename T>
I CVector<T>::size() const { return size_; }

template <typename T>
B CVector<T>:: empty() const { return size_ == 0; }

template <typename T>
void CVector<T>::clear() { size_ = 0; }

template <typename T>
T& CVector<T>::operator[](I index) { return data[index]; }

template <typename T>
const T& CVector<T>::operator[](int index) const { return data[index]; }

template <typename T>
T& CVector<T>::at(I index) {
    if (index < 0 || index >= size_) {
        throw out_of_range("CVector::at- indice fuera de rango ");
    }
    return data[index];
}