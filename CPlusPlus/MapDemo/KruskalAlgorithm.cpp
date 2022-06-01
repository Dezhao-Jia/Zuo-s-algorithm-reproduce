// https://blog.csdn.net/nichchen/article/details/84678365
// https://blog.csdn.net/YF_Li123/article/details/75195549
// https://blog.csdn.net/nichchen/article/details/84678365 (并查集知识连接)
// Kruskal算法：解决最小生成树的问题，采用了边贪心的策略（用于无向图），如果是稀疏图（边少），选择kruskal算法

// 算法思想 —— 在初始状态时隐去图中的所有边，这样图中每个顶点都自成一个连通块
/*
    （1）对所有的边按边权从小到大进行排序；
    （2）按边权从小到大测试所有边，如果当前测试边所连接的两个顶点不在同一个连通块中，则把这条测试边加入当前最小生成树中；否则，将边舍弃；
    （3）执行步骤（2），知道最小生成树中的边数等于总顶点数减1或者测试完所有的边时结束。当结束时，如果最小生成树的边数小于总顶点数减1，则说明该图不连通。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
// 定义边
struct edge
{
    int u, v;  // 边的两个端点编号
    float cost;  // 边的权值
    edge(int x, int y, float c): u(x), v(y), cost(c) {}
};
 
// 边的比较函数
bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}
 
// 并查集查询函数，返回x所在集合的根结点，即查看边所连接的两个点是否在一个连通块中
int findFather(vector<int> father, int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
 
    // 更新father参数
    int z;
    while (a != father[a])
    {
        z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
 
// Kruskal算法求无向图的最小生成树
void Kruskal(int n, int m, vector<edge> &E, vector<edge> &res, float &totalCost)
{
    // n:顶点个数
    // m:边的个数
    // E:边的合集
    vector<int> father(n);  // 并查集数组
    int faU;    // 端点 u所在集合的根节点
    int faV;    // 端点 v所在集合的根节点

    // 初始化并查集
    for (int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    sort(E.begin(), E.end(), cmp);  // 所有边按照权值从小到大排序
    for (int i = 0; i < m; ++i)
    {
        faU = findFather(father, E[i].u);
        faV = findFather(father, E[i].v);

        // 若不在一个集合中
        if (faU != faV)
        {
            res.push_back(E[i]);
            father[faU] = faV;
            totalCost += E[i].cost;
        }
    }
 
}
 
int main()
{
    // 各边及其权重
    vector<edge> E = {edge(0, 7, 0.16),
                      edge(2, 3, 0.17),
                      edge(1, 7, 0.19),
                      edge(0, 2, 0.26),
                      edge(5, 7, 0.28),
                      edge(1, 3, 0.29),
                      edge(1, 5, 0.32),
                      edge(2, 7, 0.34),
                      edge(4, 5, 0.35),
                      edge(1, 2, 0.36),
                      edge(4, 7, 0.37),
                      edge(0, 4, 0.38),
                      edge(6, 2, 0.40),
                      edge(3, 6, 0.52),
                      edge(6, 0, 0.58),
                      edge(6, 4, 0.93)};

    // random_shuffle()用来对一个元素序列进行重新排序（随机的）
    random_shuffle(E.begin(), E.end());

    cout << "Original Undirected Graphs: " << endl;
    for (size_t i = 0; i < E.size(); ++i)
    {
        cout << "edge: " << E[i].u << " " << E[i].v << " " << E[i].cost << endl;
    }

    cout << "----------------" << endl;
    int n = 8;
    int m = 16;
    vector<edge> res;
    float totalCost = 0;
    Kruskal(n, m, E, res, totalCost);

    cout << "Minimum Spanning Trees: " << endl;
    for (size_t i = 0; i < res.size(); ++i)
    {
        cout << "edge: " << res[i].u << " " << res[i].v << " " << res[i].cost << endl;
    }

    cout << endl;
    cout << "num of edge: " << res.size() << endl;
    cout << "total cost: " << totalCost << endl;
 
    return 0;
}