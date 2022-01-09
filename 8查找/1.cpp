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
/*struct qnode
{
	bitree data[MAXSIZE];//存放树节点
	int deep[MAXSIZE];//结点所在层
	int locate[MAXSIZE];//打印节点位置
	int front,rear;//头指针，尾指针 
}qn; */

char ch;
bitree t;
int k;//测试组数
int ans; 
bitree q[10086];
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
//计算结点的层次
int tlevel(bitree& t,int data)
{
    bitree dangqian;
    int level1;
    if(t==NULL)
    {
    //	cout<<"00000"<<endl;
        return (-1);
    }
    else
    {
        dangqian=t;
        level1=0;
        while(dangqian)
        {
            level1++;
            if(dangqian->data>data)
            {
                dangqian=dangqian->lchild;
            }
            else if(dangqian->data<data)
            {
                dangqian=dangqian->rchild;
            }
            else
            {
                return level1;
            }
        }
    }
    return -1;
}
 

int main()
{
	cin>>k;
	while(k--)
	{
		ans=0;
		int shuru=0;
		memset(a,0,sizeof(a));
		memset(q,0,sizeof(q));
		cin>>shuru;
		cbtree(t);
		
		cout<<tlevel(t,shuru)<<endl;
			
	} 
	
    return 0;
}
