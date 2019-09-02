#include <stdio.h>
int sqrt(int n){
    int x=1;
    while(x*x<n)x<<=1;
    int l=x>>1,r=x+1;
    while(l<r){
        int m=(l+r)/2;
        if(m*m<n){
            l=m+1;
            continue;
        }
        if(m*m>n){
            r=m;
            continue;
        }
        l=r=m;
        break;
    }
    return l;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d",(a+4+sqrt((a-4)*(a-4)-16*b))/4,(a+4-sqrt((a-4)*(a-4)-16*b))/4);
}