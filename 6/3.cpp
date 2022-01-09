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
	int ltag,rtag;//����������־ 
}bitnode,*bitree;
char ch;
bitree t;
int k;//��������
int ans; 
bitree q[10086],q1[10086];
int a[100086];
bitnode* pre=NULL;//��ǰǰ��
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
				ln->ltag=0;
				ln->rtag=0;  
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
				rn->ltag=0;
				rn->rtag=0; 
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

//��������е�һ�������ʽڵ� 
bitnode* firstnode(bitnode* p)//pΪ�� 
{
	//�����½��
	while(p->ltag==0&&p!=NULL)//������ ��p���ܵ�һ��������null 
	{
		p=p->lchild;//������ 
	} 
	return p; 
}
//p����
bitnode* nextnode(bitnode* p)//������������ 
{
	if(p->rtag==0)//�������� 
	{
		return firstnode(p->rchild);
	} 
	else 
	{
		return p->rchild;//ֱ�Ӻ�� 
	 } 
}
//�����������󱻷��ʽڵ� 
bitnode* lastnode(bitnode* p)//pΪ�� 
{
	//�����½��
	while(p->rtag==0&&p!=NULL)//���Һ��� 
	{
		p=p->rchild;//������ 
	} 
//	cout<<p<<endl; 
	return p; 
}
//pǰ�� 
bitnode* prenode(bitnode* p)//������������ 
{
	if(p->ltag==0)//�������� 
	{
		return lastnode(p->lchild);
	} 
	else 
	{
		return p->lchild;//ֱ�Ӻ�� 
	 } 
}
//�������������� 
void inthr(bitnode* p)
{
	if(p!=NULL)
	{//����� 
		//cout<<p->lchild->data<<endl; 
		inthr(p->lchild);//������
		if(p->lchild==NULL)//�������գ�����ǰ�� 
		{
			p->lchild=pre;
			p->ltag=1; 
		}
		if(pre!=NULL&&pre->rchild==NULL)
		{
			pre->rchild=p;//���
			pre->rtag=1;
		}
		pre=p;
		//������
		inthr(p->rchild); 
	}
	else
	return;
}
void cinthr(bitree& t)
{
	pre=NULL;//��ʼ��
	if(t!=NULL)//�ǿն����������� 
	{
		inthr(t);
		if(pre->rchild==NULL)//�������һ���ڵ�
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
			front++;//���� 
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
				if(temp->lchild!=NULL&&temp->ltag==0)//���ҽڵ���ӣ��ж��������Һ��ӣ� 
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
