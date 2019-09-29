#include <stdio.h>
void search(int l,int r,int *a,int cur,int *b){
    int i;
    if(l==r)return;
    printf("%d ",b[cur]);
    for(i=l;i<r;i++){
        if(a[i]==b[cur])break;
    }
    search(l,i,a,cur+i-r,b);
    search(i+1,r,a,cur-1,b);
}
int main(){
    int n;
    scanf("%d",&n);
    int *a=new int[n];
    int *b=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    search(0,n,a,n-1,b);
    delete[] b;
    delete[] a;
}