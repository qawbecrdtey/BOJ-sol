#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int const d=a+b-c,e=b+c-a,f=c+a-b;
    if(d<=0||e<=0||f<=0){printf("-1");return 0;}
    printf("1\n");
    if(d&1)printf("%d.5 ",d/2);
    else printf("%d.0 ",d/2);
    if(f&1)printf("%d.5 ",f/2);
    else printf("%d.0 ",f/2);
    if(e&1)printf("%d.5",e/2);
    else printf("%d.0",e/2);
}