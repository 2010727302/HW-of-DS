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
//bitree t;
int ans; 
//bitnode* p;//p指向目标节点
thrnode* pre=NULL;//当前前驱
//bitnode* final=NULL;//最终结果 
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

void infind(thrtree& t)
{
	if(t!=NULL)
	{
		infind(t->lchild);//访问左子树 
		visit(t);//访问根节点
		infind(t->rchild);//访问右子树 
	}
}
void inthr(thrtree &p,thrtree &pre)
{
	if(p!=NULL)
	{
		inthr(p->lchild,pre);//左子树
		if(p->lchild==NULL)//左子树空，建立前驱 
		{
			p->lchild=pre;
			p->ltag=1; 
		}
		if(pre!=NULL&&pre->rchild==NULL)
		{
			pre->rchild=p;//后继
			pre->rtag=1;
		}
		pre=p;
		//右子树
		inthr(p->rchild,pre); 
	}
}
void cinthr(thrtree& t)
{
	pre=NULL;//初始化
	if(t!=NULL)//非空二叉树线索化 
	{
		infind(t);
		if(pre->rchild==NULL)//处理最后一个节点
		{
			pre->rtag=1; 
		 } 
	} 
}
void cinthr2(thrtree& t)
{
	thrtree pre=NULL;//初始化
	if(t!=NULL)//非空二叉树线索化 
	{
		inthr(t,pre);
		pre->rchild=NULL;//处理最后一个节点
		pre->rtag=1; 

	} 
}
//中序遍历中第一个被访问节点 
thrnode* firstnode(thrnode* p)//p为根 
{
	//最左下结点
	while(p->ltag==0)//有左孩子 
	{
		p=p->lchild;//最左下 
	} 
	return p; 
}
//p后续
thrnode* nextnode(thrnode* p)//右子树最左下 
{
	if(p->rtag==0)//有右子树 
	{
		return firstnode(p->rchild);
	} 
	else 
	{
		return p->rchild;//直接后继 
	 } 
} 
//中序遍历 
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
