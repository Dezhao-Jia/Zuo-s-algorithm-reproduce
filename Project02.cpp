#include <iostream>

using namespace std;

int main()
{
    int num=1, sum=0;

    while(num <= 100)
    {
        sum += num;
        num++;
    }

    cout << "The Sum of 0 - 100 is :" << sum << endl;
    
    return 0;
}