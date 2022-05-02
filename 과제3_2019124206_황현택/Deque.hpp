#include "Deque.h"
#include <iostream>

//생성자
template <class T>
Deque<T>::Deque()
{
}

//파괴자
template <class T>
Deque<T>::~Deque()
{
}

// Push
template <class T>
void Deque<T>::Push(const T &x)
{
    mn = 1;
}