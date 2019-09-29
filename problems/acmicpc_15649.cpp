#include <stdio.h>
void f(int const n,int const m,int *a,bool *v,int idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            printf("%d ",a[i]+1);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(v[i])continue;
        a[idx]=i;
        v[i]=true;
        f(n,m,a,v,idx+1);
        v[i]=false;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int *a=new int[m]();
    bool *v=new bool[n]();
    f(n,m,a,v,0);
    delete[] v;
    delete[] a;
}