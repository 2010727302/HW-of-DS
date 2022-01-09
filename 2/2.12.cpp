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
int k;//测试组数 
linklist la,lb,lc; 
int a[10086] = {0};//输入数据 
int b[10086] = {0};
int i;
//创建新链表 
linklist lcreate(int a[],int len)
{
	lnode* l=(lnode*)malloc(sizeof(lnode));
	//申请新节点 
	l->next=NULL;
	lnode *p,*prear;
	prear=l;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
		p=(lnode*)malloc(sizeof(lnode));
		p->data=a[i];
		prear->next=p;
		prear=p;
	}
	prear->next=NULL;
	return l;//返回头结点 
}
//使用尾插法插入节点 
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb,*prear;//尾项指针 prear 
	if(la==NULL||lb==NULL)
	{
		return false;
	}
	pa=la->next;
	pb=lb->next;
	lc=la;
	prear=lc;
	lc->next=NULL;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data>=pb->data)
		{
			//pa数据大于pb 
			prear->next=pa;
			prear=pa;//尾指针向后 
			pa=pa->next;
			//cout<<"a"<<prear->data<<endl;
		}
		else
		{
			prear->next=pb;
			prear=pb;
			pb=pb->next;
			//cout<<prear->data<<endl;
		}
	}
	while(pa)
	{//pa有剩余项放入lc 
		prear->next=pa;
		prear=pa;
		pa=pa->next;
	}
	while(pb)
	{//pb有剩余项放入lc 
		prear->next=pb;
		prear=pb;
		pb=pb->next;
	//	cout<<"?"<<prear->data<<endl;
	}
	prear->next=NULL;
	return true;
}
//1.reverse2
void lreverse(linklist& l)
{
	lnode *p,*q,*tmp;
	p=l->next;
	q=p->next;
	p->next=NULL;
	//将p和q之间的指向方向改变 
	while(q!=NULL)
	{
		tmp=q->next; 
		q->next=p;//逆转方向 
		p=q;
		q=tmp;
		//pq均向后移 
	}
	l->next=p;//头指针指向第一个元素 
}
//结果输出函数 
void lprint(linklist l)
{
	lnode* p;
	if(l==NULL||l->next==NULL)
	{
		//表明为空结点 
		return;
	}
	p=l->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	cin>>k;
	while(k--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>a[0]>>b[0];
		la=lcreate(a,a[0]);
		lb=lcreate(b,b[0]);
		//lprint(la);
		//lprint(lb);
		lreverse(la);
		lreverse(lb);
		//lprint(la);
		//lprint(lb);
		//1.先将a,b由升序变降序再头插 
		//2.头插 
		lmerge(la,lb,lc);
		lprint(lc);
		free(lc); 
    }
	return 0;
}
