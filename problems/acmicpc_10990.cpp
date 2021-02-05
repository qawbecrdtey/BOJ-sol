#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        printf("*");
        if(i==0){printf("\n");continue;}
        for(int j=0;j<(i<<1)-1;j++){
            printf(" ");
        }
        printf("*\n");
    }
}