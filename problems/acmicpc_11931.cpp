#include <stdio.h>
#include <algorithm>
bool comp(int a,int b){return a>b;}
int main(){
    int n;
    scanf("%d",&n);
    int *a=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n,comp);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}