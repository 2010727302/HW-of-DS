#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define MAXSIZE 10
typedef struct
{
	int data[MAXSIZE];
	int top;//ջ��ָ�� 
}sqstack;
void inits(sqstack &s)
{
	s.top=-1;
}
bool emptys(sqstack s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//��ջ 
bool pushs(sqstack &s,int x)
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
bool pops(sqstack &s,int x)
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
bool gets(sqstack &s,int x)
{
	if(s.top==-1)//ջ�ձ���
	{
		return false;	
	} 
	x=s.data[s.top];//ջ��Ԫ�س�ջ 
	return true;
}
int main()
{
	sqstack s;
	inits(s);
	return 0;
} 
