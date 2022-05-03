#pragma once
#include "Bag.h"

template <class T>
class Deque : public Bag<T>
{
private:
public:
    //생성자 소멸자
    Deque();
    ~Deque();
    int Size() const;
    bool isEmpty();
    void Push(const T& x)
	{
		
	}
    void Pop();

};

