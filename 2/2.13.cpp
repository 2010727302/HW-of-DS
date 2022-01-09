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
//使用头插法插入链表 
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb;
	if(la==NULL||lb==NULL)
	{
		//la,lb空链表 
		return false;
	}
	pa=la->next;
	pb=lb->next;
	
	lc->next=NULL;
	
	while(pa!=NULL&&pb!=NULL)
	{
		//链表循环未结束 
		if(pa->data<=pb->data)
		{
			//pa数据比pb小
			la->next=pa->next;
	
			pa->next=lc->next;
		
			lc->next=pa;
		
			//cout<<" a"<<pa->data<<endl;
		}
		else
		{
			//pa数据比pb大的情况，同理 
			lb->next=pb->next;
			pb->next=lc->next;
			lc->next=pb;
			//cout<<" b"<<pb->data<<endl;
		}
		pa=la->next;//将更新过的指针比较 
		pb=lb->next;
	}
	while(la->next!=NULL)
	{
		//当la有剩余项，将其放入lc 
		pa=la->next;
		la->next=pa->next;
		pa->next=lc->next;
		lc->next=pa;
	
	}
	while(lb->next!=NULL)
	{
		//当lc有剩余项，将其放入lc 
		pb=lb->next;
		lb->next=pb->next;
		pb->next=lc->next;
		lc->next=pb;

	}
	
	return true;
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
		//lreverse(la);
		//lreverse(lb);
		//lprint(la);
		//lprint(lb);
		//1.reverse a,b
		//2.头插 
		lnode* lc=(lnode*)malloc(sizeof(lnode));
		lmerge(la,lb,lc);
		lprint(lc);
		free(lc); 
	} 
	
    return 0;
}
