#include "test.h"

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