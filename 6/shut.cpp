#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct lnode
{
	int value;//结点数据元素 
	bool isempty;//结点是否空 
}tnode;
tnode t[MAXSIZE];
//从第一个存储 
void tinit()
{
	for(int i=0;i<MAXSIZE;i++)
	{
		t[i].isempty=true; 
	}	
}
void ctree()
{ 
/* 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序
存储的二叉树t */
	int i=0;
	tinit(); /* 构造空二叉树T */
	printf("0表示空结点，输999结束");
	while(1) 
	{
		scanf("%d",&t[i].value);
		if(t[i].value==999) 
		{
			t[i].isempty=true;
			break; 
		}
		i++; 
	}
	cout<<i<<endl;
}
int main()
{
	ctree();
    return 0;
}
