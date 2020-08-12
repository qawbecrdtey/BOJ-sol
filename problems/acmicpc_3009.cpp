#include <stdio.h>
int main(){
    int a[2][3];
    for(int i=0;i<3;i++){
        scanf("%d%d",&a[0][i],&a[1][i]);
    }
    if(a[0][0]==a[0][1])printf("%d ",a[0][2]);
    else if(a[0][0]==a[0][2])printf("%d ",a[0][1]);
    else printf("%d ",a[0][0]);
    if(a[1][0]==a[1][1])printf("%d",a[1][2]);
    else if(a[1][0]==a[1][2])printf("%d",a[1][1]);
    else printf("%d",a[1][0]);
}