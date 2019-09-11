#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[2000010]={};
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x+1000000]++;
    }
    for(int i=-1000000;i<=1000000;i++){
        while(a[i+1000000]--){
            printf("%d\n",i);
        }
    }
}