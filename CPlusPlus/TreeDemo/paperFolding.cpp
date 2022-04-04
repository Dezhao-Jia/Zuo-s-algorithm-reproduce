#include <iostream>

using namespace std;

void PrintProcess(int i, int num, bool down)
{
    if(i > num)
    {
        return;
    }
    PrintProcess(i+1, num, true);
    cout << down ? "down" : "up";
    PrintProcess(i+1, num, false);
}

void PrintAllFolds(int num)
{
    PrintProcess(1, num, true);
}

int main()
{
    int num = 4;
    PrintAllFolds(4);

    return 0;
}