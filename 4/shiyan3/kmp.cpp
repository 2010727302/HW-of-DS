#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct lnode
{
	char ch[MAXSIZE];//ÿ���洢һ���ַ�
	int length;//ʵ�ʳ��� 
}sst;
int next[10086],nextv[10086];
//�����ַ��� 
sst inputs()
{
	//�����cin���룬�ַ������0��ʼ 
	sst s1;
 	char c;
 	int i=0;
	while(1)
	{
		scanf("%c",&c);
		if(c=='\n')
		{
			break;
		}
		
		i++;
		s1.ch[i]=c;
		//cout<<i<<endl;
		//cout<<s1.ch[i]<<endl;	
	}
	s1.length=i;
	//s1.ch[i+1]='\0';
	return s1;
}
//kmp
int mats2(sst s,sst t,int next[])
{
	//int k=1;
	int i=1,j=1;
	while(i<=s.length&&j<=t.length)
	{
		if(s.ch[i]==t.ch[j]||j==0)
		{
			//cout<<s.ch[i]<<t.ch[i]<<endl;
			i++;
			j++;//�����Ƚ� 
		}
		else
		{
			j=next[j];//ģʽ������
		 } 
		 //cout<<i<<" "<<j<<endl;
	}
	if(j>t.length)
	{
		//cout<<i-t.length<<endl;
		return i-t.length;
	}
	else
	{
		return 0;
	}	 
} 
//��t��next 
void getn(sst t,int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<t.length)
	{
		if(j==0||t.ch[i]==t.ch[j])
		{//��ȵ���� 
			i++;
			j++;
			//pi=pj,next[j+1]=next[j]+1
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}
//next�Ż� 
void getnv(sst t,int nextv[])
{
	int i=1,j=0;
	nextv[1]=0;
	while(i<t.length)
	{
		if(j==0||t.ch[i]==t.ch[j])
		{
			i++;
			j++;
			if(t.ch[i]!=t.ch[j])
			{
				nextv[i]=j;
			}
			else
			{
				nextv[i]=nextv[j];
			}
		}
		else
		{
			j=nextv[j];
		}
	}
 } 
int main()
{
	sst s,t;
	
	s=inputs();
	t=inputs();
	getn(t,next);
	//getnv(t,next);
	//cout<<s.length<<" "<<t.length<<endl; 
	/*for(int i=1;i<=s.length;i++)
	{
		cout<<s.ch[i];
	}
	cout<<endl;
	for(int i=1;i<=t.length;i++)
	{
		cout<<t.ch[i];
	}*/

	int k2=mats2(s,t,next);
	//kmp 
	if(k2)
	{
		cout<<"ƥ��ɹ�,��"<<k2<<endl; 
	}
	else
	{
		cout<<"ƥ��ʧ��"<<endl; 
	}
	/*
	
	for(int i=1;i<=t.length;i++)
	{
		cout<<next[i]<<" ";
	}*/
    return 0;
}
