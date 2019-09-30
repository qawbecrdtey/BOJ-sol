#include <stdio.h>
const int s[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<3;i++){
        const int m=(i==2?4:10);
        if(sum+s[i]>=n)continue;
        sum+=s[i];
        for(int j=0;j<m;j++){
            if(sum+s[j]>=n)continue;
            sum+=s[j];
            for(int k=0;k<6;k++){
                if(sum+s[k]>=n)continue;
                sum+=s[k];
                for(int l=0;l<10;l++){
                    if(sum+s[l]!=n)continue;
                    printf("%d%d:%d%d",i,j,k,l);
                    return 0;
                }
                sum-=s[k];
            }
            sum-=s[j];
        }
        sum-=s[i];
    }
    printf("Impossible");
}