#include <iostream>

using namespace std;

void print(int *matrix, int iRows, int iCols)
{
    for (int i = 0; i < iRows; i++)
    {
        for (int j = 0; j < iCols; j++)
        {
            cout << *(matrix + i * iCols + j) << " ";
        }
        cout << endl;
    }
}

void printLevel(int *matrix, int iCols, int aR, int aC, int bR, int bC, bool fromUp)
{
    //cout << aR << " " << aC << " " << bR << " " << bC << " " << fromUp << endl;
    if (fromUp) //从上往下输出的情况
    {
        while (aR != bR + 1)
        {
            cout << *(matrix + aR * iCols + aC) << " ";
            aR++;
            aC--;
        }
    }
    else
    {
        while (bR != aR - 1)
        {
            cout << *(matrix + bR * iCols + bC) << " ";
            bR--;
            bC++;
        }
    }
    //cout << endl;
}

void ZigZagPrint(int *matrix, int iRows, int iCols)
{
    int aR = 0, aC = 0, bR = 0, bC = 0;
    int endR = iRows - 1, endC = iCols - 1;
    bool fromUp = false;

    while (aR != iRows)
    {
        printLevel((int *)matrix, iRows, aR, aC, bR, bC, fromUp);
        //此处顺序不可以更改，否则会造成内存越界
        aR = aC == endC ? aR + 1 : aR;
        aC = aC == endC ? aC : aC + 1;
        bC = bR == endR ? bC + 1 : bC;
        bR = bR == endR ? bR : bR + 1;
        
        fromUp = !fromUp;
    }
}

int main()
{
    int matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    cout << "The Shape of Matrix before Sprial is :" << endl;
    print((int*)matrix, 3, 3);

    cout << "The Except Output of Matrix is :" << endl;
    ZigZagPrint((int*)matrix, 3, 3);

    return 0;
}