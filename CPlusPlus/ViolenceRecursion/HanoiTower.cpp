// 汉诺塔问题

#include <iostream>

using namespace std;

// 汉诺塔问题
// 首先有两个杆 from和 to, 即将圆盘从哪里移动至哪里
// 其次有一个 help杆，作为辅助
void hanoiTower(int n, string from, string to, string help)
{
    if(n == 1)
    {
        cout << "Move 1 from " << from << "to " << to << endl;
        return;
    }
    hanoiTower(n-1, from, help, to);
    cout << "Move " << n << "from " << from << "to " << to << endl;
    hanoiTower(n-1,help, to, from);
}

int main()
{
    return 0;
}