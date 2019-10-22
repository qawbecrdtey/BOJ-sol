#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int j=1;j*j<=n;j++){
        if(n%j)continue;
        if(n/j==j)cnt++;
        else cnt+=2;
    }
    printf("%d",cnt);
}