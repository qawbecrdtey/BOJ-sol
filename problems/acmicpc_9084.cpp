#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int *cost=new int[n];
        int res;
        for(int i=0;i<n;i++){
            scanf("%d",&cost[i]);
        }
        scanf("%d",&res);
        int *dp=new int[res+1]();
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=cost[i];j<=res;j++){
                dp[j]+=dp[j-cost[i]];
            }
        }
        printf("%d\n",dp[res]);
        delete[] cost;
        delete[] dp;
    }
}