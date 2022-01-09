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
	int deept;
	struct bitnode *lchild,*rchild;//���Һ���ָ�� 
}bitnode,*bitree;
char ch;
int dn;//�������߶� 
bitree t;
int k;//��������
int ans; 
int a[100086];

//abc  de g  f   
//ab d  ce f   
//������
void cbtree(bitree &t)
{
	scanf("%c",&ch); // abdg   e  c f    
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

//������� 
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
//rdl 
void rdl(bitree& t,int n)
{
	if(t!=NULL)
	{
		rdl(t->rchild,n+1); //���������� 
		//visit(t);
	
		for(int i=0;i<n;i++)
		{
			//cout<<"    ";
			printf("\t");
		 } 
		printf("%2c\n",t->data);//���ʸ��ڵ�
		rdl(t->lchild,n+1);//���������� 
		
	}
}


int main()
{
	cbtree(t);
	//cout<<"��ȣ�"<<endl;
	dn=dtree(t);
	//cout<<dn<<endl;
	rdl(t,0);
	
    return 0;
}
