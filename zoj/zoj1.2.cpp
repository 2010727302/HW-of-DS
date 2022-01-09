#include<iostream>
using namespace std;
long long k=0,sum[100086],ans=0,tou,wei,l,r;
int a[100086];
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	sum[1]=a[1];
	tou=1;
	wei=1;
	ans=a[1];
	l=1;r=1;
	for(int i=2;i<=k;i++)
	{
		if(sum[i-1]>=0)
		{
			sum[i]=sum[i-1]+a[i];
			wei=i;
		}
		else
		{
			sum[i]=a[i];
			tou=i;
			wei=i;
		}
		if(sum[i]>ans)
		{
			ans=sum[i];
			l=tou;
			r=wei;
		}
	}
	if(ans>=0)
	{
		cout<<ans<<" "<<a[l]<<" "<<a[r];
	}
	else
	{
		cout<<0<<" "<<a[1]<<" "<<a[k];
	}
	return 0;
 } 
