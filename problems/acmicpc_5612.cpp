#include <stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int max=m;
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        m+=a-b;
        if(max<m)max=m;
        if(m<0){
            printf("0");
            return 0;
        }
    }
    printf("%d",max);
}