#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
//二叉排序树结点
typedef struct bstnode
{
	int key;//结点数据元素 
	struct bstnode *lchild,*rchild;//左右孩子指针 
}bstnode,*bstree;
//用于树的打印 
struct qnode
{
	bstree data[MAXSIZE];//存放树节点
	int deep[MAXSIZE];//结点所在层
	int locate[MAXSIZE];//打印节点位置
	int front,rear;//头指针，尾指针 
}q; 
bstree t,p; 
int shuru2,shuru3,chazhao;
//12 7 17 11 16 2 13 9 21 4 0
//找值为key的结点 （非递归 
bstnode *bsearch(bstree t,int key)
{
	while(t!=NULL&&key!=t->key)
	{
		if(key<t->key)//<在左子树找 
		{
			t=t->lchild;
		}
		else//>在右子树找 
		{
			t=t->rchild; 
		} 
		chazhao++;
	}
	//失败返回NULL 
	return t;
}
//找值为key的结点 （递归 
bstnode *bsearch2(bstree t,int key)
{
	if(t==NULL)//失败返回NULL 
	return NULL;
	if(key==t->key)//成功 
	return t;
	else if(key<t->key)//<在左子树找 
	{
		return bsearch(t->lchild,key);
	}
	else//>在右子树找 
	{
		return bsearch(t->rchild,key);
	} 
	
	return t;
}
//插入值为key的结点 递归 
int binsert(bstree& t,int key)
{
	if(t==NULL)//失败
	{
		t=(bstree)malloc(sizeof(bstnode));
		t->key=key;
		t->lchild=t->rchild=NULL;
		return 1; //插入成功 
	}

	if(key==t->key)//存在相同，插入失败 
	return 0;
	else if(key<t->key)//<在左子树找 
	{
		binsert(t->lchild,key);
	}
	else//>在右子树找 
	{
		binsert(t->rchild,key);
	} 

}
//按照数组关键字建立二叉排序树 
void cbst(bstree &t)
{
	t=NULL;//初始t空
	int shuru;
	cin>>shuru;
	while(shuru!=0)//依次将每个关键字插入二叉排序树 
	{
		binsert(t,shuru);
		cin>>shuru;	
	} 
}
//遍历 
void btra(bstree& t)
{
	if(t==NULL)//数为空 
	{
		//cout<<"空树"<<endl;
		return;
	}
	if(t)
	{
		btra(t->lchild);//遍历左孩子
		cout<<t->key<<" ";
		btra(t->rchild);//遍历右孩子
	} 
}
//格式化打印
void bprint(bstree& t)
{
	int j=1,k=0;//层，层内位置 
	q.front=0,q.rear=1;//初始化 
	q.data[0]=t;//将根节点相关信息加入队列 
	q.deep[0]=1;
	q.locate[0]=30;
	cout<<"\t"<<endl; 
	while(q.front!=q.rear)
	{
		//int n=q.rear-q.front;
		//cout<<" n"<<n<<endl;
		bstree temp=q.data[q.front];
		int i=q.deep[q.front];//当前层，层内位置 
		int nloc=q.locate[q.front];
		//cout<<"  "<<endl;
		if(j<i)//进新层换行 
		{
			cout<<endl<<endl<<endl;
			//cout<<endl;
			j++;
			k=0; 
			//while(k<(nloc))//制层内位置
			{
				//cout<<" ";
				//k++;	
			} 
		}
		while(k<(nloc+5))//控制层内位置
		{
			cout<<" ";
			k++;	
		} 
		cout<<temp->key;
		//cout<<":"<<i;
		if(temp->lchild)//有左孩子 ，入队
		{
			q.data[q.rear]=temp->lchild;//将相关信息加入队列 
			q.deep[q.rear]=i+1;
			q.locate[q.rear]=(int)(nloc-pow(2,(5-i)));
			//cout<<" "<<q.locate[q.rear];
			q.rear++;
		} 
		if(temp->rchild)//有右孩子 ，入队
		{
			q.data[q.rear]=temp->rchild;//将相关信息加入队列 
			q.deep[q.rear]=i+1;
			q.locate[q.rear]=(int)(nloc+pow(2,(5-i)));
			//cout<<" "<<q.locate[q.rear];
			q.rear++;
		} 
		q.front++;//出列 
		//cout<<"fr"<<front<<endl;
		
	}	
	cout<<endl;
 } 
//删除
bool bdelete(bstree& p)
{
	bstree q1,f,s;
	f=NULL;
	//查找key
	//cout<<p->key<<endl;
	// 删除p 
	if (!p->rchild&&!p->lchild)//叶子节点 
	{
		//cout<<0<<endl;
		p=NULL;
		//free(p);
	}
	else if (!p->rchild)//只有左孩子，左孩子代替 
	{
		q1=p; 
		p=p->lchild;
		//q1=p->lchild;
		//p->key=q1->key;
		free(q1);
	}
	else if (!p->lchild)//只有右孩子，右孩子代替 
	{
		q1=p; 
		p=p->rchild;//只需用结点 p 的右子树根结点代替结点 p 即可
		free(q1);
	}
	else//左右孩子均存在 
	{ 
		q1=p; 
		s=p->lchild;//p左孩子 
		while(s->rchild)//s为中序遍历前驱 
		{ 
			q1=s;
			s=s->rchild;
		} 
		p->key = s->key;
		//判断结点 p 的左子树 s 是否有右子树，分为两种情况讨论
		if( q1 != p ) 
		q1->rchild = s->lchild; //若有，则在删除直接前驱结点的同时，令前驱的左孩子结点改为 q 指向结点的孩子结点
		else
		q1->lchild = s->lchild; //否则，直接将左子树上移即可
		free(s);
	}
	return 1;
}
 //删除t
int bstdel(bstree&t,int key)
{
 	if(t==NULL)//不存在关键字等于key的数据元素
	return 0;
	if(key==t->key)//成功
	{
		bdelete(t);
		return 1;
	} 
	
	else if(key<t->key)//<在左子树找 
	{
		return bstdel(t->lchild,key);
	}
	else//>在右子树找 
	{
		return bstdel(t->rchild,key);
	} 
	
	return 1;
 }

int main()
{
	cout<<"创建排序二叉树："<<endl; 
	cbst(t); 
	
	cout<<"遍历二叉树："<<endl; 
	btra(t);
	cout<<endl;	
	cout<<"打印二叉树："<<endl;
	bprint(t);
	cout<<endl;
	cout<<"查找二叉树（输入你要查找的key）："<<endl;
	cin>>shuru2;
	p=bsearch(t,shuru2);
	if(p)
	{
		cout<<"该节点存在"<<endl;
		cout<<"次数："<<chazhao+1<<endl;
	}
	else
	{
		cout<<"该节点不存在"<<endl;
		cout<<"次数："<<chazhao+1<<endl;
	}
	cout<<"删除二叉树（输入你要查找的key）："<<endl;
	cin>>shuru3;
	int panduan=0;
	panduan=bstdel(t,shuru3);
	if(panduan)
	{
		cout<<"删除成功"<<endl; 
	} 
	else
	{
		cout<<"删除失败"<<endl; 
	}
	cout<<"遍历二叉树："<<endl; 
	btra(t);
	cout<<endl;	
	cout<<"打印二叉树："<<endl;
	bprint(t);
	cout<<endl;
    return 0;
}
