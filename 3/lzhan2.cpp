#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define MAXSIZE 10
struct snode 
{
    int data;
    struct snode* next;
};
typedef struct snode* lstack;
void inits(lstack &s)
{
	s=NULL;
}
bool emptys(lstack &s)
{
	if(s)
		return true;
	else
		return false;
}
//ÈëÕ» 
bool pushs(lstack &s,int &x)
{
	lstack p=(snode*)malloc(sizeof(snode));
	p->data=x;
	p->next=s;
	s=p;
	return true;
}
//³öÕ» 
bool pops(lstack &s,int& x)
{
	if(!s)//Õ»¿Õ±¨´í
	{
		return false;	
	} 
	lstack p=s;
	x=s->data;
	s=s->next;
	free(p);
	return true;
}

int main()
{
	lstack s;
	int x=1;
	inits(s);
	pushs(s,x);
	pops(s,x);
	cout<<x<<endl;
	return 0;
} 
