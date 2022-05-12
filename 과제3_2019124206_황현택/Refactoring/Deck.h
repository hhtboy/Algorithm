#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
#include  "Deque.h"
#include "Card.h"

class Card;

//절댓값을 구해주는 함수
inline int Abs(int n)
{
	if(n>=0) {return n;}
	else {return (-1)*n;}
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


class Deck : public Deque<Card> {
private:
	//front와 rear가 선택됐을 때 shift할 횟수
	int f;
	int r;
	int randNumArr[52];
public:
	Deck(){};
	Deck(int n);
	~Deck();
	bool isFront(Card& C);
	void PushAndShift(Card& C);
	void ShowDeck();
	void CreateRandArr();
	//n개의 카드를 만들고 덱에 넣음
	void MakeRandCard(int n);
	//n개의 랜덤 카드를 생성하고 넣어줌
};

Deck::Deck(int n)
{
	front = 0;
	rear = 0;
	capacity = n;
	array = new Card[capacity];
}

Deck::~Deck()
{
}



//shift를 front를 선택해서 할 지 결정
bool Deck::isFront(Card& C)
{
	f = 0;
	r = 0;
	//front와 들어갈 index를 비교해서 거리 f 측정
	for(int i = 0; C > array[(front + i + 1)%capacity]  ; i++)
	{
		f++;
	}
	//rear과 들어갈 index를 비교해서 거리 r 측정
	for(int i = 0;array[(rear - i)%capacity] > C; i++)
	{
		r++;
	}

	//f와 r중 더 작은 값을 리턴해서 적게 shift하게끔 함
	if( f<= r)
		return true;
	else
		return false;
}

void Deck::PushAndShift(Card& C)
{
	ShowDeck();
	//front 선택
	if(isFront(C))
	{
		//f번 shift한 후 push하고 다시 f번 shift해줌
		for(int i = 0 ; i < f  ; i++)
		{
			Shift_left();
			ShowDeck();
		}
		Push_Front(C);
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
		//r번 shift하고 push한 후 다시 r번 shift
		for(int i = 0 ; i < r ; i++)
		{
			Shift_right();
			ShowDeck();
		}
		Push_Rear(C);
		ShowDeck();
		for(int i = 0 ; i < r ; i++)
		{
			Shift_left();
			ShowDeck();
		}
	}
}

//덱을 순차적으로 돌면서 값을 출력
void Deck::ShowDeck()
{
	int i = (front + 1)%capacity;
	while(true)
	{
		if(front==0&&rear==0)
			return;
		// <<연산자 오버로딩 사용
		std::cout<<array[i];
		//rear에 도달했다면 출력을 멈춤
		if(i == rear%capacity)
			break;
		if(++i >= capacity)
			i = i%capacity;
	}
	std::cout<<std::endl;
}

void Deck::CreateRandArr()
{
	//1부터 52까지 배열을 만들고
	//랜덤으로 50번 섞는다
	srand((unsigned)time(NULL));
	int mixCount = 50;
	for(int i = 0; i < 52 ; i++)
	{
		randNumArr[i] = i;
	}
	for(int i = 0 ; i < mixCount ;)
	{
		int c1 = (rand())%52;
		int c2 = (rand())%52;
		//52장 중 같은 카드를 고르면 섞을 수 없으므로 그 경우는 무시
		if(c1 != c2)
		{
			::Swap(randNumArr[c1],randNumArr[c2]);
			i++;
		}
	}

}

void Deck::MakeRandCard(int n)
{
	//카드 생성, shift, push를 n번 반복
	for(int i = 0; i < n ; i++)
	{
		Card C;
		switch(randNumArr[i]/13)
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
		//생성한 카드에 데이터를 집어넣는다
		C.cardNum = randNumArr[i]%13 + 1;
		C.cardRank = randNumArr[i] + 1;
		
		PushAndShift(C);
		std::cout<<"-------------------------------"<<std::endl;
	}
}
