#pragma once

template <class T>
class Bag
{
protected:
    T *array;
    int capacity;
    int top;

public:
    Bag();
    virtual ~Bag();
    virtual int Size() const;
    virtual bool isEmpty();
    virtual void Push(const T &x);
    virtual void Pop();
};

