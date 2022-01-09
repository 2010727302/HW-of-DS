
#include<iostream>
#include<cstdio>
#include<malloc.h>
 
 
#define OVERFLOW -2
 
 
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
 
void CreateBiTree(BiTree &L){
    char ch;
    scanf("%c",&ch);
    if(ch=='#')L=NULL;
    else{
        L=(BiTree)malloc(sizeof(BiTNode));
        if(!L)exit(OVERFLOW);
        L->data=ch;
        CreateBiTree(L->lchild);
        CreateBiTree(L->rchild);
    }
}
 
 
void PreOrderTraverse(BiTree L){
    if(L){
        printf("%c",L->data);
        PreOrderTraverse(L->lchild);
        PreOrderTraverse(L->rchild);
    }
}
void PostOrderTraverse(BiTree L){
    if(L){
        PostOrderTraverse(L->lchild);
        PostOrderTraverse(L->rchild);
        printf("%c",L->data);
    }
}
 
 
void InOrderTraverse(BiTree L){
    if(L){
        InOrderTraverse(L->lchild);
        printf("%c",L->data);
        InOrderTraverse(L->rchild);
    }
}
 
 
int Depth(BiTree L){
    int d1,d2,d3;
    if(!L)d1=0;
    else{
        d2=Depth(L->lchild);
        d3=Depth(L->rchild);
        d1=1+(d2>d3?d2:d3);
    }
    return d1;
}
int Leaf(BiTree L,int &c){
    if(L!=NULL){//在树不为空的时候才能讨论左右结点
        if(L->lchild==NULL&&L->rchild==NULL)c++;
        Leaf(L->lchild,c);
        Leaf(L->rchild,c);
    }
    return c;
}
void GetFloor(BiTree L,char data,int floor,int &res){
    if(L!=NULL){
        if(L->data==data){
            res=floor;
        }
        GetFloor(L->lchild,data,floor+1,res);
        GetFloor(L->rchild,data,floor+1,res);
    }
}
int c=0;
void Count(BiTree L){
    if(L!=NULL){
        c++;
        Count(L->lchild);
        Count(L->rchild);
    }
}
int main(){
    BiTree T;
    CreateBiTree(T);
    printf("先序遍历序列为：\n");
    PreOrderTraverse(T);
    printf("\n中序遍历序列为：\n");
    InOrderTraverse(T);
    printf("\n后序遍历序列为：\n");
    PostOrderTraverse(T);
    printf("\n高度：%d\n",Depth(T));
    int m=0;
    Leaf(T,m);
    printf("叶子数：%d\n",m);
    int floor=1,res;
    GetFloor(T,'D',floor,res);
    printf("在第%d层\n",res);
    Count(T);
    printf("一共有%d个结点\n",c);
}
