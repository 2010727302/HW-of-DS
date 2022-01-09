#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
//弧节点
typedef struct arcnode 
{
	int adjvex;//顶点位置
	struct arcnode *next;//指向下一条弧 
}arcnode; 
//顶点 
typedef struct vnode
{
	int data;//顶点信息
	arcnode *first;//第一条边/弧 
} vnode,adjlist[MAXSIZE];
//邻接表存储 
typedef struct
{
	adjlist vertices;
	int vexnum, arcnum;  //结点数，边的个数 
	
}graph;
int main()
{

    return 0;
}
