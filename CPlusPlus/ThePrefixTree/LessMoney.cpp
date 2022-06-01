#include <iostream>
#include <queue>

// https://www.cnblogs.com/jasmineTang/p/14369283.html

using namespace std;

class MaxheapComparator
{
    public:
        bool operator()(const int n1, const int n2) const
        {
            return n1 < n2;
        }
};

class MinheapComparator
{
    public:
        bool operator()(const int n1, const int n2) const
        {
            return n2 < n1;
        }
};

int lessMoney(int arr[], int len)
{
    // cout << "==================lessMoney==================" << endl;
    // 优先级队列---小根堆
    priority_queue<int, vector<int>, greater<int>> pQ;
    for(int i=0; i<len; i++)
    {
        pQ.push(arr[i]);    // 所有数字进入小根堆
    }

    int sum = 0;
    int cur = 0;
    while(pQ.size() > 1)    // 当小根堆只剩一个数字时，这就是代价
    {
        int tmp1 = pQ.top();
        pQ.pop();
        int tmp2 = pQ.top();
        pQ.pop();
        cur = tmp1 + tmp2;  // 两个最小数字合为一个节点，够建小根堆过程
        sum += cur;
        pQ.push(cur);
    }
    return sum;
}

int main()
{
    // solution
    int arr[] = {6, 7, 8, 9};
    int lenArr = sizeof(arr)/sizeof(arr[0]);
    cout << "The less Money using is :" << lessMoney(arr, lenArr) << endl;

    int arrHelp[] = {3, 5, 2, 7, 0, 1, 6, 4};
    int lenHelp = sizeof(arrHelp)/sizeof(arrHelp[0]);

    // min heap
    cout << "Min Heap" << endl;
    priority_queue<int, vector<int>, greater<int>> minQ1;
    for(int i=0; i<lenHelp; i++)
    {
        minQ1.push(arrHelp[i]);
    }

    while(!minQ1.empty())
    {
        cout << minQ1.top() << " ";
        minQ1.pop();
    }
    cout << endl;

    // min heap use comparator
    cout << "Min Heap Use Comparator" << endl;
    priority_queue<int, vector<int>, MinheapComparator> minQ2;
    for(int i=0; i<lenHelp; i++)
    {
        minQ2.push(arrHelp[i]);
    }

    while(!minQ2.empty())
    {
        cout << minQ2.top() << " ";
        minQ2.pop();
    }
    cout << endl;

    // max heap use comparator
    cout << "Max Heap Use Comparator" << endl;
    priority_queue<int, vector<int>, MaxheapComparator> maxQ;
    for(int i=0; i<lenHelp; i++)
    {
        maxQ.push(arrHelp[i]);
    }

    while(!maxQ.empty())
    {
        cout << maxQ.top() << " ";
        maxQ.pop();
    }
    cout << endl;

    return 0;
}