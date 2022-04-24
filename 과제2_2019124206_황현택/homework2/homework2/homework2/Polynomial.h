#pragma once
#include "Term.h"

class Polynomial
{
private:
	//몇번째인지 세기 위한 static변수와 고유값을 나타내는 const변수
	static char id;

	//계수(coef)가 0이 아닌 term의 Array
	Term* termArr;

	//termArr의 크기
	int capacity;

	//term의 개수
	int terms;
	
public:
	//객체 별 고유 ID값
	char ID;

	//생성자
	Polynomial();
	
	//다항식 입력 받기
	void InputPoly();

	//새로운 항 추가 함수
	void NewTerms(float, int);
	
	//다항식 출력 함수
	void ShowTermArr();

	//index 항 제거
	void CleanIndex(int index); 

	//다항식 정렬
	void SortTermArr();

	//계수 정리 함수(계수가 0이면 그 항 삭제)
	void CleanTermArr();

	//다항식 덧셈 오버로딩
	Polynomial operator+(Polynomial);

	//다항식 곱셈 오버로딩
	Polynomial operator*(Polynomial);

	//대입값 계산해서 반환하는 Eval함수
	float Eval(float);
};

bool compare(Term a, Term b);
float Pow(float, int);