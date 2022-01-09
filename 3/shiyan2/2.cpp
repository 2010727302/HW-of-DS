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
	int top;//ջ��ָ�� 
}sqstack;
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
bool pushs(sqstack &s,char& x)
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
bool pops(sqstack &s,char& x)
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
bool gets(sqstack &s,char& x)
{
	if(s.top==-1)//ջ�ձ���
	{
		return false;	
	} 
	x=s.data[s.top];//ջ��Ԫ�س�ջ 
	return true;
}
//ƥ�����ź��� 
bool checks(char str[],int len)
{
	sqstack s;
	inits(s);
	for(int i=0;i<len;i++)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//ɨ�赽������ 
		{
			pushs(s,str[i]);//��ջ 
		}
		else//ɨ�赽������ 
		{
			if(emptys(s))//ջ��û��Ԫ�� 
			{
				return false;
			}
			char tope;//ջ��Ԫ�� 
			pops(s,tope);//ջ��Ԫ�س�ջ 
			if(str[i]==')'&&tope!='(')//�ж��Ƿ�ƥ�� 
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
	if(emptys(s))//��ջΪ������ȷ 
	return true;
	else
	return false;
}
int main()
{
	cin>>str;
	if(checks(str,strlen(str)))
	{
		cout<<"ƥ��"<<endl;
	} 
	else
	{
		cout<<"�˴�����ƥ�䲻�Ϸ�"<<endl;
	}
    return 0;
}
