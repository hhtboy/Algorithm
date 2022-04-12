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

	//넓이 계산 함수
	void CulRectArea();

	//겹치는 영역에 대한 정보 출력
	Rectangle OverlapRect(Rectangle& r1, Rectangle& r2);

	//입,출력 연산자 오버로딩
	friend std::ostream& operator <<(std::ostream&, Rectangle&); 
	friend std::istream& operator >>(std::istream&, Rectangle&); 

	Rectangle operator +(Rectangle&);

	//편의를 위해 만든 Max,Min 함수
	int Max(int a, int b)
	{
		return (a >= b) ? a : b;
	}

	int Min(int a, int b)
	{
		return (a <= b) ? a : b;
	}
};
