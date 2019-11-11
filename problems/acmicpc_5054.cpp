#include <stdio.h>
#include <algorithm>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int *a=new int[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        std::sort(a,a+n);
        printf("%d\n",(a[n-1]-a[0])*2);
        delete[] a;
    }
}