#pragma once
#include <iostream>

template <class T>
class Bag
{
protected:
    T *array;
    int capacity;
    int top;

public:
	Bag()
	{
		std::cout<<"bag 생성"<<std::endl;
	}
    virtual ~Bag()
	{
		std::cout<<"bag 소멸"<<std::endl;
	} 
    virtual int Size() const = 0;
    virtual bool isEmpty() = 0;
    virtual void Push(const T &x) = 0;
    virtual void Pop() = 0;
};


