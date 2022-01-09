#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
int n,d;
//dΪ��Ҫת���Ľ��� 
typedef struct
{
	char data[MAXSIZE];
	int top;//ջ��ָ�� 
}sqstack;
sqstack s;
//��ʼ��ջ 
void inits(sqstack &s)
{
	s.top=-1;
}
//�ж�ջ�Ƿ�Ϊ�� 
bool emptys(sqstack s)
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
void covert(int d)//ת�� 
{
	inits(s);
	cin>>n;
	while(n)
	{
		int mo=n%d;//��Ҫ����ջ���� 
		pushs(s,mo);
		n=n/d;
	}
	while(!emptys(s))//���ջ 
	{
		int e=0;
		pops(s,e);
		cout<<e;
	}
}
int main()
{
	//cin>>d;
	d=8;
	covert(d);
    return 0;
}
