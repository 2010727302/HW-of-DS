#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct lnode 
{
    double x,y;//���� 
    char ncity[100];//������ 
    
}city[10086];
typedef struct lnode* linklist;
int caozuo;//ѡ��������� 
linklist la,lb,lc; 
int chengshishu=0;

//����
void linsert()
{
	chengshishu++;
	cout<<"������"<<endl; 
	cin>>city[chengshishu].ncity;
	cout<<"��������"<<endl;
	cin>>city[chengshishu].x>>city[chengshishu].y;
	
}
//���������� 
bool lcreate()
{
	int k;
	cout<<"���봴����������"<<endl;
	cin>>k;
	while(k)
	{
		linsert();//����ڵ� 
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
	cout<<"1�����"<<endl;
	cout<<"2������"<<endl;
	cin>>cha;
	if(cha==1)
	{
		cout<<"��������"<<endl; 
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

		if(!flag)//û�ҵ��ó��� 
		{
			cout<<"�����ڴ˳���"<<endl;
		}

	} 
	else if(cha==2)
	{
		cout<<"���������"<<endl; 
		cin>>ch;
		for(int i=1;i<=chengshishu;i++)
		{
			if(strcmp(city[i].ncity,ch)==0)//strcmp�Ƚ������ַ��� 
			{
				cout<<city[i].x<<","<<city[i].y<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<"�����ڴ˳���"<<endl;
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
	cout<<"1ͨ������"<<endl;
	cout<<"2ͨ������"<<endl;
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

		if(!flag)//û�ҵ��ó��� 
		{
			cout<<"�����ڴ˳���"<<endl;
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
		cout<<"���������"<<endl; 
		cin>>ch;
		for(int i=1;i<=chengshishu;i++)
		{
			if(strcmp(city[i].ncity,ch)==0)//strcmp�Ƚ������ַ��� 
			{
				cout<<city[i].x<<","<<city[i].y<<endl;
				flag=1;
				cur=i;
				break;
			}
		}
		if(!flag)
		{
			cout<<"�����ڴ˳���"<<endl;
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
	cout<<"1ͨ������"<<endl;
	cout<<"2ͨ������"<<endl;
	cin>>cha;
	if(cha==1)
	{
		cout<<"��������"<<endl; 
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

		if(!flag)//û�ҵ��ó��� 
		{
			cout<<"�����ڴ˳���"<<endl;
		}
		else
		{
			cout<<"����������"<<endl;
			cin>>city[cur].ncity;
		}
	} 
	else if(cha==2)
	{
		cout<<"���������"<<endl; 
		cin>>ch;
		for(int i=1;i<=chengshishu;i++)
		{
			if(strcmp(city[i].ncity,ch)==0)//strcmp�Ƚ������ַ��� 
			{
				cout<<city[i].x<<","<<city[i].y<<endl;
				flag=1;
				cur=i;
				break;
			}
		}
		if(!flag)
		{
			cout<<"�����ڴ˳���"<<endl;
		}
		else
		{
			cout<<"����������"<<endl;
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
	cout<<"��������"<<endl;
	cin>>xx>>yy;
	cout<<"�������"<<endl;
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
		cout<<"��������Ҫ�Ĳ�������һ����ѡ��1��"<<endl;
		cout<<"1����"<<endl; 
		cout<<"2��ѯ"<<endl; 
		cout<<"3����"<<endl; 
		cout<<"4ɾ��"<<endl; 
		cout<<"5����"<<endl; 
		cout<<"6�������г���"<<endl; 
		cout<<"7�˳�"<<endl; 
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
