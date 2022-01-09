#include <iostream>
#include <stdio.h>
using namespace std;
int num[10010],dp[10010],n,from[10010],anssum=-1,anspos;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    dp[1]=num[1];
    from[1]=1;
    for(int i=2;i<=n;i++)
    { 
        if(dp[i-1]+num[i]>=num[i])
        {
            dp[i]=dp[i-1]+num[i];
            from[i]=from[i-1];   //当dp[i-1]+num[i]>=num[i]时，以第i项结尾的子序列的第1项应该是以第i-1项结尾的子序列的第1项 
        }
        else
        {
            dp[i]=num[i];
            from[i]=i;  //当num[i]>dp[i-1]+num[i]时，第i项结尾的最大子序列的第1项就是本身. 
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(anssum<dp[i])
        {
            anssum=dp[i];
            anspos=i;
        }
    }
    if(anssum==-1) cout<<"0 "<<num[1]<<" "<<num[n]<<endl;
    else cout<<anssum<<" "<<num[from[anspos]]<<" "<<num[anspos]<<endl;
    return 0;
}
