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
//弧节点
typedef struct arcnode 
{
	int adjvex;//顶点位置
	struct arcnode *next;//指向下一条弧 
}arcnode; 
//邻接表存储 
typedef struct
{
	arcnode* adjlist[MAXSIZE];//指向第一条依附该顶点的
	int vexnum, arcnum;  //结点数，边的个数 
	
}graph;
//队列 
typedef struct sque 
{
    int data[MAXSIZE];
	int front,rear;
}sque;
//栈 
typedef struct
{
	int data[MAXSIZE];
	int top;//栈顶指针 
}sqstack;
graph g;
sque q;
int count[10086];
bool visited[MAXSIZE];//访问标记数组 
//构造邻接表结构的图G
void createg(graph &g)
{
	int beg,end;
	arcnode *s;
	//初始化 
	for(int i=1;i<=g.vexnum;i++)
	{
		g.adjlist[i]=NULL;
	}
	if (g.arcnum == 0)
	{
		cout << "没有边" << endl;
	}
	else
	{
		for(int i=1;i<=g.arcnum;i++)
		{
			cin >> beg >> end;                                //输入弧的起点和终点
			s = (arcnode *)malloc(sizeof(arcnode));
			s->next = g.adjlist[end];
			s->adjvex = beg;
			g.adjlist[end] = s;
			//无向图，插入两次
			s = (arcnode *)malloc(sizeof(arcnode));           //生成弧结点
			s->next = g.adjlist[beg];                    	  //插入到邻接表中
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
//第v个顶点的第一个邻接顶点
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
//第v个顶点的相对于u的下一个邻接顶点
int nexta(graph g,int v,int u)
{
	arcnode* p=g.adjlist[v];
	while(p->adjvex!=u)
	{
		p=p->next;
	}
	if(p->next==NULL)//可能是最后一个结点 
	{
		return 0;
	}
	else
	{
		return(p->next->adjvex); 
	}
}
//初始化 
void inits(sqstack &s)
{
	s.top=-1;
}
//判断是否为空 
bool emptys(sqstack& s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//入栈 
bool pushs(sqstack &s,int& x)
{
	if(s.top==MAXSIZE-1)//栈满报错
	{
		return false;	
	} 
	s.top++;//指针先加 
	s.data[s.top]=x;//新元素入栈 
	return true;
}
//出栈 
bool pops(sqstack &s,int& x)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
	x=s.data[s.top];//栈顶元素出栈 
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
	x=s.data[s.top];//栈顶元素出栈 
	return true;
}
 //队列初始化
void initq(sque &q)
{
	q.rear=q.front=0;
}
//判断队列是否空
bool emptyq(sque &q)
{
	if(q.rear==q.front)
		return true;
	else
		return false;
}
//入队 
bool enq(sque &q,int &x)
{
	if((q.rear+1)% MAXSIZE==q.front)//队满报错 
	{
		return false;
	}
	q.data[q.rear]=x;//新元素入队尾 
	q.rear=(q.rear+1)%MAXSIZE;//队尾指针+1取模 
	return true;
}
//出队 
bool deq(sque &q,int &x)
{
	if(q.rear==q.front)//队空报错 
	{
		return false;
	}
	x=q.data[q.front];
	q.front=(q.front+1)%MAXSIZE;//队头指针+1取模 
	return true;
}
//对g深度优先（栈） 
void dfstra(graph g)
{
	sqstack s;
	cout<<"dfs 结果："<<endl; 
	//标记初始化
	memset(visited,false,sizeof(visited));
	inits(s);
	for(int v=1;v<=g.vexnum;v++)//从1开始遍历 
	{
		if(!visited[v])//对每个连通分量分别用dfs
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
					if(!visited[w])//w为v的尚未访问结点 
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
//对g广度优先
void bfstra(graph g)
{
	cout<<"bfs 结果："<<endl; 
	memset(visited,false,sizeof(visited));//初始化
	initq(q);
	for(int i=1;i<=g.vexnum;i++)
	{
		if(!visited[i])
		{
			visited[i]=true;
			cout<<i<<" ";
			enq(q,i);//和i相连的放入队列 
			while(!emptyq(q))//队列非空
			{
				int u;
				deq(q,u);//将队头元素出队列
				//对u的尚未访问的邻接顶点访问并入队
				for(int w=firsta(g,u);w>0;w=nexta(g,u,w))
				{
					if(!visited[w])//w为v的尚未访问结点 
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
	cout << "输入结点数和边数:" << endl;
	cin >> g.vexnum >> g.arcnum;

	cout << "输入边:" << endl;
	createg(g);

	dfstra(g);
	bfstra(g);
    return 0;
}
