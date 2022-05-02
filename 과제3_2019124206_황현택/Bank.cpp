#include <iostream>
#include "Bank.h"

Bank::Bank()
{
	id = 0;
	array = new int[5];
	std::cout<<"새로운 계좌 생성"<<std::endl;

}

Bank::~Bank()
{
	std::cout<<"계좌 소멸";
}

void Bank::ShowData()
{
	std::cout<<"ID 는 "<< id<<std::endl;
}



