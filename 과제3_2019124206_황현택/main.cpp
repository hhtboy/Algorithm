/*
큐의 full 문제
	하나 지우고 하나 넣고를 반복 --> n-1의 작업 필요
	이 문제를 해결하기 위해 만든 것이 원형큐(일반적)
	나머지를 구하는 %(모듈러) 연산자를 이용
	front = 시작 , rear = 끝, k = rear앞에 비어있는 지 확인
	포화상태인지 아닌지 구분하기 위해 한 칸을 비워둠
	front == k로 채우면 안 되는 칸인 것을 확인(true면 full, false면 더 채울 수 있음)

큐 삭제
	front==rear일 조건에 지울 것이 없는 공백이므로 지우지 않는다

Front와 Rear함수
	front, rear 에 있는 값을 리턴

Push
	isfull이면 큐 크기 확장(rear+1)%capacity==front
	크기를 확장한 후 적절하게 정리를 해줘야함(뒷부분 먼저 새 큐에 복사하고, 나머지 앞부분을 이어서 새 큐에 복사한다. 이어서 front와 rear을 다시 정해준다)
	


	
	
*/
#include "Bag.h"
#include "Deque.h"

int main()
{
    Deque<int> A;
}
