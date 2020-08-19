#include <stdio.h>
void f(int x,int y,int n,char** a){
    if(n==1){
        a[x][y]='*';
        return;
    }
    int const m=n/3;
    f(x,y,m,a);
    f(x,y+m,m,a);
    f(x,y+m+m,m,a);
    f(x+m,y,m,a);
    f(x+m,y+m+m,m,a);
    f(x+m+m,y,m,a);
    f(x+m+m,y+m,m,a);
    f(x+m+m,y+m+m,m,a);
}
int main(){
    int n;
    scanf("%d",&n);
    char** a=new char*[n];
    for(int i=0;i<n;i++){
        a[i]=new char[n];
        for(int j=0;j<n;j++){
            a[i][j]=' ';
        }
    }
    f(0,0,n,a);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
        delete[] a[i];
    }
    delete[] a;
}