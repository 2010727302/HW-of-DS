#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct lnode 
{
    int key;//���� 
    int num;//��� 
    struct lnode* next;
};
typedef struct lnode* linklist;
int m;//����ֵ 
int renshu;//�������� 
linklist l,la; 

bool ldelete(linklist& l)
{
	//ע��߽� 
	for(int i=1;i<m;i++)
	{
		l=l->next; //�ҵ�Ҫɾ���Ľڵ�ǰһ����� 
	}
	m=l->key;
	//���ýڵ���� 
	//cout<<m<<;
	cout<<l->num<<" ";
	//ɾ���ýڵ�(��Ϊ���ֻ�ҵ�mǰһ���ڵ�ɾ����ǰ���Ļ�m=1������⣬ֻ�ܽ�����һ���ڵ��ǰһ��)
	lnode* p;
	p=l->next;
	//����һ���ڵ��ֵ�Ƶ�ǰһ����� 
	l->num=p->num;
	l->key=p->key;
	l->next=p->next; 
	free(p);//ɾ����һ���ڵ� 
	//l=l->next;
	return true;
}


int main()
{
	cin>>m; 
	cin>>renshu; 
	//���������� 
	l=(linklist)malloc(sizeof(struct lnode));
	cin>>l->key;
	l->num=1;
	la=l;//���ͷ��� 
	l->next=NULL;
	for(int i=2;i<=renshu;i++)
	{
		lnode* q=(linklist)malloc(sizeof(struct lnode));
		l->next=q;
		q->num=i;
		cin>>q->key;
		l=q;
	}
	l->next=la;
	l=la;//�γ�ѭ���б� 
	for(int i=1;i<=renshu;i++)
	//���������Ĵ��� ����ʾ�������� 
	{
		ldelete(l);
	}
	
    return 0;
}
