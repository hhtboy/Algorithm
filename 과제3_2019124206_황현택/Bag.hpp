#include "Bag.h"
#include <iostream>

//생성자와 파괴자
template <class T>
Bag<T>::Bag()
{
    capacity = 10;
    top = -1;
    array = new T[capacity];
    std::cout << "Bag 생성" << std::endl;
}

template <class T>
Bag<T>::~Bag()
{
    delete[] array;
    std::cout << "Bag 소멸" << std::endl;
}

template <class T>
void Bag<T>::Push(const T &x)
{
    //스택이 가득 참
    if (top == capacity - 1)
    {
        std::cout << "stack is full";
        return;
    }

    array[++top] = x;

    std::cout << "현재 top은 " << top << "top의 원소는 " << array[top];
}
