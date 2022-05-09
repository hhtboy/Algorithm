#pragma once
#include <iostream>
enum cardShape
{
	none = 0,
	Spaid = 4,
	Diamond = 3,
	Heart = 2,
	Clover = 1
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
		cardRank = shape * 100 + cardNum;
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
	std::string array[5];
	array[0] = "None";
	array[1] = "Clover";
	array[2] = "Heart";
	array[3] = "Diamond";
	array[4] = "Spaid";
	os << "shape는 : "<<array[C.shape]<<" number는 : "<<C.cardNum<<std::endl;
	return os;
}

bool operator > (Card& C1, Card& C2)
{
	if(C1.shape == none)
		return true;
	std::cout<<C1.cardRank<<"//"<<C2.cardRank<<std::endl;
	if(C1.cardRank >= C2.cardRank)
	{
		return true;
	}
	else
		return false;
}

void Card::GetCardRank()
{
	std::cout<<"card rank = "<<cardRank<<std::endl;
}
