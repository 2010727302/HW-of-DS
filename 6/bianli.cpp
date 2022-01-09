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
	struct bitnode *lchild,*rchild;//左右孩子指针 
}bitnode,*bitree;
char ch;
bitree t;
int k;//测试组数
int ans; 
bitree q[10086],q1[10086];
int a[100086];
void visit(bitree& t)
{
	cout<<t->data<<endl;
}
int dtree(bitree& t)
{
	if(t=NULL)
	{
		//cout<<"1"<<endl;
		return 0;
	}
	else
	{
		int l=dtree(t->lchild);
		cout<<l<<" "<<endl;
		int r=dtree(t->rchild);
		
		return (l>r)?l+1:r+1;//树深度=max(左子树深度，右子树深度)+1 
	}
} 
void preorder(bitree t)
{
	if(t!=NULL)
	{
		visit(t);//访问根节点 
		preorder(t->lchild);//访问左子树 
		preorder(t->rchild); //访问右子树 
	}
}
void inorder(bitree t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);//访问左子树 
		visit(t);//访问根节点
		inorder(t->rchild);//访问右子树 
	}
}
void postorder(bitree t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);//访问左子树 
		postorder(t->rchild);//访问右子树
		visit(t);//访问根节点 
	}
}
//创建树
void cbtree(bitree &root)
{
	int geshu=0;
	while(1)
	{
		cin>>a[geshu];
		if(a[geshu]==-1)
		{
			geshu--;
			break;
		}
		geshu++;
	}
	//cout<<"i:"<<geshu<<endl;
	//插入根结点
	root=(bitree)malloc(sizeof(bitnode));
	root->data=a[0];
	root->lchild=NULL;
	root->rchild=NULL;
	int front=0,rear=1;//队列 	
	q[0]=root;
	int shuzu=1; 
	while(rear!=front)//队列不为空
	{
		int n=rear-front;//数组大小 
		for(int i=0;i<n;i++)
		{
			bitree temp=q[front];//队列节点 
			front++;
			int lt=a[shuzu];//左节点 
			shuzu++;
			int rt=a[shuzu];//右节点 
			shuzu++;
			if(lt!=0)
			{
				bitnode *ln=(bitree)malloc(sizeof(bitnode));
				ln->data=lt;
				temp->lchild=ln;//父子结点相连 
				q[rear]=ln;//左节点入队 
				rear++;
			}
			else
			{
				temp->lchild=NULL;
			}
			if(rt!=0)
			{
				bitnode *rn=(bitree)malloc(sizeof(bitnode));
				rn->data=rt;
				temp->rchild=rn;//父子结点相连 
				q[rear]=rn;//右节点入队 
				rear++;
			}
			else
			{
				temp->rchild=NULL;
			}
		}
	} 
}
//链式队列节点
typedef struct lnode
{
	bitnode* data;
	struct lnode* next;
}lnode;
typedef struct lnode* linklist; 
typedef struct
{
	lnode *front,*rear;
}lque;
void qinit(lque &q)
{
	q.front=q.rear=(lnode*)malloc(sizeof(lnode));
	q.front->next=NULL;
}
void enq(lque &q,bitree& x)
{
	lnode* s=(linklist)malloc(sizeof(lnode));
	s->data=x;
	s->next=NULL;
	q.rear->next=s;
	q.rear=s;
	
}
bool deq(lque &q,bitree& x)
{
	if(q.front==q.rear)
	{
		return false;
	}
	lnode *p=q.front->next;
	x=p->data;//返回头结点元素 
	q.front->next=p->next;//修改头结点的next
	if(q.rear==p)//特殊处理最后一个结点 
	{
		q.rear=q.front;//修改rear 
	} 
	free(p);
	return true;
}
bool isempty(lque &q)
{
	return (q.rear==q.front);
}
//层序遍历
void lorder(bitree t)
{
	lque q;
	//queue<bitnode>*q;
	qinit(q);//初始化 
	bitree p;
	enq(q,t);//根节点入队 
	while(!isempty(q))//队列不空 
	{
		deq(q,p);//队头出队 
		visit(p);//访问出对节点 
		if(p->lchild!=NULL)
		{
			enq(q,p->lchild);//左孩子入队 
		}
		if(p->rchild!=NULL)
		{
			enq(q,p->rchild);//右孩子入队 
		}
	}
 } 
int main()
{
	cin>>k;
	while(k--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(q,0,sizeof(q));
		cbtree(t);
		cout<<t->data<<endl;
		ans=dtree(t);
		//memset(q1,0,sizeof(q1));
		//tprint(t) ;
	} 
	
    return 0;
    return 0;
}
