#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
//线索 
typedef struct thrnode
{
	int data;//结点数据元素 
	struct thrnode *lchild,*rchild;//左右孩子指针
	int ltag,rtag;//左右线索标志 
}thrnode,*thrtree;
char ch;
int ans; 
thrnode* pre=NULL;//当前前驱
/*void visit2(thrtree& q)
{
	if(q==p)//当前访问为p 
	{
		final=pre;//找到p前驱 
	}
	else
	{
		pre=q;//pre指向当前访问结点 
	}
}*/
void visit(thrtree& q)
{
	if(q->lchild==NULL)//左子树空，建立前驱 
	{
		q->lchild=pre;
		q->ltag=1; 
	}
	if(pre!=NULL&&pre->rchild==NULL)
	{
		pre->rchild=q;//后继
		pre-> rtag=1;
	}
	pre=q;
}

void prfind(thrtree& t)
{
	if(t!=NULL)
	{
		visit(t);//访问根节点
		if(t->ltag==0)//lchild非前驱线索
		{
			prfind(t->lchild);//访问左子树 
		} 
		
		
		prfind(t->rchild);//访问右子树 
	}
}

void cinthr(thrtree& t)
{
	pre=NULL;//初始化
	if(t!=NULL)//非空二叉树线索化 
	{
		prfind(t);
		if(pre->rchild==NULL)//处理最后一个节点
		{
			pre->rtag=1; 
		 } 
	} 
}

int main()
{

	
    return 0;
}
