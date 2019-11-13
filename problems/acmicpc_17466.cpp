#include <stdio.h>
int main(){
    using ll=long long;
    int n,p;
    scanf("%d%d",&n,&p);
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=p;
    }
    printf("%d",ans);
}