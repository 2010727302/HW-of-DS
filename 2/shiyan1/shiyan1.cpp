#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
//�ṹ�嶨�� 
struct lnode 
{
    double x,y;//���� 
    char ncity[100];//������ 
    struct lnode* next;
};
typedef struct lnode* linklist;
int caozuo;//ѡ��������� 
linklist la,lb,lc; 
//���������� 
bool linit(linklist& l)
{
	l=(linklist)malloc(sizeof(struct lnode));//�����½ڵ� 
	if(l==NULL)return false;//����ɹ� 
	l->next=NULL;
	return true;
}

//�������� 
void linsert(linklist& l)
{
	lnode *prear,*p;
	p=(linklist)malloc(sizeof(struct lnode));
	cout<<"������"<<endl; 
	scanf("%s",p->ncity);
	//cout<<p->ncity;
	cout<<"��������"<<endl;
	cin>>p->x>>p->y;
	prear=l; //lָ��ͷ��㣬Ҫ�ȱ�� 
	//β�巨 
	while(l->next!=NULL)
	{
		l=l->next;
	} //�������ҵ����һ���ڵ�
	l->next=p;
	p->next=NULL;
	l=prear;
	//cout<<l->next->x<<endl;
	//cout<<p->x<<p->y;
}
//���������� 
bool lcreate(linklist& l)
{
	int k;
	cout<<"���봴����������"<<endl;
	cin>>k;
	while(k)
	{
		linsert(l);//����ڵ� 
		k--;
		//cout<<k<<endl;
	}
	return true;
} 
//���� 
bool lfind(linklist& l)
{
	int cha;
	double xx,yy;
	char ch[20];
	linklist l1=l;
	cout<<"1�����"<<endl;
	cout<<"2������"<<endl;
	cin>>cha;
	if(cha==1) 
	{
		cout<<"��������"<<endl; 
		cin>>xx>>yy;
		l=l->next;
		//cout<<l->x<<l->y<<endl;
		while((l!=NULL)&&!((l->x==xx)&&(l->y==yy)))//�и�����ֻ��x,y����һ��һ�²����ҵ� 
		{
			l=l->next;
		
		}
		//cout<<l->x<<l->y<<endl;
		if(l==NULL)//û�ҵ��ó��� 
		{
			cout<<"�����ڴ˳���"<<endl;
		}
		else
		{
			cout<<l->ncity<<endl;
		 } 
	} 
	else if(cha==2)
	{
		cout<<"���������"<<endl; 
		cin>>ch;
		while(l!=NULL&&(strcmp(l->ncity,ch)!=0))//strcmp�Ƚ������ַ��� 
		{
			l=l->next;
		}
		if(l==NULL)
		{
			cout<<"�����ڴ˳���"<<endl;
		}
		else
		{
			cout<<l->x<<" , "<<l->y<<endl;
		 } 
	}
	l=l1;//Ҫ�ص�ͷ��㷽���Ժ�Ĳ��� 
	return true;
} 
//ɾ�� 
bool ldelete(linklist& l)
{
	int cha;
	double xx,yy;
	char ch[20];
	linklist l1=l;
	cout<<"1ͨ������"<<endl;
	cout<<"2ͨ������"<<endl;
	cin>>cha;
	if(cha==1)//ͨ������ɾ�� 
	{
		cout<<"��������"<<endl; 
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
			cout<<"�����ڴ˳���"<<endl;
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
	else if(cha==2)//ͨ������ɾ�� 
	{
		cout<<"���������"<<endl; 
		cin>>ch;
		while(l->next!=NULL&&(strcmp(l->next->ncity,ch)!=0))
		{
			l=l->next;
		}
		if(l->next==NULL)
		{
			cout<<"�����ڴ˳���"<<endl;
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
//���� 
bool lupdate(linklist& l)
{
	int cha;
	double xx,yy;
	char ch[20];
	linklist l1=l;
	cout<<"1ͨ������"<<endl;
	cout<<"2ͨ������"<<endl;
	cin>>cha;
	if(cha==1)//ͨ������ 
	{
		cout<<"��������"<<endl; 
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
			cout<<"�����ڴ˳���"<<endl;
		}
		else
		{
			cout<<"����������"<<endl;
			cin>>l->next->ncity; 
		} 
	} 
	else if(cha==2)//ͨ������
	{
		cout<<"���������"<<endl; 
		cin>>ch;
		while(l->next!=NULL&&(strcmp(l->next->ncity,ch)!=0))
		{
			l=l->next;
		}
		if(l->next==NULL)
		{
			cout<<"�����ڴ˳���"<<endl;
		}
		else
		{
			cout<<"����������"<<endl;
			cin>>l->next->x>>l->next->y; 
		} 
	}
	l=l1;
	return true;
}
//�жϳ��о����Ƿ���ϱ�׼ 
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
//���� 
bool lcompute(linklist& l)
{

	double xx,yy;
	double dis;
	linklist l1=l;
	cout<<"��������"<<endl;
	cin>>xx>>yy;
	cout<<"�������"<<endl;
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
