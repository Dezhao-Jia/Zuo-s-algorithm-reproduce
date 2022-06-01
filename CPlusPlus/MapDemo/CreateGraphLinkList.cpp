// https://blog.csdn.net/nichengwuxiao/article/details/78911896
// 图的邻接链表实现

#include <iostream>

using namespace std;

// 枚举类型元素表示图的种类
// DG ：有向图      WDG ： 带权有向图
// UDG ：无向图     WUDG ： 带权无向图
enum GraphKind
{
    DG,
    WDG,
    UDG,
    WUDG
};

// VertexType : 顶点类型
// VRType ： 顶点之间的关系类型
// InfoType : 弧的信息类型
template <typename VertexType, typename VRType, typename InfoType>
class ALGraph
{
public:
    ALGraph(int verNum, GraphKind _kind):vexnum(verNum), kind(_kind)
    {
        for(int i=0; i<MAX_VERTEX_NUM; i++)
        {
            vertices[i].firstarc = nullptr;
        }
    }

    // 构造图，进行选择
    void Create()
    {
        switch (kind)
        {
        case DG:
        {
            CreateDG();
            break;
        }
        case WDG:
        {
            CreateWDG();
            break;
        }
        case UDG:
        {
            CreateUDG();
            break;
        }
        case WUDG:
        {
            CreateWUDG();
            break;
        }
        default:
        {
            return;
        }
        }
    }

    // 打印邻接表
    void displayGraph()
    {
        for(int i=0; i<vexnum; i++)
        {
            cout << "第" << i+1 << "个顶点是 :" << vertices[i].data
                 << "邻接表为 :";

            ArcNode *arcNode = vertices[i].firstarc;
            while(arcNode != nullptr)
            {
                cout << "->" << vertices[arcNode->adjvex].data
                     << "(" << arcNode->info << ")";
                arcNode = arcNode->nextarc;
            }
            cout << endl;
        }
    }

private:
    // 初始化邻接链表的表头节点
    void InitVertics()
    {
        cout << "请输入每个节点的关键字 :" << endl;
        VertexType val;
        for(int i=0; i<vexnum; i++)
        {
            cin >> val;
            vertices[i].data = val;
        }
    }

    // 插入一个表节点
    void insertArc(int vHead, int vTail, InfoType w)
    {
        // 构造一个表节点
        ArcNode *newArcNode = new ArcNode;
        newArcNode->adjvex = vTail;
        newArcNode->nextarc = nullptr;
        newArcNode->info = w;

        // acrNode是 vertices[vHead]的邻接表
        ArcNode *arcNode = vertices[vHead][vTail].firstarc;
        if(arcNode == nullptr)
        {
            vertices[vHead][vTail].firstarc = newArcNode;
        }
        else
        {
            while(arcNode->nextarc != nullptr)
            {
                arcNode = arcNode->nextarc;
            }
            arcNode->nextarc = newArcNode;
        }
        arcnum++;
    }

    // 构造有向图
    void CreateDG()
    {
        InitVertics();
        int vHead, vTail;
        cout << "请依次输入每条边的开始顶点、 结束顶点 :" << endl;
        while (cin >> vHead >> vTail)
        {
           insertArc(vHead, vTail, 0);
        }
    }

    // 构造带权有向图
    void CreateWDG()
    {
        InitVertics();
        int vHead, vTail;
        InfoType w;
        cout << "请依次输入每条边的开始顶点、 结束顶点 、 权值 :" << endl;
        while (cin >> vHead >> vTail >> w)
        {
            insertArc(vHead, vTail, w);
        }
    }

    // 构造无向图
    void CreateUDG()
    {
        InitVertics();
        int vHead, vTail;
        cout << "请依次输入每条边的开始顶点、 结束顶点 :" << endl;
        while (cin >> vHead >> vTail)
        {
            insertArc(vHead, vTail, 0);
            insertArc(vTail, vHead, 0);
        }
    }

    // 构造带权无向图
    void CreateWUDG()
    {
        InitVertics();
        int vHead, vTail;
        InfoType w;
        cout << "请依次输入每条边的开始顶点、 结束顶点 、 权值 :" << endl;
        while (cin >> vHead >> vTail >> w)
        {
            insertArc(vHead, vTail, w);
            insertArc(vTail, vHead, w);
        }
    }

    // const数据成员必须在构造函数初始化
    static const int MAX_VERTEX_NUM = 20;   // 最大顶点个数

    // 表节点
    struct ArcNode
    {
        int adjvex; // 该弧所指向的顶点的位置
        ArcNode *nextarc;  // 指向下一条弧的指针
        InfoType info;  // 该弧相关信息的指针
    };

    // 头节点
    struct VNode
    {
        VertexType data;    // 顶点信息
        ArcNode *firstarc;  // 指向第一条依附于该节点的弧的指针
    };

    VNode vertices[MAX_VERTEX_NUM]; // 表节点数组
    int vexnum; // 图的当前顶点数
    int arcnum; // 图的弧数
    GraphKind kind; // 图的种类
};

int main()
{
    return 0;
}