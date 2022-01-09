#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;

#define MAX_VERTEX_NUM 30           //图的最大顶点数不超过30个
#define MAXQSIZE 40                 //队列的最大容量

enum BOOL{ False, True };

typedef struct ArcNode
{
	int adjvex;                      //顶点位置
	struct ArcNode *nextarc;         //指向下一条弧的指针
}ArcNode;                            //弧结点

typedef struct{
	ArcNode* AdjList[MAX_VERTEX_NUM];            //指向第一条依附该顶点的弧的指针
	int vexnum, arcnum;                          //图的当前顶点和弧数
}Graph;

typedef struct                       //队列结构
{
	int elem[MAXQSIZE];              //数据域
	int front;                       // 队头指针
	int rear;                       // 队尾指针
}SqQueue;

BOOL visited[MAX_VERTEX_NUM];       //全局变量——访问标志数组
void CreateGraph(Graph &);          //生成图的邻接表
void DFSTraverse(Graph);            //深度优先搜索遍历图
void DFS(Graph, int);
void BFSTraverse(Graph);            //广度优先搜索遍历图
void Initial(SqQueue &);            //初始化一个队列
BOOL QueueEmpty(SqQueue);           //判断队列是否为空
BOOL EnQueue(SqQueue &, int);       //将一个元素入队列
BOOL DeQueue(SqQueue &, int &);     //将一个元素出队列
int firstAdjVex(Graph, int);        //求图中某一顶点的第一个邻接顶点
int NextAdjVex(Graph, int, int);    //求某一顶点的下一个邻接顶点

void CreateGraph(Graph &G){
	//构造邻接表结构的图G
	int i;
	int start, end;
	ArcNode *s;
	for (i = 1; i <= G.vexnum; i++)
		G.AdjList[i] = NULL;                              //初始化指针数组
	if (G.arcnum == 0){
		cout << "The graph have no edges." << endl;
	}
	else{
		for (i = 1; i <= G.arcnum; i++)
		{
			cin >> start >> end;                              //输入弧的起点和终点
			s = (ArcNode *)malloc(sizeof(ArcNode));           //生成一个弧结点
			s->nextarc = G.AdjList[start];                    //插入到邻接表中
			s->adjvex = end;
			G.AdjList[start] = s;
			{
				s = (ArcNode *)malloc(sizeof(ArcNode));
				s->nextarc = G.AdjList[end];
				s->adjvex = start;
				G.AdjList[end] = s;
			}
		}
	}
}

void DFSTraverse(Graph G)
{
	//深度优先遍历图G
	int i;
	cout << "The depth-first traversal order is:" << endl;
	for (i = 1; i <= G.vexnum; i++)
		visited[i] = False;               //访问标志数组初始化
	for (i = 1; i <= G.vexnum; i++)
	if (!visited[i]) DFS(G, i);
	cout << endl;
}

void DFS(Graph G, int i){
	//从第i个顶点出发递归地深度遍历图G
	int w;
	visited[i] = True;                                             //访问第i个顶点
	cout << i <<"  ";
	for (w = firstAdjVex(G, i); w > 0; w = NextAdjVex(G, i, w))
	if (!visited[w]) DFS(G, w);                                    //对尚未访问的邻接顶点w调用DFS
}

void BFSTraverse(Graph G){
	//按广度优先非递归的遍历图G，使用辅助队列Q和访问标志数组visited
	int i, u, w;
	SqQueue	Q;
	cout << "The breadth-first traversal order is:" << endl;
	for (i = 1; i <= G.vexnum; i++) visited[i] = False;                        //访问标志数组初始化
	Initial(Q);                                                                //初始化队列
	for (i = 1; i <= G.vexnum; i++)
	if (!visited[i])
	{
		visited[i] = True;                                                      //访问顶点i
		cout << i<< "  ";
		EnQueue(Q, i);                                                          //将序号i入队列
		while (!QueueEmpty(Q))                                                  //若队列不空，继续
		{
			DeQueue(Q, u);                                                      //将队头元素出队列并置u
			for (w = firstAdjVex(G, u); w > 0; w = NextAdjVex(G, u, w))
			if (!visited[w])                                                    //对u的尚未访问的邻接顶点w进行访问并入队列
			{
				visited[w] = True;
				cout << w << "  ";
				EnQueue(Q, w);
			}
		}
	}
	cout << endl;
}

int firstAdjVex(Graph G, int v)
{
	//在图G中寻找第v个顶点的第一个邻接顶点
	if (!G.AdjList[v])
		return 0;
	else
		return(G.AdjList[v]->adjvex);
}

int NextAdjVex(Graph G, int v, int u)
{
	//在图中寻找第v个顶点的相对于u的下一个邻接顶点
	ArcNode *p;
	p = G.AdjList[v];
	while (p->adjvex != u) p = p->nextarc;                    //在顶点v的弧链中找到顶点u
	if (p->nextarc == NULL)
		return 0;                                             //若已经是最后一个结点，返回0
	else
		return(p->nextarc->adjvex);                           //返回下一个邻接顶点的序号
}

void Initial(SqQueue &Q)
{
	//队列初始化
	Q.front = Q.rear = 0;
}

BOOL QueueEmpty(SqQueue Q){
	//判断队列是否已空，若空返回True,否则返回False
	if (Q.front == Q.rear)
		return True;
	else
		return False;
}

BOOL EnQueue(SqQueue &Q, int ch)
{
	//入队列，成功返回True,失败返回False
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return False;
	Q.elem[Q.rear] = ch;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return True;
}

BOOL DeQueue(SqQueue &Q, int &ch)
{
	//出队列，成功返回True,并用ch返回该元素值，失败返回False
	if (Q.front == Q.rear)
		return False;
	ch = Q.elem[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return True;//成功出队列，返回True
}

int main(){
	Graph G;                        //采用邻接表结构的图
	
	cout << "Please enter the number of vertices and arcs:" << endl;
	cin >> G.vexnum >> G.arcnum;

	cout << "Enter the arc heads and tails on each side:" << endl;
	CreateGraph(G);

	DFSTraverse(G);
	BFSTraverse(G);


	//cout << "Please enter any number to finish running.";
	int stay;
	cin >> stay;  //由于要上交.exe可执行文件，程序完执行，就会自动关闭了，这里是临时增加的停留操作，让执行结果在窗口中停留

}

