#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    double d=1.0/a,e=1.0/b,f=1.0/c;
    printf("%f",1/(d+e+f));
}