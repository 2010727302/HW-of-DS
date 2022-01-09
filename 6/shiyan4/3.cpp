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
	char data;//�������Ԫ�� 
	struct bitnode *lchild,*rchild;//���Һ���ָ�� 
}bitnode,*bitree;
char ch;
bitree t;
int k;//��������
int ans; 
int a[100086];
//������
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
//���� 
void visit(bitree& t)
{
	printf("%c",t->data);
}
//���� 
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
				printf("%c",p->data);//���ʸ��ڵ�
				s.push(p);
				p=p->lchild;//����������
			}
	
			p=s.top();
			s.pop();
			p=p->rchild;//���������� 
		
		}
		 
		
	}
}
//���� 
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
				p=p->lchild;//����������
			}
	
			p=s.top();
			s.pop();
			printf("%c",p->data);//���ʸ��ڵ�
			p=p->rchild;//���������� 
		
		}
		 
		
	}
}
//���� 
void postorder(bitree& t)
{

	if(t!=NULL)
	{
		bitnode* p=t;
		stack<bitnode*> s;
		bitnode* last=t;//�ϴη��ʵ� 
		//s.push(p);
		while(!s.empty()||p)
		{
		
			while(p)
			{
				s.push(p);
				p=p->lchild;//����������
			}
			if(!s.empty())
			{
				p=s.top();
				//if(p->rchild==NULL||p->rchild==last)
				if( (p->lchild == NULL && p->rchild == NULL) || (p->rchild == NULL && last == p->lchild) || (last == p->rchild) )
				{	//Ҷ�ڵ�����Һ��Ӷ������� 
					printf("%c",p->data);//���ʸ��ڵ�
					s.pop();//ջ��Ԫ�س�ջ
					last=p;//���ʹ�p�� 
					p=NULL;//����ǰ����ÿ�
				}
				else
				{
					p=p->rchild;//���������� 
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
	cout<<"�����������Ϊ��"<<endl;
	preorder(t);
	cout<<endl; 
	cout<<"�����������Ϊ��"<<endl;
	inorder(t); 
	cout<<endl; 
	cout<<"�����������Ϊ��"<<endl;
	postorder(t); 
	cout<<endl; 

    return 0;
}
