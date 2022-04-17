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
	for (int i = 0; i < capacity; i++)
	{
		// 배열이 가득 차면 크기를 두배로 늘리고, 새로운 배열을 만듬
		if (capacity == terms)
		{
			capacity *= 2;
			//여기에 새로운 배열 생성, 기존 데이터 복사
			//
		}


	}
		


}