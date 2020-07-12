#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x=10;
    int k=1;
    long long ans=0;
    while(x-1<=n){
        ans+=(x-x/10)*k;
        x*=10;
        k++;
    }
    ans+=(n-x/10+1)*k;
    printf("%d",ans);
}