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
	
	Rectangle* r1 = new Rectangle();
	Rectangle* r2 = new Rectangle();
	std::cin >> *r1;
	std::cin >> *r2;

	std::cout << *r1 << std::endl
			  << *r2 << std::endl;

	// delete r2;
}
