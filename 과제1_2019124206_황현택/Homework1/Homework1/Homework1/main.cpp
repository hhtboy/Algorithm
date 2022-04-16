#include <iostream>
#include "Rectangle.h"

int main()
{
	// Rectangle r1(1, 1, 3, 4);
	// std::cout << r1;
	
	// Rectangle* r2 = new Rectangle(2, 3, 5, 5);
	// std::cout << *r2;

	// r1 = r1 + *r2;
	
	// std::cout << r1<<std::endl;
	
	//r1 생성
	Rectangle* r1 = new Rectangle();
	std::cin >> *r1;
	std::cout << std::endl;
	std::cout << *r1;
	r1->CulRectArea();

	std::cout << std::endl;

	//r2 생성
	Rectangle* r2 = new Rectangle();
	std::cin >> *r2;
	std::cout << std::endl;
	std::cout << *r2;
	r2->CulRectArea();
	std::cout << std::endl;
	Rectangle r3 = r1->OverlapRect(*r1, *r2);

	// delete r2;
}
