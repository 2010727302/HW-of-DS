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
int ans; 
thrnode* pre=NULL;//��ǰǰ��
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

void prfind(thrtree& t)
{
	if(t!=NULL)
	{
		visit(t);//���ʸ��ڵ�
		if(t->ltag==0)//lchild��ǰ������
		{
			prfind(t->lchild);//���������� 
		} 
		
		
		prfind(t->rchild);//���������� 
	}
}

void cinthr(thrtree& t)
{
	pre=NULL;//��ʼ��
	if(t!=NULL)//�ǿն����������� 
	{
		prfind(t);
		if(pre->rchild==NULL)//�������һ���ڵ�
		{
			pre->rtag=1; 
		 } 
	} 
}

int main()
{

	
    return 0;
}
