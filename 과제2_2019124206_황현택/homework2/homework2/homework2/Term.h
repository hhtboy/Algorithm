#pragma once
class Polynomial;

class Term
{
friend class Polynomial;
public:
	//exp 리턴
	int GetExp();

private:
	//계수
	float coef; 
	//지수
	int exp;
};

