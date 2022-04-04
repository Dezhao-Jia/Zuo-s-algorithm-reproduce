//螺旋形式输出矩阵内容
#include <iostream>

using namespace std;

void printEdge(int* matrix, int iRows, int iCols,int tR, int tC, int dR, int dC)
{
    if(tR == dR)
    {
        for(int i=tC; i<=dC; i++)
        {
            cout << *(matrix + tR*iRows + i) << " ";
        }
    }

    else if(tC == dC)
    {
        for(int i=tR; i<=dR; i++)
        {
            cout << *(matrix + i*iRows + tR) << " ";
        }
    }

    else
    {
        int curR = tR;
        int curC = tC;
        while(curC != dC)
        {
            cout << *(matrix + tR*iRows + curC) << " ";
            curC++;
        }
        while(curR != dR)
        {
            cout << *(matrix + curR*iRows + curC) << " ";
            curR++;
        }
        while(curC != tC)
        {
            cout << *(matrix + dR*iRows + curC) << " ";
            curC--;
        }
        while(curR != tR)
        {
            cout << *(matrix + curR*iRows + tC) << " ";
            curR--;
        }
    }
}

//void spiralOrderPrint(int* 矩阵地址, int 行数, int 列数)
void spiralOrderPrint(int* matrix, int iRows, int iCols)
{
    int tR = 0; //左上角 x坐标
    int tC = 0; //左上角 y坐标
    int dR = iRows - 1; //右下角 x坐标
    int dC = iCols - 1; //右下角 y坐标

    while(tR <= dR && tC <= dC)
    {
        printEdge(matrix, iRows, iCols, tR++, tC++, dR--, dC--);
    }    
}

void print(int* matrix, int iRows, int iCols)
{
    for(int i=0; i<iRows; i++)
    {
        for(int j=0; j<iCols; j++)
        {
            cout << *(matrix + i*iCols + j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3] = { {1,2,3}, {5,7,8}, {9,2,4} };

    cout << "The Shape of Matrix before Sprial is :" << endl;
    print((int*)matrix, 3, 3);

    cout << "The Except Output of Matrix is :" << endl;
    spiralOrderPrint((int*)matrix, 3, 3);

    return 0;
}