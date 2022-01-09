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
//ʹ��β�巨����ڵ� 
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb,*prear;//β��ָ�� prear 
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
			//pa���ݴ���pb 
			prear->next=pa;
			prear=pa;//βָ����� 
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
	{//pa��ʣ�������lc 
		prear->next=pa;
		prear=pa;
		pa=pa->next;
	}
	while(pb)
	{//pb��ʣ�������lc 
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
	//��p��q֮���ָ����ı� 
	while(q!=NULL)
	{
		tmp=q->next; 
		q->next=p;//��ת���� 
		p=q;
		q=tmp;
		//pq������� 
	}
	l->next=p;//ͷָ��ָ���һ��Ԫ�� 
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
		lreverse(la);
		lreverse(lb);
		//lprint(la);
		//lprint(lb);
		//1.�Ƚ�a,b������併����ͷ�� 
		//2.ͷ�� 
		lmerge(la,lb,lc);
		lprint(lc);
		free(lc); 
    }
	return 0;
}
