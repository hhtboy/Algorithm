#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial()
{
	termArr = new Term();
	capacity = 1;
	terms = 0;
}

void Polynomial::NewTerms(int coef,int exp)
{
	if(capacity == terms)
	{
		//term arr 크기를 늘리고 기존 데이터 복사
		capacity *= 2;
		Term *temp = new Term[capacity];
		std::copy(termArr, termArr + terms, temp);
		delete[] termArr;
		termArr = temp;
	}

	termArr[terms].coef = coef;
	termArr[terms].exp = exp;
	terms++;
}

void Polynomial::ShowTermArr()
{
	for (int i = 0; i < terms;i++)
	{
		std::cout << "계수 : " << termArr[i].coef << " 지수 : " << termArr[i].exp << std::endl;
	}
}
