#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;

#define MAX_VERTEX_NUM 30           //ͼ����󶥵���������30��
#define MAXQSIZE 40                 //���е��������

enum BOOL{ False, True };

typedef struct ArcNode
{
	int adjvex;                      //����λ��
	struct ArcNode *nextarc;         //ָ����һ������ָ��
}ArcNode;                            //�����

typedef struct{
	ArcNode* AdjList[MAX_VERTEX_NUM];            //ָ���һ�������ö���Ļ���ָ��
	int vexnum, arcnum;                          //ͼ�ĵ�ǰ����ͻ���
}Graph;

typedef struct                       //���нṹ
{
	int elem[MAXQSIZE];              //������
	int front;                       // ��ͷָ��
	int rear;                       // ��βָ��
}SqQueue;

BOOL visited[MAX_VERTEX_NUM];       //ȫ�ֱ����������ʱ�־����
void CreateGraph(Graph &);          //����ͼ���ڽӱ�
void DFSTraverse(Graph);            //���������������ͼ
void DFS(Graph, int);
void BFSTraverse(Graph);            //���������������ͼ
void Initial(SqQueue &);            //��ʼ��һ������
BOOL QueueEmpty(SqQueue);           //�ж϶����Ƿ�Ϊ��
BOOL EnQueue(SqQueue &, int);       //��һ��Ԫ�������
BOOL DeQueue(SqQueue &, int &);     //��һ��Ԫ�س�����
int firstAdjVex(Graph, int);        //��ͼ��ĳһ����ĵ�һ���ڽӶ���
int NextAdjVex(Graph, int, int);    //��ĳһ�������һ���ڽӶ���

void CreateGraph(Graph &G){
	//�����ڽӱ�ṹ��ͼG
	int i;
	int start, end;
	ArcNode *s;
	for (i = 1; i <= G.vexnum; i++)
		G.AdjList[i] = NULL;                              //��ʼ��ָ������
	if (G.arcnum == 0){
		cout << "The graph have no edges." << endl;
	}
	else{
		for (i = 1; i <= G.arcnum; i++)
		{
			cin >> start >> end;                              //���뻡�������յ�
			s = (ArcNode *)malloc(sizeof(ArcNode));           //����һ�������
			s->nextarc = G.AdjList[start];                    //���뵽�ڽӱ���
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
	//������ȱ���ͼG
	int i;
	cout << "The depth-first traversal order is:" << endl;
	for (i = 1; i <= G.vexnum; i++)
		visited[i] = False;               //���ʱ�־�����ʼ��
	for (i = 1; i <= G.vexnum; i++)
	if (!visited[i]) DFS(G, i);
	cout << endl;
}

void DFS(Graph G, int i){
	//�ӵ�i����������ݹ����ȱ���ͼG
	int w;
	visited[i] = True;                                             //���ʵ�i������
	cout << i <<"  ";
	for (w = firstAdjVex(G, i); w > 0; w = NextAdjVex(G, i, w))
	if (!visited[w]) DFS(G, w);                                    //����δ���ʵ��ڽӶ���w����DFS
}

void BFSTraverse(Graph G){
	//��������ȷǵݹ�ı���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited
	int i, u, w;
	SqQueue	Q;
	cout << "The breadth-first traversal order is:" << endl;
	for (i = 1; i <= G.vexnum; i++) visited[i] = False;                        //���ʱ�־�����ʼ��
	Initial(Q);                                                                //��ʼ������
	for (i = 1; i <= G.vexnum; i++)
	if (!visited[i])
	{
		visited[i] = True;                                                      //���ʶ���i
		cout << i<< "  ";
		EnQueue(Q, i);                                                          //�����i�����
		while (!QueueEmpty(Q))                                                  //�����в��գ�����
		{
			DeQueue(Q, u);                                                      //����ͷԪ�س����в���u
			for (w = firstAdjVex(G, u); w > 0; w = NextAdjVex(G, u, w))
			if (!visited[w])                                                    //��u����δ���ʵ��ڽӶ���w���з��ʲ������
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
	//��ͼG��Ѱ�ҵ�v������ĵ�һ���ڽӶ���
	if (!G.AdjList[v])
		return 0;
	else
		return(G.AdjList[v]->adjvex);
}

int NextAdjVex(Graph G, int v, int u)
{
	//��ͼ��Ѱ�ҵ�v������������u����һ���ڽӶ���
	ArcNode *p;
	p = G.AdjList[v];
	while (p->adjvex != u) p = p->nextarc;                    //�ڶ���v�Ļ������ҵ�����u
	if (p->nextarc == NULL)
		return 0;                                             //���Ѿ������һ����㣬����0
	else
		return(p->nextarc->adjvex);                           //������һ���ڽӶ�������
}

void Initial(SqQueue &Q)
{
	//���г�ʼ��
	Q.front = Q.rear = 0;
}

BOOL QueueEmpty(SqQueue Q){
	//�ж϶����Ƿ��ѿգ����շ���True,���򷵻�False
	if (Q.front == Q.rear)
		return True;
	else
		return False;
}

BOOL EnQueue(SqQueue &Q, int ch)
{
	//����У��ɹ�����True,ʧ�ܷ���False
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return False;
	Q.elem[Q.rear] = ch;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return True;
}

BOOL DeQueue(SqQueue &Q, int &ch)
{
	//�����У��ɹ�����True,����ch���ظ�Ԫ��ֵ��ʧ�ܷ���False
	if (Q.front == Q.rear)
		return False;
	ch = Q.elem[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return True;//�ɹ������У�����True
}

int main(){
	Graph G;                        //�����ڽӱ�ṹ��ͼ
	
	cout << "Please enter the number of vertices and arcs:" << endl;
	cin >> G.vexnum >> G.arcnum;

	cout << "Enter the arc heads and tails on each side:" << endl;
	CreateGraph(G);

	DFSTraverse(G);
	BFSTraverse(G);


	//cout << "Please enter any number to finish running.";
	int stay;
	cin >> stay;  //����Ҫ�Ͻ�.exe��ִ���ļ���������ִ�У��ͻ��Զ��ر��ˣ���������ʱ���ӵ�ͣ����������ִ�н���ڴ�����ͣ��

}

