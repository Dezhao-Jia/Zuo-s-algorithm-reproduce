//In this project, we are find number in a sorted matrix
//We return wether the number in the matrix
#include <iostream>

using namespace std;

bool isConsist(int* matrix, int iRows, int iCols, int num)
{
    int row = 0;
    int col = iCols - 1;

    while(row < iRows && col > -1)
    {
        if( *(matrix + row*iCols + col) == num)
        {
            return true;
        }
        else if( *(matrix + row*iCols + col) > num)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

int main()
{
    int matrix[3][3] = { {1,2,3}, {4,1,6}, {7,8,9} };
    int num = 5;

    isConsist((int*)matrix, 3, 3, 5);
    return 0;
}