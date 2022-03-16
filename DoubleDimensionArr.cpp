#include <iostream>

using namespace std;

//二维数组的传参

void show(const double (*)[5], int);
//Using const to protect the memory

int main()
{
    double powers[3][5] = 
    {
        {23.1, 25.9, 75.4, 56.1, 33.4},
        {14.1, 58.2, 11.2, 56.4, 16.3},
        {45.5, 78.1, 29.5, 35.4, 61.7}
    };

    show(powers,3);

    return 0;
}

void show(const double (*arrs)[5], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout << arrs[i][j] << " ";
        }
        cout << endl;
    }
}
