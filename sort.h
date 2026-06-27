#ifndef __SORT_H__
#define __SORT_H__

#include "item.h"

template <typename T>
void intercambiar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

bool MenorPrioridad(Item* a, Item* b);

template <typename T, typename Func>
void BurbujaClasico(T arr[], I n, Func comesBefore);

template <typename T, typename Func>
I Particionar(T arr[], I first, I last, Func comesBefore);

template <typename T, typename Func>
void QuickSort(T arr[], I first, I last, Func comesBefore);

template <typename T, typename Func>
void Merge(T arr[], I left, I mid, I right, Func comesBefore);

template <typename T, typename Func>
void MergeSort(T arr[], I begin, I end, Func comesBefore);

#include "sort.cpp" 

#endif // __SORT_H__