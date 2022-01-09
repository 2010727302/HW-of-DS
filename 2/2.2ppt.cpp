#include <cstdio>
#include<cstdlib>
#include<iostream>
#include<conio.h>
using namespace std;
typedef int ElemType;
typedef int Status; 
#define OK 1 
#define OVERFLOW -2 
#define ERROR 0 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct 
{
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
Status ListInsert_Sq(Sqlist *L, int i, ElemType e);
Status InitList_Sq(Sqlist *L);
Status ListDelete_Sq(Sqlist *L,int i,ElemType *e);
int main()
{
	Sqlist Lst;
	int i, n=101;
	ElemType e;
	if(InitList_Sq(&Lst)==OK)
	{//if initialization succeeds
		for(i=1;i<=n;i++)
		if(ListInsert_Sq(&Lst,i,i)!=OK) break;
		//insert 1～n to the position 1～n
		printf("\n"); // 换行
		for(i=0;i<Lst.length;i++)
		printf("i,e=%d,%d\n",i,Lst.elem[i]);
		// Print 1～n
		getch(); // Wait for the keyboard’s responding
		if(ListDelete_Sq(&Lst,5,&e)==OK)
		{
			// delete the 5th element
			printf("delete_elem=%d\n",e);
			// Print the deleted element
			getch(); // Wait for the keyboard’s responding
			for(i=0;i<Lst.length;i++)
			printf("i,e=%d,%d\n",i,Lst.elem[i]);
			// Print all the elements in the List
		}
	}
}
Status InitList_Sq(Sqlist *L)
{ // 构造一个空的线性表L
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
	if(!L->elem)exit(OVERFLOW);
	L->length=0; 
	L->listsize=LIST_INIT_SIZE;
	return OK; 
}
Status ListInsert_Sq(Sqlist *L, int i, ElemType e)
{
	ElemType *q,*p,*newbase;
	if(i<1 || i>L->length+1) 
	return ERROR;
	if(L->length>=L->listsize)
	{
		newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW); 
		L->elem=newbase;
		L->listsize+=LISTINCREMENT;
	}
	q=&(L->elem[i-1]); 
	for(p=&(L->elem[L->length-1]); p>=q; --p)
		*(p+1)=*p;
	*q=e; 
	++L->length;
	return OK;
}
Status ListDelete_Sq(Sqlist *L,int i,ElemType *e)
{
	ElemType *p,*q;
	if((i<1)||(i>L->length)) return ERROR; 
	p=&(L->elem[i-1]); 
	*e=*p; 
	q=(L->elem+L->length-1);
	for(++p;p<=q;++p)
		*(p-1)=*p; 
	--L->length; 
	return OK;
}
