#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int d=(a>0?a:-a)+(b>0?b:-b);
    if(c<d||((d-c)%2))printf("NO");
    else printf("YES");
}