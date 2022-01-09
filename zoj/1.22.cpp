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
    int L=0,R=0;// ��������е�����Ҷ˵�
    int left=0,right=0;// ��ǰ�����е�����Ҷ˵�
    for (int j = 1; j < N; ++j) {
        if(dp[j-1]>0){
            // ǰ���[0,j-1]�������кʹ���0���ͽ���ӵ���ǰ��������Ϊ[0,j]����������к�
            dp[j] = dp[j-1] + nums[j];
            right = j;// ֻ�ı����Ҷ˵�
        } else {
            dp[j] = nums[j];// �ı�����˵���Ҷ˵�
            left = j;
            right = j;
        }
        if(dp[j]>max_sum){// ��¼��������кͼ������Ҷ˵�
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
