#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int k=1;
    for(int i=0;i<7;i++){
        for(int j=0;j<n-1;j++){
            printf(((j/k)&1)?"B":"A");
        }
        if((n-2)/k==0)printf("B");
        else printf((((n-1)/k)&1)?"B":"A");
        printf("\n");
        k+=k;
    }
}