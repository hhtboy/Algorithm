 #include "test.h"
int count;

//선택 정렬 Selection sort
int main()
{
    Test::childTest.Init();
}

//연산 한 번당 count 증가
//시간 복잡도는 2n+3, n은 for문 반복
float sum(float *a, const int n)
{
    float s = 0; //s 선언하는 연산
    count++;
    for (int i = 0; i < n;i++)
    {
        count++;//for 문을 도는 것에 대해 증가
        s += a[i];
        count++; //s 지정문에 대해 증가
    }
    count++; //for문을 돌지 않아도 비교를 했기 때문에 증가(마지막 for 문)
    count++; //return 에 대해 증가
   
    return s;
}

//시간 복잠도는 2n+2
float rsum(float *a, const int n)
{
    count++;//if문에 대해
    if(n<=0)
    {
        count++;//return문에 대해
        return 0;
    }
    else{
        count++;//return에 대해
        return (rsum(a, n - 1) + a[n - 1]);
    }
}

// 2중 반복에 대한 시간 복잡도 2mn + 2m + 1, m과 n의 순서가 바뀌면 결과는 같지만 시간복잡도가 달라진다. m이 작을수록 시간복잡도 감소
void add(int **a, int **b, int **c, int m, int n)
{
    for (int i = 0; i < m;i++)
    {
        count++; //for문에 대한
        for (int j = 0; j < n; j++)
        {
            count++;//for문에 대한
            c[i][j] = a[i][j] + b[i][j];
            count++; //배열 덧셈
        }
        count++; //마지막 for문
    }
    count++;//마지막 for문
}
