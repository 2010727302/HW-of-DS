#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int nums[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d",&nums[i]);
    }
    int dp[N];
    dp[0] = nums[0];
    int max_sum = nums[0];
    int L=0,R=0;// 最大子序列的左和右端点
    int left=0,right=0;// 当前子序列的左和右端点
    for (int j = 1; j < N; ++j) {
        if(dp[j-1]>0){
            // 前面的[0,j-1]的子序列和大于0，就讲其加到当前数字上作为[0,j]的最大子序列和
            dp[j] = dp[j-1] + nums[j];
            right = j;// 只改变了右端点
        } else {
            dp[j] = nums[j];// 改变了左端点和右端点
            left = j;
            right = j;
        }
        if(dp[j]>max_sum){// 记录最大子序列和及其左右端点
            max_sum = dp[j];
            L = left;
            R = right;
        }
    }
    if(max_sum>=0){
        printf("%d %d %d",max_sum,nums[L],nums[R]);
    } else {
        printf("0 %d %d",nums[0],nums[N-1]);
    }
    return 0;
}
