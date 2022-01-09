#include <cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct lnode 
{
    int data;
    struct lnode* next;
};
typedef struct lnode* linklist;
linklist la,lb,lc;
int a[10086] = {10, 1, 4, 5, 7, 9, 11, 13, 15, 18, 19};
int b[10086] = {8, 3, 4, 6, 7, 10, 15, 18, 20};
int i;
//初始化空链表 
bool linit(linklist& l)
{
	l=(linklist)malloc(sizeof(struct lnode));
	if(l==NULL)return false;
	l->next=NULL;
	return true;
}
//判断链表是否为空 
bool empty(linklist l)
{
	return (l=NULL);
}
//按位查找
lnode* find(linklist& l,int i,int& e)
{
	if(i<0)return NULL;
	lnode* p;
	int j=0;//current p point to
	p=l;
	while(p!=NULL&&j<i-1)//find i-1
	{
		p=p->next;
		j++;
	}
	e=p->data;
	return p;
 } 
 //后插
bool ninsert(lnode* p,int e)
{
	if(p==NULL)//i not valid
	{
		return false;
	}	
	lnode* s=(lnode*)malloc(sizeof(lnode));
	if(s==NULL)//malloc fail
	{
		return false;
	}
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
} 
//在第i个位置插入元素e  
bool linsert(linklist& l,int i,int e)
{
	if(i<1)
	{
		return false;
	}	
	lnode* p=find(l,i-1,e);
	return ninsert(p,e);
}

//前插p之前 
bool pinsert(lnode* p,int e) 
{
	if(p==NULL)//i not valid
	{
		return false;
	}	
	lnode* s=(lnode*)malloc(sizeof(lnode));
	if(s==NULL)//malloc fail
	{
		return false;
	}
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data=e;
	return true;
}
//删除
bool ldelete(linklist& l,int i,int e) 
{
	if(i<1)
	{
		return false;
	}	
	lnode* p=find(l,i-1,e);
	if(p==NULL)
	{
		return false;
	}
	if(p->next==NULL)
	{
		return false;
	}
	lnode* q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
}

 //按值查找 
 lnode* locate(linklist& l,int e) 
 {
	lnode* p=l->next;
	while(p!=NULL&&p->data!=e)
	{
		p=p->next;
	}
	
	return p;
 }
 //表长
 int len(linklist l)
{
	int len=0;
	lnode* p=l;
	while(p->next!=NULL)
	{
		p=p->next;
		len++; 
	}
	return len;
} 
void attach(int a,linklist *prear)
{
    linklist p;
    p=(linklist)malloc(sizeof(struct lnode*));
    p->data=a;
    p->next=NULL;
    (*prear)->next=p;
    *prear=p;
}
//头插 
linklist headi(linklist& l)
{
	lnode* s;
	int x;
	l=(linklist)malloc(sizeof(lnode));
	l->next=NULL;
	cin>>x;
	while(x!=9999)
	{
		s=(lnode*)malloc(sizeof(lnode));
		s->data=x;
		s->next=l->next;
		l->next=s;
		cin>>x;
	}
	return l;
}
//打印
void print(int e)
{
	
}
//逆置 
/*linklist reve(linklist& l)
{
	lnode* s;
	int x;
	l=(linklist)malloc(sizeof(lnode));
	l->next=NULL;
	cin>>x;
	while(x!=9999)
	{
		s=(lnode*)malloc(sizeof(lnode));
		s->data=x;
		s->next=l->next;
		l->next=s;
		cin>>x;
	}
	return l;
}*/
bool lmerge(linklist la,linklist lb,linklist &lc)
{
	lnode *pa,*pb,*prear;//尾项指针 
	if(la==NULL||lb==NULL)
	{
		return false;
	}
	pa=la->next;
	pb=lb->next;
	prear=lc;
	lc=la;
	lc->next=NULL;
	while(pa->next!=NULL&&pb->next!=NULL)
	{
		if(pa->data>=pb->data)
		{
			prear->next=pa;
			prear=pa;
			pa=pa->next;
		}
		else
		{
			prear->next=pb;
			prear=pb;
			pb=pb->next;
		}
	}
	while(pa->next)
	{
		prear->next=pa;
		pa=pa->next;
	}
	while(pb->next)
	{
		prear->next=pb;
		pb=pb->next;
	}
	prear->next=NULL;
	return true;
}
void lprint(linklist l)
{
	lnode* p;
	if(l==NULL||l->next==NULL)
	{
		return;
	}
	p=l->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	linit(la);
	linit(lb);
	linit(lc);
	//linklist pa=la;
	//linklist pb=lb;
	for(int i=1;i<=a[0];i++)
	{
		ninsert(la,a[i]);
		//pa=la->next;
		//cout<<a[i]<<" ";
	}
	for(int i=1;i<=b[0];i++)
	{
		ninsert(lb,b[i]);
		//pb=lb->next;
	}
	lprint(la);
	lprint(lb);
	lmerge(la,lb,lc);
	lprint(lc);
    return 0;
}
