#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        while(m%n){
            const int tmp=m/n+1;
            n=n*tmp-m;
            m*=tmp;
        }
        printf("%d\n",m/n);
    }
}