#pragma once
#include "Term.h"

class Polynomial
{
private:
	//계수(coef)가 0이 아닌 term의 Array
	Term* termArr;
	//termArr의 크기
	int capacity;
	//term의 개수
	int terms;
	
public:
	//생성자
	Polynomial();
	void GetTerms();
};