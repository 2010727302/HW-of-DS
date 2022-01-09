#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct
{
	char ch[MAXSIZE];//每个存储一个字符
	int length;//实际长度 
}sst;
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
 } //定位，返回第一次出现位置，否则为0 
int indexs(sst s,sst t)
{
	int i=1,n=s.length,m=t.length;
	sst sub;
	while(i<=n-m+1)
	{
		subs(sub,s,i,m);
		if(coms(sub,t)!=0)
		{
			i++;
		}
		else
		{
			return i;//返回在主串位置 
		}
	}
	return 0;//不存在 
	 
} 
int main()
{
	
    return 0;
}
