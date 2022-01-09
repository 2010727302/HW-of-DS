#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
/*
 * ջ �� ���� ����ջ һ���䵱ͣ���� ��һ�������ջ��Ԫ��˳�� �������ڴ���Ŷӵĳ�
 * ����ÿһ���������ݰ�������������������������ȥ����Ϣ���������պ��뼰�������ȥ��ʱ��
 */
using namespace std;
char str[100086];
char info;
int n;
typedef struct
{
	int chepai[MAXSIZE];
	int shijian[MAXSIZE];
	int top;//ջ��ָ�� 
}sqstack;
sqstack s;
struct lnode 
{
    int chepai,time;
    struct lnode* next;
};
typedef struct lnode* linklist;
typedef struct
{
	lnode *front,*rear;
	int len;
}lque;
lque q;
void inits(sqstack &s)
{
	s.top=-1;
}
bool emptys(sqstack s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//��ջ 
bool pushs(sqstack &s,int& che,int& time)
{
	
	s.top++;//ָ���ȼ� 
	s.chepai[s.top]=che;//��Ԫ����ջ 
	s.shijian[s.top]=time;
	cout<<che<<"ͣ��"<<s.top+1<<endl;
	//cout<<"s.top"<<s.top<<endl;
	//cout<<"che"<<s.chepai[s.top]<<endl;
	//cout<<s.shijian[s.top]<<endl;
	return true;
}
//��ջ 
bool pops(sqstack &s,int& che,int &time)
{
	if(s.top==-1)//ջ�ձ���
	{
		return false;	
	} 
	time=s.shijian[s.top];//ջ��Ԫ�س�ջ
	che=s.chepai[s.top]; 
	s.top--;//ָ���ټ� 
	return true;
}
//��ջ��Ԫ�� 
bool gets(sqstack &s,int& x)
{
	if(s.top==-1)//ջ�ձ���
	{
		return false;	
	} 
//	x=s.data[s.top];//ջ��Ԫ�س�ջ 
	return true;
}


void initq(lque &q)
{
	q.front=q.rear=(lnode*)malloc(sizeof(lnode));
	q.front->next=NULL;
}
void enq(lque &q,int x,int time1)
{
	lnode* s=(linklist)malloc(sizeof(lnode));
	s->chepai=x;
	s->time=time1;
	s->next=NULL;
	q.rear->next=s;
	q.rear=s;
	q.len++;
	cout<<x<<"ͣ�ڱ��"<<q.len<<endl; 
	
}
bool deq(lque &q,int& x,int& leti)
{
	if(q.front==q.rear)
	{
		return false;
	}
	lnode *p=q.front->next;
	x=p->chepai;//����ͷ���Ԫ�� 
	int det=leti-p->time;
	//cout<<det<<"det"<<endl;
	int qian=2*det;
	cout<<x<<"ͣ�ڱ��Ҫ����ǮΪ"<<qian<<endl; 
	q.front->next=p->next;//�޸�ͷ����next
	if(q.rear==p)//���⴦�����һ����� 
	{
		q.rear=q.front;//�޸�rear 
	} 
	free(p);
	return true;
}
void checkq(lque &q,int&che,int &letime)
{
	lnode *pr=q.front;
	//x=p->chepai;
	//int det=leti-p->time;
	while(pr->next->chepai!=che)
	{
		pr=pr->next;
	}
	lnode *p=pr->next;
	cout<<p->chepai<<"ǮΪ"<<2*(letime-p->time)<<endl;
	
	che=p->chepai;
	letime=p->time;
	if(p->next!=NULL)
	{
		pr->next=p->next;
		free(p);
	}
	else
	{
		pr->next=NULL;
		free(p);
	}
	 
}
int main()
{
	cout<<"����ͣ������С"<<endl;
	cin>>n;
	inits(s);
	initq(q); 
	while(1)
	{
		cout<<"������Ϣ��"<<endl; 
		cin>>info;
		if(info=='E')
		{
			break;
		}
		else
		{
			if(info=='A')
			{
				cout<<"���복�ƺ�ʱ��"<<endl;
				int che=0,time=0;
				cin>> che>>time;
				//cheΪ1��3�ͳ� ��2��4���� 
				if(s.top==n-1)//ջ�������� 
				{
					cout<<"ͣ��������,����ʱͣ�ڱ��"<<endl;
					enq(q,che,time);
				}
				else
				{
					pushs(s,che,time);
				}
			}
			else if(info=='D')
			{
				int flag=1;
				cout<<"���복�ƺ�ʱ��"<<endl;
				int che=0,letime=0,money=0;
				cin>>che>>letime;
				sqstack s1;
				inits(s1);
				int che1,time1;
			
				//����ͣ���� 
				while(s.top!=-1)
				{
					pops(s,che1,time1);
					if(che1==che)
					{
						flag=0;
						if(che==1||che==3)
						{
							money=(letime-time1)*5;
							cout<<che1<<"�ͳ���Ҫ����Ǯ"<<money<<endl;
							break;
						} 
						else if(che==2||che==4)
						{
							money=(letime-time1)*7.5;
							cout<<che1<<"������Ҫ����Ǯ"<<money<<endl;
							break;
						} 
						
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
						int che2;//��ջ���� 
						deq(q,che2,letime);
						pushs(s,che2,letime);
						
					}
				}
				else 
				{
					cout<<"���ڱ��"<<endl;
					checkq(q,che,letime) ;
				} 
				
			}
		}
	}
    return 0;
}
