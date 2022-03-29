#include <iostream>
#include <algorithm>
#include <numeric>
#include "test.h"
void sort(int *arr, const int n);
void swap(int &a, int &b);
void Permutation(int *a, const int k, const int m);
void Permutations(int *a, const int m);
int Factorial(int n);
int BinarySearch(int *arr, const int x, const int left, const int right);
int MyBinarySearch(int *arr, const int x, const int left, const int right);

//선택 정렬 Selection sort
int main()
{

    int arr[] = {2, 3, 1, 4, 5};

    sort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i];
    }

    std::cout << std::endl;
    std::cout << MyBinarySearch(arr, 5, 0, 4);
    std::cout << std::endl;
    Permutation(arr, 0, 4);
}

// int *InputArr()
// {
//     int arrLen;
//     std::cout << "배열의 길이 : " << std::endl;
//     std::cin >> arrLen;
//     int *arr = new int[arrLen];

//     for (int i = 0; i < arrLen; i++)
//     {
//         std::cin >> arr[i];
//     }
//     return arr;
// }

void sort(int *arr, const int n)
{

    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int k = i + 1; k < n; k++)
        {
            if (arr[k] < arr[min])
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

int BinarySearch(int *arr, const int x, const int left, const int right)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        if (x < arr[middle])
        {
            return BinarySearch(arr, x, left, middle - 1);
        }
        else if (x > arr[middle])
        {
            return BinarySearch(arr, x, middle + 1, right);
        }
        return middle;
    }

    return -1;
}

int MyBinarySearch(int *arr, const int x, int left, int right)
{

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (x < arr[middle])
        {
            right = middle - 1;
        }
        else if (x > arr[middle])
        {
            left = middle + 1;
        }
        else // x == middle
        {
            return middle;
        }
    }
    return -1;
}

// permutation
void Permutation(int *a, const int k, const int m)
{
    //순열 출력 부분
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    // 새로운 순열 생성,
    else
    {
        for (int i = k; i <= m; i++)
        {
            swap(a[k], a[i]);
            Permutation(a, k + 1, m);
            swap(a[k], a[i]);
        }
    }
}
// void Permutations(int *a, const int m) // a부터 m까지 순열 출력
// {
//     do
//     {
//         std::copy(a, a + m + 1, std::ostream_iterator<char>(std::cout, " "));
//     } while (std::next_permutation(a, a + m + 1));
// }

int Factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * Factorial(num - 1);
    }
}
