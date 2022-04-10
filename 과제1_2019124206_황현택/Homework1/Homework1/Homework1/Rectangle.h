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
	//������, �ı���
	Rectangle(int, int, int, int);
	Rectangle();
	~Rectangle();

	//��,��� ������ �����ε�
	friend std::ostream& operator <<(std::ostream&, Rectangle&); 
	friend std::istream& operator >>(std::istream&, Rectangle&); 

	Rectangle operator +(Rectangle&);
};