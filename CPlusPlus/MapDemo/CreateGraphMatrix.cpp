// https://blog.csdn.net/nichengwuxiao/article/details/78911896
// 图的矩阵实现
// 输入 ^Z代表输入完成

#include <iostream>
#include <vector>

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
class MGraph
{
public:
    // vexnum 的值在无参数传入情况下默认赋值给 vexNum
    MGraph(int vexNum, GraphKind _kind) : vexnum(vexNum), arcnum(0), kind(_kind)
    {
        // 分配顶点向量数组
        vvec = new VertexType[vexnum];

        // 动态分配二维数组作为邻接矩阵
        arcs = new ArcCell* [vexnum];
        for (int i = 0; i < vexnum; i++)
        {
            // 为每一行动态分配空间
            arcs[i] = new ArcCell[vexnum];
        }
    }

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

    // 初始化顶点数组和邻接矩阵
    void Init()
    {
        cout << "请输入每个顶点的关键字 :" << endl;
        VertexType val;

        // 为每个顶点的元素赋值
        for (int i = 0; i < vexnum; i++)
        {
            cin >> val;
            vvec[i] = val;
        }

        // 为单个顶点赋进权值及弧信息
        for (int i = 0; i < vexnum; i++)
        {
            ArcCell ac;
            ac.adj = 0;
            ac.info = -1;
            for(int j = 0; j < vexnum; j++)
            {
                arcs[i][j] = ac;    // 初始状态下每个节点与其他结点都无边关系状态
            }
        }
    }

    // 构造有向图
    void CreateDG()
    {
        Init();
        int vHead, vTail;
        cout << "请依次输入每条边的开始顶点、 结束顶点 :" << endl;
        while (cin >> vHead >> vTail)
        {
            arcnum++;
            arcs[vHead][vTail].adj = 1;
        }
    }

    // 构造带权有向图
    void CreateWDG()
    {
        Init();
        int vHead, vTail;
        InfoType w;
        cout << "请依次输入每条边的开始顶点、 结束顶点 、 权值 :" << endl;
        while (cin >> vHead >> vTail >> w)
        {
            arcnum++;
            arcs[vHead][vTail].adj = w;
        }
    }

    // 构造无向图
    void CreateUDG()
    {
        Init();
        int vHead, vTail;
        cout << "请依次输入每条边的开始顶点、 结束顶点 :" << endl;
        while (cin >> vHead >> vTail)
        {
            arcnum += 2;
            arcs[vHead][vTail].adj = 1;
            arcs[vTail][vHead].adj = 1;
        }
    }

    // 构造带权无向图
    void CreateWUDG()
    {
        Init();
        int vHead, vTail;
        InfoType w;
        cout << "请依次输入每条边的开始顶点、 结束顶点 、 权值 :" << endl;
        while (cin >> vHead >> vTail >> w)
        {
            arcnum += 2;
            arcs[vHead][vTail].adj = w;
            arcs[vTail][vHead].adj = w;
        }
    }

    // 展示图的相关信息
    void DisplayGraph()
    {
        cout << "总共有"
             << " " << vexnum << "个顶点，"
             << arcnum << "条边" << endl;

        for (int i = 0; i < vexnum; i++)
        {
            cout << "第" << i + 1 << "个顶点是 :" << vvec[i]
                 << "相邻的边有 :";
            for (int j = 0; j < vexnum; j++)
            {
                if (arcs[i][j].adj != 0)
                {
                    cout << vvec[j] << "(" << arcs[i][j].adj << ")";
                }
            }
            cout << endl;
        }
    }

private:
    struct ArcCell
    {
        // 顶点关系类型
        // 对于无权图，用 1或 0表示相邻与否
        // 对于带权图，为权值类型
        VRType adj;

        // 该弧相关的信息的指针
        InfoType info;
    };

    VertexType *vvec; // 顶点向量
    ArcCell **arcs;   // 邻接矩阵
    int vexnum;       // 图的当前顶点个数
    int arcnum;       // 图的弧数量
    GraphKind kind;   // 图的种类标志
};

int main()
{
    cout << "构造无向图 :" << endl;
    MGraph<char, int, int> UDGGraph(4, UDG);
    UDGGraph.Create();
    UDGGraph.DisplayGraph();
    /*
        cout << "构造带权无向图 :" << endl;
        MGraph<char, int, int> WUDGGraph(9, WUDG);
        WUDGGraph.Create();
        WUDGGraph.DisplayGraph();

        cout << "构造有向图 :" << endl;
        MGraph<char, int, int> DGGraph(6,DG);
        DGGraph.Create();
        DGGraph.DisplayGraph();

        cout << "构造带权有向图 :" << endl;
        MGraph<char, int, int> DGGraph(6,WDG);
        DGGraph.Create();
        DGGraph.DisplayGraph();
    */
    return 0;
}