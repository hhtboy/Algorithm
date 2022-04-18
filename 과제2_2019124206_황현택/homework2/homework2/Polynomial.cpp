#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial()
{
	termArr = new Term();
	capacity = 1;
	terms = 0;
}

void Polynomial::GetTerms()
{
	int n;
	while (true)
	{
		std::cin >> n;
		if(std::cin)
		{
			if(capacity == terms)
			{
				//term arr 크기를 늘리고 기존 데이터 복사
				capacity *= 2;
				Term *temp = new Term[capacity];
				std::copy(termArr, termArr + terms, temp);
			}
		}
		else
		{
			break;
		}
	}
}