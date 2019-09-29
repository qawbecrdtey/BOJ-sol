#include <stdio.h>
using uint=unsigned int;
uint pow(uint n,uint m){
    if(m==0)return 1;
    uint x=pow(n,m/2);
    return x*x*(m%2?n:1);
}
int main(){
    int n;
    scanf("%d",&n);
    uint ans=0;
    for(int i=0;i<n;i++){
        uint x;
        scanf("%u",&x);
        ans+=pow(x/10,x%10);
    }
    printf("%u",ans);
}