#include<stdio.h>
#include<iostream>
using namespace std;
int data[100086],next1[100086],list[100086],result[100086];
int toua,n,k,cnt=0;
int main()
{
	cin>>toua>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int ca,cd,na;
		cin>>ca>>cd>>na;
		data[ca]=cd;
		next1[ca]=na;
	}
	int p=toua;
	while(p!=-1)
	{
		cnt++;
		list[cnt]=p;
		p=next1[p];
	}
	for(int i=1;i<=cnt;i++)
	{
		result[i]=list[i];
		//cout<<result[i]<<endl;
	}
	for(int i=1;i<=(cnt-cnt%k);i++)
	{
		if(i%k!=0)
		{
			result[i]=list[i/k*k+k+1-i%k];
		}
		else
		{
			result[i]=list[i/k*k-k+1];
		}
	}
	for(int i=1;i<cnt;i++)
	{
		 printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
	}
	printf("%05d %d -1", result[cnt], data[result[cnt]]);
	return 0;
 } 
