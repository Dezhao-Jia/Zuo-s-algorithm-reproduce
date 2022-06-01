// 求 N的阶乘       factorial : 阶乘

#include <iostream>

using namespace std;

int factorial(int n)
{
    if(n == 1)
    {
        return n;
    }
    return n*factorial(n - 1);
}

int main()
{
    return 0;
}