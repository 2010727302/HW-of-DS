#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct bitnode
{
	int data;//�������Ԫ�� 
	//struct bitnode *parent;//���ڵ� 
	struct bitnode *lchild,*rchild;//���Һ���ָ�� 
}bitnode,*bitree;
char ch;
bitree t;
//������
bool cbtree(bitree &t)
{
	scanf("%c",&ch);// abdg###e##c#f##
	if(ch=='#')
	{
		t=NULL;
		
	}
	else
	{
		if(!(t=(bitree)malloc(sizeof(bitnode))))
		{
			return false;
		}
		t->data=ch;
		cbtree(t->lchild);
		cbtree(t->rchild);
	}
	return true;
 } 
void ctree1()
{
	//�������
	bitree root=NULL;
	//��������
	root=(bitree)malloc(sizeof(bitnode));
	root->data=1;
	root->lchild=NULL;
	root->rchild=NULL;
	//�����½��
	bitnode* p= (bitree)malloc(sizeof(bitnode));
	p->data=2;
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;
}
int main()
{
	cbtree(t);
    return 0;
}
