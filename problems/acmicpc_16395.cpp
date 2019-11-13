#include <stdio.h>
int main(){
    long long a[40][40]={};
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++){
        a[0][i]=a[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            a[j][i-j]=a[j-1][i-j]+a[j][i-j-1];
        }
    }
    printf("%lld",a[k-1][n-k]);
}