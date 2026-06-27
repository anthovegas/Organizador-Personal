#include "sort.h"

bool MenorPrioridad(Item* a, Item* b) {
    return a->getPriority() < b->getPriority();
}

template <typename T, typename Func>
void BurbujaClasico(T arr[], I n, Func comesBefore) {
    if (n <= 1) return;
    for (auto i = 0; i < n - 1; ++i)
        for (auto j = i + 1; j < n; ++j)
            if (comesBefore(arr[j], arr[i]))
                intercambiar(arr[i], arr[j]);
}

template <typename T, typename Func>
I Particionar(T arr[], I first, I last, Func comesBefore) {
    T pivote = arr[last];
    I i = first - 1;

    for (auto j = first; j <= last - 1; ++j) {
        if (comesBefore(arr[j], pivote)) {
            ++i;
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[last]);
    return i + 1;
}

template <typename T, typename Func>
void QuickSort(T arr[], I first, I last, Func comesBefore) {
    if (first < last) {
        I pi = Particionar(arr, first, last, comesBefore);
        QuickSort(arr, first, pi - 1, comesBefore);
        QuickSort(arr, pi + 1, last, comesBefore);
    }
}

template <typename T, typename Func>
void Merge(T arr[], I left, I mid, I right, Func comesBefore) {
    I subArrayOne = mid - left + 1;
    I subArrayTwo = right - mid;

    T* leftArray  = new T[subArrayOne];
    T* rightArray = new T[subArrayTwo];

    for (I i = 0; i < subArrayOne; ++i) leftArray[i]  = arr[left + i];
    for (I j = 0; j < subArrayTwo; ++j) rightArray[j] = arr[mid + 1 + j];

    I i = 0, j = 0, k = left;
    while (i < subArrayOne && j < subArrayTwo) {
        if (comesBefore(leftArray[i], rightArray[j])) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    while (i < subArrayOne)  { arr[k] = leftArray[i];  ++i; ++k; }
    while (j < subArrayTwo)  { arr[k] = rightArray[j]; ++j; ++k; }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T, typename Func>
void MergeSort(T arr[], I begin, I end, Func comesBefore) {
    if (begin >= end)
        return;

    I mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid, comesBefore);
    MergeSort(arr, mid + 1, end, comesBefore);
    Merge(arr, begin, mid, end, comesBefore);
}