#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct lnode
{
	int value;//�������Ԫ�� 
	bool isempty;//����Ƿ�� 
}tnode;
tnode t[MAXSIZE];
//�ӵ�һ���洢 
void tinit()
{
	for(int i=0;i<MAXSIZE;i++)
	{
		t[i].isempty=true; 
	}	
}
void ctree()
{ 
/* �������������������н���ֵ(�ַ��ͻ�����), ����˳��
�洢�Ķ�����t */
	int i=0;
	tinit(); /* ����ն�����T */
	printf("0��ʾ�ս�㣬��999����");
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
