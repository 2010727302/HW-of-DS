#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int k,num,data1[10086],flag;
int find(int a[], int N)
{
	int lower=1, upper=N, mid;
	while (lower <= upper)
	{	
		mid = (lower+upper)/2;
		if (a[mid]>mid)
			upper = mid-1;
		else if (a[mid]<mid)
			lower = mid+1;
		else
			return mid;
	}
	return 0;
}
int main()
{
  
	cin>>k;
    while(k!=0)
    {
    	memset(data1,0,sizeof(data1));
    	flag=0;
		cin>>num;
    	for(int i=1;i<=num;i++)
    	{
    		cin>>data1[i];
    		data1[i]++;
		}
		flag=find(data1,num);
		if(flag)
			cout<<flag-1<<endl;
		else
		{
			cout<<-1<<endl;
		}
		k--;
	}
    return 0;
}

