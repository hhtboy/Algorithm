#include <iostream>
#include "test.h"
void sort(int* arr, const int n);
void swap(int &a, int &b);
int Factorial(int n);

//선택 정렬 Selection sort
int main()
{
    int arr[5] = {5, 3, 4, 1, 2};
    sort(arr, 5);
    for (int i = 0; i < 5;i++)
    {
        std::cout << arr[i];
    }

    std::cout << Factorial(5);
}

void sort(int* arr, const int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int k = i + 1; k < n; k++)
        {
            if(arr[k]<arr[min])
            {
                min = k;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Factorial(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        return num * Factorial(num - 1);
    }
}
