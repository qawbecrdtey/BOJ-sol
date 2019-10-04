#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int *a=new int[n];
    int *b=new int[n];
    int max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                b[i]=(b[j]+a[i]>b[i]?b[j]+a[i]:b[i]);
            }
        }
        max=(max>b[i]?max:b[i]);
    }
    printf("%d",max);
    delete[] b;
    delete[] a;
}