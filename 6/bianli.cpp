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
		
		return (l>r)?l+1:r+1;//�����=max(��������ȣ����������)+1 
	}
} 
void preorder(bitree t)
{
	if(t!=NULL)
	{
		visit(t);//���ʸ��ڵ� 
		preorder(t->lchild);//���������� 
		preorder(t->rchild); //���������� 
	}
}
void inorder(bitree t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);//���������� 
		visit(t);//���ʸ��ڵ�
		inorder(t->rchild);//���������� 
	}
}
void postorder(bitree t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);//���������� 
		postorder(t->rchild);//����������
		visit(t);//���ʸ��ڵ� 
	}
}
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
		int n=rear-front;//�����С 
		for(int i=0;i<n;i++)
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
//��ʽ���нڵ�
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
	x=p->data;//����ͷ���Ԫ�� 
	q.front->next=p->next;//�޸�ͷ����next
	if(q.rear==p)//���⴦�����һ����� 
	{
		q.rear=q.front;//�޸�rear 
	} 
	free(p);
	return true;
}
bool isempty(lque &q)
{
	return (q.rear==q.front);
}
//�������
void lorder(bitree t)
{
	lque q;
	//queue<bitnode>*q;
	qinit(q);//��ʼ�� 
	bitree p;
	enq(q,t);//���ڵ���� 
	while(!isempty(q))//���в��� 
	{
		deq(q,p);//��ͷ���� 
		visit(p);//���ʳ��Խڵ� 
		if(p->lchild!=NULL)
		{
			enq(q,p->lchild);//������� 
		}
		if(p->rchild!=NULL)
		{
			enq(q,p->rchild);//�Һ������ 
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
