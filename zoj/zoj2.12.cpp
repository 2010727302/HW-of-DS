#include <stdio.h>
#include<cstdlib>
typedef struct PolyNode
{
    int coef;
    int expon;
    struct PolyNode *link;
}*Polynomial;

void Attach(int a,int b,Polynomial *pRear)
{
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=a;
    P->expon=b;
    P->link=NULL;
    (*pRear)->link=P;
    *pRear=P;
}

Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int n,a,b;
    scanf("%d",&n);
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear=P;
    while(n--)
    {
        scanf("%d %d",&a,&b);
        Attach(a,b,&Rear);
    }
    t=P;
    P=P->link;
    free(t);
    return P;
}

Polynomial Add(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;
    while(P1&&P2)
    {
        if(P1->expon>P2->expon)
        {
            Attach(P1->coef,P1->expon,&rear);
            P1=P1->link;
        }
        if(P1->expon<P2->expon)
        {
            Attach(P2->coef,P2->expon,&rear);
            P2=P2->link;
        }
        if(P1->expon==P2->expon)
        {
            sum=P1->coef+P2->coef;
            if(sum)
            {
                Attach(sum,P1->expon,&rear);
            }
            P1=P1->link;
            P2=P2->link;
        }
    }
    for(;P1;P1=P1->link) Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link) Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp=front;
    front=front->link;
    free(temp);
    return front;
}

Polynomial Mult(Polynomial P1,Polynomial P2)
{
    Polynomial P,Rear,t1,t2,t;
    int a,b;
    if(!P1||!P2) return NULL;
    t1=P1;
    t2=P2;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear=P;
    while(t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;
    }
    t1=t1->link;
    while(t1)
    {
        t2=P2;
        Rear=P;
        while(t2)
        {
            a=t1->coef*t2->coef;
            b=t1->expon+t2->expon;
            while(Rear->link&&Rear->link->expon>b)
            {
                Rear=Rear->link;
            }
            if(Rear->link&&Rear->link->expon==b)
            {
                if(Rear->link->coef+a)
                    Rear->link->coef+=a;
                else
                {
                    t=Rear->link;
                    Rear->link=t->link;
                    free(t);
                }
            }
            else
            {
                t=(Polynomial)malloc(sizeof(struct PolyNode));
                t->coef=a;
                t->expon=b;
                t->link=Rear->link;
                Rear->link=t;
                Rear=Rear->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    t2=P;
    P=P->link;
    free(t2);
    return P;
}

void PrintPoly(Polynomial P)
{
    int flag=0;
    if(!P)
    {
        printf("0 0\n");
        return ;
    }
    while(P)
    {
        if(!flag) flag=1;
        else printf(" ");
        printf("%d %d",P->coef,P->expon);
        P=P->link;
    }
    printf("\n");
}

int main()
{
    Polynomial P1,P2,PP,PS;

    P1=ReadPoly();
    P2=ReadPoly();
    PP=Mult(P1,P2);
    PrintPoly(PP);
    PS=Add(P1,P2);
    PrintPoly(PS);

    return 0;
}
