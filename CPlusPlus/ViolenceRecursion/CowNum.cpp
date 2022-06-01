/*
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛
请编程实现在第n年的时候，共有多少头母牛？
输入描述:
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述
输出描述:
对于每个测试实例，输出在第n年的时候母牛的数量
————————————————
版权声明：本文为CSDN博主「李滚滚」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_35479108/article/details/90210029
*/

#include <iostream>

using namespace std;

int CowNumber(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else if(n == 3)
    {
        return 3;
    }
    else
    {
        return CowNumber(n-1) + CowNumber(n-3);
    }
}

int main()
{
    return 0;
}