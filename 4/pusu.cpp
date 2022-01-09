#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct lnode
{
	char ch[MAXSIZE];//每个存储一个字符
	int length;//实际长度 
}sst;
int sum=0;
int next[10086],nextv[10086];
 //子串，第pos个字符长度为len 
bool subs(sst& sub,sst s,int pos,int len)
{
	//子串越界
	if(pos+len-1>s.length) 
	{
		return false;
	}
	for(int i=pos;i<pos+len;i++)
	{
		sub.ch[i-pos+1]=s.ch[i];
	}
	sub.length=len;
	return true;
 } 
//比较字符串
int coms(sst s,sst t)
{
	for(int i=1;i<=s.length&&i<=t.length;i++)
	{
		if(s.ch[i]!=t.ch[i])
		{
			return s.ch[i]-t.ch[i];
		}
		//扫描过的所有字符相同，则长度长的更大
		return s.length-t.length; 
	}
 } 
 //朴素算法 
int mats(sst s,sst t)
{
	//int k=1;

	int i=1,j=1;
	while(i<=s.length&&j<=t.length)
	{
		if(s.ch[i]==t.ch[j])
		{
			//cout<<s.ch[i]<<t.ch[i]<<endl;
			i++;
			j++;//继续比较 
		}
		else
		{
			/*k++;
			i=k;
			j=1; 
			or*/
			i=i-j+2;//检查下一个子串 
			j=1;
			
		 } 
		 sum++;
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
//输入字符串 
sst inputs()
{
	sst s1;
 	char c;
 	int i=0;
	while(1)
	{
		scanf("%c",&c);
		if(c==' '||c=='\n')
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
			j++;//继续比较 
		}
		else
		{
			j=next[j];//模式串向右
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
//求t的next 
void getn(sst t,int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<t.length)
	{
		if(j==0||t.ch[i]==t.ch[j])
		{
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
//next优化 
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
 //next优化 
void getnv2(sst t)
{
	int i=1,j=2;
	nextv[1]=0;
	while(j<=t.length)
	{
		if(t.ch[next[j]]==t.ch[j])
		{
			nextv[j]=nextv[next[j]];
		}
		else
		{
			nextv[j]=next[j];
		}
		j++;
	}
 } 
int main()
{
	sst s,t;
	
	s=inputs();
	t=inputs();
	getn(t,next);
	getnv2(t);
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
	int k=mats(s,t);
	if(k)
	{
		cout<<"匹配成功,在"<<k<<endl; 
	}
	else
	{
		cout<<"匹配失败"<<endl; 
	}
	cout<<sum<<endl;
	int k2=mats2(s,t,next);
	if(k2)
	{
		cout<<"匹配成功,在"<<k2<<endl; 
	}
	else
	{
		cout<<"匹配失败"<<endl; 
	}
	for(int i=1;i<=t.length;i++)
	{
		cout<<next[i]<<" ";
	}
    return 0;
}
