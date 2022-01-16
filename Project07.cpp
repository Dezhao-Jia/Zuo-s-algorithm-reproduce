#include <iostream>

using namespace std;

int main()
{
    double num = 3.14;
    double* ptrNum;
    ptrNum = &num;

    void* vptr = &num;  //void pointer can point to any type parameter

    //The array's name is the first address
    double score[] {2.1, 32.1, 56.8, 27.3, 11.1};
    double* ptrScore = score;

    cout << "The size of score is :" << sizeof(score) << '\t'
         << "The size of ptrScore is :" << sizeof(ptrScore) << endl;

    cout << "The value of num is :" << num << endl;
    cout << "The address of num is :" << &num << endl;
    cout << "The value of ptrNum is :" << ptrNum << endl;
    cout << "The address's value of ptrNum point to is :" << *ptrNum << endl;
    cout << "The address of ptrNum is :" << &ptrNum << endl;

    return 0;
}