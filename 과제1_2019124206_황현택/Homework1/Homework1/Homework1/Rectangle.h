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
	//�?�?�?, �????
	Rectangle(int, int, int, int);
	Rectangle();
	~Rectangle();

	//�?�? ??? �?�?
	void CulRectArea();

	//???�? �?�?�? ����? �??� ???
	Rectangle OverlapRect(Rectangle& r1, Rectangle& r2);

	//�?,??? �?�?�? �????�?
	friend std::ostream& operator <<(std::ostream&, Rectangle&); 
	friend std::istream& operator >>(std::istream&, Rectangle&); 

	Rectangle operator +(Rectangle&);

	//�?�??� �?�? ??? Max,Min �?�?
	int Max(int a, int b);


	int Min(int a, int b);
};
