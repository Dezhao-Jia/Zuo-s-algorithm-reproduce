#include <iostream>

using namespace std;

void infect(int *matrix, int i, int j, int iRows, int iCols)
{
    if (i < 0 || i >= iRows || j < 0 || j >= iCols || matrix[i*iCols + j] != 1)
    {
        return;
    }
    matrix[i*iCols + j] = 2;
    infect(matrix, i + 1, j, iRows, iCols);
    infect(matrix, i - 1, j, iRows, iCols);
    infect(matrix, i, j + 1, iRows, iCols);
    infect(matrix, i, j - 1, iRows, iCols);
}

int CountIslands(int *matrix, int iRows, int iCols)
{
    if (matrix == nullptr)
    {
        return 0;
    }

    int res = 0;
    for (int i = 0; i < iRows; i++)
    {
        for (int j = 0; j < iCols; j++)
        {
            if (matrix[i*iCols + j] == 1)
            {
                res++;
                infect(matrix, i, j, iRows, iCols);
            }
        }
    }
    return res;
}

void print(int* matrix, int iRows, int iCols)
{
    for(int i=0; i<iRows; i++)
    {
        for(int j=0; j<iCols; j++)
        {
            cout << matrix[i*iCols + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[7][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0} };

    print((int *)matrix, 7, 9);

    int num = CountIslands((int *)matrix, 7, 9);
    cout << "The number of islands is :" << num << endl;

    return 0;
}