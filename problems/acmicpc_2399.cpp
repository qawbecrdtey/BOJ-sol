#include <stdio.h>
#include <algorithm>
int main(){
    int n;
    scanf("%d",&n);
    long long *a=new long long[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    std::sort(a,a+n);
    long long ans=0;
    int m=1-n;
    for(int i=0;i<n;i++){
        ans+=m*a[i];
        m+=2;
    }
    printf("%lld",ans*2);
    delete[] a;
}