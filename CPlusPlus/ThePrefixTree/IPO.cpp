// https://blog.csdn.net/weixin_35479108/article/details/90209991

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
    public:
        int profit;
        int cost;
        Node(int profit, int cost)
        {
            this->profit = profit;
            this->cost = cost;
        }
};

class MinCostComparator
{
    public:
        bool operator()(Node o1, Node o2)
        {
            return o1.cost > o2.cost;
        }
};

class MaxProfitComparator
{
    public:
        bool operator()(Node o1, Node o2)
        {
            return o2.profit > o1.profit;
        }
};

int FindMaximizedCapital(vector<int> costs, vector<int> profits, int k, int money)
{
    // 将每个节点的信息放到节点类型当中
    vector<Node> nodes;
    for(int i=0; i<costs.size(); i++)
    {
        Node tmp(profits[i], costs[i]);
        nodes.push_back(tmp);
    }

    // 根据 costs大小将项目放进小根堆
    priority_queue<Node, vector<Node>, MinCostComparator> costQueue;
    priority_queue<Node, vector<Node>, MaxProfitComparator> profitQueue;

    for(int i=0; i<nodes.size(); i++)
    {
        costQueue.push(nodes[i]);
    }

    for(int i=0; i<k; i++)
    {
        while(!costQueue.empty() && costQueue.top().cost < money)
        {
            Node tmp = costQueue.top();
            profitQueue.push(tmp);
            costQueue.pop();
        }

        if(profitQueue.empty())
        {
            return money;
        }

        money += profitQueue.top().profit;
        profitQueue.pop();
    }
    return money;
}

int main()
{
    vector<int> costs = {10, 20, 30, 50, 60};
    vector<int> profits = {20, 60, 80, 70, 90};
    cout << FindMaximizedCapital(costs, profits, 4, 40) << endl;

    return 0;
}