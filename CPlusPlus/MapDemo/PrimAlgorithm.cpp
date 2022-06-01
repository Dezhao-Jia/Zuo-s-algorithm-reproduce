// https://blog.csdn.net/NichChen/article/details/84729210?spm=1001.2014.3001.5502

// 最小生成树
/*
    是在一个给定的无向图G(V,E)中求一棵树T
    使得这棵树拥有图G中的所有顶点,
    且所有边都是来自图G中的边，并且满足整棵树的边权之和最小。
*/

// Prim算法
/*
对图G(V,E)
设置集合S，存放已经被访问的顶点
然后每次从集合V-S中选择与集合S的最短距离最小的一个顶点（记为u），访问并加入集合S
令顶点u为中介点，优化所有从u能到达的顶点v与集合S之间的最短距离
这样的操作执行n次（n为顶点个数），直到集合S已包含所有顶点
*/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
 
const int INF = 1e9;
 
struct Node
{
    int v;
    int dis;
    Node(int x, int y): v(x), dis(y) {}
};
 
int PrimG(int n, int s, vector<vector<int>> G, vector<bool> &vis, vector<int> &d)
{
    /*
      n:         顶点个数
      s:         初始点
      G:         图的邻接矩阵
      vis:       标记顶点是否被访问
      d:         储存起点s到其它顶点的最短距离
      return:    最小生成树的边权之和
    */

    fill(vis.begin(), vis.end(), false);    // 标记所有点处于未被访问状态
    fill(d.begin(), d.end(), INF);  // 标记所有边距离为无限大（1000000000）

    d[s] = 0;   // 起始点到自身距离为 0
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        int MIN = INF;

        // 该点未被访问且至该点距离最小
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
 
        // 找不到小于INF的d[u],则剩下的顶点与集合S不连通
        if (u == -1)
        {
            return -1;
        }

        vis[u] = true;
        sum += d[u];

        // 该段循环可看作是将已访问节点看作是一个整体
        for (int v = 0; v < n; ++v)
        {
            // v未被访问 且 u到v可达 且 u到v距离小于起始点到 v的距离
            if (!vis[v] && G[u][v] != INF && G[u][v] < d[v])
            {
                d[v] = G[u][v];
            }
        }
    }
    return sum;
}
 
int PrimAdj(int n, int s, vector<vector<Node>> Adj, vector<bool> &vis, vector<int> &d)
{
    /*
     * n:         顶点个数
     * s:         初始点
     * Adj:       图的邻接表
     * vis:       标记顶点是否被访问
     * d:         储存起点s到其它顶点的最短距离
     * return:    最小生成树的边权之和
     */
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), INF);

    d[s] = 0;
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        int MIN = INF;

        for (int j = 0; j < n; ++j)
        {
            if (!vis[j] && d[j] < MIN)
            {
                MIN = d[j];
                u = j;
            }
        }
 
        // 找不到小于INF的d[u],则剩下的顶点与集合S不连通
        if (u == -1)
        {
            return -1;
        }
 
        vis[u] = true;
        sum += d[u];
        for (size_t j = 0; j < Adj[u].size(); ++j)
        {
            int v = Adj[u][j].v;
            if (!vis[v] && Adj[u][j].dis < d[v])
            {
                d[v] = Adj[u][j].dis;
            }
        }
    }
    return sum;
}
 
int main()
{
    int n = 6;
    /*邻接矩阵*/
    vector<vector<int>> G = { {  0,  4,INF,INF,  1,  2},
                              {  4,  0,  6,INF,INF,  3},
                              {INF,  6,  0,  6,INF,  5},
                              {INF,INF,  6,  0,  4,  5},
                              {  1,INF,INF,  4,  0,  3},
                              {  2,  3,  5,  5,  3,  0} };
 
    for (size_t i = 0; i < G.size(); ++i)
    {
        for (size_t j = 0; j < G[i].size(); ++j)
        {
            if (G[i][j] != INF && G[i][j] != 0)
            {
                cout << i << " " << j << " " << G[i][j] << endl;
            }
        }
    }
    cout << "--------" << endl;
 

    /*邻接表*/
    vector<vector<Node>> Adj = {{Node(4,1),Node(5,2),Node(1,4)},
                                {Node(0,4),Node(5,3),Node(2,6)},
                                {Node(1,6),Node(3,6),Node(5,5)},
                                {Node(2,6),Node(4,4),Node(5,5)},
                                {Node(0,1),Node(5,3),Node(3,4)},
                                {Node(0,2),Node(1,3),Node(2,5),Node(3,5),Node(4,3)}};
 
 
    for (size_t i = 0; i < Adj.size(); ++i)
    {
        for (size_t j = 0; j < Adj[i].size(); ++j)
        {
            cout << i << " " << Adj[i][j].v << " " << Adj[i][j].dis << endl;
        }
    }
    cout << "--------" << endl;
 
    vector<bool> vis(n);
    vector<int> d(n);
 
    int resG = PrimG(n, 0, G, vis, d);    // 邻接矩阵版
    int resAdj = PrimAdj(n, 0, Adj, vis, d);    // 邻接表版
 
    cout << resG << endl << resAdj << endl;
 
    return 0;
}