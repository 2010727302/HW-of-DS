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
int k;//�������� 
linklist la,lb,lc; 
int a[10086] = {0};//�������� 
int b[10086] = {0};
int i;
//���������� 
linklist lcreate(int a[],int len)
{
	lnode* l=(lnode*)malloc(sizeof(lnode));
	//�����½ڵ� 
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
	return l;//����ͷ��� 
}
//ʹ��β�巨�������� 
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb,*prear;//β��ָ�� 
	if(la==NULL||lb==NULL)
	{
		return false;
	}//la,lb�������� 
	pa=la->next;
	pb=lb->next;
	lc=la;
	prear=lc;
	lc->next=NULL;
	int len=0;
	len=min(a[0],b[0]) ;
	//�ȴ���a,b���е����� 
	for(int i=1;i<=len;i++)
	{
		//һ��ѭ�����Ȳ���a���ٲ���b 
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
		//a��������˳����� 
		prear->next=pa;
		prear=pa;
		pa=pa->next;
	}
	while(pb)
	{
		//b��������˳����� 
		prear->next=pb;
		prear=pb;
		pb=pb->next;
	//	cout<<"?"<<prear->data<<endl;
	}
	prear->next=NULL;
	
	return true;
}

//���������� 
void lprint(linklist l)
{
	lnode* p;
	if(l==NULL||l->next==NULL)
	{
		//����Ϊ�ս�� 
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
