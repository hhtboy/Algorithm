#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
#include <algorithm>
#include <numeric>

void sort(int *arr, const int n);
void swap(int &a, int &b);
void Permutation(int *a, const int k, const int m);
void Permutations(int *a, const int m);
int Factorial(int n);
int BinarySearch(int *arr, const int x, const int left, const int right);
int MyBinarySearch(int *arr, const int x, const int left, const int right);

class Test
{
public:
    class childTest
    {
        public:
            void Init();
    };
    // Test(); //생성자의 이름은 클래스 이름

    // 연산자 overloading
    bool operator==(const Test &test); 
    friend std::ostream& operator <<(std::ostream &, Test &test);
    void Init();
    int GetHeight();
    int GetWidth();

private:
    int width;
    int height;
};
#endif