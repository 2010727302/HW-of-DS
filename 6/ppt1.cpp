#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
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
		//visit(t);//���ʸ��ڵ� 
		printf("%c",t->data);
		preorder(t->lchild);//���������� 
		preorder(t->rchild); //���������� 
	}
}
//���� 
void inorder(bitree& t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);//���������� 
		visit(t);//���ʸ��ڵ�
		inorder(t->rchild);//���������� 
	}
}
//���� 
void postorder(bitree& t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);//���������� 
		postorder(t->rchild);//����������
		visit(t);//���ʸ��ڵ� 
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
		return ans;//�����=max(��������ȣ����������)+1 
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
	cout<<"�����������Ϊ��"<<endl;
	preorder(t);
	cout<<endl; 
	cout<<"�����������Ϊ��"<<endl;
	inorder(t); 
	cout<<endl; 
	cout<<"�����������Ϊ��"<<endl;
	postorder(t); 
	cout<<endl; 
	cout<<"�߶ȣ�"<<endl;
	cout<<dtree(t)<<endl;
	//cout<<"�����������Ϊ��"<<endl;
    return 0;
}
