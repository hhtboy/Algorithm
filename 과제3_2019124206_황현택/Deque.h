#pragma once
#include <iostream>
#include "Bag.h"
#include "Card.h"
template <class U>
class Deque : public Bag<U>
{
protected:
	int front;
	int rear;

public:
    //생성자 소멸자
	Deque(){};
    Deque(int n);
    ~Deque();

    int Size() const;

    bool isEmpty();

	bool isFull();

	void ChangeSize1D();

	void Push(const U& x);

	void Push_right(const U& x);

	void Push_left(const U& x);

    void Pop();

	void Pop_right();

	void Pop_left();

	void Shift_left();

	void Shift_right();

	void ShowDeque();

};

//생성자
template <class U>
Deque<U>::Deque(int n)
{
	front = 0;
	rear = 0;
	this->capacity = n;
	this->array = new U[this->capacity];
}

//파괴자
template <class U>
Deque<U>::~Deque()
{
	delete []this->array;
	std::cout<<"Deque 삭제"<<std::endl;
}

template <class U>
int Deque<U>::Size() const
{
	return 1;
}


//Deque가 비어있음
template <class U>
bool Deque<U>::isEmpty()
{
	
	if((this->front)%this->capacity == ((this->rear)%this->capacity))
		return true;
	else
		return false;
}

//Deque가 가득 참
template <class U>
bool Deque<U>::isFull()
{
	//rear+1 = front인 경우 true를 반환, (capacity로 나눈 나머지)
	if((this->front)%this->capacity == ((this->rear+1)%this->capacity))
		return true;
	else
		return false;
}

//Deque가 가득 찼을 때 호출됨, 기존 데이터를 복사하고 크기를 두 배로 늘려줌
template <class U>
void Deque<U>::ChangeSize1D()
{
	U* temp = new U[this->capacity * 2];
	//front가 제일 앞에 있을 경우
	if(front%this->capacity == 0)
	{
		//Deque 뒷부분 복사
		std::copy(this->array + 1, this->array + this->capacity, temp + 1 + this->capacity);
		//rear값을 맨 뒤로 이동시켜줌
		rear = rear + this->capacity;
	}

	//front가 제일 뒤에 있을 경우
	else if(front%this->capacity == this->capacity - 1)
	{
		//Deque 앞부분 복사
		std::copy(this->array, this->array + this->capacity - 1, temp);
	}

	//front가 중앙에 있을 경우
	else
	{
		//Deque 뒷부분 복사
		std::copy(this->array + front%this->capacity + 1, this->array + this->capacity, temp + (front % this->capacity) + this->capacity + 1);
		//Deque 앞부분 복사
		std::copy(this->array, this->array + (rear%this->capacity) + 1, temp);
	}

	//front와 rear의 위치를 다시 잡아준다.
	front = front + this->capacity;
	this->capacity *= 2;
	delete []this->array;
	this->array = temp;
}

//Deque에 새 데이터를 넣음, 크기가 가득 찼으면 크기를 늘려줌
template <class U>
void Deque<U>::Push(const U& x)
{
	//Deque가 가득 차면 크기를 늘림
	if(isFull())
	{
		ChangeSize1D();
	}
	this->array[++rear%this->capacity] = x;
}

//rear 오른쪽에 데이터 삽입
template <class U>
void Deque<U>::Push_right(const U& x)
{
	if(isFull())
	{
		ChangeSize1D();
	}

	this->array[++rear%this->capacity] = x;
}

//front 왼쪽에 데이터 삽입
template <class U>
void Deque<U>::Push_left(const U& x)
{
	if(isFull())
	{
		ChangeSize1D();
	}

	//front가 0 보다 크면 1 감소시킴
	if(front > 0)
	{
		this->array[(front--)%this->capacity] = x;
	}

	//front가 0일 경우 Deque의 끝으로 front를 옮김
	else // front == 0
	{
		this->array[(front)%this->capacity] = x;
		front = this->capacity - 1;
	}
}

template <class U>
void Deque<U>::Pop()
{
	this->array[(front + 1)%this->capacity].~U();
	front++;
}

template <class U>
void Deque<U>::Pop_right()
{
	this->array[rear%this->capacity].~U();
	//rear == 0이면 rear을 감소시킬 때 맨 뒤로 보냄
	if(rear>0)
		rear--;
	else
		rear = this->capacity - 1;
}

template <class U>
void Deque<U>::Pop_left()
{
	this->array[(front + 1)%this->capacity].~U();
	front++;
}

//pop_left + push_right
template <class U>
void Deque<U>::Shift_left()
{
	//Push할 때 데이터를 보존하기 위해 push->pop순서로 한다
	Push_right(this->array[(front + 1)%this->capacity]);
	Pop_left();
}

template <class U>
void Deque<U>::Shift_right()
{
	//Push할 때 데이터를 보존하기 위해 push->pop순서로 한다
	Push_left(this->array[rear%this->capacity]);
	Pop_right();
}

template <class U>
void Deque<U>::ShowDeque()
{
	for(int i = 0; i < this->capacity ; i++)
	{
		std::cout<<this->array[i];
	}

	std::cout<<"front = "<<front<<"   rear = "<<rear<<std::endl;
	std::cout<<std::endl;

	
}
















