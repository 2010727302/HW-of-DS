#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;
struct lnode 
{
    int key;//���� 
    int num;//��� 
    int flag;//�Ƿ��Ѿ���� 
    
}huan[10086];
typedef struct lnode* linklist;
int m;//����ֵ 
int renshu;//�������� 
linklist l,la; 


int main()
{
	cin>>m; 
	cin>>renshu; 
	for(int i=1;i<=renshu;i++)
	{
		cin>>huan[i].key;
		huan[i].num=i;
		huan[i].flag=0;
	} 
	int dangqianren=renshu;
	int cur=0;
	for(int i=1;i<=renshu;i++)
	{
		
		int jishu=m;
		//cout<<i<<":";
		/*if(i==1)
		{
			cur=0;
		}*/
		while(jishu!=0)//�ҵ�Ҫ����� 
		{
			cur=(cur+1)%dangqianren;//ʹ��mod���� 
			if(cur==0)cur=dangqianren;
			if(huan[cur].flag==0)//��δ���� 
			{
				jishu--; 
				//cout<<"jihsu"<<jishu<<" ";
			}
			//cout<<"cur"<<cur<<endl;
		}
		cout<<huan[cur].num<<endl;
		m=huan[cur].key;
		huan[cur].flag=1;
		//cout<<endl;
	}
	
    return 0;
}
