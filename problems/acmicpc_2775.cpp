#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k,n;
        scanf("%d%d",&k,&n);
        auto *a=new long long[n+1];
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
        for(int i=0;i<k;i++){
            long long sum=0;
            for(int j=1;j<=n;j++){
                a[j]=(sum+=a[j]);
            }
        }
        printf("%lld\n",a[n]);
        delete[] a;
    }
}