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
	struct bitnode *lchild,*rchild;//���Һ���ָ�� 
}bitnode,*bitree;
char ch;
bitree t;
int k;//��������
int ans; 
bitree q[10086];
int a[100086];
//������
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
	//��������
	root=(bitree)malloc(sizeof(bitnode));
	root->data=a[0];
	root->lchild=NULL;
	root->rchild=NULL;
	int front=0,rear=1;//���� 	
	q[0]=root;
	int shuzu=1; 
	while(rear!=front)//���в�Ϊ��
	{
		//int n=rear-front;//�����С 
		//for(int i=0;i<n;i++)
		{
			bitree temp=q[front];//���нڵ� 
			front++;
			int lt=a[shuzu];//��ڵ� 
			shuzu++;
			int rt=a[shuzu];//�ҽڵ� 
			shuzu++;
			if(lt!=0)
			{
				bitnode *ln=(bitree)malloc(sizeof(bitnode));
				ln->data=lt;
				temp->lchild=ln;//���ӽ������ 
				q[rear]=ln;//��ڵ���� 
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
				temp->rchild=rn;//���ӽ������ 
				q[rear]=rn;//�ҽڵ���� 
				rear++;
			}
			else
			{
				temp->rchild=NULL;
			}
		}
	} 
}

//��Ҷ�� 
int leaf(bitree &t)
{
	if(t==NULL)//��ָ�뷵��0 
	{
		//cout<<"1"<<endl;
		return 0;
	}
	else if(t->lchild==NULL&&t->rchild==NULL)//����������Ҷ�ӽڵ����Ϊ0,������һ��Ҷ�ӽڵ�
	{
		//cout<<t->data<<endl;
		return 1;
	}
	else//��������������Ҷ�ӽڵ����
	{
		
		return (leaf(t->lchild)+leaf(t->rchild));
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
		ans=leaf(t);
		cout<<ans<<endl;	
	} 
	
    return 0;
}
