#include <stdio.h>
#include <algorithm>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int *a=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    printf("%d",a[k-1]);
    delete[] a;
}