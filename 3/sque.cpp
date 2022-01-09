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
//��� 
bool enq(sque &q,int &x)
{
	if(q.rear+1==q.front)//�������� 
	{
		return false;
	}
	q.data[q.rear]=x;//��Ԫ�����β 
	q.rear=(q.rear+1)%MAXSIZE;//��βָ��+1ȡģ 
	return true;
}
//���� 
bool deq(sque &q,int &x)
{
	if(q.rear==q.front)//�ӿձ��� 
	{
		return false;
	}
	x=q.data[q.front];
	q.front=(q.front+1)%MAXSIZE;//��ͷָ��+1ȡģ 
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
