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
void tswap(bitree& root)
{
	bitree temp=root->lchild;
	root->lchild=root->rchild;
	root->rchild=temp;
	if(root->lchild!=NULL)
	{
		tswap(root->lchild);
	}
	if(root->rchild!=NULL)
	{
		tswap(root->rchild);
	}
}
void tprint(bitree& root)
{
	int front=0,rear=1;
	q1[0]=root;
	while(front!=rear)
	{
		//int n=rear-front;
		//cout<<" n"<<n<<endl;
		//for(int i=0;i<n;i++)
		{
			bitree temp=q1[front];
			if(temp!=NULL)
			{
				//cout<<temp->data<<"fr"<<front<<endl;
				if(front!=0)
				{
					cout<<" ";
				}
				cout<<temp->data;
				q1[rear]=temp->lchild;//左右节点入队 
				rear++;
				q1[rear]=temp->rchild;	
				//cout<<rear<<"rc"<< temp->rchild->data<<endl;
				rear++;
				//cout<<"r"<<rear<<endl;
			
			}
			else
			{
				cout<<" 0";
			}
			front++;//出列 
			//cout<<"fr"<<front<<endl;
		}
		
	}
		
	cout<<endl;
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
		tswap(t);
		memset(q1,0,sizeof(q1));
		tprint(t) ;
	} 
	
    return 0;
}
