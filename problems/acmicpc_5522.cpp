#include <stdio.h>
int main() {
    int n=0;
    for(int i=0;i<5;i++){
        int x;
        scanf("%d",&x);
        n+=x;
    }
    printf("%d",n);
}