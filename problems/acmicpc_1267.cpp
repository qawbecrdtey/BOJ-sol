#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int y=0,m=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        y+=10+10*(x/30);
        m+=15+15*(x/60);
    }
    if(y>m)printf("M %d",m);
    else if(y<m)printf("Y %d",y);
    else printf("Y M %d",y);
}