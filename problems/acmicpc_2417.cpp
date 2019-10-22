#include <stdio.h>
using ll=long long;
int main(){
    ll n;
    scanf("%lld",&n);
    ll l=0,r=3037000500;
    int cnt=0;
    while(l<r){
        ll mid=(l+r)/2;
        if(mid*mid>=n)r=mid;
        else l=mid+1;
    }
    printf("%lld",l);
}