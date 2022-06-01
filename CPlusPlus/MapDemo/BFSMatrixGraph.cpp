// 版权声明：本文为CSDN博主「JMW1407」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/JMW1407/article/details/108590505

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define VERTEXNUM 5

// 创建图 
void createGraph(vector<vector<int>>&edge, int start, int end) 
{
	edge[start][end] = 1;
}

//打印存储的图
void displayGraph(vector<vector<int>>&edge) 
{
	int i, j;
	for (i = 0; i<VERTEXNUM; i++) 
    {
		for (j = 0; j<VERTEXNUM; j++) 
        {
			//printf("%d ", edge[i][j]);
			cout << edge[i][j] << " ";
		}
		cout << endl;
	}
}

// BFS
void BFS(vector<vector<int>>&edge ,vector<int>& vertexStatusArr) 
{
	queue<int>q;
	q.push(0);
	vertexStatusArr[0] = 1;
	int idx = 0;
	while (!q.empty())
	{
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int j = 0; j< VERTEXNUM; j++) 
        {
			if (edge[idx][j] == 1 && vertexStatusArr[j] == 0)
			{
				q.push(j);
				vertexStatusArr[j] = 1;
			}
		}
	}
	cout << endl;
}

int main()
{

	//初始化邻接矩阵
	vector<vector<int>>edge(VERTEXNUM, vector<int>(VERTEXNUM, 0));

	//存放顶点的遍历状态，0：未遍历，1：已遍历  
	vector<int> vertexStatusArr(VERTEXNUM, 0);

	cout << "After init: " << endl;
	displayGraph(edge);

	//创建图
	createGraph(edge, 0, 3);
	createGraph(edge, 0, 4);
	createGraph(edge, 3, 1);
	createGraph(edge, 3, 2);
	createGraph(edge, 4, 1);

	cout << "After create: " << endl;
	displayGraph(edge);

    cout << "BFS :" << endl;
	BFS(edge, vertexStatusArr);
	return 0;
}