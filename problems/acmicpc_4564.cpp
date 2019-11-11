#include <stdio.h>
int main(){
    while(true){
        int n;
        scanf("%d",&n);
        if(n==0)break;
        printf("%d ",n);
        while(n>9){
            int m=1;
            while(n){
                m*=n%10;
                n/=10;
            }
            printf("%d ",n=m);
        }
        printf("\n");
    }
}