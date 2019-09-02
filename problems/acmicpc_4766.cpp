#include <stdio.h>
int main(){
    float a,b;
    scanf("%f",&a);
    while(true){
        scanf("%f",&b);
        if(b==999)break;
        printf("%.2f\n",b-a);
        a=b;
    }
}