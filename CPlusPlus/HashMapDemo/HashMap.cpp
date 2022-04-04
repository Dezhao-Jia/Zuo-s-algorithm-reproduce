// map简介
/*
    Map是STL的一个关联容器，提供一对一的数据处理能力
    (其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值)
    可以修改实值，而不能修改key
    map内部自建一颗红黑树(一种非严格意义上的平衡二叉树)
    这颗树具有对数据自动排序的功能,在map内部所有的数据都是有序的
    特点是增加和删除节点对迭代器的影响很小
*/

// map功能
/*
    自动建立Key － value的对应。key 和 value可以是任意你需要的类型
    根据key值快速查找记录，查找的复杂度基本是Log(N)[以 10为底]
    快速插入Key -Value 记录
    快速删除记录
    根据Key 修改value记录
    遍历所有记录
*/

// map中的基本操作函数
/*
    begin()         返回指向map头部的迭代器
    clear(）        删除所有元素
    count()         返回指定元素出现的次数
    empty()         如果map为空则返回true
    end()           返回指向map末尾的迭代器
    equal_range()   返回特殊条目的迭代器对
    erase()         删除一个元素
    find()          查找一个元素
    get_allocator() 返回map的配置器
    insert()        插入元素
    key_comp()      返回比较元素key的函数
    lower_bound()   返回键值>=给定元素的第一个位置
    max_size()      返回可以容纳的最大元素个数
    rbegin()        返回一个指向map尾部的逆向迭代器
    rend()          返回一个指向map头部的逆向迭代器
    size()          返回map中元素的个数
    swap()           交换两个map
    upper_bound()    返回键值>给定元素的第一个位置
    value_comp()     返回比较元素value的函数
*/

// https://www.cnblogs.com/fnlingnzb-learner/p/5833051.html
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<int,string> mapStudent; //构造 map

    // 方式一向 map中插入数据
    mapStudent.insert(pair<int, string>(200101, "Bob"));
    mapStudent.insert(pair<int, string>(200102, "Candy"));
    mapStudent.insert(pair<int, string>(200103, "Tom"));

    // 方式二向 map中插入数据
    mapStudent.insert(map<int, string>::value_type(200201, "Ammy"));
    mapStudent.insert(map<int, string>::value_type(200202, "Jeery"));
    mapStudent.insert(map<int, string>::value_type(200203, "Lucy"));

    // 方式三向 map中插入数据
    mapStudent[200301] = "JiaKing";
    mapStudent[200302] = "GodJia";
    mapStudent[200303] = "FireKing";

    // 使用迭代器遍历 map
    cout << "使用正向迭代器遍历 map :" << endl;
    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    // 输出 map的大小
    int mapSize = mapStudent.size();
    cout << "The size of mapStudent is :" << mapSize << endl;

    // 使用反向迭代器遍历 map
    cout << "使用反向迭代器遍历 map :" << endl;
    map<int, string>::reverse_iterator iterReverse;
    for (iterReverse = mapStudent.rbegin(); iterReverse != mapStudent.rend(); iterReverse++)
    {
        cout << iterReverse->first << " " << iterReverse->second << endl;
    }

    // 使用数组方式遍历 map
    for (int i = 1; i <= mapSize; i++)
    {
        cout << mapStudent[i] << endl;
    }

    // 查找并获取map中的元素（包括判定这个关键字是否在map中出现）
    map<int, string>::iterator iterFind;
    iterFind = mapStudent.find(200102);
    if (iterFind != mapStudent.end())
    {
        cout << "Find, The value is :" << iterFind->second << endl;
    }
    else
    {
        cout << "Not find" << endl;
    }

    // 从 map中删除元素
    // 方法一 : 使用迭代器删除
    mapStudent.erase(iterFind);
    // 方法二 : 使用关键字删除，删除成功返回1，否则返回0
    int res = mapStudent.erase(200101);
    // 方法三 : 清空迭代器
    mapStudent.erase(mapStudent.begin(), mapStudent.end());

    // map中的 swap用法
    // map中的swap不是一个容器中的元素交换，而是两个容器所有元素的交换

    return 0;
}