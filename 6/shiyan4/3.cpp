#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<stack>
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
	if (ch==' ') t=NULL;
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
		bitnode* p=t;
		stack<bitnode*> s;
		while(!s.empty()||p)
		{
			while(p)
			{
				printf("%c",p->data);//访问根节点
				s.push(p);
				p=p->lchild;//访问左子树
			}
	
			p=s.top();
			s.pop();
			p=p->rchild;//访问右子树 
		
		}
		 
		
	}
}
//中序 
void inorder(bitree& t)
{
	if(t!=NULL)
	{
		bitnode* p=t;
		stack<bitnode*> s;
		while(!s.empty()||p)
		{
			while(p)
			{
			
				s.push(p);
				p=p->lchild;//访问左子树
			}
	
			p=s.top();
			s.pop();
			printf("%c",p->data);//访问根节点
			p=p->rchild;//访问右子树 
		
		}
		 
		
	}
}
//后序 
void postorder(bitree& t)
{

	if(t!=NULL)
	{
		bitnode* p=t;
		stack<bitnode*> s;
		bitnode* last=t;//上次访问的 
		//s.push(p);
		while(!s.empty()||p)
		{
		
			while(p)
			{
				s.push(p);
				p=p->lchild;//访问左子树
			}
			if(!s.empty())
			{
				p=s.top();
				//if(p->rchild==NULL||p->rchild==last)
				if( (p->lchild == NULL && p->rchild == NULL) || (p->rchild == NULL && last == p->lchild) || (last == p->rchild) )
				{	//叶节点或左右孩子都访问了 
					printf("%c",p->data);//访问根节点
					s.pop();//栈顶元素出栈
					last=p;//访问过p了 
					p=NULL;//将当前结点置空
				}
				else
				{
					p=p->rchild;//访问右子树 
				}
			}
			

		}
		 
	}
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

    return 0;
}
