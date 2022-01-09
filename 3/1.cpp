#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
typedef struct
{
	char data[MAXSIZE];
	int top;//栈顶指针 
}sqstack;
sqstack s1;
int k;//测试组数 
int len; 
int i;
char inf[100086];
//判断优先级 (+-<*/)
int pri(char a)
{
	if(a=='+'||a=='-')
	{
		return 1;
	}
	else if(a=='/'||a=='*')
	{
		return 2;
	}
}
//判断是否为操作数
int op(char a) 
{
	if(a=='+'||a=='-'||a=='/'||a=='*')
	{
		//cout<<a<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
}
//初始化栈 
void inits(sqstack &s)
{
	s.top=-1;
}
//判断栈是否为空 
bool emptys(sqstack &s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//入栈 
bool pushs(sqstack &s,char &x)
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
bool pops(sqstack &s,char &x)
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
bool gets(sqstack &s,char &x)
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
	cin>>k;
	while(k--)
	{
		cin>>len;
		cin>>inf;
		//cout<<inf[0]<<endl;
		inits(s1);
		//cout<<op(inf[1])<<endl; 
		for(int i=0;i<len;i++)
		{
			if(op(inf[i])==1)//非操作数 
			{
				char x;
				if(emptys(s1)==true) //栈为空直接入栈 
				{
					pushs(s1,inf[i]);
					//cout<<i<<inf[i]<<endl;
					continue;
				}
				else 
				{
					char x;
					gets(s1,x);
					//cout<<"x"<<x<<endl;
					if(pri(inf[i])>pri(x))//当前操作符优先级比栈中高 
					{
						//cout<<x;
						//cout<<"pri1"<<pri(inf[i])<<endl;
						
					/*
						if(pri(inf[i])==pri(x))//相等时候因为从左到右先出栈 
						{
							pops(s1,x);
							cout<<x;
						}
					*/
						pushs(s1,inf[i]);
					}
					else
					{
						//cout<<"em"<<emptys(s1)<<endl;
						//cout<<"pri1"<<pri(inf[i])<<endl;
						while(((pri(inf[i]))<=pri(x))&&(emptys(s1)!=1))
						//站内元素出栈直到栈空或只有不比当前优先级小的操作符 
						{
							pops(s1,x);
							//cout<<"p"<<pri(inf[i])<<" "<<pri(x)<<endl;
							cout<<x;
							gets(s1,x);
						}
						pushs(s1,inf[i]);
					}
				
				}
			}
			else
			{
				cout<<inf[i];
			} 
			
		}
		while(emptys(s1)!=1)//栈中有残余元素出栈 
		{
				char x;
				pops(s1,x);
				cout<<x;
		}
		cout<<endl;
	}

    return 0;
}
