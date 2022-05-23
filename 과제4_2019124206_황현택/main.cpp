#include <iostream>
#include "CNode.h"
#include "CircularList.h"
#include "Card.h"

//n 크기의 랜덤한 배열 생성
int* MakeRandArr(int n);

int main()
{
	/*
	CircularList<int> C;
	C.InsertFront(30);
	C.SortList();

	C.InsertFront(20);
	C.SortList();
	C.InsertFront(10);
	C.SortList();
	
	C.InsertFront(40);
	C.SortList();

	C.InsertFront(50);
	C.SortList();
	*/


	//연결리스트 생성
	CircularList<Card> C;
	
	//리스트에 넣을 랜덤 카드 생성
	//랜덤 데이터를 갖는 배열 생성
	int* arr = MakeRandArr(5);

	for(int i = 0; i<5;i++)
	{
		Card MyCard(arr[i]);
		C.InsertFront(MyCard);
		C.ShowList();
		C.SortList();
	}
}

int* MakeRandArr(int n)
{
	int* result = new int[n];
	int array[52];
	srand((unsigned)time(NULL));
	int mixCount = 50;
	for(int i = 0; i < 52 ; i++)
	{
		array[i] = i;
	}
	for(int i = 0 ; i < mixCount ;)
	{
		int c1 = (rand())%52;
		int c2 = (rand())%52;
		if(c1 != c2)
		{
			swap(array[c1],array[c2]);
			i++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		result[i] = array[i];
	}

	return result;
}


