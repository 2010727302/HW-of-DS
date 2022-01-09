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
//使用尾插法插入链表 
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb,*prear;//尾项指针 
	if(la==NULL||lb==NULL)
	{
		return false;
	}//la,lb空链表返回 
	pa=la->next;
	pb=lb->next;
	lc=la;
	prear=lc;
	lc->next=NULL;
	int len=0;
	len=min(a[0],b[0]) ;
	//先处理a,b都有的项数 
	for(int i=1;i<=len;i++)
	{
		//一次循环中先插入a，再插入b 
		prear->next=pa;
		prear=pa;
		pa=pa->next;

		prear->next=pb;
		prear=pb;
		pb=pb->next;
		//cout<<prear->data<<endl;
	}
	while(pa)
	{
		//a项数多则按顺序放入 
		prear->next=pa;
		prear=pa;
		pa=pa->next;
	}
	while(pb)
	{
		//b项数多则按顺序放入 
		prear->next=pb;
		prear=pb;
		pb=pb->next;
	//	cout<<"?"<<prear->data<<endl;
	}
	prear->next=NULL;
	
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
		lnode* lc=(lnode*)malloc(sizeof(lnode));
		lmerge(la,lb,lc);
		lprint(lc);
		free(lc); 
	} 
	
    return 0;
}
