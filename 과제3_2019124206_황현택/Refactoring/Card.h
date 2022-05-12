#pragma once
#include <iostream>
#include "Deck.h"

class Deck;

//카드의 모양 열거형
enum cardShape
{
	none = 0,
	Spaid = 1,
	Diamond = 2,
	Heart = 3,
	Clover = 4
};

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

class Card {
private:
	//카드 모양
	enum cardShape shape;
	//1~13 
	int cardNum;
	//카드의 우선 순위
	int cardRank;
public:
	Card(){};
	Card(cardShape _shape, int _num);
	~Card();
	//랜덤으로 카드를 만듬
	Card MakeRandCard();
	friend void Deck::MakeRandCard(int n);
	friend std::ostream& operator << (std::ostream& os, Card& C);
	friend bool operator > (Card& C1, Card& C2);
};


Card::Card(cardShape _shape, int _num)
{
	shape = _shape;
	cardNum = _num;
	if(shape == none)
	{
		cardRank = 0;
	}
	else
		cardRank = shape * 13 + cardNum;
}

Card::~Card()
{
	shape  = none;
	cardNum = 0;
}

Card Card::MakeRandCard()
{
	Card C;
	
	return C;
}

//카드 출력연산자 오버로딩
std::ostream& operator << (std::ostream& os, Card& C)
{
	//배열에서 알맞은 shape에 따른 char를 출력해줌
	const char* array[5] = {"X", "♣", "♥", "◆", "♠"};
	os 
	<<"|"<<array[C.shape]<<" "<<C.cardNum<< "|  ";
	return os;
}

//비교연산자 > 오버로딩
bool operator > (Card& C1, Card& C2)
{
	//isFront 메소드에서 배열이 비어있을 경우 무한반복하는 것을 막기 위해
	//C1, C2가 none일 경우 false를 반환해 isFront의 반복문을 멈추게 함
	if(C1.shape == none)
		return false;
	if(C2.shape == none)
		return false;
	if(C1.cardRank >= C2.cardRank)
	{
		return true;
	}

	return false;
}
