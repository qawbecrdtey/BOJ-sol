#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int max=-1;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(max<x)max=x;
    }
    printf("%d",max);
}