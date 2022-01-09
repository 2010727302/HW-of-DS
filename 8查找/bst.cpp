#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#define MAXSIZE 10086
using namespace std;
//�������������
typedef struct bstnode
{
	int key;//�������Ԫ�� 
	struct bstnode *lchild,*rchild;//���Һ���ָ�� 
}bstnode,*bstree;
//�������Ĵ�ӡ 
struct qnode
{
	bstree data[MAXSIZE];//������ڵ�
	int deep[MAXSIZE];//������ڲ�
	int locate[MAXSIZE];//��ӡ�ڵ�λ��
	int front,rear;//ͷָ�룬βָ�� 
}q; 
bstree t,p; 
int shuru2,shuru3,chazhao;
//12 7 17 11 16 2 13 9 21 4 0
//��ֵΪkey�Ľ�� ���ǵݹ� 
bstnode *bsearch(bstree t,int key)
{
	while(t!=NULL&&key!=t->key)
	{
		if(key<t->key)//<���������� 
		{
			t=t->lchild;
		}
		else//>���������� 
		{
			t=t->rchild; 
		} 
		chazhao++;
	}
	//ʧ�ܷ���NULL 
	return t;
}
//��ֵΪkey�Ľ�� ���ݹ� 
bstnode *bsearch2(bstree t,int key)
{
	if(t==NULL)//ʧ�ܷ���NULL 
	return NULL;
	if(key==t->key)//�ɹ� 
	return t;
	else if(key<t->key)//<���������� 
	{
		return bsearch(t->lchild,key);
	}
	else//>���������� 
	{
		return bsearch(t->rchild,key);
	} 
	
	return t;
}
//����ֵΪkey�Ľ�� �ݹ� 
int binsert(bstree& t,int key)
{
	if(t==NULL)//ʧ��
	{
		t=(bstree)malloc(sizeof(bstnode));
		t->key=key;
		t->lchild=t->rchild=NULL;
		return 1; //����ɹ� 
	}

	if(key==t->key)//������ͬ������ʧ�� 
	return 0;
	else if(key<t->key)//<���������� 
	{
		binsert(t->lchild,key);
	}
	else//>���������� 
	{
		binsert(t->rchild,key);
	} 

}
//��������ؼ��ֽ������������� 
void cbst(bstree &t)
{
	t=NULL;//��ʼt��
	int shuru;
	cin>>shuru;
	while(shuru!=0)//���ν�ÿ���ؼ��ֲ������������ 
	{
		binsert(t,shuru);
		cin>>shuru;	
	} 
}
//���� 
void btra(bstree& t)
{
	if(t==NULL)//��Ϊ�� 
	{
		//cout<<"����"<<endl;
		return;
	}
	if(t)
	{
		btra(t->lchild);//��������
		cout<<t->key<<" ";
		btra(t->rchild);//�����Һ���
	} 
}
//��ʽ����ӡ
void bprint(bstree& t)
{
	int j=1,k=0;//�㣬����λ�� 
	q.front=0,q.rear=1;//��ʼ�� 
	q.data[0]=t;//�����ڵ������Ϣ������� 
	q.deep[0]=1;
	q.locate[0]=30;
	cout<<"\t"<<endl; 
	while(q.front!=q.rear)
	{
		//int n=q.rear-q.front;
		//cout<<" n"<<n<<endl;
		bstree temp=q.data[q.front];
		int i=q.deep[q.front];//��ǰ�㣬����λ�� 
		int nloc=q.locate[q.front];
		//cout<<"  "<<endl;
		if(j<i)//���²㻻�� 
		{
			cout<<endl<<endl<<endl;
			//cout<<endl;
			j++;
			k=0; 
			//while(k<(nloc))//�Ʋ���λ��
			{
				//cout<<" ";
				//k++;	
			} 
		}
		while(k<(nloc+5))//���Ʋ���λ��
		{
			cout<<" ";
			k++;	
		} 
		cout<<temp->key;
		//cout<<":"<<i;
		if(temp->lchild)//������ �����
		{
			q.data[q.rear]=temp->lchild;//�������Ϣ������� 
			q.deep[q.rear]=i+1;
			q.locate[q.rear]=(int)(nloc-pow(2,(5-i)));
			//cout<<" "<<q.locate[q.rear];
			q.rear++;
		} 
		if(temp->rchild)//���Һ��� �����
		{
			q.data[q.rear]=temp->rchild;//�������Ϣ������� 
			q.deep[q.rear]=i+1;
			q.locate[q.rear]=(int)(nloc+pow(2,(5-i)));
			//cout<<" "<<q.locate[q.rear];
			q.rear++;
		} 
		q.front++;//���� 
		//cout<<"fr"<<front<<endl;
		
	}	
	cout<<endl;
 } 
