#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
//���� 
typedef struct thrnode
{
	int data;//�������Ԫ�� 
	struct thrnode *lchild,*rchild;//���Һ���ָ��
	int ltag,rtag;//����������־ 
}thrnode,*thrtree;
char ch;
//bitree t;
int ans; 
//bitnode* p;//pָ��Ŀ��ڵ�
thrnode* pre=NULL;//��ǰǰ��
//bitnode* final=NULL;//���ս�� 
/*void visit2(thrtree& q)
{
	if(q==p)//��ǰ����Ϊp 
	{
		final=pre;//�ҵ�pǰ�� 
	}
	else
	{
		pre=q;//preָ��ǰ���ʽ�� 
	}
}*/
void visit(thrtree& q)
{
	if(q->lchild==NULL)//�������գ�����ǰ�� 
	{
		q->lchild=pre;
		q->ltag=1; 
	}
	if(pre!=NULL&&pre->rchild==NULL)
	{
		pre->rchild=q;//���
		pre-> rtag=1;
	}
	pre=q;
}

void infind(thrtree& t)
{
	if(t!=NULL)
	{
		infind(t->lchild);//���������� 
		visit(t);//���ʸ��ڵ�
		infind(t->rchild);//���������� 
	}
}
void inthr(thrtree &p,thrtree &pre)
{
	if(p!=NULL)
	{
		inthr(p->lchild,pre);//������
		if(p->lchild==NULL)//�������գ�����ǰ�� 
		{
			p->lchild=pre;
			p->ltag=1; 
		}
		if(pre!=NULL&&pre->rchild==NULL)
		{
			pre->rchild=p;//���
			pre->rtag=1;
		}
		pre=p;
		//������
		inthr(p->rchild,pre); 
	}
}
void cinthr(thrtree& t)
{
	pre=NULL;//��ʼ��
	if(t!=NULL)//�ǿն����������� 
	{
		infind(t);
		if(pre->rchild==NULL)//�������һ���ڵ�
		{
			pre->rtag=1; 
		 } 
	} 
}
void cinthr2(thrtree& t)
{
	thrtree pre=NULL;//��ʼ��
	if(t!=NULL)//�ǿն����������� 
	{
		inthr(t,pre);
		pre->rchild=NULL;//�������һ���ڵ�
		pre->rtag=1; 

	} 
}
//��������е�һ�������ʽڵ� 
thrnode* firstnode(thrnode* p)//pΪ�� 
{
	//�����½��
	while(p->ltag==0)//������ 
	{
		p=p->lchild;//������ 
	} 
	return p; 
}
//p����
thrnode* nextnode(thrnode* p)//������������ 
{
	if(p->rtag==0)//�������� 
	{
		return firstnode(p->rchild);
	} 
	else 
	{
		return p->rchild;//ֱ�Ӻ�� 
	 } 
} 
//������� 
void inorder(thrtree& t)
{
	for(thrnode *p=firstnode(t);p!=NULL;p=nextnode(p))
	{
		visit(p);	
	}	
} 
int main()
{

	
    return 0;
}
