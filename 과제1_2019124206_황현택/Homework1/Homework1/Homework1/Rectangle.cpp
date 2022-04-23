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
	std::cout << ++id << "번째 Rectangle 객체 생성\n";
}

//생성자 오버로딩 : 데이터를 직접 입력
Rectangle::Rectangle()
{
	//멤버변수 데이터 초기화
	xLow = 0;
	yLow = 0;
	width = 0;
	height = 0;
	std::cout << "새로운 Rectangle 객체를 생성했습니다." << std::endl;
}

//파괴자
Rectangle::~Rectangle()
{
	std::cout <<"좌표 (" << xLow << ',' << yLow << ')'
		<< " Rectangle 객체 소멸\n\n";
}

//사각형 넓이 계산
void Rectangle::CulRectArea()
{
	std::cout << "넓이 : " << width * height << std::endl;
}

//겹치는 영역에 대한 정보 출력
Rectangle Rectangle::OverlapRect(Rectangle& r1, Rectangle& r2)
{
	int xLow = Max(r1.xLow, r2.xLow);
	int yLow = Max(r1.yLow, r2.yLow);
	int width = Min(r1.xLow + r1.width, r2.xLow + r2.width) - xLow;
	int height = Min(r1.yLow + r1.height, r2.yLow + r2.height) - yLow;
	
	//겹치는 영역 체크
	if (width <= 0 || height <= 0)
	{
		std::cout << "겹치는 영역이 없습니다." << std::endl;
		return r1;
	}

	std::cout << "영역의 height : " << height<<std::endl;
	std::cout << "영역의 width : " << width << std::endl;
	std::cout << "영역의 xLow : " << xLow <<std::endl;
	std::cout << "영역의 yLow : " << yLow <<std::endl;
	std::cout << "영역의 넓이 : " << width * height <<std::endl;

	return Rectangle(xLow, yLow, width, height);
}

//출력 연산자
std::ostream& operator <<(std::ostream& os, Rectangle& r)
{
	os << "height : " << r.height << std::endl
		<< "width : " << r.width << std::endl
		<< "x : " << r.xLow << std::endl
		<< "y : " << r.yLow << std::endl
		<< std::endl;

	return os;
}

//입력 연산자
std::istream& operator >>(std::istream& os, Rectangle& r)
{
	std::cout << "height 입력 : ";
	os >> r.height;
	std::cout << "width 입력 : ";
	os >> r.width;
	std::cout << "xLow 입력 : ";
	os >> r.xLow;
	std::cout << "yLow 입력 : ";
	os >> r.yLow;;


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

//편의를 위해 만든 Max,Min 함수
int Rectangle::Max(int a, int b)
{
	return (a >= b) ? a : b;
}

int Rectangle::Min(int a, int b)
{
	return (a <= b) ? a : b;
}