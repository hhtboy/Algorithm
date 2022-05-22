#pragma once
#include <iostream>

template <class T>
class CNode {
private:
	T data;
	//노드의 뒤 노드에 대한 포인터
	CNode<T>* nextNode;

public:
	CNode();
	~CNode();
	CNode(const T& x);
	//클래스 템플릿을 friend 로 선언하는 방법
	template <class C> friend class CircularList;
};

template <class T>
CNode<T>::CNode()
{

}

template <class T>
CNode<T>::~CNode()
{
	std::cout<<data<<" 노드 삭제"<<std::endl;
}

template <class T>
CNode<T>::CNode(const T& x)
{
	data = x;
}
