#include <stdio.h>
int main(){
    int a,b,c,d,e,f;
    scanf("%d:%d:%d",&a,&b,&c);
    scanf("%d:%d:%d",&d,&e,&f);
    int g=d-a,h=e-b,i=f-c;
    if(i<0){i+=60;h--;}
    if(h<0){h+=60;g--;}
    if(g<0)g+=24;
    printf("%02d:%02d:%02d",g,h,i);
}