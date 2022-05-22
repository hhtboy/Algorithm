#pragma once
#include <iostream>
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
	enum cardShape shape;
	//1~13 
	int cardNum;
	//카드의 우선 순위
	int cardRank;
public:
	Card(){};
	Card(cardShape _shape, int _num);
	~Card();
	void GetCardData();
	void GetCardRank();
	//랜덤으로 카드를 만듬
	friend void MakeRandCard(int num);
	friend std::ostream& operator << (std::ostream& os, Card& C);
	friend bool operator > (Card& C1, Card& C2);
	friend bool operator != (Card& C,int);
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

void Card::GetCardData()
{
	switch(shape)
	{
	case Spaid:
		std::cout<<"카드의 모양 : Spaid "<<"카드의 번호 : "<<cardNum<<std::endl;
		break;
	case Diamond:
		std::cout<<"카드의 모양 : Spaid "<<"카드의 번호 : "<<cardNum<<std::endl;
		break;
	case Heart:
		std::cout<<"카드의 모양 : Spaid "<<"카드의 번호 : "<<cardNum<<std::endl;
		break;
	case Clover:
		std::cout<<"카드의 모양 : Spaid "<<"카드의 번호 : "<<cardNum<<std::endl;
		break;

	default:
		std::cout<<"잘못된 카드입니다"<<std::endl;

	}
}



std::ostream& operator << (std::ostream& os, Card& C)
{
	const char* array[5] = {"X", "♠", "◆", "♥", "♣"};
	os 
	<<"|"<<array[C.shape]<<" "<<C.cardNum<< "|  ";
	return os;
}

bool operator > (Card& C1, Card& C2)
{
	if(C1.shape == none)
		return false;
	if(C2.shape == none)
		return false;
	if(C1.cardRank >= C2.cardRank)
	{
		return true;
	}
	else
		return false;
}

bool operator != (Card& C, int n)
{
	return C.cardRank != n;
}

void Card::GetCardRank()
{
	std::cout<<"card rank = "<<cardRank<<std::endl;
}
