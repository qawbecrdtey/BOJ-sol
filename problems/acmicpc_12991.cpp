#include <stdio.h>
#include <algorithm>
using namespace std;
using ll=long long;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    ll *a=new ll[n];
    ll *b=new ll[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    ll l=a[0]*b[0];
    ll r=a[n-1]*b[n-1]+1;
    while(l<r){
        ll cnt=0;
        ll m=(l+r)/2;
        for(int i=0;i<n;i++){
            int lll=0,rrr=n;
            while(lll<rrr){
                ll mmm=b[(lll+rrr)/2];
                if(a[i]*mmm<=m)lll=(lll+rrr)/2+1;
                else rrr=(lll+rrr)/2;
            }
            cnt+=lll;
        }
        if(cnt<k)l=m+1;
        else r=m;
    }
    printf("%lld",l);
    delete[] b;
    delete[] a;
}