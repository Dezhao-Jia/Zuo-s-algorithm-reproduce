// 版权声明：本文为CSDN博主「JMW1407」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/JMW1407/article/details/108590505

#include <iostream>
#include <vector>

using namespace std;

// 图的顶点数目
#define VERTEXNUM 5

// 创建图 
void createGraph(vector<vector<int>>&edge, int start, int end)
{
	edge[start][end] = 1;
}

// 打印存储的图
void displayGraph(vector<vector<int>>&edge) 
{
	int i, j;
	for (i = 0; i<VERTEXNUM; i++) 
    {
		for (j = 0; j<VERTEXNUM; j++) 
        {
			cout << edge[i][j] << " ";
		}
		cout << endl;
	}
}

void DFScore(vector<vector<int>>&edge, int i, vector<int>& vertexStatusArr) 
{
	if (vertexStatusArr[i] == 1) 
    {
		return;
	}
	cout << i << " ";
	vertexStatusArr[i] = 1;

	for (int j = 0; j<VERTEXNUM; j++) 
    {
		if (edge[i][j] == 1) 
        {
			DFScore(edge, j, vertexStatusArr);
		}
	}
}

// 深度优先遍历
void DFS(vector<vector<int>>&edge, vector<int>& vertexStatusArr) 
{
	cout << "Start BFT graph: " << endl;
	for (int i = 0; i<VERTEXNUM; i++) 
    {
		DFScore(edge, i, vertexStatusArr);
	}
	cout << endl;
}

int main() 
{
	
	//初始化邻接矩阵
	vector<vector<int>> edge(VERTEXNUM, vector<int>(VERTEXNUM, 0));
	
	//存放顶点的遍历状态，0：未遍历，1：已遍历  
	vector<int> vertexStatusArr(VERTEXNUM,0);

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

	//深度优先遍历
	DFS(edge, vertexStatusArr);

	return 0;
}