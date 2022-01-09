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
	int ltag,rtag;//左右线索标志 
}bitnode,*bitree;
char ch;
bitree t;
int k;//测试组数
int ans; 
bitree q[10086],q1[10086];
int a[100086];
bitnode* pre=NULL;//当前前驱
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
				ln->ltag=0;
				ln->rtag=0;  
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
				rn->ltag=0;
				rn->rtag=0; 
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

//中序遍历中第一个被访问节点 
bitnode* firstnode(bitnode* p)//p为根 
{
	//最左下结点
	while(p->ltag==0&&p!=NULL)//有左孩子 ，p可能第一个所以是null 
	{
		p=p->lchild;//最左下 
	} 
	return p; 
}
//p后续
bitnode* nextnode(bitnode* p)//右子树最左下 
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
//中序遍历中最后被访问节点 
bitnode* lastnode(bitnode* p)//p为根 
{
	//最右下结点
	while(p->rtag==0&&p!=NULL)//有右孩子 
	{
		p=p->rchild;//最右下 
	} 
//	cout<<p<<endl; 
	return p; 
}
//p前驱 
bitnode* prenode(bitnode* p)//右子树最左下 
{
	if(p->ltag==0)//有右子树 
	{
		return lastnode(p->lchild);
	} 
	else 
	{
		return p->lchild;//直接后继 
	 } 
}
//创造线索二叉树 
void inthr(bitnode* p)
{
	if(p!=NULL)
	{//左根右 
		//cout<<p->lchild->data<<endl; 
		inthr(p->lchild);//左子树
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
		inthr(p->rchild); 
	}
	else
	return;
}
void cinthr(bitree& t)
{
	pre=NULL;//初始化
	if(t!=NULL)//非空二叉树线索化 
	{
		inthr(t);
		if(pre->rchild==NULL)//处理最后一个节点
		{
			pre->rtag=1; 
		 } 
	} 
}
void tprint(bitree& root)
{
	int front=0,rear=1;
	q1[0]=root;
	while(front!=rear)
	{
		int n=rear-front;
		//cout<<" n"<<n<<endl;
		for(int i=0;i<n;i++)
		{
			bitnode* temp=q1[front];
			front++;//出列 
			if(temp!=NULL)
			{
				//cout<<"temp:"<<temp->data<<"  ltag"<<temp->ltag<<endl;
				/*if(front!=0)
				{
					cout<<" ";
				}*/
				
				bitnode* tpre= prenode(temp);
				bitnode* tnext= nextnode(temp);
				if(tpre==NULL)
				{
					cout<<"0 ";
				}
				else
				{
					cout<<tpre->data<<" ";
				}
				if(tnext==NULL)
				{
					cout<<"0 ";
				}
				else
				{
					cout<<tnext->data<<" ";
				}
				if(temp->lchild!=NULL&&temp->ltag==0)//左右节点入队（判断有无左右孩子） 
				{
					q1[rear]=temp->lchild;
					rear++;
				}
				if(temp->rchild!=NULL&&temp->rtag==0)
				{
					q1[rear]=temp->rchild;	
					//cout<<rear<<"rc"<< temp->rchild->data<<endl;
					rear++;
					//cout<<"r"<<rear<<endl;
				}
				
			
			}
			
			
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
		pre=NULL;
		memset(a,0,sizeof(a));
		memset(q,0,sizeof(q));
		cbtree(t);
		cinthr(t);
		memset(q1,0,sizeof(q1));
		tprint(t) ;
	} 

    return 0;
}
