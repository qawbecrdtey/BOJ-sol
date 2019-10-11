#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    auto *a=new pair<pair<int,int>,int>[n]();
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first.first,&a[i].first.second);
        a[i].second=123456789;
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        int find=-1;
        for(int j=i+1;j<n;j++){
            if(a[j].first.second==a[i].first.second){
                find=j;
                break;
            }
        }
        if(find!=-1){
            if(a[find].first.first-a[i].first.first<a[i].second){
                a[i].second=a[find].first.first-a[i].first.first;
            }
            a[find].second=a[find].first.first-a[i].first.first;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i].second;
    }
    printf("%d",ans);
    delete[] a;
}