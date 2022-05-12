#pragma once
#include <iostream>


//컨테이너 형식의 클래스 템플릿
template <class T>
class Bag
{
protected:
    T *array;
    int capacity;
    int top;

public:
	Bag(){}
	//Bag의 자식이 상속받는 순수가상함수
    virtual ~Bag(){}
    virtual int Size() const = 0;
    virtual bool isEmpty() = 0;
    virtual void Push(const T &x) = 0;
    virtual void Pop() = 0;
};


