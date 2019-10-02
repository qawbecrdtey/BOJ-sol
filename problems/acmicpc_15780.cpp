#include <stdio.h>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int m=0;
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        m+=(x+1)/2;
    }
    printf(m>=n?"YES":"NO");
}