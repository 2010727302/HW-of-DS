#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct lnode 
{
    double x,y;//坐标 
    char ncity[100];//城市名 
    
}city[10086];
typedef struct lnode* linklist;
int caozuo;//选择操作类型 
linklist la,lb,lc; 
int chengshishu=0;

//插入
void linsert()
{
	chengshishu++;
	cout<<"城市名"<<endl; 
	cin>>city[chengshishu].ncity;
	cout<<"城市坐标"<<endl;
	cin>>city[chengshishu].x>>city[chengshishu].y;
	
}
//创建新链表 
bool lcreate()
{
	int k;
	cout<<"输入创建城市数："<<endl;
	cin>>k;
	while(k)
	{
		linsert();//插入节点 
		k--;
		//cout<<k<<endl;
	}
	return true;
} 
bool lfind()
{
	int cha;
	double xx,yy;
	char ch[20];
	int flag=0;
	cout<<"1查城市"<<endl;
	cout<<"2查坐标"<<endl;
	cin>>cha;
	if(cha==1)
	{
		cout<<"输入坐标"<<endl; 
		cin>>xx>>yy;

		for(int i=1;i<=chengshishu;i++)
		{
			if(city[i].x==xx&&city[i].y==yy)
			{
				cout<<city[i].ncity<<endl;
				flag=1;
				break;
			}
		}

		if(!flag)//没找到该城市 
		{
			cout<<"不存在此城市"<<endl;
		}

	} 
	else if(cha==2)
	{
		cout<<"输入城市名"<<endl; 
		cin>>ch;
		for(int i=1;i<=chengshishu;i++)
		{
			if(strcmp(city[i].ncity,ch)==0)//strcmp比较两个字符串 
			{
				cout<<city[i].x<<","<<city[i].y<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<"不存在此城市"<<endl;
		}
	
	}
	return true;
} 
bool ldelete()
{
	int cha;
	int flag=0;
	double xx,yy;
	char ch[20];
	int cur=0;
	cout<<"1通过坐标"<<endl;
	cout<<"2通过城市"<<endl;
	cin>>cha;
	if(cha==1)
	{
		for(int i=1;i<=chengshishu;i++)
		{
			if(city[i].x==xx&&city[i].y==yy)
			{
				cout<<city[i].ncity<<endl;
				flag=1;
				cur=i;
				break;
			}
		}

		if(!flag)//没找到该城市 
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{

			strncpy ( city[cur].ncity,city[chengshishu].ncity , sizeof(city[chengshishu].ncity) );
			city[cur].x=city[chengshishu].x;
			city[cur].y=city[chengshishu].y;
			chengshishu--;
		}
	} 
	else if(cha==2)
	{
		cout<<"输入城市名"<<endl; 
		cin>>ch;
		for(int i=1;i<=chengshishu;i++)
		{
			if(strcmp(city[i].ncity,ch)==0)//strcmp比较两个字符串 
			{
				cout<<city[i].x<<","<<city[i].y<<endl;
				flag=1;
				cur=i;
				break;
			}
		}
		if(!flag)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			strncpy ( city[cur].ncity,city[chengshishu].ncity , sizeof(city[chengshishu].ncity) );
			city[cur].x=city[chengshishu].x;
			city[cur].y=city[chengshishu].y;
			chengshishu--;
		}
	}
	return true;
}
bool lupdate()
{
	int cha,flag=0,cur=0;
	double xx,yy;
	char ch[20];
	cout<<"1通过坐标"<<endl;
	cout<<"2通过城市"<<endl;
	cin>>cha;
	if(cha==1)
	{
		cout<<"输入坐标"<<endl; 
		cin>>xx>>yy;
		for(int i=1;i<=chengshishu;i++)
		{
			if(city[i].x==xx&&city[i].y==yy)
			{
				flag=1;
				cur=i;
				break;
			}
		}

		if(!flag)//没找到该城市 
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			cout<<"输入新名字"<<endl;
			cin>>city[cur].ncity;
		}
	} 
	else if(cha==2)
	{
		cout<<"输入城市名"<<endl; 
		cin>>ch;
		for(int i=1;i<=chengshishu;i++)
		{
			if(strcmp(city[i].ncity,ch)==0)//strcmp比较两个字符串 
			{
				cout<<city[i].x<<","<<city[i].y<<endl;
				flag=1;
				cur=i;
				break;
			}
		}
		if(!flag)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			cout<<"输入新坐标"<<endl;
			cin>>city[cur].x>>city[cur].y; 
		} 
	}

	return true;
}
bool pan(double xx,double yy,double dis,int i)
{
	double dx=(city[i].x)-xx;
	double dy=(city[i].y)-yy;

	if(((dx*dx+dy*dy)<=dis*dis)&&(!((dx==0)&&(dy==0))))
	{
	//	cout<<l->x<<l->y<<endl;
		return true;
	}
	else
	{
		return false;
	}
}
bool lcompute()
{

	double xx,yy;
	double dis;
	cout<<"输入坐标"<<endl;
	cin>>xx>>yy;
	cout<<"输入距离"<<endl;
	cin>>dis;
	for(int i=1;i<=chengshishu;i++)
	{
		if(pan(xx,yy,dis,i)==true)
		{
			cout<<city[i].ncity<<endl;
			cout<<city[i].x<<","<<city[i].y<<endl;
		}

	}

	return true;
}
int main()
{

	while(1)
	{	
		cout<<"此输入想要的操作（第一次请选择1）"<<endl;
		cout<<"1创建"<<endl; 
		cout<<"2查询"<<endl; 
		cout<<"3插入"<<endl; 
		cout<<"4删除"<<endl; 
		cout<<"5更新"<<endl; 
		cout<<"6计算所有城市"<<endl; 
		cout<<"7退出"<<endl; 
		cin>>caozuo;
		
		if(caozuo==7)
		{
			break;
		}
		else
		{
			switch(caozuo)
			{
				case 1:

					lcreate();
					break;
				case 2:
					lfind();
					break;
				case 3:
					linsert();
					break;
				case 4:
					ldelete();
					break;
				case 5:
					lupdate();
					break;
				case 6:
					lcompute();
					break;
				default:
					break;
			}
		}		
	} 
	
    return 0;
}
