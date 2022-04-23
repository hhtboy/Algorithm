#include "Polynomial.h"
#include <algorithm>
#include <iostream>

char Polynomial::id = 'A';

Polynomial::Polynomial()
{
	ID = id;
	++id;
	termArr = new Term();
	capacity = 1;
	terms = 0;
}

void Polynomial::InputPoly()
{
	float c;
	int e;

	while(true)
	{
		std::cin >> c;
		if(std::getchar() != ' ')
		{
			std::cout << "계수와 지수를 모두 입력해주세요.";
			return ;
			//break;
		}
		std::cin >> e;

		NewTerms(c, e);
		if(std::getchar() != ' ')
		{
			break;
		}
	}
}



void Polynomial::NewTerms(float coef,int exp)
{
	if(capacity == terms)
	{
		//term arr 크기를 늘리고 기존 데이터 복사
		capacity *= 2;
		Term *temp = new Term[capacity];
		std::copy(termArr, termArr + terms, temp);
		delete[] termArr;
		termArr = temp;
	}

	termArr[terms].coef = coef;
	termArr[terms].exp = exp;
	terms++;
}

void Polynomial::ShowTermArr()
{
	//항이 0밖에 없으면 0을 출력, 실제로는 (0,0) term이 저장돼 있음
	if(terms ==0)
	{
		std::cout << "입력한 식 "<<ID<<" : " << 0;
		return;
	}

	std::cout << "입력한 식 " <<ID<< " : ";
	//마지막 항 뒤는 연산자가 안 오므로 마지막 항 제외하고 반복
	for (int i = 0; i < terms - 1; i++)
	{
		//계수가 1이면 무시하고 출력
		if(termArr[i].coef == 1)
		{
			std::cout << "x^" << termArr[i].exp;
		}

		//계수 != 1이면 정상 출력
		else
		{
			std::cout << termArr[i].coef << "x^" << termArr[i].exp;
		}

		//다음 항이 0 이상일 경우 +를 붙여주고, 아니면 무시(다음에 -가 자연스럽게 붙을 수 있게)
		if(termArr[i+1].coef>0)
		{
			std::cout << "+";
		}
	}

	//빠뜨린 마지막 항 출력
	//계수가 1이면 1을 무시하고 출력
	if(termArr[terms-1].coef == 1)
	{
		//지수가 0이면 x를 무시한 1을 출력하고, 아니면 정상 출력
		if(termArr[terms-1].exp ==0)
		{
			std::cout << 1;
		}
		else
		{
			std::cout << "x^" << termArr[terms - 1].exp;
		}
	}
	//계수가 1이 아니면 정상 출력
	else
	{
		//지수가 0이면 계수만 출력하고, 아니면 둘 다 출력
		if(termArr[terms-1].exp ==0)
		{
			std::cout << termArr[terms - 1].coef;
		}
		else
		{
			std::cout << termArr[terms-1].coef << "x^" << termArr[terms-1].exp;
		}
	}
}

//특정 index 항 제거
void Polynomial::CleanTermArr(int index)
{
	Term *temp = new Term[capacity];
	std::copy(termArr, termArr + index, temp);
	std::copy(termArr + index+1, termArr + terms, temp + index);
	std::copy(temp, temp + terms, termArr);
	termArr[terms - 1].coef = 0;
	termArr[terms - 1].exp = 0;
}

//다항식 정렬
void Polynomial::SortTermArr()
{
	std::sort(termArr, termArr + terms,compare);
}

//다항식 계수를 정리하는 함수
void Polynomial::CleanPoly()
{
	for (int i = 0; i < terms;i++)
	{
		for (int j = i + 1; j < terms; j++)
		{
			//지수가 같으면 더함
			if(termArr[i].exp == termArr[j].exp)
			{
				termArr[i].coef += termArr[j].coef;
				termArr[j].coef = 0;
			}
		}
	}

	//계수가 0이 있는지 한번 돌아서 확인 후, 계수가 0인 항 제거
	for (int i = 0; i < terms;i++)
	{
		if(termArr[i].coef == 0)
		{
			CleanTermArr(i);
			i--;
			terms--;
		}
	}
}

// + 연산자 오버로딩
Polynomial Polynomial::operator+(Polynomial b)
{
	Polynomial c;
	int aPos = 0;
	int bPos = 0;
	while(aPos<terms && bPos<b.terms)
	{
		//두 항의 지수가 같으면 더함
		if(termArr[aPos].exp == b.termArr[bPos].exp)
		{
			float t = termArr[aPos].coef + b.termArr[bPos].coef;
			if(t)
			{
				c.NewTerms(t, termArr[aPos].exp);
			}
			aPos++;
			bPos++;
		}
		//a차수가 더 크면 aPos의 항을 추가
		else if(termArr[aPos].exp > b.termArr[bPos].exp)
		{
			c.NewTerms(termArr[aPos].coef, termArr[aPos].exp);
			aPos++;
		}
		//b차수가 더 크면 bPos의 항을 추가
		else
		{
			c.NewTerms(b.termArr[bPos].coef, b.termArr[bPos].exp);
			bPos++;
		}
	}
	//남은 항 추가
	for (; aPos < terms; aPos++)
	{
		c.NewTerms(termArr[aPos].coef, termArr[aPos].exp);
	}
	for (; bPos < b.terms;bPos++)
	{
		c.NewTerms(termArr[bPos].coef, termArr[bPos].exp);
	}

	return c;
}

// * 연산자 오버로딩
// Polynomial Polynomial::operator*(Polynomial b)
// {

// }