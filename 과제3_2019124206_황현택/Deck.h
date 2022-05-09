#pragma once
#include <iostream>
#include <cstdlib>
#include "Card.h"
#include  "Deque.h"

inline int Abs(int n)
{
	if(n>=0) {return n;}
	else {return (-1)*n;}
}

class Deck : public Deque<Card> {
private:
	//front와 rear가 선택됐을 때 shift할 횟수
	int f;
	int r;
public:
	Deck(){};
	Deck(int n);
	~Deck();

	int GetCardIndex(Card& C);
	bool isFront(int index);
	void MoveCard(Card&C, int index);
	void ShowDeck();
	//n개의 랜덤 카드를 생성하고 넣어줌
	friend void MakeRandCard(Deck& D, int num);
	
};

Deck::Deck(int n)
{
	front = 0;
	rear = 0;
	capacity = n;
	array = new Card[capacity];
	std::cout<<"Deck 생성"<<std::endl;
}

Deck::~Deck()
{
	std::cout<<"Deck 소멸"<<std::endl;
}

int Deck::GetCardIndex(Card& C)
{
	int i;
	for(i = (front + 1) % capacity ; i != (rear + 1) % capacity ; )
	{
		if(array[i] > C)
		{
			i = (i + 1) % capacity;
		}
		else
		{
			return i;

		}
	}
	return i % capacity;
}

//shift를 front를 선택해서 할 지 결정
bool Deck::isFront(int index)
{
	f = 0;
	r = 0;
	if(index>front%capacity)
		f = index - front%capacity - 1;
	else
		f = capacity - (front%capacity - index + 1);
	if(index < rear)
		r = rear%capacity - index;
	else
		r = capacity - (rear%capacity - index);

	if(f <= r)
		return true;
	else
		return false;
}

void Deck::MoveCard(Card& C, int index)
{
	//front 선택
	if(isFront(index))
	{
		int num = (front + 1)%capacity;
		for(int i = 0 ; i < f  ; i++)
		{
			Shift_left();
		}
		Push_left(C);
		for(int i = 0 ; i < f ; i++)
		{
			Shift_right();
		}
	}

	//rear 선택
	else
	{
		int num = (rear + 1)%capacity;
		for(int i = 0 ; i < r ; i++)
		{
			Shift_right();
		}
		Push_right(C);
		for(int i = 0 ; i < r ; i++)
		{
			Shift_left();
		}
	}
}

void Deck::ShowDeck()
{
	int i = (front + 1)%capacity;
	while(true)
	{
		std::cout<<array[i];
		if(i == rear%capacity)
			break;
		if(++i >= capacity)
			i = i%capacity;
	}
}

void MakeRandCard(int num)
{
	int array[52];
	//50번 섞을 것임
	int mixCount = 50;
	for(int i = 0; i < 52 ; i++)
	{
		array[i] = i + 1;
	}

	for(int i = 0 ; i < mixCount ;)
	{
		int c1 = (rand())%52;
		int c2 = (rand())%52;
		if(c1 != c2)
		{
			swap(array[c1],array[c2]);
			i++;
		}
	}

	//카드를 만들 만큼 배열의 앞부분에서 할당해줌
	int index;
	Deck D(10);
	for(int i = 0; i < num ; i++)
	{
		Card C;
		switch(array[i]/13)
		{
		case 0 :
			C.shape = Clover;
			break;
		case 1 :
			C.shape = Heart;
			break;
		case 2:
			C.shape = Diamond;
			break;
		case 3:
			C.shape = Spaid;
			break;
		default:
			C.shape = none;
			break;
		}
		C.cardNum = array[i]%13 + 1;
		C.cardRank = array[i] + 1;
		index = D.GetCardIndex(C);
		std::cout<<"이번에 넣을 카드 번호는 : "<<array[i] + 1<<std::endl;
		D.MoveCard(C,index);
		D.ShowDeque();
		D.ShowDeck();
	}

}
