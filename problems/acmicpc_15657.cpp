#include <stdio.h>
#include <algorithm>
void f(int const n,int const m,int *const a,int const *const b,int const idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            printf("%d ",b[a[i]]);
        }
        printf("\n");
        return;
    }
    for(int i=a[idx-1];i<n;i++){
        a[idx]=i;
        f(n,m,a,b,idx+1);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int *a=new int[m]();
    int *b=new int[n]();
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    std::sort(b,b+n);
    for(int i=0;i<n;i++){
        a[0]=i;
        f(n,m,a,b,1);
    }
    delete[] a;
}