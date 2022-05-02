#pragma once

template <typename T>
class Bag
{
private:
    T *array;
    int capacity;
    int top;

public:
    virtual Bag();
    virtual ~Bag();
    virtual int Size() const;
    virtual bool isEmpty();
    virtual void Push(const T &x);
    virtual void Pop();
};

#include "Bag.hpp"