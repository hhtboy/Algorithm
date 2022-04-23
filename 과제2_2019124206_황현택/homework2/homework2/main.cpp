#include <iostream>
#include "Polynomial.h"

int main()
{
	//a 다항식 입력받기
	std::cout << "다항 식 A입력 :";
	Polynomial a;
	a.InputPoly();

	//b다항식 입력받기
	std::cout << "다항 식 B입력 :";
	Polynomial b;
	b.InputPoly();

	//a 다항식 입력 이후
	a.SortTermArr();
	a.CleanPoly();
	a.ShowTermArr();

	std::cout << std::endl;

	// b 다항식 입력 이후
	b.SortTermArr();
	b.CleanPoly();
	b.ShowTermArr();

	std::cout << std::endl;

	//a+b
	Polynomial c = a + b;
	// c.SortTermArr();
	// c.CleanPoly();
	c.ShowTermArr();
}

//sort 함수에서 사용되는 비교 기준
bool compare(Term a,Term b)
{
	return a.GetExp() > b.GetExp();
}