#include "Bag.h"
#include <iostream>

//�����ڿ� �ı���
template <class T>
Bag<T>::Bag()
{
    capacity = 10;
    top = -1;
    array = new T[capacity];
    std::cout << "Bag ����" << std::endl;
}

template <class T>
Bag<T>::~Bag()
{
    delete[] array;
    std::cout << "Bag �Ҹ�" << std::endl;
}

template <class T>
void Bag<T>::Push(const T &x)
{
    //������ ���� ��
    if (top == capacity - 1)
    {
        std::cout << "stack is full";
        return;
    }

    array[++top] = x;

    std::cout << "���� top�� " << top << "top�� ���Ҵ� " << array[top];
}
