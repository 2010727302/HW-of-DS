#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
typedef struct
{
	char vex[MAXSIZE];//顶点 
	int edge[MAXSIZE][MAXSIZE];//邻接矩阵
	int vexnum,arcnum; //当前节点数和弧数 
}graph;
bool visited[MAXSIZE];//访问标记数组 
//对g深度优先
void dfstra(graph g)
{
	for(int i=0;i<g.vexnum;i++)
	{
		visited[i]=false;//标记初始化 
	}
	for(int i=0;i<g.vexnum;i++)//从0开始遍历 
	{
		if(!visited[i])//对每个连通分量分别用bfs
		{
			dfs(g,i); 
		} 
	}
 } 
//深度优先 
void dfs(graph g,int v)
{
	visit(v);//访问初始v
	visited[v]=true;//
	for(w=firstnei(g,v);w>=0;w=nextnei(g,v,w))
	{
		if(!visited[w])//w为v的尚未访问结点 
		{
			dfs(g,w);
		} 
	}
}
int main()
{

    return 0;
}
