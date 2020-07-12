#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    bool a[3]={true,false,false};
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        bool tmp=a[x];
        a[x]=a[y];
        a[y]=tmp;
    }
    for(int i=0;i<3;i++){
        if(a[i])printf("%d",i+1);
    }
}