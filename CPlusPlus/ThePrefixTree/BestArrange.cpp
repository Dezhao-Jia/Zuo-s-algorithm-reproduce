//版权声明：本文为CSDN博主「李滚滚」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明
//原文链接：https://blog.csdn.net/weixin_35479108/article/details/90209991
// 安排会议时间得到最多的宣讲场次
/*
    一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目的宣讲
    给你每一个项目开始的时间和结束的时间(给你一个数组，里面 是一个个具体的项目)
    你来安排宣讲的日程，要求会议室进行的宣讲的场次最多。返回这个最多的宣讲场次
*/

// 解决步骤
/*
将n个会议的开始时间，结束时间，会议编号放在一个结构体数组中。按结束时间从大到小排序
函数给定开始时间，在开始时间之后的宣讲会才可以进行
选择第一个会议之后，按照贪心策略选择接下来的会议。
如果会议i ii的开始时间大于等于前一个会议的结束时间，那么此会议是可以安排的，
每次选择会议后，更新记录前一个宣讲会end的时间，代码用start表示；
不满足条件的会议舍弃，继续检查下一个会议
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Program
{
public:
    int id;
    int strat;
    int end;

    Program(int id, int start, int end)
    {
        this->id = id;
        this->strat = start;
        this->end = end;
    }
};

bool compare(const Program ne1, const Program ne2)
{
    return ne1.end < ne2.end;
}

int bestArrange(vector<Program> Programs, int start)
{
    sort(Programs.begin(), Programs.end(), compare);
    int result = 0;
    for (int i = 0; i < Programs.size(); i++)
    {
        if (start <= Programs[i].strat)
        {
            result++;
            start = Programs[i].end;
            cout << "安排宣讲会 :" << Programs[i].id << " "
                 << "开始时间 :" << Programs[i].strat << " "
                 << "结束时间 :" << Programs[i].end << endl;
        }
    }
    return result;
}

int main()
{
    vector<Program> vec;
    Program p1(1, 0, 3);
    vec.push_back(p1);

    Program p2(2, 2, 4);
    vec.push_back(p2);

    Program p3(3, 3, 5);
    vec.push_back(p3);

    cout << bestArrange(vec, 0) << endl;

    return 0;
}