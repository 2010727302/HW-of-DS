#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int k,num,data1[10086],flag;
int main()
{
  
	cin>>k;
    while(k!=0)
    {
    	memset(data1,0,sizeof(data1));
    	flag=0;
		cin>>num;
    	for(int i=0;i<=num-1;i++)
    	{
    		cin>>data1[i];
    		if(data1[i]==i&&flag==0)
    		{
    			cout<<i<<endl;
    			flag=1;
			}
			//cout<<data1[i]<<" ";
		}
		if(!flag)
		{
			cout<<"-1"<<endl;
		}
		k--;
	}
    return 0;
}

