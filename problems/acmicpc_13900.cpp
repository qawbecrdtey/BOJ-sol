#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0,sum2=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
        sum2+=x*x;
    }
    sum*=sum;
    printf("%lld",(sum-sum2)/2);
}