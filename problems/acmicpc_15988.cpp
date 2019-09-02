#include <stdio.h>
#define MOD 1000000009
int main(){
    int n;
    scanf("%d",&n);
    int max=-1;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(max<a[i])max=a[i];
    }
    int *dp=new int[max+1];
    dp[0]=1;
    for(int i=1;i<=max;i++){
        dp[i]=dp[i-1];
        if(i>1)dp[i]=(dp[i]+dp[i-2])%MOD;
        if(i>2)dp[i]=(dp[i]+dp[i-3])%MOD;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",dp[a[i]]);
    }
    delete[] dp;
    delete[] a;
}