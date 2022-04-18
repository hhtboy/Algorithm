#include <iostream>
#include "Polynomial.h"

int main()
{
	std::cout << "다항식 입력 :";
	Polynomial a;

	while(true)
	{
		int coef;
		int exp;
		std::cin >> coef;
		if (std::cin) 
		{
			std::cin >> exp;
			if (std::cin)
			{
				a.NewTerms(coef, exp);
			}
			else
			{
				break;
			}
		}

		else
		{
			break;
		}
	}

	//다항식 입력 이후
	a.ShowTermArr();
}
