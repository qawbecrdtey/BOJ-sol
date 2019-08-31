#include <stdio.h>
#include <utility>
using namespace std;
int main(){
    pair<int,int> a[1000010];
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        a[i].first=a[i-1].first+1;
        a[i].second=i-1;
        if(i%3==0){
            if(a[i/3].first+1<a[i].first){
                a[i].first=a[i/3].first+1;
                a[i].second=i/3;
            }
        }
        if(i%2==0){
            if(a[i/2].first+1<a[i].first){
                a[i].first=a[i/2].first+1;
                a[i].second=i/2;
            }
        }
    }
    printf("%d\n",a[n].first);
    while(n>=1){
        printf("%d ",n);
        n=a[n].second;
    }
}