#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct bitnode
{
	char data;//结点数据元素 
	struct bitnode *lchild,*rchild;//左右孩子指针 
}bitnode,*bitree;
char ch;
bitree t;
int k;//测试组数
int ans; 
int a[100086];
//创建树
void cbtree(bitree &t)
{
	scanf("%c",&ch); // abdg###e##c#f##
	if (ch=='#') t=NULL;
	else 
	{
		t=(bitnode *) malloc(sizeof (bitnode));
		/*if(!t)
		{
			return false;
		 } */
		t->data = ch ;
		//cout<<t->data<<endl;
		cbtree(t->lchild);
		cbtree(t->rchild);
	}
	//return true;
}
//访问 
void visit(bitree& t)
{
	printf("%c",t->data);
}
//先序 
void preorder(bitree& t)
{
	if(t!=NULL)
	{
		//visit(t);//访问根节点 
		printf("%c",t->data);
		preorder(t->lchild);//访问左子树 
		preorder(t->rchild); //访问右子树 
	}
}
//中序 
void inorder(bitree& t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);//访问左子树 
		visit(t);//访问根节点
		inorder(t->rchild);//访问右子树 
	}
}
//后序 
void postorder(bitree& t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);//访问左子树 
		postorder(t->rchild);//访问右子树
		visit(t);//访问根节点 
	}
}
int dtree(bitree& t)
{
	if(t==NULL)
	{
		//cout<<"1"<<endl;
		return 0;
	}
	else
	{
		int l=dtree(t->lchild);
		//cout<<l<<" "<<endl;
		int r=dtree(t->rchild);
		int ans=((l>r)?l+1:r+1);
		return ans;//树深度=max(左子树深度，右子树深度)+1 
	}
} 
int leaf(bitree &t,int c)
{
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			c++;
		}
		leaf(t->lchild,c);
		leaf(t->rchild,c);
	}
	return c;
}
int main()
{
	
		//ans=0;
		//memset(a,0,sizeof(a));
	cbtree(t);
	cout<<"先序遍历序列为："<<endl;
	preorder(t);
	cout<<endl; 
	cout<<"中序遍历序列为："<<endl;
	inorder(t); 
	cout<<endl; 
	cout<<"后序遍历序列为："<<endl;
	postorder(t); 
	cout<<endl; 
	cout<<"高度："<<endl;
	cout<<dtree(t)<<endl;
	//cout<<"后序遍历序列为："<<endl;
    return 0;
}
