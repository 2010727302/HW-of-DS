#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct lnode 
{
    int data;
    struct lnode* next;
};
typedef struct lnode* linklist;
typedef struct
{
	lnode *front,*rear;
}lque;
void initq(lque &q)
{
	q.front=q.rear=(lnode*)malloc(sizeof(lnode));
	q.front->next=NULL;
}
void enq(lque &q,int x)
{
	lnode* s=(linklist)malloc(sizeof(lnode));
	s->data=x;
	s->next=NULL;
	q.rear->next=s;
	q.rear=s;
	
}
bool deq(lque &q,int x)
{
	if(q.front==q.rear)
	{
		return false;
	}
	lnode *p=q.front->next;
	x=p->data;//返回头结点元素 
	q.front->next=p->next;//修改头结点的next
	if(q.rear==p)//特殊处理最后一个结点 
	{
		q.rear=q.front;//修改rear 
	} 
	free(p);
	return true;
}
int main()
{
	lque q;
	initq(q);
    return 0;
}
