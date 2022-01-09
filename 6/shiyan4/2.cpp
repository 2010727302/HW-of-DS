#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct bitnode
{
	char data;//结点数据元素 
	int deept;
	struct bitnode *lchild,*rchild;//左右孩子指针 
}bitnode,*bitree;
char ch;
int dn;//整棵树高度 
bitree t;
int k;//测试组数
int ans; 
int a[100086];

//abc  de g  f   
//ab d  ce f   
//创建树
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

//树的深度 
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
		return ans;//树深度=max(左子树深度，右子树深度)+1 
	}
} 
//rdl 
void rdl(bitree& t,int n)
{
	if(t!=NULL)
	{
		rdl(t->rchild,n+1); //访问右子树 
		//visit(t);
	
		for(int i=0;i<n;i++)
		{
			//cout<<"    ";
			printf("\t");
		 } 
		printf("%2c\n",t->data);//访问根节点
		rdl(t->lchild,n+1);//访问左子树 
		
	}
}


int main()
{
	cbtree(t);
	//cout<<"深度："<<endl;
	dn=dtree(t);
	//cout<<dn<<endl;
	rdl(t,0);
	
    return 0;
}
