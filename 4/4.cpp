#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct
{
	char ch[MAXSIZE];//ÿ���洢һ���ַ�
	int length;//ʵ�ʳ��� 
}sst;
 //�Ӵ�����pos���ַ�����Ϊlen 
bool subs(sst& sub,sst s,int pos,int len)
{
	//�Ӵ�Խ��
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
//�Ƚ��ַ���
int coms(sst s,sst t)
{
	for(int i=1;i<=s.length&&i<=t.length;i++)
	{
		if(s.ch[i]!=t.ch[i])
		{
			return s.ch[i]-t.ch[i];
		}
		//ɨ����������ַ���ͬ���򳤶ȳ��ĸ���
		return s.length-t.length; 
	}
 } //��λ�����ص�һ�γ���λ�ã�����Ϊ0 
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
			return i;//����������λ�� 
		}
	}
	return 0;//������ 
	 
} 
int main()
{
	
    return 0;
}
