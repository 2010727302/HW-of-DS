#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
/*
 * 栈 与 队列 两个栈 一个充当停车场 另一个保存出栈的元素顺序 队列用于存放排队的车
 * 另外每一组输入数据包括三个数据项：汽车“到达”或“离去”信息、汽车牌照号码及到达或离去的时刻
 */
using namespace std;
char str[100086];
char info;
int n;
typedef struct
{
	int chepai[MAXSIZE];
	int shijian[MAXSIZE];
	int top;//栈顶指针 
}sqstack;
sqstack s;
struct lnode 
{
    int chepai;
    struct lnode* next;
};
typedef struct lnode* linklist;
typedef struct
{
	lnode *front,*rear;
	int len;
}lque;
lque q;

//初始化 
void inits(sqstack &s)
{
	s.top=-1;
}
//栈空 
bool emptys(sqstack s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//入栈 
bool pushs(sqstack &s,int& che,int& time)
{
	
	s.top++;//指针先加 
	s.chepai[s.top]=che;//新元素入栈 
	s.shijian[s.top]=time;
	cout<<che<<"停在"<<s.top+1<<endl;
	//cout<<"che"<<s.chepai[s.top]<<endl;
	//cout<<s.shijian[s.top]<<endl;
	return true;
}
//出栈 
bool pops(sqstack &s,int& che,int &time)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
	time=s.shijian[s.top];//栈顶元素出栈
	che=s.chepai[s.top]; 
	s.top--;//指针再减 
	return true;
}
//查栈顶元素 
bool gets(sqstack &s,int& x)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
//	x=s.data[s.top];//栈顶元素出栈 
	return true;
}

//初始化 
void initq(lque &q)
{
	q.front=q.rear=(lnode*)malloc(sizeof(lnode));
	q.front->next=NULL;
}
//入队 
void enq(lque &q,int x)
{
	lnode* s=(linklist)malloc(sizeof(lnode));
	s->chepai=x;
	s->next=NULL;
	q.rear->next=s;
	q.rear=s;
	q.len++;
	cout<<x<<"停在便道"<<q.len<<endl; 
	
}
//出队 
bool deq(lque &q,int& x)
{
	if(q.front==q.rear)
	{
		return false;
	}
	lnode *p=q.front->next;
	x=p->chepai;//返回头结点元素 
	q.front->next=p->next;//修改头结点的next
	if(q.rear==p)//特殊处理最后一个结点 
	{
		q.rear=q.front;//修改rear 
	} 
	free(p);
	return true;
}
int main()
{
	cout<<"输入停车场大小"<<endl;
	cin>>n;
	inits(s);
	initq(q); 
	while(1)
	{
		cout<<"输入信息："<<endl; 
		cin>>info;
		if(info=='E')
		{
			break;
		}
		else
		{
			if(info=='A')//有车停入 
			{
				cout<<"输入车牌和时间"<<endl;
				int che=0,time=0;
				cin>> che>>time;
				
				if(s.top==n-1)//栈满进入便道 
				{
					cout<<"停车场已满,请暂时停在便道"<<endl;
					enq(q,che);
				}
				else
				{
					pushs(s,che,time);
				}
			}
			else if(info=='D')//有车开出 
			{
				int flag=1;
				cout<<"输入车牌和时间"<<endl;
				int che=0,letime=0,money=0;
				cin>>che>>letime;
				sqstack s1;
				inits(s1);
				int che1,time1;
			
				//车出停车场 
				while(s.top!=-1)
				{
					pops(s,che1,time1);
					if(che1==che)
					{
						flag=0;
						money=(letime-time1)*2;
						cout<<che1<<"需要付的钱"<<money<<endl;
						break;
					}
					pushs(s1,che1,time1);
				}
				while(s1.top!=-1)
				{
					pops(s1,che1,time1);
					pushs(s,che1,time1);
				}
				if(flag==0)
				{
					if(q.len!=0)
					{
						int che2;//入栈车牌 
						deq(q,che2);
						pushs(s,che2,letime);
						
					}
				}
				else
				{
					cout<<"停车场不存在该车"<<endl; 
				 } 
				
			}
		}
	}
    return 0;
}
