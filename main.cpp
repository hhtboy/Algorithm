#include <iostream>
#include <algorithm>
#include <numeric>
#include "test.h"
void sort(int* arr, const int n);
void swap(int &a, int &b);
void Permutations(int *a, const int m);
int Factorial(int n);
int BinarySearch(int *arr, const int x, const int left, const int right);

//선택 정렬 Selection sort
int main()
{

    int arr[] = {2, 3, 1, 4, 5};

    sort(arr, 5);
    Permutations(arr, 5);

    for (int i = 0; i < 5;i++)
    {
        std::cout << arr[i];
    }

    std::cout<<std::endl;

}

int* InputArr()
{
    int arrLen;
    std::cout << "배열의 길이 : " << std::endl;
    std::cin >> arrLen;
    int *arr = new int[arrLen];
    
    
    for (int i = 0; i < arrLen; i++)
    {
        std::cin >> arr[i];
    }
    return arr;
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

// int BinarySearch(int* arr, const int x, const int left, const int right)
// {
//     if(left<=right)
//     {
//         int middle = (left + right) / 2;
//         if(x<arr[middle])
//         {
//             return BinarySearch(arr, x, left, middle - 1);
//         }
//         else if(x>arr[middle])
//         {
//             return BinarySearch(arr, x, middle + 1, right);
//         }
//         return middle;
//     }

//     return -1;
// }

//permutation
void  Permutation(char *a, const int k, const int n)
{

}
void Permutations(int *a, const int m) // a부터 m까지 순열 출력
{
    do
    {
        std::copy(a, a + m + 1, std::ostream_iterator<char>(std::cout, " "));
    } while (std::next_permutation(a,a+m+1));
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
