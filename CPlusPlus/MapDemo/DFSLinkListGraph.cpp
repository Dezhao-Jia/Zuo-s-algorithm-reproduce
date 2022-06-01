// 版权声明：本文为CSDN博主「JMW1407」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/JMW1407/article/details/108590505

#include <stdio.h>
#include <malloc.h>

#define VERTEXNUM 5

//存放顶点的邻接表元素  
class Edge 
{
    public:
        int vertex;
        Edge* next;
};

// 创建图 
void createGraph(Edge** edge, int start, int end) 
{
	Edge* newedge = (Edge*)malloc(sizeof(Edge));
	newedge->vertex = end;
	newedge->next = NULL;
	edge = edge + start;
	while (*edge != NULL) 
    {
		edge = &((*edge)->next);
	}
	*edge = newedge;
}

// 打印存储的图 
void displayGraph(Edge** edge) 
{
	int i;
	Edge* p;
	for (i = 0; i<VERTEXNUM; i++) 
    {
		printf("%d:", i);
		p = *(edge + i);
		while (p != NULL)
        {
			printf("%d ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}

// 释放邻接表占用的内存 
void delGraph(Edge** edge) 
{
	int i;
	Edge* p;
	Edge* del;
	for (i = 0; i<VERTEXNUM; i++) 
    {
		p = *(edge + i);
		while (p != NULL) 
        {
			del = p;
			p = p->next;
			free(del);
		}
		edge[i] = NULL;
	}
	free(edge);
}

void DFTcore(Edge** edge, int i, int* vertexStatusArr) 
{
	if (vertexStatusArr[i] == 1)
    {
		return;
	}
	printf("%d ", i);
	vertexStatusArr[i] = 1;
	Edge* p = *(edge + i);
	while (p != NULL) 
    {
		DFTcore(edge, p->vertex, vertexStatusArr);
		p = p->next;
	}
}

// 深度优先遍历 
void DFT(Edge** edge, int* vertexStatusArr) 
{
	printf("start BFT graph:\n");
	int i;
	for (i = 0; i<VERTEXNUM; i++) 
    {
		DFTcore(edge, i, vertexStatusArr);
	}
	printf("\n");
}

int main() 
{
	//动态创建存放边的指针数组   
	Edge** edge = (Edge**)malloc(sizeof(Edge*)*VERTEXNUM);
	int i;
	for (i = 0; i<VERTEXNUM; i++) 
    {
		edge[i] = NULL;
	}
	//存放顶点的遍历状态，0：未遍历，1：已遍历  
	int* vertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
	for (i = 0; i<VERTEXNUM; i++) 
    {
		vertexStatusArr[i] = 0;
	}

	printf("after init:\n");
	displayGraph(edge);
	//创建图  
	createGraph(edge, 0, 3);
	createGraph(edge, 0, 4);
	createGraph(edge, 3, 1);
	createGraph(edge, 3, 2);
	createGraph(edge, 4, 1);

	printf("after create:\n");
	displayGraph(edge);

	//深度优先遍历 
	DFT(edge, vertexStatusArr);
    
	//释放邻接表占用的内存  
	delGraph(edge);
	edge = NULL;
	free(vertexStatusArr);
	vertexStatusArr = NULL;
	return 0;
}