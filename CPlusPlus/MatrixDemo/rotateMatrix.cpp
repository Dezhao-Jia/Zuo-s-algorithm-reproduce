#include <iostream>

using namespace std;

void rotateEdge(int* matrix, int iRows, int tR, int tC, int dR, int dC)
{
    int times = dC - tC;
    int tmp = 0;

    for(int i=0; i!=times; i++)
    {
        tmp = *(matrix + tR*iRows + i); // (tR, tC + i)
        *(matrix + tR*iRows + i) = *(matrix + (dR - i)*iRows + tC); // (tR, tC + i) swap (dR - i, tC)
        *(matrix + (dR - i)*iRows + tC) = *(matrix + dR*iRows + (dC - i));  // (dR - i, tC) swap (dR, dC - i)
        *(matrix + dR*iRows + (dC - i)) = *(matrix + (tR + i)*iRows + dC);  // (dR, dC - i) swap (tR + i, dC)
        *(matrix + (tR + i)*iRows + dC) = tmp;  // (tR + i, dC) swap (tR, tC + i)
    }
}

void rotate(int* matrix, int iRows, int iCols)
{
    int tR = 0;
    int tC = 0;
    int dR = iRows - 1;
    int dC = iCols - 1;
    
    while(tR < dR)
    {
        rotateEdge((int*)matrix, iRows, tR++, tC++, dR--, dC--);
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
    rotate((int *)matrix, 3, 3);
    print((int*)matrix, 3, 3);

    return 0;
}