#pragma once
#include <iostream>
#include "Bag.h"

//Bag를 상속받은 클래스 템플릿
template <class U>
class Deque : public Bag<U>
{
protected:
	//데이터의 시작과 끝 index
	//front는 비워두고, 다음 index 부터 채워넣음
	int front;
	int rear;

public:
	//기본 생성자를 정의하지 않으면 템플릿 클래스를 생성할 때 컴파일 에러가 생김
	Deque(){};
    Deque(int n);
    ~Deque();

    int Size() const;

    bool isEmpty();

	//deque가 가득 찼을 때 true 반환(front 제외)
	bool isFull();

	//가득찬 deque의 크기를 늘림
	void ChangeSize1D();

	void Push(const U& x);
	void Push_Rear(const U& x);
	void Push_Front(const U& x);
    void Pop();
	void Pop_Rear();
	void Pop_Front();

	//디큐를 왼쪽으로 한칸씩 이동
	void Shift_left();
	//디큐를 오른쪽으로 한칸씩 이동
	void Shift_right();
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
	rear++;
	//front, rear가 capacity보다 커지는 것을 방지
	rear = rear % this->capacity;
	
	this->array[rear%this->capacity] = x;
}

//rear 오른쪽에 데이터 삽입
template <class U>
void Deque<U>::Push_Rear(const U& x)
{
	if(isFull())
	{
		ChangeSize1D();
	}
	rear++;
	//front, rear가 capacity보다 커지는 것을 방지
	rear = rear % this->capacity;

	this->array[rear%this->capacity] = x;
}

//front 왼쪽에 데이터 삽입
template <class U>
void Deque<U>::Push_Front(const U& x)
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
		//front, rear가 capacity보다 커지는 것을 방지
		front = front % this->capacity;

	}
}

template <class U>
void Deque<U>::Pop()
{
	this->array[(front + 1)%this->capacity].~U();
	front++;
	//front, rear가 capacity보다 커지는 것을 방지
	front = front % this->capacity;

}

template <class U>
void Deque<U>::Pop_Rear()
{
	this->array[rear%this->capacity].~U();
	//rear == 0이면 rear을 감소시킬 때 맨 뒤로 보냄
	if(rear>0)
		rear--;

	else
		rear = this->capacity - 1;
	//rear가 capacity보다 작아지지 않게 조정
	rear = rear % this->capacity;
}

template <class U>
void Deque<U>::Pop_Front()
{
	this->array[(front + 1)%this->capacity].~U();
	front++;
	//front가 capacity보다 커지지 않게 조정
	front = front % this->capacity;
}

//pop_left + push_right
template <class U>
void Deque<U>::Shift_left()
{
	//Push할 때 데이터를 보존하기 위해 push->pop순서로 한다
	Push_Rear(this->array[(front + 1)%this->capacity]);
	Pop_Front();
}
template <class U>
void Deque<U>::Shift_right()
{
	//Push할 때 데이터를 보존하기 위해 push->pop순서로 한다
	Push_Front(this->array[rear%this->capacity]);
	Pop_Rear();
}


