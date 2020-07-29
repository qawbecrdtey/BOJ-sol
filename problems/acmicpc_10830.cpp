#include <stdio.h>
#include <memory>
#include <utility>
using namespace std;
unique_ptr<unique_ptr<int[]>[]> mult(unique_ptr<unique_ptr<int[]>[]>& a, unique_ptr<unique_ptr<int[]>[]>& b, int n){
    auto arr=make_unique<unique_ptr<int[]>[]>(n);
    for(int i=0;i<n;i++){
        arr[i]=make_unique<int[]>(n);
        for(int j=0;j<n;j++){
            arr[i][j]=0;
            for(int k=0;k<n;k++){
                arr[i][j]=(arr[i][j]+a[i][k]*b[k][j])%1000;
            }
        }
    }
    return move(arr);
}
int main(){
    int n;
    long long b;
    scanf("%d%lld",&n,&b);
    auto A=make_unique<unique_ptr<int[]>[]>(n);
    auto ans=make_unique<unique_ptr<int[]>[]>(n);
    for(int i=0;i<n;i++){
        A[i]=make_unique<int[]>(n);
        ans[i]=make_unique<int[]>(n);
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
            ans[i][j]=0;
        }
        ans[i][i]=1;
    }
    while(b){
        if(b&1){
            ans=mult(ans,A,n);
        }
        A=mult(A,A,n);
        b>>=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}