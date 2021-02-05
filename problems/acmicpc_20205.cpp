#include <stdio.h>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    auto b=new int*[n*k];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            b[i*k+j]=new int[n*k];
        }
        for(int j=0;j<n;j++){
            int a;
            scanf("%d",&a);
            for(int x=0;x<k;x++){
                for(int y=0;y<k;y++){
                    b[i*k+x][j*k+y]=a;
                }
            }
        }
    }
    for(int i=0;i<n*k;i++){
        for(int j=0;j<n*k;j++){
            printf("%d ",b[i][j]);
        }
        delete[] b[i];
        printf("\n");
    }
    delete[] b;
}