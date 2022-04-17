#pragma once
class Polynomial;

class Term
{
friend Polynomial;

private:
	//계수
	float coef; 
	//지수
	int exp;
};

