#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
typedef struct
{
	char vex[MAXSIZE];//���� 
	int edge[MAXSIZE][MAXSIZE];//�ڽӾ���
	int vexnum,arcnum; //��ǰ�ڵ����ͻ��� 
}graph;
bool visited[MAXSIZE];//���ʱ������ 
//��g�������
void bfstra(graph g)
{
	for(int i=0;i<g.vexnum;i++)
	{
		visited[i]=false;//��ǳ�ʼ�� 
	}
	initq(q);
	for(int i=0;i<g.vexnum;i++)//��0��ʼ���� 
	{
		if(!visited[i])//��ÿ����ͨ�����ֱ���bfs
		{
			bfs(g,i); 
		} 
	}
 } 
//������� 
void bfs(graph g,int v)
{
	visit(v);//���ʳ�ʼv
	visited[v]=true;
	enqueue(q,v);
	while(!isempty(q))
	{
		dequeue(q,v);
		//���v�����ڽӵ� 
		for(w=firstnei(g,v);w>=0;w=nextnei(g,v,w))
		{
			if(!visited[w])//wΪv����δ���ʽ�� 
			{
				visit(w);
				visited[w]=true;//�����
				enqueue(q,w);//w���	
			} 
		}
	 } 
}
int main()
{

    return 0;
}
