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
	std::cout << "입력 한 식 " << a.ID << " : ";
	a.ShowTermArr();

	std::cout << std::endl;

	// b 다항식 입력 이후
	b.SortTermArr();
	b.CleanPoly();
	std::cout << "입력 한 식 " << b.ID << " : ";
	b.ShowTermArr();
	std::cout << std::endl;

	//a+b
	// Polynomial c = a + b;
	// c.SortTermArr();
	// c.CleanPoly();
	// c.ShowTermArr();

	// std::cout << std::endl;

	//a*b
	Polynomial d = a * b;
	d.SortTermArr();
	d.CleanPoly();
	std::cout << "A X B = ";
	d.ShowTermArr();

	std::cout << std::endl;

	//다항식에 대입 값 출력
	float x;
	std::cout << "대입 할 값 x 입력 : ";
	std::cin >> x;
	std::cout << "결과 : " << a.ID << "(" << x << ")"
			  << " = " << a.Eval(x) << ", "
			  << b.ID << "(" << x << ")"
			  << " = " << b.Eval(x) << ", "<< d.ID << "(" << x << ")"
			  << " = " << d.Eval(x) << ", ";
}
