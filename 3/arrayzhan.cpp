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
	int top;//栈顶指针 
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
//入栈 
bool pushs(sqstack &s,int x)
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
bool pops(sqstack &s,int x)
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
bool gets(sqstack &s,int x)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
	x=s.data[s.top];//栈顶元素出栈 
	return true;
}
int main()
{
	sqstack s;
	inits(s);
	return 0;
} 
