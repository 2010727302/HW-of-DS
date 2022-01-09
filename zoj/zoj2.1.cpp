#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct lnode *list;
struct lnode
{
	int c,e;
	list link;
} ;
void attach(int c1,int e1,list *prear)
{
	list p;
	p=(list)malloc(sizeof(struct lnode));
	p->c=c1;
	p->e=e1;
	p->link=NULL;
	(*prear)->link=p;
	*prear=p;
	
}
void print(list p)
{
	int flag=0;
	if(!p)
	{
		cout<<0<<" "<<0;
		return;
	}
	while(p->link)
	{
		cout<<p->c<<" "<<p->e<<" ";
		p=p->link;
	}
	cout<<p->c<<" "<<p->e;
}
list read()
{
	list p,rear,t;
	int c,e,n;
	p=(list)malloc(sizeof(struct lnode));
	p->link=NULL;
	rear=p;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>e;
		attach(c,e,&rear);
	}
	t=p;
	p=p->link;
	free(t);
	return p;
}

list add(list p1,list p2)
{
	list p,rear,t1,t2,t;
	t1=p1,t2=p2;
	rear=(list)malloc(sizeof(struct lnode));	
	p=rear;
	while(t1&&t2)
	{
		if(t1->e==t2->e)
		{
			int sum=(t1->c)+(t2->c);
			if(sum)
			attach(sum,t1->e,&rear);
			t1=t1->link;
			t2=t2->link;
		}
		else if((t1->e)>t2->e)
		{
			attach(t1->c,t1->e,&rear);
			t1=t1->link;
		}
		else
		{
			attach(t2->c,t2->e,&rear);
			t2=t2->link;
		}
	}
	while(t1)
	{
		attach(t1->c,t1->e,&rear);
		t1=t1->link;
	}
	while(t2)
	{
		attach(t2->c,t2->e,&rear);
		t2=t2->link;
	}
	//rear->link=NULL;
	t=p;
	p=p->link;
	free(t);
	return p;
}
list mult(list p1,list p2)
{
	list p,rear,t1,t2,t;
	int c1,e1;
	if(!p1||!p2)
	{
		return NULL;
	}
	t1=p1,t2=p2;
	p=(list)malloc(sizeof(struct lnode));
	p->link=NULL;
	rear=p;
	while(t2)
	{
		attach(t1->c*t2->c,t1->e+t2->e,&rear);
		t2=t2->link;
	}
	t1=t1->link;
	while(t1)
	{
		t2=p2;
		rear=p;
		while(t2)
		{
			e1=t1->e+t2->e;
			c1=t1->c*t2->c;
			while(rear->link&&rear->link->e>e1)//到前一项 
			{
				rear=rear->link;
			}
			if(rear->link&&rear->link->e==e1)
			{
				int sum=(rear->link->c)+c1;
				if(sum)
				{
					rear->link->c=sum;
				}
				else//delete 
				{
					t=rear->link;
					rear->link=t->link;
					free(t); 
				}
			}
			else
			{
				t=(list)malloc(sizeof(struct lnode));
				t->c=c1;
				t->e=e1;
				t->link=rear->link;
				rear->link=t;
				rear=rear->link;
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
	t2=p;
	p=p->link;
	free(t2);
	return p;
}
int main()
{
	list p1,p2,pp,ps;
	p1=read();
	p2=read();
	pp=mult(p1,p2);
	print(pp);
	cout<<endl;
	ps=add(p1,p2);
	print(ps);
	return 0;
 } 
