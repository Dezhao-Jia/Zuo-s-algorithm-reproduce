#include <iostream>
#include <map>

// map库及其常见操作
/*
    构造函数：
        map<int, string> myMap1;
        map<int, string> myMap2 (myMap2.begin(), myMap.end());
        map<int, string> myMap3 (myMap2);

    插入数据：
        myMap[1] = "one";
        myMap.insert( map<int, string> :: value_type(11, "oneone"));
        myMap.insert( pair<int, string>(111, "oneoneone"));

    查找元素：利用 find()方法，find()函数返回一个迭代器指向键值为 key的元素，若没有则返回指向 map尾部的迭代器
        map<int, string>::iterator itr;
        itr = myMap.find(1);
        if(itr != myMap.end())  // 若无法找到，返回 myMap.end()
        {
            cout << itr->first << " " << itr->second << endl;
        }
        else
            cout << "Can't find. " << endl;

    删除元素：使用 rease()方法实现
        itr = myMap.find(1)
        if(itr != myMap.end())
        {
            myMap.erase(itr)
        }
        or
        myMap.erase(myMap.begin(), myMap.end())

    swap() : 对 map中的两个 map进行交换，而非对 map内的两个元素的交换

    size() : 返回 map内元素个数

    empty() : 判断 map是否为空，是则返回 true

    begin() : 返回指向 map头部的迭代器

    end() : 返回指向 map尾部的迭代器

    count() : 返回指定元素出现的次数
*/

using namespace std;

class Node
{
    public:
        int value;
        Node* next;
        Node* rand;

        Node(int data)
        {
            this->value = data;
        }
};

Node* CopyList(Node* head)
{
    if( head != nullptr )
    {
        return NULL;
    }

    Node* cur = head;
    Node* next = nullptr;

    // 构造链表
    while( cur != nullptr )
    {
        next = cur->next;
        Node tmp(cur->value);
        cur->next = &tmp;   // &tmp 意为 tmp变量的地址
        cur->next->next = next;
        cur = next;
    }

    // 设置 rand指针
    cur = head;
    Node* curCopy = nullptr;
    while( cur != nullptr )
    {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != nullptr ? cur->rand : nullptr;
        cur = next;
    }

    // 分裂链表
    Node* res = head->next;
    cur = head;
    while( cur != nullptr )
    {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next != nullptr ? next->next : nullptr;
        cur = next;
    }

    return res;
}

void PrintRandLinkList(Node* head)
{
    Node* cur = head;
    cout << "Order :";
    while( cur != nullptr )
    {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    return 0;
}