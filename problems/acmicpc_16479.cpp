#include <stdio.h>
int main(){
    int k,a,b;
    scanf("%d%d%d",&k,&a,&b);
    printf("%f",k*k-(b-a)*(b-a)/4.0);
}