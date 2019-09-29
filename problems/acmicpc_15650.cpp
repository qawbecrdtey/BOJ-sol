#include <stdio.h>
void f(int const n,int const m,int *const a,int const idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            printf("%d ",a[i]+1);
        }
        printf("\n");
        return;
    }
    for(int i=a[idx-1]+1;i<n;i++){
        a[idx]=i;
        f(n,m,a,idx+1);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int *a=new int[m+1]();
    for(int i=0;i<n;i++){
        a[0]=i;
        f(n,m,a,1);
    }
    delete[] a;
}