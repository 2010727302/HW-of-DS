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
	int top;//ջ��ָ�� 
}sqstack;
sqstack s1;
int k;//�������� 
int len; 
int i;
char inf[100086];
//�ж����ȼ� (+-<*/)
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
//�ж��Ƿ�Ϊ������
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
//��ʼ��ջ 
void inits(sqstack &s)
{
	s.top=-1;
}
//�ж�ջ�Ƿ�Ϊ�� 
bool emptys(sqstack &s)
{
	if(s.top==-1)
		return true;
	else
		return false;
}
//��ջ 
bool pushs(sqstack &s,char &x)
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
bool pops(sqstack &s,char &x)
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
bool gets(sqstack &s,char &x)
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
			if(op(inf[i])==1)//�ǲ����� 
			{
				char x;
				if(emptys(s1)==true) //ջΪ��ֱ����ջ 
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
					if(pri(inf[i])>pri(x))//��ǰ���������ȼ���ջ�и� 
					{
						//cout<<x;
						//cout<<"pri1"<<pri(inf[i])<<endl;
						
					/*
						if(pri(inf[i])==pri(x))//���ʱ����Ϊ�������ȳ�ջ 
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
						//վ��Ԫ�س�ջֱ��ջ�ջ�ֻ�в��ȵ�ǰ���ȼ�С�Ĳ����� 
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
		while(emptys(s1)!=1)//ջ���в���Ԫ�س�ջ 
		{
				char x;
				pops(s1,x);
				cout<<x;
		}
		cout<<endl;
	}

    return 0;
}
