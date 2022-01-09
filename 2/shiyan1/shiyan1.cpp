#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
//结构体定义 
struct lnode 
{
    double x,y;//坐标 
    char ncity[100];//城市名 
    struct lnode* next;
};
typedef struct lnode* linklist;
int caozuo;//选择操作类型 
linklist la,lb,lc; 
//创建新链表 
bool linit(linklist& l)
{
	l=(linklist)malloc(sizeof(struct lnode));//申请新节点 
	if(l==NULL)return false;//申请成功 
	l->next=NULL;
	return true;
}

//插入链表 
void linsert(linklist& l)
{
	lnode *prear,*p;
	p=(linklist)malloc(sizeof(struct lnode));
	cout<<"城市名"<<endl; 
	scanf("%s",p->ncity);
	//cout<<p->ncity;
	cout<<"城市坐标"<<endl;
	cin>>p->x>>p->y;
	prear=l; //l指向头结点，要先标记 
	//尾插法 
	while(l->next!=NULL)
	{
		l=l->next;
	} //向后查找找到最后一个节点
	l->next=p;
	p->next=NULL;
	l=prear;
	//cout<<l->next->x<<endl;
	//cout<<p->x<<p->y;
}
//创建新链表 
bool lcreate(linklist& l)
{
	int k;
	cout<<"输入创建城市数："<<endl;
	cin>>k;
	while(k)
	{
		linsert(l);//插入节点 
		k--;
		//cout<<k<<endl;
	}
	return true;
} 
//查找 
bool lfind(linklist& l)
{
	int cha;
	double xx,yy;
	char ch[20];
	linklist l1=l;
	cout<<"1查城市"<<endl;
	cout<<"2查坐标"<<endl;
	cin>>cha;
	if(cha==1) 
	{
		cout<<"输入坐标"<<endl; 
		cin>>xx>>yy;
		l=l->next;
		//cout<<l->x<<l->y<<endl;
		while((l!=NULL)&&!((l->x==xx)&&(l->y==yy)))//有个坑是只有x,y期中一个一致不算找到 
		{
			l=l->next;
		
		}
		//cout<<l->x<<l->y<<endl;
		if(l==NULL)//没找到该城市 
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			cout<<l->ncity<<endl;
		 } 
	} 
	else if(cha==2)
	{
		cout<<"输入城市名"<<endl; 
		cin>>ch;
		while(l!=NULL&&(strcmp(l->ncity,ch)!=0))//strcmp比较两个字符串 
		{
			l=l->next;
		}
		if(l==NULL)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			cout<<l->x<<" , "<<l->y<<endl;
		 } 
	}
	l=l1;//要回到头结点方便以后的操作 
	return true;
} 
//删除 
bool ldelete(linklist& l)
{
	int cha;
	double xx,yy;
	char ch[20];
	linklist l1=l;
	cout<<"1通过坐标"<<endl;
	cout<<"2通过城市"<<endl;
	cin>>cha;
	if(cha==1)//通过坐标删除 
	{
		cout<<"输入坐标"<<endl; 
		cin>>xx>>yy;
		//l=l->next;
		//cout<<l->x<<l->y<<endl;
		while(l->next!=NULL&&!((l->next->x==xx)&&(l->next->y==yy)))
		{
			l=l->next;
			//cout<<l->x<<l->y<<endl;
		}
		//cout<<l->x<<l->y<<endl;
		if(l->next==NULL)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			lnode*p;
			p=l->next;
			cout<<p->ncity<<endl;
			l->next=p->next;
			free(p);
		} 
	} 
	else if(cha==2)//通过名称删除 
	{
		cout<<"输入城市名"<<endl; 
		cin>>ch;
		while(l->next!=NULL&&(strcmp(l->next->ncity,ch)!=0))
		{
			l=l->next;
		}
		if(l->next==NULL)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			
			lnode*p;
			p=l->next;
			cout<<l->next->x<<" , "<<l->next->y<<endl;
			l->next=p->next;
			free(p);
		 } 
	}
	l=l1;
	return true;
}
//更新 
bool lupdate(linklist& l)
{
	int cha;
	double xx,yy;
	char ch[20];
	linklist l1=l;
	cout<<"1通过坐标"<<endl;
	cout<<"2通过城市"<<endl;
	cin>>cha;
	if(cha==1)//通过坐标 
	{
		cout<<"输入坐标"<<endl; 
		cin>>xx>>yy;
		//l=l->next;
		//cout<<l->x<<l->y<<endl;
		while(l->next!=NULL&&!((l->next->x==xx)&&(l->next->y==yy)))
		{
			l=l->next;
			//cout<<l->x<<l->y<<endl;
		}
		//cout<<l->x<<l->y<<endl;
		if(l->next==NULL)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			cout<<"输入新名字"<<endl;
			cin>>l->next->ncity; 
		} 
	} 
	else if(cha==2)//通过城市
	{
		cout<<"输入城市名"<<endl; 
		cin>>ch;
		while(l->next!=NULL&&(strcmp(l->next->ncity,ch)!=0))
		{
			l=l->next;
		}
		if(l->next==NULL)
		{
			cout<<"不存在此城市"<<endl;
		}
		else
		{
			cout<<"输入新坐标"<<endl;
			cin>>l->next->x>>l->next->y; 
		} 
	}
	l=l1;
	return true;
}
//判断城市距离是否符合标准 
bool pan(double xx,double yy,double dis,linklist& l)
{
	double dx=(l->x)-xx;
	double dy=(l->y)-yy;
	//cout<<dx<<" "<<dy<<endl;
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
//计算 
bool lcompute(linklist& l)
{

	double xx,yy;
	double dis;
	linklist l1=l;
	cout<<"输入坐标"<<endl;
	cin>>xx>>yy;
	cout<<"输入距离"<<endl;
	cin>>dis;
	l=l->next;
	while(l!=NULL)
	{
		if(pan(xx,yy,dis,l)==true)
		{
			cout<<l->ncity<<endl;
			cout<<l->x<<","<<l->y<<endl;
		}
	
		l=l->next;
	}
		//cout<<l->x<<l->y<<endl;

	l=l1;
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
					linit(la);
					lcreate(la);
					break;
				case 2:
					lfind(la);
					break;
				case 3:
					linsert(la);
					break;
				case 4:
					ldelete(la);
					break;
				case 5:
					lupdate(la);
					break;
				case 6:
					lcompute(la);
					break;
				default:
					break;
			}
		}		
	} 
	
    return 0;
}
