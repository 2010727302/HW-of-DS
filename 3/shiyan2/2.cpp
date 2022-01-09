#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
char str[100086];
typedef struct
{
	char data[MAXSIZE];
	int top;//栈顶指针 
}sqstack;
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
bool pushs(sqstack &s,char& x)
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
bool pops(sqstack &s,char& x)
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
bool gets(sqstack &s,char& x)
{
	if(s.top==-1)//栈空报错
	{
		return false;	
	} 
	x=s.data[s.top];//栈顶元素出栈 
	return true;
}
//匹配括号函数 
bool checks(char str[],int len)
{
	sqstack s;
	inits(s);
	for(int i=0;i<len;i++)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//扫描到右括号 
		{
			pushs(s,str[i]);//入栈 
		}
		else//扫描到左括号 
		{
			if(emptys(s))//栈中没有元素 
			{
				return false;
			}
			char tope;//栈顶元素 
			pops(s,tope);//栈顶元素出栈 
			if(str[i]==')'&&tope!='(')//判断是否匹配 
			{
				return false;
			}
			if(str[i]==']'&&tope!='[')
			{
				return false;
			}
			if(str[i]=='}'&&tope!='{')
			{
				return false;
			}
		}
	}
	if(emptys(s))//若栈为空则正确 
	return true;
	else
	return false;
}
int main()
{
	cin>>str;
	if(checks(str,strlen(str)))
	{
		cout<<"匹配"<<endl;
	} 
	else
	{
		cout<<"此串括号匹配不合法"<<endl;
	}
    return 0;
}
