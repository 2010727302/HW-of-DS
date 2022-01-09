#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int  m,n,k;
int st[100086];
int a[100086];
int main()
{
	cin>>m>>n>>k;
	for(int ci=1;ci<=k;ci++)
	{
		memset(st,0,sizeof(st));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int zhan=0,cur=1,flag=0;
		for(int i=1;i<=n;i++)
		{
			zhan++;
			st[zhan]=i;
			//cout<<zhan<<" "<<st[zhan]<<" ";
			if(zhan>m)
			{
				break;
			}
			while(zhan!=0&&st[zhan]==a[cur])
			{
				zhan--;
				cur++;
			//	cout<<st[zhan]<<" "<<zhan<<endl;	
			}
		}
		if(cur==n+1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}	
	return 0;
 } 
