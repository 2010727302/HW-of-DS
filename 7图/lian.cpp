#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
//���ڵ�
typedef struct arcnode 
{
	int adjvex;//����λ��
	struct arcnode *next;//ָ����һ���� 
}arcnode; 
//���� 
typedef struct vnode
{
	int data;//������Ϣ
	arcnode *first;//��һ����/�� 
} vnode,adjlist[MAXSIZE];
//�ڽӱ�洢 
typedef struct
{
	adjlist vertices;
	int vexnum, arcnum;  //��������ߵĸ��� 
	
}graph;
int main()
{

    return 0;
}
