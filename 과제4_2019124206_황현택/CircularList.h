#pragma once
#include "CNode.h"
#include "Card.h"
#include <iostream>

template <class T>
class CircularList {
private:
	CNode<T>* first;
	CNode<T>* last;
public:
	//생성자 파괴자
	CircularList()
	{
		last = nullptr;
	}
	~CircularList()
	{
		int n = 0;
		while(first!=first->nextNode)
		{
			CNode<T>* remove = first->nextNode;
			first->nextNode = remove->nextNode;
			delete remove;
		}
		delete first;
	}

	//리스트 앞에 노드 삽입
	void InsertFront(const T& e);

	//리스트 정렬
	void SortList();

	//노드를 뒷 노드와 swap, 노드의 전 노드 prev가 필요
	void Swap(CNode<T>* cur);

	//리스트 내용 출력
	void ShowList();	
		
	//원형리스트에 대한 반복자
	class CircularIterator {

	private:
		//반복자에서 다룰 노드, 현재 가리키고 있는 노드에 대한 포인터
		CNode<T>* current;
	public:
		friend class CircularList;
		CircularIterator(CNode<T>* x)
		{
			current = x;
		}
		~CircularIterator()
		{
		}
		//사전&사후 증가 연산자
		CircularIterator& operator++()
		{
			current = current -> nextNode;
			return *this;
		}
		CircularIterator operator++(int)
		{
			CircularIterator old = *this;
			current = current->nextNode;
			return old;
		}

		//덧셈 연산자
		CircularIterator& operator+(int)
		{
			current = current->nextNode;
			return *this;
		}

		//뺄셈 연산자
		CircularIterator& operator-(int)
		{
		}

		//동등 검사 연산자
		bool operator==(CircularIterator iter)
		{
			return current == iter->current;
		}

		bool operator!=(CircularIterator iter)
		{
			return current != iter.current;
		}

		//참조&역참조 연산자
		T& operator*() const
		{
			return current->data;
		}
		T* operator->() const
		{
			return &current->data;
		}

		bool operator > (CircularIterator iter)
		{
			return iter.current->data > iter.current->nextNode->data;
		}

		friend std::ostream& operator<<(std::ostream& os, const CircularIterator& iter)
		{
			os <<
			"current = "<<
			iter.current->data<<
			std::endl;
			return os;
		}

	};

	CircularIterator Begin()
	{
		return CircularIterator(first);
	}

	CircularIterator End()
	{
		return CircularIterator(last);
	}

};

template <class T>
void CircularList<T>::InsertFront(const T& e)
{
	CNode<T> *newNode = new CNode<T>(e);
	//공백이 아닌 리스트
	if(last)
	{
		newNode->nextNode = first->nextNode;
		first->nextNode = newNode;
	}
	//공백 리스트
	else
	{
		first = new CNode<T>();
		last = newNode;
		first->nextNode = last;
		last->nextNode = first;
	}
}

template <class T>
void CircularList<T>::SortList()
{
	for(CircularIterator iter = ++this->Begin(); iter.current->nextNode->data != 0;)
	{
		if(iter.current->data > iter.current->nextNode->data)
		{
			Swap(iter.current);
			ShowList();
			std::cout<<"\n";
		}
		else
		{
			iter++;
		}
	}
}

template <class T>
void CircularList<T>::Swap(CNode<T>* cur)
{
	//swap 후 last가 변했다면 last를 바꿔줌
	if(cur->nextNode == last)
	{
		last = cur;
	}

	//스왑할 노드의 앞 노드를 찾음
	CircularIterator iter = this->Begin();
	for(; iter.current->nextNode != cur; iter++){}
	
	//prev, cur, next를 사용해 swap
	CNode<T>* prev = iter.current;
	CNode<T>* next = cur->nextNode;

	prev->nextNode = cur->nextNode;
	cur->nextNode = next->nextNode;
	next->nextNode = cur;

}

template <class T>
void CircularList<T>::ShowList()
{
	for(CircularIterator iter = ++this->Begin(); iter != this->End() + 1; iter++)
	{
		std::cout<<iter;
	}
}
