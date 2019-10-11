#include <stdio.h>
#include <algorithm>
using ll=long long;
inline ll _abs(ll a){return a>0?a:-a;}
int main(){
    int n;
    scanf("%d",&n);
    ll *a=new ll[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    std::sort(a,a+n);
    ll closest=20000000001;
    ll ans[3];
    for(int i=0;i<n-2;i++){
        int j=i+1,k=n-1;
        while(j<k){
            const ll sum=a[i]+a[j]+a[k];
            if(_abs(sum)<closest){
                closest=_abs(sum);
                ans[0]=a[i];
                ans[1]=a[j];
                ans[2]=a[k];
            }
            if(sum<0)j++;
            else k--;
        }
    }
    printf("%lld %lld %lld",ans[0],ans[1],ans[2]);
    delete[] a;
}