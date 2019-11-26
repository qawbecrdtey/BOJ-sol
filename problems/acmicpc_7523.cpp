#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Scenario #%d:\n",i);
        long long n,m;
        scanf("%lld%lld",&n,&m);
        printf("%lld\n\n",n*(m-n+1)+((m-n)*(m-n+1))/2);
    }
}