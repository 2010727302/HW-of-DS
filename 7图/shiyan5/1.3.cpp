#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
//8 9
//1 2 1 3 2 4 2 5 5 8 4 8 3 7 3 6 6 7
//1 0
//5 7
//1 2 1 5 2 5 2 3 2 4 3 4 4 5
//���ڵ�
typedef struct arcnode 
{
	int adjvex;//����λ��
	struct arcnode *next;//ָ����һ���� 
}arcnode; 
//�ڽӱ�洢 
typedef struct
{
	arcnode* adjlist[MAXSIZE];//ָ���һ�������ö����
	int vexnum, arcnum;  //��������ߵĸ��� 
	
}graph;
//���� 
typedef struct sque 
{
    int data[MAXSIZE];
	int front,rear;
}sque;
//ջ 
typedef struct
{
	int data[MAXSIZE];
	int top;//ջ��ָ�� 
}sqstack;
graph g;
sque q;
int count[10086];
bool visited[MAXSIZE];//���ʱ������ 
//�����ڽӱ�ṹ��ͼG
void createg(graph &g)
{
	int beg,end;
	arcnode *s;
	//��ʼ�� 
	for(int i=1;i<=g.vexnum;i++)
	{
		g.adjlist[i]=NULL;
	}
	if (g.arcnum == 0)
	{
		cout << "û�б�" << endl;
	}
	else
	{
		for(int i=1;i<=g.arcnum;i++)
		{
			cin >> beg >> end;                                //���뻡�������յ�
			s = (arcnode *)malloc(sizeof(arcnode));
			s->next = g.adjlist[end];
			s->adjvex = beg;
			g.adjlist[end] = s;
			//����ͼ����������
			s = (arcnode *)malloc(sizeof(arcnode));           //���ɻ����
			s->next = g.adjlist[beg];                    	  //���뵽�ڽӱ���
			s->adjvex = end;
			g.adjlist[beg] = s; 	
		}
		s = (arcnode *)malloc(sizeof(arcnode)); 
		for(int i=1;i<=g.vexnum;i++)
		{
			s=g.adjlist[i];
			cout<<i<<":";
			while(s)
			{
				cout<<s->adjvex<<" ";
				s=s->next;
				count[i]++;
			}
			cout<<endl;
		}
	} 
	
}
//��v������ĵ�һ���ڽӶ���
int firsta(graph g,int v)
{
	if(!g.adjlist[v])
	{
		return 0;
	}
	else
	{
		return (g.adjlist[v]->adjvex);
	}
}
//��v������������u����һ���ڽӶ���
int nexta(graph g,int v,int u)
{
	arcnode* p=g.adjlist[v];
	while(p->adjvex!=u)
	{
		p=p->next;
	}
	if(p->next==NULL)//���������һ����� 
	{
		return 0;
	}
	else
	{
		return(p->next->adjvex); 
	}
}
//��ʼ�� 
void inits(sqstack &s)
{
	s.top=-1;
}
//�ж��Ƿ�Ϊ�� 
bool emptys(sqstack& s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//��ջ 
bool pushs(sqstack &s,int& x)
{
	if(s.top==MAXSIZE-1)//ջ������
	{
		return false;	
	} 
	s.top++;//ָ���ȼ� 
	s.data[s.top]=x;//��Ԫ����ջ 
	return true;
}
//��ջ 
bool pops(sqstack &s,int& x)
{
	if(s.top==-1)//ջ�ձ���
	{
		return false;	
	} 
	x=s.data[s.top];//ջ��Ԫ�س�ջ 
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
	x=s.data[s.top];//ջ��Ԫ�س�ջ 
	return true;
}
 //���г�ʼ��
void initq(sque &q)
{
	q.rear=q.front=0;
}
//�ж϶����Ƿ��
bool emptyq(sque &q)
{
	if(q.rear==q.front)
		return true;
	else
		return false;
}
//��� 
bool enq(sque &q,int &x)
{
	if((q.rear+1)% MAXSIZE==q.front)//�������� 
	{
		return false;
	}
	q.data[q.rear]=x;//��Ԫ�����β 
	q.rear=(q.rear+1)%MAXSIZE;//��βָ��+1ȡģ 
	return true;
}
//���� 
bool deq(sque &q,int &x)
{
	if(q.rear==q.front)//�ӿձ��� 
	{
		return false;
	}
	x=q.data[q.front];
	q.front=(q.front+1)%MAXSIZE;//��ͷָ��+1ȡģ 
	return true;
}
//��g������ȣ�ջ�� 
void dfstra(graph g)
{
	sqstack s;
	cout<<"dfs �����"<<endl; 
	//��ǳ�ʼ��
	memset(visited,false,sizeof(visited));
	inits(s);
	for(int v=1;v<=g.vexnum;v++)//��1��ʼ���� 
	{
		if(!visited[v])//��ÿ����ͨ�����ֱ���dfs
		{
			visited[v]=true;
			cout<<v<<" ";
			pushs(s,v);
			while(!emptys(s))
			{
				int w,cishu=0;
				gets(s,v);
				for(w=firsta(g,v);w>0;w=nexta(g,v,w))
				{
					//cout<<"w"<<w<<endl;
					if(!visited[w])//wΪv����δ���ʽ�� 
					{
						cout<<w<<" " ;
						visited[w]=1;
						pushs(s,w);
						break;
					} 
				}
				//gets(s,v);
		
				if(w==0)
				{
					pops(s,v);
				}
				/*//gets(s,v);
				int data=nexta(g,v,w);
				cout<<"data"<<data<<endl;
				if(data==0)
				{
					pops(s,v);
				}*/
					
			}
		}
	}
	cout<<endl;
 } 
//��g�������
void bfstra(graph g)
{
	cout<<"bfs �����"<<endl; 
	memset(visited,false,sizeof(visited));//��ʼ��
	initq(q);
	for(int i=1;i<=g.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=true;
			cout<<i<<" ";
			enq(q,i);//��i�����ķ������ 
			while(!emptyq(q))//���зǿ�
			{
				int u;
				deq(q,u);//����ͷԪ�س�����
				//��u����δ���ʵ��ڽӶ�����ʲ����
				for(int w=firsta(g,u);w>0;w=nexta(g,u,w))
				{
					if(!visited[w])//wΪv����δ���ʽ�� 
					{
						visited[w]=true;
						cout<<w<<" ";
						enq(q,w);
					} 
				}
			}  
		}
		cout<<endl;
		
	}
}
int main()
{
	cout << "���������ͱ���:" << endl;
	cin >> g.vexnum >> g.arcnum;

	cout << "�����:" << endl;
	createg(g);

	dfstra(g);
	bfstra(g);
    return 0;
}
