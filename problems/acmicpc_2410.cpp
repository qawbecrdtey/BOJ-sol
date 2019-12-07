#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
	int m = 0;
	while ((1<<m)<=n)m++;
    int **a=new int*[m];
    for(int i=0;i<m;i++){
        a[i]=new int[n+1]();
        int const x=1<<i;
		a[i][x]=1;
        for(int j=x+1;j<=n;j++){
            for(int k=0;k<=i;k++){
                a[i][j]=(a[i][j]+a[k][j-x])%1000000000;
            }
        }
    }
    int sum=0;
    for(int i=0;i<m;i++){
        sum=(sum+a[i][n])%1000000000;
    }
    printf("%d",sum);
    for(int i=0;i<m;i++)delete[] a[i];
    delete[] a;
}