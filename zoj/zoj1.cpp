#include<iostream>
using namespace std;
long long k=0,sum=0,ans=0;
int a[100086];
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=k;i++)
	{
		
		sum+=a[i];
			
			if(sum>ans)
			{
				ans=sum;
			}
			if(sum<0)
			{
				sum=0;
			}
			
		
	}
	cout<<ans;
	return 0;
 } 
