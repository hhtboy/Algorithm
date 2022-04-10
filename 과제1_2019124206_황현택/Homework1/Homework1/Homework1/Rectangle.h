#pragma once

#include <iostream>

class Rectangle
{
private:
	static int id;
	int width;
	int height;
	int xLow, yLow;

public:
	//생성자, 파괴자
	Rectangle(int, int, int, int);
	Rectangle();
	~Rectangle();

	//입,출력 연산자 오버로딩
	friend std::ostream& operator <<(std::ostream&, Rectangle&); 
	friend std::istream& operator >>(std::istream&, Rectangle&); 

	Rectangle operator +(Rectangle&);
};