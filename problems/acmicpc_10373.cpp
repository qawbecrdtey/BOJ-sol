#include <stdio.h>
#include <algorithm>
int main(){
    int b,k,d,p;
    scanf("%d%d%d%d",&b,&k,&d,&p);
    int *e=new int[d];
    int *f=new int[p];
    for(int i=0;i<d;i++){
        scanf("%d",&e[i]);
    }
    for(int i=0;i<p;i++){
        scanf("%d",&f[i]);
    }
    std::sort(e,e+d);
    std::sort(f,f+p);
    for(int i=d-2;i>=0;i--){
        e[i]+=e[i+1];
    }
    for(int i=p-2;i>=0;i--){
        f[i]+=f[i+1];
    }
    for(int i=0;i<d/2;i++){
        int tmp=e[i];
        e[i]=e[d-i-1];
        e[d-i-1]=tmp;
    }
    for(int i=0;i<p/2;i++){
        int tmp=f[i];
        f[i]=f[p-i-1];
        f[p-i-1]=tmp;
    }
    
}