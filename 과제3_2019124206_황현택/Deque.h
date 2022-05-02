#pragma once

template <class T>
class Deque : public Bag
{
private:
public:
    //생성자 소멸자
    Deque();
    ~Deque();
    void Push(const T &x);
};

#include "Deque.hpp"