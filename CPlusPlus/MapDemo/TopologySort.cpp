// 版权声明：本文为CSDN博主「hh66__66hh」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/hh66__66hh/article/details/83349142

// 图的拓扑排序
// 基本概念
/*
    对于一个有向无环图G = (V, E)来说，其拓扑排序就是G中所有顶点的一种线性排序，这种排序满足如下条件：
    如果图G中包含边(a, b)，即由顶点a指向顶点b的有向边，那么在G的拓扑排序中，顶点a一定处于顶点b前面；
    因此如果有向图G中包含回路，则不可能排出这样一个线性次序。
*/

// 基本思路
/*

    无箭头的一端称为弧尾
    从图中选出一个入度为0的顶点输出，然后删掉这个顶点，
    并且删去以这个顶点为尾的弧，然后重复上述步骤，直至全部顶点输出。
    对于拓扑排序，由于要删掉以某个入度为0的顶点为尾的弧，也就是要删掉相应的边，
    因此一般采用邻接表来对图进行表示，但要稍作修改：顶点表中的每个结点增加一项用来表示该顶点此时的入度值
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Maximum 1000

// 边表节点
typedef struct EdgeListNode
{
    int adjId;  // 弧头在顶点表中的下标
    int weight; // 弧的权值
    EdgeListNode* next; // 指向边表中的下一个结点
};

// 顶点表节点
typedef struct VertexListNode
{
    int in; // 入度
    int data;   //该顶点的值
    EdgeListNode* firstadj; // 指向该顶点的边表里的第一个节点
};

// 邻接链表表示的图结构
typedef struct GraphAdjList
{
    int vertexnumber;   // 顶点个数
    int edgenumber;     // 弧的条数
    VertexListNode vertextlist[Maximum];    // 顶点表
};

// 返回存储了拓扑排序的 vector
vector<int> ToplogicalSort(GraphAdjList g)
{
    int ans = 0;
    queue<int> q;   // 用于存储入度为 0的待处理顶点
    vector<int> sort_queue; // 用于存储拓扑排序结果

    // 清空队列
    while(!q.empty()) 
    {
        q.pop();
    }

    int i, j, k;
    // 找出所有入度为 0的顶点，入队列
    for(i=1; i<=g.vertexnumber; i++) 
    {
        if(g.vertextlist[i].in == 0) 
        {
            q.push(i);
        }
    }

    EdgeListNode *temp;
    while(!q.empty()) 
    {
        j = q.front();
        q.pop();
        ans++;
        
        sort_queue.push_back(j);
        temp = g.vertextlist[j].firstadj;

        // 遍历其边表，找出与其由边相连的顶点
        while(temp != NULL) 
        {
            // 顶点入度减一
            if(--g.vertextlist[temp->adjId].in == 0) 
            {
                q.push(temp->adjId);
            }
            temp = temp->next;
        }
    }

    // 当图为有环有向图时
    if(ans < g.vertexnumber) 
    {
        // 清空 vector
		sort_queue.clear();
	}
    return sort_queue;
}

int main()
{
    // 邻接链表建立
    GraphAdjList g;
    g.vertexnumber = 5;
    g.edgenumber = 5;

    // 邻接链表节点赋值
    for(int i=1; i<6; i++) 
    {
        g.vertextlist[i].data = i;
        g.vertextlist[i].firstadj = NULL;
    }

    g.vertextlist[1].in = g.vertextlist[4].in = 0;  // 1，4节点入度为 0
    g.vertextlist[5].in = g.vertextlist[3].in = 2;  // 3，5节点入度为 2
    g.vertextlist[2].in = 1;    // 1节点入度为 1

    EdgeListNode* t;
    t = (EdgeListNode*)malloc(sizeof(EdgeListNode));
    t->adjId = 3; t->next = NULL; g.vertextlist[1].firstadj = t;

    t = (EdgeListNode*)malloc(sizeof(EdgeListNode));
    t->adjId = 2; t->next = g.vertextlist[1].firstadj; g.vertextlist[1].firstadj = t;

    t = (EdgeListNode*)malloc(sizeof(EdgeListNode));
    t->adjId = 5; t->next = NULL; g.vertextlist[2].firstadj = t;

    t = (EdgeListNode*)malloc(sizeof(EdgeListNode));
    t->adjId = 5; t->next = NULL; g.vertextlist[3].firstadj = t;

    t = (EdgeListNode*)malloc(sizeof(EdgeListNode));
    t->adjId = 3; t->next = NULL; g.vertextlist[4].firstadj = t;

    vector<int> v;
    v = ToplogicalSort(g);
    
    if(v.size() == 0) 
    {
        cout<<"This graph has ring"<<endl;
    }
    else 
    {
        for(int i=0; i<v.size(); i++) 
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}