#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
typedef struct
{
	char* ch;//ch指向基地址 
	int length;//实际长度 
}hs;
hs s;
int main()
{
	s.ch=(char *)malloc(MAXSIZE*sizeof(char));
	s.length=0; 
    return 0;
}
