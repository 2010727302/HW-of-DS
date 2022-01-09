  /* ��ӡ������ */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
/****�������������Ͷ���****/
typedef char TElemType;
typedef struct BiTNode
    { TElemType data;
      struct BiTNode *lchild,*rchild;
    } BiTNode, *BiTree;

/****������������****/
void CreateBiTree(BiTree *T)
{ char ch;
  scanf("%c",&ch);
  if (ch==' ')
     *T=NULL;
  else
   { *T=(BiTree)malloc(sizeof(BiTNode));
     (*T)->data=ch;
     CreateBiTree(&(*T)->lchild);
     CreateBiTree(&(*T)->rchild); }
}
/****RDL����������****/
void RDLTraverse(BiTree T)
{ if (T)
   {RDLTraverse(T->rchild);
    printf("%2c",T->data);
    RDLTraverse(T->lchild); }
}

/****��������������****/
int BiTreeDepth(BiTree T)
{ int h1,h2,h;
  if (T==NULL)
     return 0;
  else
   { h1=BiTreeDepth(T->lchild);
     h2=BiTreeDepth(T->rchild);
     if (h1>h2)
   h=h1+1;
     else
   h=h2+1;
    }
    return h;
}
/****��ӡ������****/
void  DaYin(BiTree T,int n)
{ int i;
  
  if(T)
  {    
    DaYin(T->rchild,n+1);
    cout<<BiTreeDepth(T)<<" ";
   for(i=BiTreeDepth(T);i<n;i++)
   {
      printf("\t");
   }  
   printf("%2c",T->data);
   printf("\n");
      DaYin(T->lchild,n+1);   
  }
}
/****������****/
main()
{ BiTree T; 
  printf("�������������:\n"); CreateBiTree(&T);
   printf("�����ӡ���������:\n"); DaYin(T,1);
  printf("\n");
}
