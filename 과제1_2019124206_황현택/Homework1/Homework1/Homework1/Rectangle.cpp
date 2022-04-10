#include "Rectangle.h"
#include <iostream>
//using namespace std;

int Rectangle::id = 0;

//������
Rectangle::Rectangle(int x, int y, int w, int h)
{
	xLow = x;
	yLow = y;
	width = w;
	height = h;

	std::cout << ++id << "��° Rectangle ��ü ����\n\n";
}

//������ �����ε� : �����͸� ���� �Է�
Rectangle::Rectangle()
{
	xLow = 0;
	yLow = 0;
	width = 0;
	height = 0;
}

//�ı���
Rectangle::~Rectangle()
{
	std::cout << "��ǥ (" << xLow << ',' << yLow << ')'
		<< " Rectangle ��ü �Ҹ�\n\n";
}

//��� ������
std::ostream& operator <<(std::ostream& os, Rectangle& r)
{
	os << "height : " << r.height << std::endl
		<< "width : " << r.width << std::endl
		<< "x : " << r.xLow << std::endl
		<< "y : " << r.yLow << std::endl << std::endl;

	return os;
}

//�Է� ������
std::istream& operator >>(std::istream& os, Rectangle& r)
{
	os >> r.height

		>> r.width

		>> r.xLow

		>> r.yLow;


	return os;
}

//���ϱ� ������
Rectangle Rectangle::operator +(Rectangle& r)
{

	int sum_x, sum_y, sum_w, sum_h;

	sum_x = xLow + r.xLow;
	sum_y = yLow + r.yLow;
	sum_w = this->width + r.width;
	sum_h = this->height + r.height;

	return Rectangle(sum_x, sum_y, sum_w, sum_h);
}

