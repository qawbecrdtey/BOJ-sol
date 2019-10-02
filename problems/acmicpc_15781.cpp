#include <stdio.h>
#include <algorithm>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    int max=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        max=(max>x?max:x);
    }
    sum=max;
    max=0;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        max=(max>x?max:x);
    }
    sum+=max;
    printf("%d",sum);
}