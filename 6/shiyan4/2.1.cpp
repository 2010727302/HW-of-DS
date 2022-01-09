  /* 打印二叉树 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 100086
using namespace std;
/****二叉链树的类型定义****/
typedef char TElemType;
typedef struct BiTNode
    { TElemType data;
      struct BiTNode *lchild,*rchild;
    } BiTNode, *BiTree;

/****先序建立二叉树****/
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
/****RDL遍历二叉树****/
void RDLTraverse(BiTree T)
{ if (T)
   {RDLTraverse(T->rchild);
    printf("%2c",T->data);
    RDLTraverse(T->lchild); }
}

/****计算二叉树的深度****/
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
/****打印二叉树****/
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
/****主函数****/
main()
{ BiTree T; 
  printf("先序输入二叉树:\n"); CreateBiTree(&T);
   printf("输出打印二叉树结果:\n"); DaYin(T,1);
  printf("\n");
}
