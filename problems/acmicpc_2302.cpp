#include <stdio.h>
int a[50];
int fib(int n){
    if(n<2)return a[n]=1;
    if(a[n]==0){
        return fib(n-1)+fib(n-2);
    }
    else return a[n];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int *b=new int[m+1]();
    long long ans=1;
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        ans*=fib(b[i]-b[i-1]-1);
    }
    ans*=fib(n-b[m]);
    printf("%lld",ans);
}