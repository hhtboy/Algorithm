#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class Chain {
private:
	//첫번째 노드 포인터
	Node<T>* first;
public:
	Chain() : first(0){};
	class Iterator {
	private:
		Node<T> *current;

	public:
		Iterator(Node<T> *x)
		{
			current = x;
		}

		Iterator& operator ++()
		{
			current = current->link;
			return *this;
		}

		Iterator operator ++(int)
		{
			Iterator old = *this;
			current = current->link;
			return old;
		}
		
		

		bool operator == (const Iterator& iter)
		{
			return current == iter.current;
		}

		bool operator != (const Iterator& iter)
		{
			return current != iter.current;
		}

		T& operator*() const 
		{
			return current->data;
		}

		T* operator&() const
		{
			return &current->data;
		}

		friend std::ostream& operator<<(std::ostream& os, Iterator& iter)
		{
			os << iter.current->data;
			return os;
		}
	};

	Iterator Begin()
	{
		return Iterator(first);
	}

	Iterator End()
	{
		return Iterator(0);
	}

	
	void Insert(Node<T> *x);
	void Delete(Node<T> *x, Node<T> *y);
};



template <class T>
void Chain<T>::Insert(Node<T> *x)
{
	if(first)
	{
		first->link = new Node<T>(x->data,x->link);
	}
	else
	{
		first = new Node<T>(x->data,0);
	}
}

template <class T>
void Chain<T>::Delete(Node<T> *x, Node<T> *y)
{

}