//ɾ��
bool bdelete(bstree& p)
{
	bstree q1,f,s;
	f=NULL;
	//����key
	//cout<<p->key<<endl;
	// ɾ��p 
	if (!p->rchild&&!p->lchild)//Ҷ�ӽڵ� 
	{
		//cout<<0<<endl;
		p=NULL;
		//free(p);
	}
	else if (!p->rchild)//ֻ�����ӣ����Ӵ��� 
	{
		q1=p; 
		p=p->lchild;
		//q1=p->lchild;
		//p->key=q1->key;
		free(q1);
	}
	else if (!p->lchild)//ֻ���Һ��ӣ��Һ��Ӵ��� 
	{
		q1=p; 
		p=p->rchild;//ֻ���ý�� p ������������������ p ����
		free(q1);
	}
	else//���Һ��Ӿ����� 
	{ 
		q1=p; 
		s=p->lchild;//p���� 
		while(s->rchild)//sΪ�������ǰ�� 
		{ 
			q1=s;
			s=s->rchild;
		} 
		p->key = s->key;
		//�жϽ�� p �������� s �Ƿ�������������Ϊ�����������
		if( q1 != p ) 
		q1->rchild = s->lchild; //���У�����ɾ��ֱ��ǰ������ͬʱ����ǰ�������ӽ���Ϊ q ָ����ĺ��ӽ��
		else
		q1->lchild = s->lchild; //����ֱ�ӽ����������Ƽ���
		free(s);
	}
	return 1;
}
 //ɾ��t
int bstdel(bstree&t,int key)
{
 	if(t==NULL)//�����ڹؼ��ֵ���key������Ԫ��
	return 0;
	if(key==t->key)//�ɹ�
	{
		bdelete(t);
		return 1;
	} 
	
	else if(key<t->key)//<���������� 
	{
		return bstdel(t->lchild,key);
	}
	else//>���������� 
	{
		return bstdel(t->rchild,key);
	} 
	
	return 1;
 }

int main()
{
	cout<<"���������������"<<endl; 
	cbst(t); 
	
	cout<<"������������"<<endl; 
	btra(t);
	cout<<endl;	
	cout<<"��ӡ��������"<<endl;
	bprint(t);
	cout<<endl;
	cout<<"���Ҷ�������������Ҫ���ҵ�key����"<<endl;
	cin>>shuru2;
	p=bsearch(t,shuru2);
	if(p)
	{
		cout<<"�ýڵ����"<<endl;
		cout<<"������"<<chazhao+1<<endl;
	}
	else
	{
		cout<<"�ýڵ㲻����"<<endl;
		cout<<"������"<<chazhao+1<<endl;
	}
	cout<<"ɾ����������������Ҫ���ҵ�key����"<<endl;
	cin>>shuru3;
	int panduan=0;
	panduan=bstdel(t,shuru3);
	if(panduan)
	{
		cout<<"ɾ���ɹ�"<<endl; 
	} 
	else
	{
		cout<<"ɾ��ʧ��"<<endl; 
	}
	cout<<"������������"<<endl; 
	btra(t);
	cout<<endl;	
	cout<<"��ӡ��������"<<endl;
	bprint(t);
	cout<<endl;
    return 0;
}
