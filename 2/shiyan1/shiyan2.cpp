#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct lnode 
{
    int key;//密码 
    int num;//编号 
    struct lnode* next;
};
typedef struct lnode* linklist;
int m;//出列值 
int renshu;//测试人数 
linklist l,la; 

bool ldelete(linklist& l)
{
	//注意边界 
	for(int i=1;i<m;i++)
	{
		l=l->next; //找到要删除的节点前一个结点 
	}
	m=l->key;
	//将该节点输出 
	//cout<<m<<;
	cout<<l->num<<" ";
	//删除该节点(因为如果只找到m前一个节点删除当前结点的话m=1会出问题，只能将后面一个节点填到前一个)
	lnode* p;
	p=l->next;
	//将后一个节点的值移到前一个结点 
	l->num=p->num;
	l->key=p->key;
	l->next=p->next; 
	free(p);//删除后一个节点 
	//l=l->next;
	return true;
}


int main()
{
	cin>>m; 
	cin>>renshu; 
	//创建新链表 
	l=(linklist)malloc(sizeof(struct lnode));
	cin>>l->key;
	l->num=1;
	la=l;//标记头结点 
	l->next=NULL;
	for(int i=2;i<=renshu;i++)
	{
		lnode* q=(linklist)malloc(sizeof(struct lnode));
		l->next=q;
		q->num=i;
		cin>>q->key;
		l=q;
	}
	l->next=la;
	l=la;//形成循环列表 
	for(int i=1;i<=renshu;i++)
	//调用人数的次数 ，表示处理完了 
	{
		ldelete(l);
	}
	
    return 0;
}
