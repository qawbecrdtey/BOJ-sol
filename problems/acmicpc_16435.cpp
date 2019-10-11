#include <stdio.h>
#include <algorithm>
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    int *a=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    for(int i=0;i<n;i++){
        if(l<a[i]){
            printf("%d",l);
            return 0;
        }
        l++;
    }
    printf("%d",l);
    delete[] a;
}