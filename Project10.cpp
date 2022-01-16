//Inline function
//编译器使用函数代码替换函数调用
#include <iostream>

using namespace std;

#define N 5
#define S(num) num*num

inline int pow(int, int);

int main()
{
    int result1 = pow(2,8);
    cout << "The value of result1 is :" << result1 << endl;
    
    int result2 = S(3);
    cout << "The value of result2 is :" << result2 << endl;

    return 0;
}

int pow(int num1, int num2)
{
    int result = 1;
    for(int i=0; i<num2; i++)
    {
        result *=num1;
    }
    return result;
}