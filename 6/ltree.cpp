#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct bitnode
{
	int data;//结点数据元素 
	//struct bitnode *parent;//父节点 
	struct bitnode *lchild,*rchild;//左右孩子指针 
}bitnode,*bitree;
char ch;
bitree t;
//创建树
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
	//定义空树
	bitree root=NULL;
	//插入根结点
	root=(bitree)malloc(sizeof(bitnode));
	root->data=1;
	root->lchild=NULL;
	root->rchild=NULL;
	//插入新结点
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
