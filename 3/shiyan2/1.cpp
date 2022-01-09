#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
int n,d;
//d为将要转换的进制 
typedef struct
{
	char data[MAXSIZE];
	int top;//栈顶指针 
}sqstack;
sqstack s;
//初始化栈 
void inits(sqstack &s)
{
	s.top=-1;
}
//判断栈是否为空 
bool emptys(sqstack s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//入栈 
bool pushs(sqstack &s,int& x)
{
	if(s.top==MAXSIZE-1)//栈满报错
	{
		return false;	
	} 
	s.top++;//指针先加 
	s.data[s.top]=x;//新元素入栈 
	return true;
}
//出栈 
bool pops(sqstack &s,int& x)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
	x=s.data[s.top];//栈顶元素出栈 
	s.top--;//指针再减 
	return true;
}
//查栈顶元素 
bool gets(sqstack &s,int& x)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
	x=s.data[s.top];//栈顶元素出栈 
	return true;
}
void covert(int d)//转换 
{
	inits(s);
	cin>>n;
	while(n)
	{
		int mo=n%d;//将要放入栈的数 
		pushs(s,mo);
		n=n/d;
	}
	while(!emptys(s))//输出栈 
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
