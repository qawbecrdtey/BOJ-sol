#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    auto *a=new pair<int,int>[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    int *b=new int[n];
    int cnt=1;
    b[0]=a[0].second;
    for(int i=1;i<n;i++){
        auto const x=lower_bound(b,b+cnt,a[i].second)-b;
        if(x==cnt){
            b[cnt++]=a[i].second;
        }
        else{
            b[x]=a[i].second;
        }
    }
    printf("%d",n-cnt);
    delete[] b;
    delete[] a;
}