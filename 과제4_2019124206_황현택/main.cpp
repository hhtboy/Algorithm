#include <iostream>
#include "CNode.h"
#include "CircularList.h"
#include "Card.h"

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


	CircularList<Card> C;
	
	Card C1(Heart,10);
	Card C2(Spaid,10);
	Card C3(Diamond,10);
	Card C4(Clover,10);
	Card C5(Clover,1);

	C.InsertFront(C1);
	C.SortList();

	C.InsertFront(C2);
	C.SortList();

	C.InsertFront(C3);
	C.SortList();

	C.InsertFront(C4);
	C.SortList();

	C.InsertFront(C5);
	C.SortList();
}
