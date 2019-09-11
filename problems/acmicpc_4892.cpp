#include <stdio.h>
int main(){
    int cnt=1;
    while(true){
        int n;
        scanf("%d",&n);
        if(n==0)break;
        printf("%d. ", cnt++);
        printf(n%2?"odd ":"even ");
        n=(n*3+1)/2;
        n*=3;
        n/=9;
        printf("%d\n",n);
    }
}