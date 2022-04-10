#include "Rectangle.h"
#include <iostream>
//using namespace std;

int Rectangle::id = 0;

//생성자
Rectangle::Rectangle(int x, int y, int w, int h)
{
	xLow = x;
	yLow = y;
	width = w;
	height = h;

	std::cout << ++id << "번째 Rectangle 객체 생성\n\n";
}

//생성자 오버로딩 : 데이터를 직접 입력
Rectangle::Rectangle()
{
	xLow = 0;
	yLow = 0;
	width = 0;
	height = 0;
}

//파괴자
Rectangle::~Rectangle()
{
	std::cout << "좌표 (" << xLow << ',' << yLow << ')'
		<< " Rectangle 객체 소멸\n\n";
}

//출력 연산자
std::ostream& operator <<(std::ostream& os, Rectangle& r)
{
	os << "height : " << r.height << std::endl
		<< "width : " << r.width << std::endl
		<< "x : " << r.xLow << std::endl
		<< "y : " << r.yLow << std::endl << std::endl;

	return os;
}

//입력 연산자
std::istream& operator >>(std::istream& os, Rectangle& r)
{
	os >> r.height

		>> r.width

		>> r.xLow

		>> r.yLow;


	return os;
}

//더하기 연산자
Rectangle Rectangle::operator +(Rectangle& r)
{

	int sum_x, sum_y, sum_w, sum_h;

	sum_x = xLow + r.xLow;
	sum_y = yLow + r.yLow;
	sum_w = this->width + r.width;
	sum_h = this->height + r.height;

	return Rectangle(sum_x, sum_y, sum_w, sum_h);
}

