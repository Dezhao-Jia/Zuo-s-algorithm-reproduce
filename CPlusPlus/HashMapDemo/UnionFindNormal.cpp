// 并查集的普通算法实现
// https://blog.csdn.net/linjw1008/article/details/113183535

#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
    private:
        vector<int> father; // 存储每个结点的父节点序号

    public:
        UnionFind(int n)
        {
            // 初始化，将每个节点的根节点设置为它本身，即每个节点都代表一个独立的子集
            father.resize(n);
            for(int i=0; i<n; i++)
            {
                father[i] = i;
            }
        }

        int findNormal(int x)   // 普通寻找根节点算法
        {
            if(x == father[x])  // 某个节点为其本身的父节点
            {
                return x;
            }
            return findNormal(father[x]); // 继续递归向上查找父节点
        }

        int findZip(int x)  // 路径压缩寻找根节点算法
        {
            if(x == father[x])  // 某个节点为其本身的父节点
            {
                return x;
            }
            father[x] = findZip(father[x]);
            return father[x];
        }

        void merge(int a, int b)
        {
            int rootOfA = findNormal(a);
            int rootOfB = findNormal(b);
            father[rootOfA] = rootOfB;
        }

};

int main()
{
    return 0;
}