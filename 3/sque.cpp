#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define MAXSIZE 10
typedef struct sque 
{
    int data[MAXSIZE];
	int front,rear;
}sque;

void initq(sque &q)
{
	q.rear=q.front=0;
}
bool emptyq(sque &q)
{
	if(q.rear==q.front)
		return true;
	else
		return false;
}
//入队 
bool enq(sque &q,int &x)
{
	if(q.rear+1==q.front)//队满报错 
	{
		return false;
	}
	q.data[q.rear]=x;//新元素入队尾 
	q.rear=(q.rear+1)%MAXSIZE;//队尾指针+1取模 
	return true;
}
//出队 
bool deq(sque &q,int &x)
{
	if(q.rear==q.front)//队空报错 
	{
		return false;
	}
	x=q.data[q.front];
	q.front=(q.front+1)%MAXSIZE;//队头指针+1取模 
	return true;
}
 
int main()
{
	sque q;
	int x=1;
	initq(q);
	enq(q,x);
	deq(q,x);
	cout<<x<<endl;
	return 0;
} 
