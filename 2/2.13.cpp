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
//ʹ��ͷ�巨�������� 
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb;
	if(la==NULL||lb==NULL)
	{
		//la,lb������ 
		return false;
	}
	pa=la->next;
	pb=lb->next;
	
	lc->next=NULL;
	
	while(pa!=NULL&&pb!=NULL)
	{
		//����ѭ��δ���� 
		if(pa->data<=pb->data)
		{
			//pa���ݱ�pbС
			la->next=pa->next;
	
			pa->next=lc->next;
		
			lc->next=pa;
		
			//cout<<" a"<<pa->data<<endl;
		}
		else
		{
			//pa���ݱ�pb��������ͬ�� 
			lb->next=pb->next;
			pb->next=lc->next;
			lc->next=pb;
			//cout<<" b"<<pb->data<<endl;
		}
		pa=la->next;//�����¹���ָ��Ƚ� 
		pb=lb->next;
	}
	while(la->next!=NULL)
	{
		//��la��ʣ����������lc 
		pa=la->next;
		la->next=pa->next;
		pa->next=lc->next;
		lc->next=pa;
	
	}
	while(lb->next!=NULL)
	{
		//��lc��ʣ����������lc 
		pb=lb->next;
		lb->next=pb->next;
		pb->next=lc->next;
		lc->next=pb;

	}
	
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
		//lreverse(la);
		//lreverse(lb);
		//lprint(la);
		//lprint(lb);
		//1.reverse a,b
		//2.ͷ�� 
		lnode* lc=(lnode*)malloc(sizeof(lnode));
		lmerge(la,lb,lc);
		lprint(lc);
		free(lc); 
	} 
	
    return 0;
}
