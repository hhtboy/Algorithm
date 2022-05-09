#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
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
	bool isFront(Card& C);
	void MoveCard(Card& C);
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



//shift를 front를 선택해서 할 지 결정
bool Deck::isFront(Card& C)
{
	f = 0;
	r = 0;
	for(int i = 0;array[(front + i + 1)%capacity] > C  ; i++)
	{
		f++;
	}
	for(int i = 0;C > array[(rear - i)%capacity]; i++)
	{
		r++;
	}

	if( f<= r)
		return true;
	else
		return false;
}

void Deck::MoveCard(Card& C)
{
	ShowDeck();
	//front 선택
	if(isFront(C))
	{
		for(int i = 0 ; i < f  ; i++)
		{
			Shift_left();
			ShowDeck();
		}
		Push_left(C);
		ShowDeck();
		for(int i = 0 ; i < f ; i++)
		{
			Shift_right();
			ShowDeck();
		}
	}

	//rear 선택
	else
	{
		for(int i = 0 ; i < r ; i++)
		{
			Shift_right();
			ShowDeck();
		}
		Push_right(C);
		ShowDeck();
		for(int i = 0 ; i < r ; i++)
		{
			Shift_left();
			ShowDeck();
		}
	}
}

void Deck::ShowDeck()
{
	int i = (front + 1)%capacity;
	while(true)
	{
		if(front==0&&rear==0)
			return;
		std::cout<<array[i];
		if(i == rear%capacity)
			break;
		if(++i >= capacity)
			i = i%capacity;
	}
	std::cout<<std::endl;
}

void MakeRandCard(int num)
{
	//1부터 52까지 배열을 만들고
	//랜덤으로 50번 섞는다
	int array[52];
	srand((unsigned)time(NULL));
	int mixCount = 50;
	for(int i = 0; i < 52 ; i++)
	{
		array[i] = i;
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
	Deck D(10);
	for(int i = 0; i < num ; i++)
	{
		Card C;
		switch(array[i]/13)
		{
		//숫자를 13으로 나눈 몫이 모양, 나머지가 (1 ~ 13) 번호가 된다.
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
		//생성한 카드에 데이터를 집어넣는다ㅓ
		C.cardNum = array[i]%13 + 1;
		C.cardRank = array[i] + 1;
		std::cout<<"이번에 넣을 카드 : "
				 << C <<std::endl;
		D.MoveCard(C);
		std::cout<<"-------------------------------"<<std::endl;
	}

}
